#include "FakeD3D12Device.h"

//#include "FakeD3D12CommandQueue.h"

FakeD3D12Device::FakeD3D12Device(ID3D12Device6* real) : real(real)
{
	// EMPTY
}

HRESULT __stdcall FakeD3D12Device::QueryInterface(REFIID riid, void** ppvObject)
{
	return real->QueryInterface(riid, ppvObject);
}

ULONG __stdcall FakeD3D12Device::AddRef(void)
{
	return real->AddRef();
}

ULONG __stdcall FakeD3D12Device::Release(void)
{
	return real->Release();
}

HRESULT __stdcall FakeD3D12Device::GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData)
{
	return real->GetPrivateData(guid, pDataSize, pData);
}

HRESULT __stdcall FakeD3D12Device::SetPrivateData(REFGUID guid, UINT DataSize, const void* pData)
{
	return real->SetPrivateData(guid, DataSize, pData);
}

HRESULT __stdcall FakeD3D12Device::SetPrivateDataInterface(REFGUID guid, const IUnknown* pData)
{
	return real->SetPrivateDataInterface(guid, pData);
}

HRESULT __stdcall FakeD3D12Device::SetName(LPCWSTR Name)
{
	return real->SetName(Name);
}

UINT __stdcall FakeD3D12Device::GetNodeCount(void)
{
	return real->GetNodeCount();
}

HRESULT __stdcall FakeD3D12Device::CreateCommandQueue(const D3D12_COMMAND_QUEUE_DESC* pDesc, REFIID riid, void** ppCommandQueue)
{
	auto toReturn = real->CreateCommandQueue(pDesc, riid, ppCommandQueue);
	//if (ppCommandQueue != nullptr)
	//{
	//	FakeD3D12CommandQueue* fake = new FakeD3D12CommandQueue(static_cast<ID3D12CommandQueue*>(*ppCommandQueue));
	//	*ppCommandQueue = fake;
	//}
	return toReturn;
}

HRESULT __stdcall FakeD3D12Device::CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE type, REFIID riid, void** ppCommandAllocator)
{
	return real->CreateCommandAllocator(type, riid, ppCommandAllocator);
}

HRESULT __stdcall FakeD3D12Device::CreateGraphicsPipelineState(const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc, REFIID riid, void** ppPipelineState)
{
	return real->CreateGraphicsPipelineState(pDesc, riid, ppPipelineState);
}

HRESULT __stdcall FakeD3D12Device::CreateComputePipelineState(const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc, REFIID riid, void** ppPipelineState)
{
	return real->CreateComputePipelineState(pDesc, riid, ppPipelineState);
}

HRESULT __stdcall FakeD3D12Device::CreateCommandList(UINT nodeMask, D3D12_COMMAND_LIST_TYPE type, ID3D12CommandAllocator* pCommandAllocator, ID3D12PipelineState* pInitialState, REFIID riid, void** ppCommandList)
{
	return real->CreateCommandList(nodeMask, type, pCommandAllocator, pInitialState, riid, ppCommandList);
}

HRESULT __stdcall FakeD3D12Device::CheckFeatureSupport(D3D12_FEATURE Feature, void* pFeatureSupportData, UINT FeatureSupportDataSize)
{
	return real->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize);
}

HRESULT __stdcall FakeD3D12Device::CreateDescriptorHeap(const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc, REFIID riid, void** ppvHeap)
{
	return real->CreateDescriptorHeap(pDescriptorHeapDesc, riid, ppvHeap);
}

UINT __stdcall FakeD3D12Device::GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
	return real->GetDescriptorHandleIncrementSize(DescriptorHeapType);
}

HRESULT __stdcall FakeD3D12Device::CreateRootSignature(UINT nodeMask, const void* pBlobWithRootSignature, SIZE_T blobLengthInBytes, REFIID riid, void** ppvRootSignature)
{
	return real->CreateRootSignature(nodeMask, pBlobWithRootSignature, blobLengthInBytes, riid, ppvRootSignature);
}

void __stdcall FakeD3D12Device::CreateConstantBufferView(const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
	real->CreateConstantBufferView(pDesc, DestDescriptor);
}

void __stdcall FakeD3D12Device::CreateShaderResourceView(ID3D12Resource* pResource, const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
	real->CreateShaderResourceView(pResource, pDesc, DestDescriptor);
}


void __stdcall FakeD3D12Device::CreateUnorderedAccessView(ID3D12Resource* pResource, ID3D12Resource* pCounterResource, const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
	real->CreateUnorderedAccessView(pResource, pCounterResource, pDesc, DestDescriptor);
}

