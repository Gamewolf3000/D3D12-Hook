//#include "FakeD3D12CommandQueue.h"
//
//FakeD3D12CommandQueue::FakeD3D12CommandQueue(ID3D12CommandQueue* real) : real(real)
//{
//
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::QueryInterface(REFIID riid, void** ppvObject)
//{
//	return real->QueryInterface(riid, ppvObject);
//}
//
//ULONG __stdcall FakeD3D12CommandQueue::AddRef(void)
//{
//	return real->AddRef();
//}
//
//ULONG __stdcall FakeD3D12CommandQueue::Release(void)
//{
//	return real->Release();
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData)
//{
//	return real->GetPrivateData(guid, pDataSize, pData);
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::SetPrivateData(REFGUID guid, UINT DataSize, const void* pData)
//{
//	return real->SetPrivateData(guid, DataSize, pData);
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::SetPrivateDataInterface(REFGUID guid, const IUnknown* pData)
//{
//	return real->SetPrivateDataInterface(guid, pData);
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::SetName(LPCWSTR Name)
//{
//	return real->SetName(Name);
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::GetDevice(REFIID riid, void** ppvDevice)
//{
//	return real->GetDevice(riid, ppvDevice);
//}
//
//void __stdcall FakeD3D12CommandQueue::UpdateTileMappings(ID3D12Resource* pResource, UINT NumResourceRegions, const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates, const D3D12_TILE_REGION_SIZE* pResourceRegionSizes, ID3D12Heap* pHeap, UINT NumRanges, const D3D12_TILE_RANGE_FLAGS* pRangeFlags, const UINT* pHeapRangeStartOffsets, const UINT* pRangeTileCounts, D3D12_TILE_MAPPING_FLAGS Flags)
//{
//	real->UpdateTileMappings(pResource, NumResourceRegions, pResourceRegionStartCoordinates, pResourceRegionSizes, pHeap, NumRanges, pRangeFlags, pHeapRangeStartOffsets, pRangeTileCounts, Flags);
//}
//
//void __stdcall FakeD3D12CommandQueue::CopyTileMappings(ID3D12Resource* pDstResource, const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate, ID3D12Resource* pSrcResource, const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate, const D3D12_TILE_REGION_SIZE* pRegionSize, D3D12_TILE_MAPPING_FLAGS Flags)
//{
//	real->CopyTileMappings(pDstResource, pDstRegionStartCoordinate, pSrcResource, pSrcRegionStartCoordinate, pRegionSize, Flags);
//}
//
//void __stdcall FakeD3D12CommandQueue::ExecuteCommandLists(UINT NumCommandLists, ID3D12CommandList* const* ppCommandLists)
//{
//	real->ExecuteCommandLists(NumCommandLists, ppCommandLists);
//}
//
//void __stdcall FakeD3D12CommandQueue::SetMarker(UINT Metadata, const void* pData, UINT Size)
//{
//	real->SetMarker(Metadata, pData, Size);
//}
//
//void __stdcall FakeD3D12CommandQueue::BeginEvent(UINT Metadata, const void* pData, UINT Size)
//{
//	real->BeginEvent(Metadata, pData, Size);
//}
//
//void __stdcall FakeD3D12CommandQueue::EndEvent(void)
//{
//	real->EndEvent();
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::Signal(ID3D12Fence* pFence, UINT64 Value)
//{
//	return real->Signal(pFence, Value);
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::Wait(ID3D12Fence* pFence, UINT64 Value)
//{
//	return real->Wait(pFence, Value);
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::GetTimestampFrequency(UINT64* pFrequency)
//{
//	return real->GetTimestampFrequency(pFrequency);
//}
//
//HRESULT __stdcall FakeD3D12CommandQueue::GetClockCalibration(UINT64* pGpuTimestamp, UINT64* pCpuTimestamp)
//{
//	return real->GetClockCalibration(pGpuTimestamp, pCpuTimestamp);
//}
//
//D3D12_COMMAND_QUEUE_DESC __stdcall FakeD3D12CommandQueue::GetDesc(void)
//{
//	return real->GetDesc();
//}
