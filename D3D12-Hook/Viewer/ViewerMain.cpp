#include <stdexcept>
#include <iostream>
#include <string>
#include <chrono>
#include <locale>
#include <codecvt>

#include <Windows.h>

#include "..\Shared\SharedConstants.h"
#include "..\Shared\MessageWriter.h"

#include "IncomingMessagesHandling.h"

#define LI std::string("\nIn file: ") + __FILE__ + "\nAt line: " + std::to_string(__LINE__)

static const UINT NR_OF_BACK_BUFFERS = 2;

void ThrowIfFailed(HRESULT hr, const std::exception& exception)
{
    if (FAILED(hr))
        throw exception;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and find what code to run for the message given
    switch (message)
    {
        // this message is read when the window is closed
    case WM_DESTROY:
    {
        // close the application entirely
        PostQuitMessage(0);
        return 0;
    } break;
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc(hWnd, message, wParam, lParam);
}

HWND InitializeWindow(HINSTANCE hInstance, int nCmdShow, unsigned int windowWidth, unsigned int windowHeight)
{
    const wchar_t CLASS_NAME[] = L"D3D12 Viewer";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hWnd = CreateWindowEx(0, CLASS_NAME, L"D3D12 Viewer", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, windowWidth, windowHeight, nullptr, nullptr, hInstance, nullptr);

    if (hWnd == nullptr)
    {
        DWORD errorCode = GetLastError();
        throw std::runtime_error("Could not create window, last error: " + std::to_string(errorCode));
    }

    ShowWindow(hWnd, nCmdShow);
    return hWnd;
}

DWORD DetermineExecutableVersion(LPCSTR applicationName)
{
    DWORD binaryType;
    GetBinaryTypeA(applicationName, &binaryType);

    if (binaryType == SCS_32BIT_BINARY) // 32 bit binary
        return 32;
    else if (binaryType == SCS_64BIT_BINARY)
        return 64;
    else
        return binaryType;
}

void StartInjector(std::wstring processId, std::string applicationPath, std::string injectorDirectory)
{
    // additional information
    STARTUPINFOW startupInfo;
    PROCESS_INFORMATION processInfo;

    // set the size of the structures
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory(&processInfo, sizeof(processInfo));

    std::wstring injectorPath = L".\\Injector";
    wchar_t* commandLine = new wchar_t[(processId.length() + 1)];
    memcpy(commandLine, processId.c_str(), processId.length() * sizeof(wchar_t));
    commandLine[processId.length()] = 0;
    injectorPath += std::to_wstring(DetermineExecutableVersion(applicationPath.c_str()));
    injectorPath += L".exe";
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring directory2 = converter.from_bytes(injectorDirectory);

    bool success = CreateProcessW(injectorPath.c_str(), commandLine, NULL, NULL, FALSE, NULL, NULL,
        directory2.c_str(), &startupInfo, &processInfo);

    if (!success)
        throw std::runtime_error("Could not start injector: " + std::to_string(GetLastError()));

    delete[] commandLine;
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
}

void StartApplication(std::string applicationPath)
{
    // additional information
    STARTUPINFOA startupInfo;
    PROCESS_INFORMATION processInfo;

    // set the size of the structures
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory(&processInfo, sizeof(processInfo));

    char* commandLine = new char[applicationPath.length()];
    memcpy(commandLine, applicationPath.c_str(), applicationPath.length());
    std::string directory = applicationPath.substr(0, applicationPath.find_last_of('\\') + 1);

    // start the program up
    bool success = CreateProcessA(applicationPath.c_str(),   // the path
        commandLine,    // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        CREATE_SUSPENDED,// Create the application in suspended mode so we can inject into it before it has time to do stuff
        NULL,           // Use parent's environment block
        directory.c_str(), // Starting directory 
        &startupInfo,   // Pointer to STARTUPINFO structure
        &processInfo    // Pointer to PROCESS_INFORMATION structure
    );

    if (!success)
        throw std::runtime_error("Failed to start process: " + applicationPath + "\nLast error was: " + std::to_string(GetLastError()));

    StartInjector(std::to_wstring(processInfo.dwProcessId), applicationPath, directory);

    Sleep(1000);

    delete[] commandLine;
    ResumeThread(processInfo.hThread);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    MessageReader messageReader;
    messageReader.Initialize(L"HOOK_MESSAGE_TO_VIEWER_MEMORY", true);
    MessageWriter messageWriter;
    messageWriter.Initialize(L"HOOK_MESSAGE_TO_INJECTED_MEMORY", true);
    AllocConsole();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

    const unsigned int windowWidth = 1280;
    const unsigned int windowHeight = 720;
    HWND window = InitializeWindow(hInstance, nCmdShow, windowWidth, windowHeight);
    ConstantsData constantsData;
    GetModuleFileNameW(NULL, constantsData.injectorPath, MAX_PATH);
    constantsData.injectorPath[std::wstring(constantsData.injectorPath).find_last_of(L'\\')] = 0;
    SharedConstants constantsMemory(constantsData);

    MSG msg = { };
    double dtS = 0.0;
    unsigned long long dtN = 1;
    const unsigned long long TIME_UNIT = 1000000000;
    auto start = std::chrono::steady_clock::now();
    auto end = start;
    unsigned long long nanoCounter = 0;
    unsigned long long frameCounter = 0;

    try
    {
        //StartApplication(".\\D3D12Test.exe");
        StartApplication("C:\\Program Files (x86)\\Steam\\steam.exe");
    }
    catch (const std::exception& e)
    {
        MessageBoxA(nullptr, e.what(), "Error", 0);
    }

    while (!(GetKeyState(VK_ESCAPE) & 0x8000) && msg.message != WM_QUIT)
    {
        dtN = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        dtS = dtN * 1.0 / TIME_UNIT;
        start = std::chrono::steady_clock::now();
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (messageReader.HasMessage())
            HandleIncomingMessage(messageReader.GetStoredMessage());

        //UPDATE LOGIC
        nanoCounter += dtN;
        if (nanoCounter >= TIME_UNIT)
        {
            nanoCounter -= TIME_UNIT;
            frameCounter = 0;
        }

        frameCounter += 1;
        end = std::chrono::steady_clock::now();
    }

    return 0;
}