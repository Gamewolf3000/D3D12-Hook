#pragma once

#include <Windows.h>
#include <stdexcept>
#include <string>

class FunctionHook
{
private:
#ifdef _WIN64 // 64-bit
    static constexpr unsigned char TRAMPOLINE_TEMPLATE[] =
    {
        0x48,
        0xb8,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x50,
        0xc3
    };
    const static unsigned int ADRESS_START = 2; // Where in the assembly the adress to the function that we jump to should start
#else //32-bit
    static constexpr unsigned char TRAMPOLINE_TEMPLATE[] =
    {
        0x68, //push in x86 assembly
        0x00, //placeholder for byte 1 of the overwriting functions adress
        0x00, //placeholder for byte 2 of the overwriting functions adress
        0x00, //placeholder for byte 3 of the overwriting functions adress
        0x00, //placeholder for byte 4 of the overwriting functions adress
        0xc3  //retn in x86 assembly
    };
    const static unsigned int ADRESS_START = 1; // Where in the assembly the adress to the function that we jump to should start
#endif
    static const unsigned int TRAMPOLINE_SIZE = ARRAYSIZE(TRAMPOLINE_TEMPLATE);
    void* originalFunction = nullptr;
    unsigned char originalCode[TRAMPOLINE_SIZE];
    unsigned char trampolineCode[TRAMPOLINE_SIZE];

public:
    FunctionHook();
    ~FunctionHook();

    void Initialize(void* functionToHook, const void* hookFunction);
    void Inject();
    void Restore();
};

/*
const int OVERWRITE_SIZE = 12;

struct HookData
{
    void* functionAdress;
    unsigned char original[OVERWRITE_SIZE];
    unsigned char neo[OVERWRITE_SIZE];
};

HookData dummyHook;

void SetupHook(void* functionToHook, void* hookFunction, HookData& hookData)
{
    hookData.functionAdress = functionToHook;
    DWORD oldProtect, restoreProtect;
    if (!VirtualProtect(functionToHook, OVERWRITE_SIZE, PAGE_EXECUTE_READ, &oldProtect))
        throw std::runtime_error("Failed to change protection level of functions memory when setting up hook");
    memcpy(hookData.original, functionToHook, OVERWRITE_SIZE);
    hookData.neo[0] = 0x48;
    hookData.neo[1] = 0xb8;
    hookData.neo[10] = 0x50;
    hookData.neo[11] = 0xc3;
    memcpy(&hookData.neo[2], &hookFunction, sizeof(void*));
    if (!VirtualProtect(functionToHook, OVERWRITE_SIZE, oldProtect, &restoreProtect))
        throw std::runtime_error("Failed to resret protection level of functions memory when setting up hook");
}

void Inject(const HookData& hookData)
{
    DWORD oldProtect, restoreProtect;
    if(!VirtualProtect(hookData.functionAdress, OVERWRITE_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect))
        throw std::runtime_error("Failed to change protection level of functions memory when injecting hook: " + std::to_string(GetLastError()));
    memcpy(hookData.functionAdress, hookData.neo, OVERWRITE_SIZE);
    VirtualProtect(hookData.functionAdress, OVERWRITE_SIZE, oldProtect, &restoreProtect);
}

void Restore(const HookData& hookData)
{
    DWORD oldProtect, restoreProtect;
    VirtualProtect(hookData.functionAdress, OVERWRITE_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect);
    memcpy(hookData.functionAdress, hookData.original, OVERWRITE_SIZE);
    VirtualProtect(hookData.functionAdress, OVERWRITE_SIZE, oldProtect, &restoreProtect);
}

void Dummy(int value)
{
    std::string message = "Value = " + std::to_string(value);
    MessageBoxA(nullptr, message.c_str(), "Dummy", 0);
}

void FakeDummy(int value)
{
    Restore(dummyHook);
    Dummy(value + 10);
    Inject(dummyHook);
}
*/