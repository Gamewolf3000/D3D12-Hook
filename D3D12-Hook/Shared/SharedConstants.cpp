#include "SharedConstants.h"

#include <mutex>

SharedConstants::SharedConstants(const ConstantsData& data)
{
    memory.CreateSharedMemory(IDENTIFIER, sizeof(ConstantsData));
    std::memcpy(memory.GetPointer(), &data, sizeof(ConstantsData));
    initialized = true;
}

void SharedConstants::InitializeRead()
{
    static std::mutex mutex;

    mutex.lock();
    if(!initialized)
        memory.ConnectToSharedMemory(IDENTIFIER, sizeof(ConstantsData));
    initialized = true;
    mutex.unlock();
}

wchar_t* SharedConstants::GetInjectorPath()
{
    return static_cast<wchar_t*>(memory.GetPointer());
}
