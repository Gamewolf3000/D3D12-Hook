#pragma once

#include "MessageHandler.h"

class MessageReader : public MessageHandler
{
private:
	MessageType GetStoredMessageType();
	void ResetStorage();

public:
	MessageReader() = default;
	~MessageReader() = default;

	bool HasMessage();
	Message GetStoredMessage();
};