void __stdcall FakeD3D12Device::CreateRenderTargetView(ID3D12Resource* pResource, const D3D12_RENDER_TARGET_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
	real->CreateRenderTargetView(pResource, pDesc, DestDescriptor);
}

void __stdcall FakeD3D12Device::CreateDepthStencilView(ID3D12Resource* pResource, const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
	real->CreateDepthStencilView(pResource, pDesc, DestDescriptor);
}

void __stdcall FakeD3D12Device::CreateSampler(const D3D12_SAMPLER_DESC* pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
	real->CreateSampler(pDesc, DestDescriptor);
}

void __stdcall FakeD3D12Device::CopyDescriptors(UINT NumDestDescriptorRanges, const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts, const UINT* pDestDescriptorRangeSizes, UINT NumSrcDescriptorRanges, const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts, const UINT* pSrcDescriptorRangeSizes, D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
	real->CopyDescriptors(NumDestDescriptorRanges, pDestDescriptorRangeStarts, pDestDescriptorRangeSizes, NumSrcDescriptorRanges, pSrcDescriptorRangeStarts, pSrcDescriptorRangeSizes, DescriptorHeapsType);
}

void __stdcall FakeD3D12Device::CopyDescriptorsSimple(UINT NumDescriptors, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart, D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart, D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
	real->CopyDescriptorsSimple(NumDescriptors, DestDescriptorRangeStart, SrcDescriptorRangeStart, DescriptorHeapsType);
}

D3D12_RESOURCE_ALLOCATION_INFO __stdcall FakeD3D12Device::GetResourceAllocationInfo(UINT visibleMask, UINT numResourceDescs, const D3D12_RESOURCE_DESC* pResourceDescs)
{
	return real->GetResourceAllocationInfo(visibleMask, numResourceDescs, pResourceDescs);
}

D3D12_HEAP_PROPERTIES __stdcall FakeD3D12Device::GetCustomHeapProperties(UINT nodeMask, D3D12_HEAP_TYPE heapType)
{
	return real->GetCustomHeapProperties(nodeMask, heapType);
}

HRESULT __stdcall FakeD3D12Device::CreateCommittedResource(const D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialResourceState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, REFIID riidResource, void** ppvResource)
{
	return real->CreateCommittedResource(pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, riidResource, ppvResource);
}

HRESULT __stdcall FakeD3D12Device::CreateHeap(const D3D12_HEAP_DESC* pDesc, REFIID riid, void** ppvHeap)
{
	return real->CreateHeap(pDesc, riid, ppvHeap);
}

HRESULT __stdcall FakeD3D12Device::CreatePlacedResource(ID3D12Heap* pHeap, UINT64 HeapOffset, const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, REFIID riid, void** ppvResource)
{
	return real->CreatePlacedResource(pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource);
}

HRESULT __stdcall FakeD3D12Device::CreateReservedResource(const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, REFIID riid, void** ppvResource)
{
	return real->CreateReservedResource(pDesc, InitialState, pOptimizedClearValue, riid, ppvResource);
}

HRESULT __stdcall FakeD3D12Device::CreateSharedHandle(ID3D12DeviceChild* pObject, const SECURITY_ATTRIBUTES* pAttributes, DWORD Access, LPCWSTR Name, HANDLE* pHandle)
{
	return real->CreateSharedHandle(pObject, pAttributes, Access, Name, pHandle);
}

HRESULT __stdcall FakeD3D12Device::OpenSharedHandle(HANDLE NTHandle, REFIID riid, void** ppvObj)
{
	return real->OpenSharedHandle(NTHandle, riid, ppvObj);
}

HRESULT __stdcall FakeD3D12Device::OpenSharedHandleByName(LPCWSTR Name, DWORD Access, HANDLE* pNTHandle)
{
	return real->OpenSharedHandleByName(Name, Access, pNTHandle);
}

HRESULT __stdcall FakeD3D12Device::MakeResident(UINT NumObjects, ID3D12Pageable* const* ppObjects)
{
	return real->MakeResident(NumObjects, ppObjects);
}

HRESULT __stdcall FakeD3D12Device::Evict(UINT NumObjects, ID3D12Pageable* const* ppObjects)
{
	return real->Evict(NumObjects, ppObjects);
}

HRESULT __stdcall FakeD3D12Device::CreateFence(UINT64 InitialValue, D3D12_FENCE_FLAGS Flags, REFIID riid, void** ppFence)
{
	return real->CreateFence(InitialValue, Flags, riid, ppFence);
}

