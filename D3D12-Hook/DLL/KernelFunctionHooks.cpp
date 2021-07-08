#include "KernelFunctionHooks.h"

#include "GlobalObjects.h"

FunctionHook hookCreateProcessW;
FunctionHook hookFreeLibrary;

std::wstring WINAPI DetermineExecutableVersion(LPCWSTR applicationName)
{
	DWORD binaryType;
	GetBinaryTypeW(applicationName, &binaryType);

	if (binaryType == SCS_32BIT_BINARY) // 32 bit binary
		return L"32";
	else if (binaryType == SCS_64BIT_BINARY)
		return L"64";
	else
		return L"UNKNOWN_EXE_VERSION";
}

std::wstring WINAPI GetApplicationName(LPCWSTR lpApplicationName, LPWSTR lpCommandLine)
{
	if (lpApplicationName != nullptr)
		return lpApplicationName;

	if (lpCommandLine[0] == '\"')
	{
		std::wstring toReturn(lpCommandLine + 1);
		return toReturn.substr(0, toReturn.find_first_of(L'\"'));
	}
	else
	{
		std::wstring toReturn(lpCommandLine);
		return toReturn.substr(0, toReturn.find_first_of(L' '));
	}

}

BOOL WINAPI LaunchInjector(LPCWSTR applicationName, LPWSTR commandLine, DWORD processId)
{
	// additional information
	STARTUPINFOW startupInfo;
	PROCESS_INFORMATION processInfo;
	// set the size of the structures
	ZeroMemory(&startupInfo, sizeof(startupInfo));
	startupInfo.cb = sizeof(startupInfo);
	ZeroMemory(&processInfo, sizeof(processInfo));

	std::wstring processIdString = std::to_wstring(processId);
	std::wstring processPath = GetApplicationName(applicationName, commandLine);
	std::wstring injectorPath(sharedConstants.GetInjectorPath());
	injectorPath += L"\\Injector";
	injectorPath += DetermineExecutableVersion(processPath.c_str());
	injectorPath += L".exe";
	std::wstring directory = injectorPath.substr(0, injectorPath.find_last_of('\\') + 1);
	wchar_t* arguments = new wchar_t[processIdString.length() + 1];
	memcpy(arguments, processIdString.c_str(), processIdString.length() * sizeof(wchar_t));
	arguments[processIdString.length()] = 0;

	Message message;
	message.type = MessageType::INJECTION_MESSAGE;
	message.data[0] = static_cast<unsigned char>(DetermineExecutableVersion(processPath.c_str()) == L"64" ? 64 : 32);
	memcpy(message.data + 1, processPath.c_str(), (processPath.length() + 1) * sizeof(wchar_t)); // + 1 for \0
	messageWriter.WriteMessage(message);

	bool toReturn = CreateProcessW(injectorPath.c_str(),
		arguments,
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		NULL,			// No creation flags
		NULL,           // Use parent's environment block
		directory.c_str(), // Starting directory 
		&startupInfo,   // Pointer to STARTUPINFO structure
		&processInfo    // Pointer to PROCESS_INFORMATION structure
	);

	delete[] arguments;
	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);

	return toReturn;
}

BOOL WINAPI FakeCreateProcessW(LPCWSTR lpApplicationName, LPWSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes,
	LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment,
	LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
	//MessageBoxA(0, "Starting fake create process", "FakeCreateProcessW", 0);
	InitializeGlobalObjects();
	hookCreateProcessW.Restore();
	//hook_CreateProcessW.Restore();

	BOOL toReturn = CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes,
		bInheritHandles, dwCreationFlags | CREATE_SUSPENDED, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);

	if (toReturn)
	{
		//MessageBoxA(0, "BEFORE LAUNCH INJECTOR", "FakeCreateProcessW", 0);
		if (!LaunchInjector(lpApplicationName, lpCommandLine, lpProcessInformation->dwProcessId))
			MessageBoxA(nullptr, ("Failed to start injector: " + std::to_string(GetLastError())).c_str(), "DLL Error", 0);
		//MessageBoxA(0, "AFTER LAUNCH INJECTOR", "FakeCreateProcessW", 0);

		Sleep(1000);
	}

	ResumeThread(lpProcessInformation->hThread);
	hookCreateProcessW.Inject();
	//hook_CreateProcessW.Inject();

	//MessageBoxA(0, "Finished fake create process", "FakeCreateProcessW", 0);

	return toReturn;
}

BOOL WINAPI FakeFreeLibrary(HMODULE hLibModule)
{
	hookFreeLibrary.Restore();
	BOOL toReturn = FreeLibrary(hLibModule);
	hookFreeLibrary.Inject();

	return toReturn;
}