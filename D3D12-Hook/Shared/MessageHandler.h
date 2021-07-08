#pragma once

#include <mutex>

#include "SharedMemory.h"

enum class MessageType
{
	NULL_MESSAGE,
	TEXT_MESSAGE,
	INJECTION_MESSAGE,
	HOOKED_MESSAGE
};

static const int MESSAGE_SIZE = 255;

struct Message
{
	MessageType type = MessageType::NULL_MESSAGE;
	unsigned char data[MESSAGE_SIZE];
};

class MessageHandler
{
protected:
	std::mutex handlerMutex;
	SharedMemory memory;
public:
	MessageHandler() = default;
	virtual ~MessageHandler() = default;

	void Initialize(const wchar_t* identifier, bool create);
};