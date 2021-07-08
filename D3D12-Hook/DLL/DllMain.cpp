#include <Windows.h>

#include "GlobalObjects.h"
#include "KernelFunctionHooks.h"
#include "DXGIFunctionHooks.h"
#include "D3D12FunctionHooks.h"

void HookFunction(const wchar_t* moduleName, const char* functionName, FunctionHook& hook, void* replacementFunction)
{
    HMODULE processHandle = nullptr;

    while(processHandle == nullptr)
        processHandle = GetModuleHandle(moduleName);

    auto adress = GetProcAddress(processHandle, functionName);
    if (!adress)
    {
        auto errorMessage = "Error hooking function: " + std::string(functionName) +  "!\nLasterror: " + std::to_string(GetLastError());
        MessageBoxA(0, errorMessage.c_str(), "Function hook error", 0);
        return;
    }

    hook.Initialize(adress, replacementFunction);
    hook.Inject();
}

DWORD WINAPI OverrideFunctions(LPVOID lpParam)
{
    (void)lpParam;
    CRITICAL_SECTION cs;
    InitializeCriticalSection(&cs);
    EnterCriticalSection(&cs);
    //MessageBoxA(0, "Starting", "DLL Override", 0);
    HookFunction(L"kernel32.dll", "CreateProcessW", hookCreateProcessW, FakeCreateProcessW);
    //HookFunction(L"kernel32.dll", "FreeLibrary", hookFreeLibrary, FakeFreeLibrary);
    //HookFunction(L"dxgi.dll", "CreateDXGIFactory", hookCreateDXGIFactory, FakeCreateDXGIFactory);
    //HookFunction(L"dxgi.dll", "CreateDXGIFactory1", hookCreateDXGIFactory1, FakeCreateDXGIFactory1);
    //HookFunction(L"dxgi.dll", "CreateDXGIFactory2", hookCreateDXGIFactory2, FakeCreateDXGIFactory2);
    //HookFunction(L"d3d12.dll", "D3D12CreateDevice", hookD3D12CreateDevice, FakeD3D12CreateDevice);
    //MessageBoxA(0, "Done", "DLL Override", 0);
    LeaveCriticalSection(&cs);
    DeleteCriticalSection(&cs);

    return 0;
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        CreateThread(
            NULL,                   // default security attributes
            0,                      // use default stack size  
            OverrideFunctions,      // thread function name
            NULL,		            // argument to thread function 
            0,                      // use default creation flags 
            NULL);		    // returns the thread identifier

        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}