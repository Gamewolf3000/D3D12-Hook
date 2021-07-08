#include <Windows.h>
#include <string>
#include <stdexcept>
#include <iostream>

BOOL SetPrivilege(HANDLE hToken, LPCTSTR lpszPrivilege, BOOL bEnablePrivilege)
{
    LUID luid;
    BOOL bRet = FALSE;

    if (LookupPrivilegeValue(NULL, lpszPrivilege, &luid))
    {
        TOKEN_PRIVILEGES tp;

        tp.PrivilegeCount = 1;
        tp.Privileges[0].Luid = luid;
        tp.Privileges[0].Attributes = (bEnablePrivilege) ? SE_PRIVILEGE_ENABLED : 0;
        //
        //  Enable the privilege or disable all privileges.
        //
        if (AdjustTokenPrivileges(hToken, FALSE, &tp, NULL, (PTOKEN_PRIVILEGES)NULL, (PDWORD)NULL))
        {
            //
            //  Check to see if you have proper access.
            //  You may get "ERROR_NOT_ALL_ASSIGNED".
            //
            bRet = (GetLastError() == ERROR_SUCCESS);
        }
    }
    return bRet;
}

void FixPrivilege()
{
    HANDLE mainToken;

    if (!OpenThreadToken(GetCurrentThread(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, FALSE, &mainToken))
    {
        if (GetLastError() == ERROR_NO_TOKEN)
        {
            if (!ImpersonateSelf(SecurityImpersonation))
                throw std::runtime_error("Error regarding ImpersonateSelf\n");

            if (!OpenThreadToken(GetCurrentThread(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, FALSE, &mainToken))
                throw std::runtime_error("Error opening thread token: " + std::to_string(GetLastError()));
        }
        else
            throw std::runtime_error("Failed to open thread token: " + std::to_string(GetLastError()));
    }

    if (!SetPrivilege(mainToken, SE_DEBUG_NAME, true))
    {
        CloseHandle(mainToken);
        throw std::runtime_error("Couldn't set DEBUG MODE: " + std::to_string(GetLastError()));
    }
    CloseHandle(mainToken);
}

void InjectDLL(std::wstring dllPath, HANDLE processHandle)
{
    // How many bytes we need to hold the whole DLL path
    int bytesToAlloc = (1 + static_cast<int>(dllPath.length())) * sizeof(WCHAR);

    // Allocate memory in the remote process for the DLL path
    LPWSTR remoteBufferForLibraryPath = LPWSTR(VirtualAllocEx(processHandle, NULL, bytesToAlloc, MEM_COMMIT, PAGE_READWRITE));
    if (remoteBufferForLibraryPath == 0)
        throw std::runtime_error("Failed to allocate virtual memory\nLast error was: " + std::to_string(GetLastError()));

    // Put the DLL path into the address space of the target process
    if (!WriteProcessMemory(processHandle, remoteBufferForLibraryPath, dllPath.c_str(), bytesToAlloc, NULL))
        throw std::runtime_error("Failed to inject dll\nLast error was: " + std::to_string(GetLastError()));

    // Get the real address of LoadLibraryW in Kernel32.dll
    PTHREAD_START_ROUTINE loadLibraryFunction = PTHREAD_START_ROUTINE(GetProcAddress(GetModuleHandleW(L"Kernel32"), "LoadLibraryW"));
    if (loadLibraryFunction == 0)
        throw std::runtime_error("Failed to get procedure adress\nLast error was: " + std::to_string(GetLastError()));

    // Create remote thread that calls LoadLibraryW
    HANDLE remoteThreadHandle = CreateRemoteThread(processHandle, NULL, 0, loadLibraryFunction, remoteBufferForLibraryPath, 0, NULL);
    if (remoteThreadHandle == 0)
        throw std::runtime_error("Failed to get create remote thread\nLast error was: " + std::to_string(GetLastError()));

    WaitForSingleObject(remoteThreadHandle, INFINITE);

    DWORD dwExitCode = 0;
    GetExitCodeThread(remoteThreadHandle, &dwExitCode);

    CloseHandle(remoteThreadHandle);
    VirtualFreeEx(processHandle, remoteBufferForLibraryPath, 0, MEM_RELEASE);
    CloseHandle(processHandle);

    //if(dwExitCode != 0)
    //    throw std::runtime_error("Thread in injected program seemingly did not exit properly\nExit code was: " + std::to_string(dwExitCode));
}

std::wstring DllPath()
{
    std::wstring dllName = L"D3D12Hook";
    wchar_t injectorPath[MAX_PATH];
    GetModuleFileNameW(NULL, injectorPath, MAX_PATH);
    std::wstring injectorFolder(injectorPath);
    injectorFolder = injectorFolder.substr(0, injectorFolder.find_last_of(L'\\') + 1);

#if _WIN64
    dllName += L"64.dll";
#else
    dllName += L"32.dll";
#endif

    return injectorFolder + dllName;
}

int wmain(int argc, wchar_t* argv[])
{
    if (argc < 1)
    {
        MessageBoxA(nullptr, "Injector got to few arguments!", "Injector Error", 0);
        return -1;
    }

    wchar_t* end;
    DWORD id = std::wcstol(argv[0], &end, 10);

    try
    {
        FixPrivilege();

        HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, id);
        if(processHandle == nullptr)
            throw std::runtime_error("Failed to get processHandle");

        InjectDLL(DllPath(), processHandle);
    }
    catch (const std::exception& e)
    {
        MessageBoxA(nullptr, e.what(), "Injector Error", 0);
    }

    return 0;
}