HRESULT __stdcall FakeD3D12Device::GetDeviceRemovedReason(void)
{
	return real->GetDeviceRemovedReason();
}

void __stdcall FakeD3D12Device::GetCopyableFootprints(const D3D12_RESOURCE_DESC* pResourceDesc, UINT FirstSubresource, UINT NumSubresources, UINT64 BaseOffset, D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts, UINT* pNumRows, UINT64* pRowSizeInBytes, UINT64* pTotalBytes)
{
	real->GetCopyableFootprints(pResourceDesc, FirstSubresource, NumSubresources, BaseOffset, pLayouts, pNumRows, pRowSizeInBytes, pTotalBytes);
}

HRESULT __stdcall FakeD3D12Device::CreateQueryHeap(const D3D12_QUERY_HEAP_DESC* pDesc, REFIID riid, void** ppvHeap)
{
	return real->CreateQueryHeap(pDesc, riid, ppvHeap);
}

HRESULT __stdcall FakeD3D12Device::SetStablePowerState(BOOL Enable)
{
	return real->SetStablePowerState(Enable);
}

HRESULT __stdcall FakeD3D12Device::CreateCommandSignature(const D3D12_COMMAND_SIGNATURE_DESC* pDesc, ID3D12RootSignature* pRootSignature, REFIID riid, void** ppvCommandSignature)
{
	return real->CreateCommandSignature(pDesc, pRootSignature, riid, ppvCommandSignature);
}

void __stdcall FakeD3D12Device::GetResourceTiling(ID3D12Resource* pTiledResource, UINT* pNumTilesForEntireResource, D3D12_PACKED_MIP_INFO* pPackedMipDesc, D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips, UINT* pNumSubresourceTilings, UINT FirstSubresourceTilingToGet, D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips)
{
	real->GetResourceTiling(pTiledResource, pNumTilesForEntireResource, pPackedMipDesc, pStandardTileShapeForNonPackedMips, pNumSubresourceTilings, FirstSubresourceTilingToGet, pSubresourceTilingsForNonPackedMips);
}

LUID __stdcall FakeD3D12Device::GetAdapterLuid(void)
{
	return real->GetAdapterLuid();
}

HRESULT __stdcall FakeD3D12Device::CreatePipelineLibrary(const void* pLibraryBlob, SIZE_T BlobLength, REFIID riid, void** ppPipelineLibrary)
{
	return real->CreatePipelineLibrary(pLibraryBlob, BlobLength, riid, ppPipelineLibrary);
}

HRESULT __stdcall FakeD3D12Device::SetEventOnMultipleFenceCompletion(ID3D12Fence* const* ppFences, const UINT64* pFenceValues, UINT NumFences, D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags, HANDLE hEvent)
{
	return real->SetEventOnMultipleFenceCompletion(ppFences, pFenceValues, NumFences, Flags, hEvent);
}

HRESULT __stdcall FakeD3D12Device::SetResidencyPriority(UINT NumObjects, ID3D12Pageable* const* ppObjects, const D3D12_RESIDENCY_PRIORITY* pPriorities)
{
	return real->SetResidencyPriority(NumObjects, ppObjects, pPriorities);
}

HRESULT __stdcall FakeD3D12Device::CreatePipelineState(const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc, REFIID riid, void** ppPipelineState)
{
	return real->CreatePipelineState(pDesc, riid, ppPipelineState);
}

HRESULT __stdcall FakeD3D12Device::OpenExistingHeapFromAddress(const void* pAddress, REFIID riid, void** ppvHeap)
{
	return real->OpenExistingHeapFromAddress(pAddress, riid, ppvHeap);
}

HRESULT __stdcall FakeD3D12Device::OpenExistingHeapFromFileMapping(HANDLE hFileMapping, REFIID riid, void** ppvHeap)
{
	return real->OpenExistingHeapFromFileMapping(hFileMapping, riid, ppvHeap);
}

HRESULT __stdcall FakeD3D12Device::EnqueueMakeResident(D3D12_RESIDENCY_FLAGS Flags, UINT NumObjects, ID3D12Pageable* const* ppObjects, ID3D12Fence* pFenceToSignal, UINT64 FenceValueToSignal)
{
	return real->EnqueueMakeResident(Flags, NumObjects, ppObjects, pFenceToSignal, FenceValueToSignal);
}

