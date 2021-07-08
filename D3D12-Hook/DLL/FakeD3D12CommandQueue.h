//#pragma once
//
//#include <d3d12.h>
//
//class FakeD3D12CommandQueue : public ID3D12CommandQueue
//{
//private:
//	ID3D12CommandQueue* real;
//
//public:
//	FakeD3D12CommandQueue(ID3D12CommandQueue* real);
//	~FakeD3D12CommandQueue() = default;
//
//
//	// Inherited via ID3D12CommandQueue
//	virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override;
//
//	virtual ULONG __stdcall AddRef(void) override;
//
//	virtual ULONG __stdcall Release(void) override;
//
//	virtual HRESULT __stdcall GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData) override;
//
//	virtual HRESULT __stdcall SetPrivateData(REFGUID guid, UINT DataSize, const void* pData) override;
//
//	virtual HRESULT __stdcall SetPrivateDataInterface(REFGUID guid, const IUnknown* pData) override;
//
//	virtual HRESULT __stdcall SetName(LPCWSTR Name) override;
//
//	virtual HRESULT __stdcall GetDevice(REFIID riid, void** ppvDevice) override;
//
//	virtual void __stdcall UpdateTileMappings(ID3D12Resource* pResource, UINT NumResourceRegions, const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates, const D3D12_TILE_REGION_SIZE* pResourceRegionSizes, ID3D12Heap* pHeap, UINT NumRanges, const D3D12_TILE_RANGE_FLAGS* pRangeFlags, const UINT* pHeapRangeStartOffsets, const UINT* pRangeTileCounts, D3D12_TILE_MAPPING_FLAGS Flags) override;
//
//	virtual void __stdcall CopyTileMappings(ID3D12Resource* pDstResource, const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate, ID3D12Resource* pSrcResource, const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate, const D3D12_TILE_REGION_SIZE* pRegionSize, D3D12_TILE_MAPPING_FLAGS Flags) override;
//
//	virtual void __stdcall ExecuteCommandLists(UINT NumCommandLists, ID3D12CommandList* const* ppCommandLists) override;
//
//	virtual void __stdcall SetMarker(UINT Metadata, const void* pData, UINT Size) override;
//
//	virtual void __stdcall BeginEvent(UINT Metadata, const void* pData, UINT Size) override;
//
//	virtual void __stdcall EndEvent(void) override;
//
//	virtual HRESULT __stdcall Signal(ID3D12Fence* pFence, UINT64 Value) override;
//
//	virtual HRESULT __stdcall Wait(ID3D12Fence* pFence, UINT64 Value) override;
//
//	virtual HRESULT __stdcall GetTimestampFrequency(UINT64* pFrequency) override;
//
//	virtual HRESULT __stdcall GetClockCalibration(UINT64* pGpuTimestamp, UINT64* pCpuTimestamp) override;
//
//	virtual D3D12_COMMAND_QUEUE_DESC __stdcall GetDesc(void) override;
//
//};