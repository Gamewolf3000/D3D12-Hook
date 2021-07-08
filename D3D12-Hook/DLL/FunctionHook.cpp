#include "FunctionHook.h"

FunctionHook::FunctionHook()
{
    memset(originalCode, 0, TRAMPOLINE_SIZE);
    memset(trampolineCode, 0, TRAMPOLINE_SIZE);
}

FunctionHook::~FunctionHook()
{
    Restore();
}

void FunctionHook::Initialize(void* functionToHook, const void* hookFunction)
{
    originalFunction = functionToHook;
    DWORD oldProtect, restoreProtect;
    if (!VirtualProtect(originalFunction, TRAMPOLINE_SIZE, PAGE_EXECUTE_READ, &oldProtect))
        throw std::runtime_error("Failed to change the protection level of the functions memory when setting up hook");
    memcpy(originalCode, functionToHook, TRAMPOLINE_SIZE);
    memcpy(trampolineCode, TRAMPOLINE_TEMPLATE, TRAMPOLINE_SIZE);
    memcpy(&trampolineCode[ADRESS_START], &hookFunction, sizeof(hookFunction));
    if (!VirtualProtect(functionToHook, TRAMPOLINE_SIZE, oldProtect, &restoreProtect))
        throw std::runtime_error("Failed to restore the protection level of the functions memory when setting up hook");
}

void FunctionHook::Inject()
{
    if (!originalFunction)
        return;

    DWORD oldProtect, restoreProtect;
    if (!VirtualProtect(originalFunction, TRAMPOLINE_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect))
        throw std::runtime_error("Failed to change protection level of functions memory when injecting hook: "
            + std::to_string(GetLastError()));

    memcpy(originalFunction, trampolineCode, TRAMPOLINE_SIZE);

    if (!VirtualProtect(originalFunction, TRAMPOLINE_SIZE, oldProtect, &restoreProtect))
        throw std::runtime_error("Failed to reset protection level of functions memory when injecting hook: "
            + std::to_string(GetLastError()));

    //Flush instruction cache. May be required on some architectures which
    //don't feature strong cache coherency guarantees, though not on neither
    //x86, x64 nor AMD64.
    FlushInstructionCache(GetCurrentProcess(), originalFunction, TRAMPOLINE_SIZE);
}

void FunctionHook::Restore()
{
    if (!originalFunction)
        return;

    DWORD oldProtect, restoreProtect;
    if(!VirtualProtect(originalFunction, TRAMPOLINE_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect))
        throw std::runtime_error("Failed to change protection level of functions memory when restoring function: "
            + std::to_string(GetLastError()));

    memcpy(originalFunction, originalCode, TRAMPOLINE_SIZE);

    if(!VirtualProtect(originalFunction, TRAMPOLINE_SIZE, oldProtect, &restoreProtect))
        throw std::runtime_error("Failed to reset protection level of functions memory when restoring function: "
            + std::to_string(GetLastError()));

    //Flush instruction cache. May be required on some architectures which
    //don't feature strong cache coherency guarantees, though not on neither
    //x86, x64 nor AMD64.
    FlushInstructionCache(GetCurrentProcess(), originalFunction, TRAMPOLINE_SIZE);
}