HRESULT __stdcall FakeD3D12Device::CreateCommandList1(UINT nodeMask, D3D12_COMMAND_LIST_TYPE type, D3D12_COMMAND_LIST_FLAGS flags, REFIID riid, void** ppCommandList)
{
	return real->CreateCommandList1(nodeMask, type, flags, riid, ppCommandList);
}

HRESULT __stdcall FakeD3D12Device::CreateProtectedResourceSession(const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc, REFIID riid, void** ppSession)
{
	return real->CreateProtectedResourceSession(pDesc, riid, ppSession);
}

HRESULT __stdcall FakeD3D12Device::CreateCommittedResource1(const D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialResourceState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, ID3D12ProtectedResourceSession* pProtectedSession, REFIID riidResource, void** ppvResource)
{
	return real->CreateCommittedResource1(pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, pProtectedSession, riidResource, ppvResource);
}

HRESULT __stdcall FakeD3D12Device::CreateHeap1(const D3D12_HEAP_DESC* pDesc, ID3D12ProtectedResourceSession* pProtectedSession, REFIID riid, void** ppvHeap)
{
	return real->CreateHeap1(pDesc, pProtectedSession, riid, ppvHeap);
}

HRESULT __stdcall FakeD3D12Device::CreateReservedResource1(const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, ID3D12ProtectedResourceSession* pProtectedSession, REFIID riid, void** ppvResource)
{
	return real->CreateReservedResource1(pDesc, InitialState, pOptimizedClearValue, pProtectedSession, riid, ppvResource);
}

D3D12_RESOURCE_ALLOCATION_INFO __stdcall FakeD3D12Device::GetResourceAllocationInfo1(UINT visibleMask, UINT numResourceDescs, const D3D12_RESOURCE_DESC* pResourceDescs, D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
	return real->GetResourceAllocationInfo1(visibleMask, numResourceDescs, pResourceDescs, pResourceAllocationInfo1);
}

HRESULT __stdcall FakeD3D12Device::CreateLifetimeTracker(ID3D12LifetimeOwner* pOwner, REFIID riid, void** ppvTracker)
{
	return real->CreateLifetimeTracker(pOwner, riid, ppvTracker);
}

void __stdcall FakeD3D12Device::RemoveDevice(void)
{
	real->RemoveDevice();
}

HRESULT __stdcall FakeD3D12Device::EnumerateMetaCommands(UINT* pNumMetaCommands, D3D12_META_COMMAND_DESC* pDescs)
{
	return real->EnumerateMetaCommands(pNumMetaCommands, pDescs);
}

HRESULT __stdcall FakeD3D12Device::EnumerateMetaCommandParameters(REFGUID CommandId, D3D12_META_COMMAND_PARAMETER_STAGE Stage, UINT* pTotalStructureSizeInBytes, UINT* pParameterCount, D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs)
{
	return real->EnumerateMetaCommandParameters(CommandId, Stage, pTotalStructureSizeInBytes, pParameterCount, pParameterDescs);
}

HRESULT __stdcall FakeD3D12Device::CreateMetaCommand(REFGUID CommandId, UINT NodeMask, const void* pCreationParametersData, SIZE_T CreationParametersDataSizeInBytes, REFIID riid, void** ppMetaCommand)
{
	return real->CreateMetaCommand(CommandId, NodeMask, pCreationParametersData, CreationParametersDataSizeInBytes, riid, ppMetaCommand);
}

HRESULT __stdcall FakeD3D12Device::CreateStateObject(const D3D12_STATE_OBJECT_DESC* pDesc, REFIID riid, void** ppStateObject)
{
	return real->CreateStateObject(pDesc, riid, ppStateObject);
}

void __stdcall FakeD3D12Device::GetRaytracingAccelerationStructurePrebuildInfo(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc, D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo)
{
	real->GetRaytracingAccelerationStructurePrebuildInfo(pDesc, pInfo);
}

D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS __stdcall FakeD3D12Device::CheckDriverMatchingIdentifier(D3D12_SERIALIZED_DATA_TYPE SerializedDataType, const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck)
{
	return real->CheckDriverMatchingIdentifier(SerializedDataType, pIdentifierToCheck);
}

HRESULT __stdcall FakeD3D12Device::SetBackgroundProcessingMode(D3D12_BACKGROUND_PROCESSING_MODE Mode, D3D12_MEASUREMENTS_ACTION MeasurementsAction, HANDLE hEventToSignalUponCompletion, BOOL* pbFurtherMeasurementsDesired)
{
	return real->SetBackgroundProcessingMode(Mode, MeasurementsAction, hEventToSignalUponCompletion, pbFurtherMeasurementsDesired);
}
