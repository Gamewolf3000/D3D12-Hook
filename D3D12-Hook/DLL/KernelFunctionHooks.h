#pragma once
#include <Windows.h>

#include "FunctionHook.h"

extern FunctionHook hookCreateProcessW;
extern FunctionHook hookFreeLibrary;
extern FunctionHook hookTest;

BOOL WINAPI FakeCreateProcessW(
	LPCWSTR               lpApplicationName,
	LPWSTR                lpCommandLine,
	LPSECURITY_ATTRIBUTES lpProcessAttributes,
	LPSECURITY_ATTRIBUTES lpThreadAttributes,
	BOOL                  bInheritHandles,
	DWORD                 dwCreationFlags,
	LPVOID                lpEnvironment,
	LPCWSTR               lpCurrentDirectory,
	LPSTARTUPINFOW        lpStartupInfo,
	LPPROCESS_INFORMATION lpProcessInformation
);

BOOL WINAPI FakeFreeLibrary(
	HMODULE hLibModule
);