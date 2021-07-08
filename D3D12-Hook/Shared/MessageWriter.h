#pragma once

#include "MessageHandler.h"

class MessageWriter : public MessageHandler
{
private:
	bool CanWriteMessage();

public:
	MessageWriter() = default;
	~MessageWriter() = default;

	void WriteMessage(const Message& message);
};