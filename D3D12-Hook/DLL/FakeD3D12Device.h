#pragma once

#include <d3d12.h>

class FakeD3D12Device : public ID3D12Device6
{
private:
	ID3D12Device6* real;

public:
	FakeD3D12Device(ID3D12Device6* real);
	~FakeD3D12Device() = default;



	// Inherited via ID3D12Device6
	virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override;

	virtual ULONG __stdcall AddRef(void) override;

	virtual ULONG __stdcall Release(void) override;

	virtual HRESULT __stdcall GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData) override;

	virtual HRESULT __stdcall SetPrivateData(REFGUID guid, UINT DataSize, const void* pData) override;

	virtual HRESULT __stdcall SetPrivateDataInterface(REFGUID guid, const IUnknown* pData) override;

	virtual HRESULT __stdcall SetName(LPCWSTR Name) override;

	virtual UINT __stdcall GetNodeCount(void) override;

	virtual HRESULT __stdcall CreateCommandQueue(const D3D12_COMMAND_QUEUE_DESC* pDesc, REFIID riid, void** ppCommandQueue) override;

	virtual HRESULT __stdcall CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE type, REFIID riid, void** ppCommandAllocator) override;

	virtual HRESULT __stdcall CreateGraphicsPipelineState(const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc, REFIID riid, void** ppPipelineState) override;

	virtual HRESULT __stdcall CreateComputePipelineState(const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc, REFIID riid, void** ppPipelineState) override;

	virtual HRESULT __stdcall CreateCommandList(UINT nodeMask, D3D12_COMMAND_LIST_TYPE type, ID3D12CommandAllocator* pCommandAllocator, ID3D12PipelineState* pInitialState, REFIID riid, void** ppCommandList) override;

	virtual HRESULT __stdcall CheckFeatureSupport(D3D12_FEATURE Feature, void* pFeatureSupportData, UINT FeatureSupportDataSize) override;

	virtual HRESULT __stdcall CreateDescriptorHeap(const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc, REFIID riid, void** ppvHeap) override;

	virtual UINT __stdcall GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType) override;

	virtual HRESULT __stdcall CreateRootSignature(UINT nodeMask, const void* pBlobWithRootSignature, SIZE_T blobLengthInBytes, REFIID riid, void** ppvRootSignature) override;

	virtual void __stdcall CreateConstantBufferView(const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

	virtual void __stdcall CreateShaderResourceView(ID3D12Resource* pResource, const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

	virtual void __stdcall CreateUnorderedAccessView(ID3D12Resource* pResource, ID3D12Resource* pCounterResource, const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

	virtual void __stdcall CreateRenderTargetView(ID3D12Resource* pResource, const D3D12_RENDER_TARGET_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

	virtual void __stdcall CreateDepthStencilView(ID3D12Resource* pResource, const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

	virtual void __stdcall CreateSampler(const D3D12_SAMPLER_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

	virtual void __stdcall CopyDescriptors(UINT NumDestDescriptorRanges, const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts, const UINT* pDestDescriptorRangeSizes, UINT NumSrcDescriptorRanges, const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts, const UINT* pSrcDescriptorRangeSizes, D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType) override;

	virtual void __stdcall CopyDescriptorsSimple(UINT NumDescriptors, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart, D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart, D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType) override;

	virtual D3D12_RESOURCE_ALLOCATION_INFO __stdcall GetResourceAllocationInfo(UINT visibleMask, UINT numResourceDescs, const D3D12_RESOURCE_DESC* pResourceDescs) override;

	virtual D3D12_HEAP_PROPERTIES __stdcall GetCustomHeapProperties(UINT nodeMask, D3D12_HEAP_TYPE heapType) override;

	virtual HRESULT __stdcall CreateCommittedResource(const D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialResourceState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, REFIID riidResource, void** ppvResource) override;

	virtual HRESULT __stdcall CreateHeap(const D3D12_HEAP_DESC* pDesc, REFIID riid, void** ppvHeap) override;

	virtual HRESULT __stdcall CreatePlacedResource(ID3D12Heap* pHeap, UINT64 HeapOffset, const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, REFIID riid, void** ppvResource) override;

	virtual HRESULT __stdcall CreateReservedResource(const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, REFIID riid, void** ppvResource) override;

	virtual HRESULT __stdcall CreateSharedHandle(ID3D12DeviceChild* pObject, const SECURITY_ATTRIBUTES* pAttributes, DWORD Access, LPCWSTR Name, HANDLE* pHandle) override;

	virtual HRESULT __stdcall OpenSharedHandle(HANDLE NTHandle, REFIID riid, void** ppvObj) override;

	virtual HRESULT __stdcall OpenSharedHandleByName(LPCWSTR Name, DWORD Access, HANDLE* pNTHandle) override;

	virtual HRESULT __stdcall MakeResident(UINT NumObjects, ID3D12Pageable* const* ppObjects) override;

	virtual HRESULT __stdcall Evict(UINT NumObjects, ID3D12Pageable* const* ppObjects) override;

	virtual HRESULT __stdcall CreateFence(UINT64 InitialValue, D3D12_FENCE_FLAGS Flags, REFIID riid, void** ppFence) override;

	virtual HRESULT __stdcall GetDeviceRemovedReason(void) override;

	virtual void __stdcall GetCopyableFootprints(const D3D12_RESOURCE_DESC* pResourceDesc, UINT FirstSubresource, UINT NumSubresources, UINT64 BaseOffset, D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts, UINT* pNumRows, UINT64* pRowSizeInBytes, UINT64* pTotalBytes) override;

	virtual HRESULT __stdcall CreateQueryHeap(const D3D12_QUERY_HEAP_DESC* pDesc, REFIID riid, void** ppvHeap) override;

	virtual HRESULT __stdcall SetStablePowerState(BOOL Enable) override;

	virtual HRESULT __stdcall CreateCommandSignature(const D3D12_COMMAND_SIGNATURE_DESC* pDesc, ID3D12RootSignature* pRootSignature, REFIID riid, void** ppvCommandSignature) override;

	virtual void __stdcall GetResourceTiling(ID3D12Resource* pTiledResource, UINT* pNumTilesForEntireResource, D3D12_PACKED_MIP_INFO* pPackedMipDesc, D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips, UINT* pNumSubresourceTilings, UINT FirstSubresourceTilingToGet, D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips) override;

	virtual LUID __stdcall GetAdapterLuid(void) override;

	virtual HRESULT __stdcall CreatePipelineLibrary(const void* pLibraryBlob, SIZE_T BlobLength, REFIID riid, void** ppPipelineLibrary) override;

	virtual HRESULT __stdcall SetEventOnMultipleFenceCompletion(ID3D12Fence* const* ppFences, const UINT64 * pFenceValues, UINT NumFences, D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags, HANDLE hEvent) override;

	virtual HRESULT __stdcall SetResidencyPriority(UINT NumObjects, ID3D12Pageable* const* ppObjects, const D3D12_RESIDENCY_PRIORITY * pPriorities) override;

	virtual HRESULT __stdcall CreatePipelineState(const D3D12_PIPELINE_STATE_STREAM_DESC * pDesc, REFIID riid, void** ppPipelineState) override;

	virtual HRESULT __stdcall OpenExistingHeapFromAddress(const void* pAddress, REFIID riid, void** ppvHeap) override;

	virtual HRESULT __stdcall OpenExistingHeapFromFileMapping(HANDLE hFileMapping, REFIID riid, void** ppvHeap) override;

	virtual HRESULT __stdcall EnqueueMakeResident(D3D12_RESIDENCY_FLAGS Flags, UINT NumObjects, ID3D12Pageable* const* ppObjects, ID3D12Fence* pFenceToSignal, UINT64 FenceValueToSignal) override;

	virtual HRESULT __stdcall CreateCommandList1(UINT nodeMask, D3D12_COMMAND_LIST_TYPE type, D3D12_COMMAND_LIST_FLAGS flags, REFIID riid, void** ppCommandList) override;

	virtual HRESULT __stdcall CreateProtectedResourceSession(const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc, REFIID riid, void** ppSession) override;

	virtual HRESULT __stdcall CreateCommittedResource1(const D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialResourceState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, ID3D12ProtectedResourceSession* pProtectedSession, REFIID riidResource, void** ppvResource) override;

	virtual HRESULT __stdcall CreateHeap1(const D3D12_HEAP_DESC* pDesc, ID3D12ProtectedResourceSession* pProtectedSession, REFIID riid, void** ppvHeap) override;

	virtual HRESULT __stdcall CreateReservedResource1(const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, ID3D12ProtectedResourceSession* pProtectedSession, REFIID riid, void** ppvResource) override;

	virtual D3D12_RESOURCE_ALLOCATION_INFO __stdcall GetResourceAllocationInfo1(UINT visibleMask, UINT numResourceDescs, const D3D12_RESOURCE_DESC* pResourceDescs, D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1) override;

	virtual HRESULT __stdcall CreateLifetimeTracker(ID3D12LifetimeOwner* pOwner, REFIID riid, void** ppvTracker) override;

	virtual void __stdcall RemoveDevice(void) override;

	virtual HRESULT __stdcall EnumerateMetaCommands(UINT* pNumMetaCommands, D3D12_META_COMMAND_DESC* pDescs) override;

	virtual HRESULT __stdcall EnumerateMetaCommandParameters(REFGUID CommandId, D3D12_META_COMMAND_PARAMETER_STAGE Stage, UINT* pTotalStructureSizeInBytes, UINT* pParameterCount, D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs) override;

	virtual HRESULT __stdcall CreateMetaCommand(REFGUID CommandId, UINT NodeMask, const void* pCreationParametersData, SIZE_T CreationParametersDataSizeInBytes, REFIID riid, void** ppMetaCommand) override;

	virtual HRESULT __stdcall CreateStateObject(const D3D12_STATE_OBJECT_DESC* pDesc, REFIID riid, void** ppStateObject) override;

	virtual void __stdcall GetRaytracingAccelerationStructurePrebuildInfo(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc, D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo) override;

	virtual D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS __stdcall CheckDriverMatchingIdentifier(D3D12_SERIALIZED_DATA_TYPE SerializedDataType, const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck) override;

	virtual HRESULT __stdcall SetBackgroundProcessingMode(D3D12_BACKGROUND_PROCESSING_MODE Mode, D3D12_MEASUREMENTS_ACTION MeasurementsAction, HANDLE hEventToSignalUponCompletion, BOOL* pbFurtherMeasurementsDesired) override;

};