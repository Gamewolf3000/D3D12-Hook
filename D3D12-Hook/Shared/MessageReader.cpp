#include "MessageReader.h"

MessageType MessageReader::GetStoredMessageType()
{
	return MessageType(static_cast<unsigned char*>(memory.GetPointer())[0]);
}

bool MessageReader::HasMessage()
{
	return GetStoredMessageType() != MessageType::NULL_MESSAGE;
}

Message MessageReader::GetStoredMessage()
{
	handlerMutex.lock();
	Message toReturn;

	if (GetStoredMessageType() != MessageType::NULL_MESSAGE)
	{
		toReturn.type = GetStoredMessageType();
		memcpy(toReturn.data, static_cast<unsigned char*>(memory.GetPointer()) + 1, MESSAGE_SIZE);
		ResetStorage();
	}

	handlerMutex.unlock();
	return toReturn;

}

void MessageReader::ResetStorage()
{
	static_cast<unsigned char*>(memory.GetPointer())[0] = unsigned char(MessageType::NULL_MESSAGE);
}
