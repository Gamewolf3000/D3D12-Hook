#include "MessageHandler.h"

void MessageHandler::Initialize(const wchar_t* identifier, bool create)
{
    if (create)
        memory.CreateSharedMemory(identifier, MESSAGE_SIZE + 1);
    else
        memory.ConnectToSharedMemory(identifier, MESSAGE_SIZE + 1);

    static_cast<unsigned char*>(memory.GetPointer())[0] = 0;
}
