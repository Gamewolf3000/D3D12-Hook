#include "MessageWriter.h"

#include <cstring>

bool MessageWriter::CanWriteMessage()
{
    return MessageType(static_cast<unsigned char*>(memory.GetPointer())[0]) == MessageType::NULL_MESSAGE;
}

void MessageWriter::WriteMessage(const Message& message)
{
    handlerMutex.lock();

    while (!CanWriteMessage())
    {
        //SPINLOCK
    }

    static_cast<unsigned char*>(memory.GetPointer())[0] = unsigned char(message.type);
    memcpy(static_cast<unsigned char*>(memory.GetPointer()) + 1, message.data, MESSAGE_SIZE);

    handlerMutex.unlock();
}
