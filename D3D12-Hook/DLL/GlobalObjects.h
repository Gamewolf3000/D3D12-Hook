#pragma once

#include "../Shared/SharedConstants.h"
#include "../Shared/MessageWriter.h"
#include "../Shared/MessageReader.h"

#include "D3D12Manager.h"

extern DWORD processId;
extern SharedConstants sharedConstants;
extern MessageWriter messageWriter;
extern MessageReader messageReader;
extern D3D12Manager* d12Manager;

void InitializeGlobalObjects();