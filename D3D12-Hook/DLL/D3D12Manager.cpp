#include "D3D12Manager.h"

D3D12Manager::D3D12Manager(DWORD processId, MessageReader* incoming, MessageWriter* outgoing) : 
	processId(processId), incomingMessages(incoming), outgoingMessages(outgoing)
{

}

void D3D12Manager::AddObject(void* real, REFIID type, void* fake)
{
	//createdInterfaces[real][type] = fake;
}

void* D3D12Manager::GetAppropriateObject(void* real, REFIID type)
{
	void* toReturn = real;

	/*auto vector = createdInterfaces.find(real);
	if (vector != createdInterfaces.end())
	{
		auto element = (*vector).second.find(type);
		if (element != (*vector).second.end())
		{
			toReturn = (*element).second;
		}
	}*/

	return toReturn;
}
