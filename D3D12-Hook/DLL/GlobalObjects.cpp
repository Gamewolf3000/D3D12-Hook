#include "GlobalObjects.h"

DWORD processId;
SharedConstants sharedConstants;
MessageWriter messageWriter;
MessageReader messageReader;
D3D12Manager* d12Manager;

void InitializeGlobalObjects()
{
	static bool initialized = false;

	if (initialized)
		return;

	processId = GetCurrentProcessId();
	sharedConstants.InitializeRead();
	messageWriter.Initialize(L"HOOK_MESSAGE_TO_VIEWER_MEMORY", false);
	messageReader.Initialize(L"HOOK_MESSAGE_TO_INJECTED_MEMORY", false);
	d12Manager = new D3D12Manager(processId, &messageReader, &messageWriter);

	Message hookedMessage;
	hookedMessage.type = MessageType::HOOKED_MESSAGE;
	memcpy(hookedMessage.data, &processId, sizeof(processId));
	messageWriter.WriteMessage(hookedMessage);

	initialized = true;

}
