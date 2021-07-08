#pragma once

#include <Windows.h>
#include <unordered_map>

#include "../Shared/MessageReader.h"
#include "../Shared/MessageWriter.h"

class D3D12Manager
{
private:
	//std::unordered_map<void*, std::unordered_map<REFIID, void*>> createdInterfaces; // real object adress as key, fake object adress as value
	DWORD processId;
	MessageReader* incomingMessages;
	MessageWriter* outgoingMessages;

public:
	D3D12Manager(DWORD processId, MessageReader* incoming, MessageWriter* outgoing);
	~D3D12Manager() = default;

	void AddObject(void* real, REFIID type, void* fake);
	void* GetAppropriateObject(void* real, REFIID type);
};