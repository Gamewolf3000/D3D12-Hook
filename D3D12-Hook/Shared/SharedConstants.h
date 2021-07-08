#pragma once

#include <Windows.h>

#include "SharedMemory.h"

struct ConstantsData
{
	wchar_t injectorPath[MAX_PATH];
};

class SharedConstants
{
private:
	static constexpr wchar_t IDENTIFIER[] = L"SHARED_HOOK_CONSTANTS";
	SharedMemory memory;
	bool initialized = false;

public:
	SharedConstants() = default;
	SharedConstants(const ConstantsData& data);
	~SharedConstants() = default;

	void InitializeRead();
	wchar_t* GetInjectorPath();
};