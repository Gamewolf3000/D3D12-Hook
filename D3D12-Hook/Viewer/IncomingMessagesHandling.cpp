#include "IncomingMessagesHandling.h"

#include <iostream>
#include <string>

void HandleTextMessage(const Message& message)
{
	std::cout << message.data << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

void HandleInjectionMessage(const Message& message)
{
	std::cout << "Injecting with " << std::to_string(static_cast<int>(message.data[0])) << "-bit injector" << std::endl;
	std::wcout << L"Into process: " << reinterpret_cast<const wchar_t*>(message.data + 1) << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

void HandleHookedMessage(const Message& message)
{
	//TEMPORARY TO SEE THAT IT WORKS
	uint32_t id = *reinterpret_cast<const uint32_t*>(message.data);
	std::cout << "Process was hooked with id: " << id << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

void HandleUnknownMessage(const Message& message)
{
	std::cout << "Error: Received unknown message type" << std::endl;
	std::cout << "Type: " << unsigned int(message.type) << std::endl;
	std::cout << "Data: " << message.data << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

void HandleIncomingMessage(const Message& message)
{
	switch (message.type)
	{
	case MessageType::TEXT_MESSAGE:
		HandleTextMessage(message);
		break;
	case MessageType::INJECTION_MESSAGE:
		HandleInjectionMessage(message);
		break;
	case MessageType::HOOKED_MESSAGE:
		HandleHookedMessage(message);
		break;
	default:
		HandleUnknownMessage(message);
		break;
	}
}
