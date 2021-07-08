#include "FakeD3D12Resource.h"

FakeD3D12Resource::FakeD3D12Resource(ID3D12Resource1* real) : real(real)
{

}

ID3D12Resource1* FakeD3D12Resource::GetReal()
{
	return real;
}

HRESULT __stdcall FakeD3D12Resource::QueryInterface(REFIID riid, void** ppvObject)
{
	return real->QueryInterface(riid, ppvObject);
}

ULONG __stdcall FakeD3D12Resource::AddRef(void)
{
	return real->AddRef();
}

ULONG __stdcall FakeD3D12Resource::Release(void)
{
	return real->Release();
}

HRESULT __stdcall FakeD3D12Resource::GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData)
{
	return real->GetPrivateData(guid, pDataSize, pData);
}

HRESULT __stdcall FakeD3D12Resource::SetPrivateData(REFGUID guid, UINT DataSize, const void* pData)
{
	return real->SetPrivateData(guid, DataSize, pData);
}

HRESULT __stdcall FakeD3D12Resource::SetPrivateDataInterface(REFGUID guid, const IUnknown* pData)
{
	return real->SetPrivateDataInterface(guid, pData);
}

HRESULT __stdcall FakeD3D12Resource::SetName(LPCWSTR Name)
{
	return real->SetName(Name);
}

HRESULT __stdcall FakeD3D12Resource::GetDevice(REFIID riid, void** ppvDevice)
{
	return real->GetDevice(riid, ppvDevice);
}

HRESULT __stdcall FakeD3D12Resource::Map(UINT Subresource, const D3D12_RANGE* pReadRange, void** ppData)
{
	return real->Map(Subresource, pReadRange, ppData);
}

void __stdcall FakeD3D12Resource::Unmap(UINT Subresource, const D3D12_RANGE* pWrittenRange)
{
	real->Unmap(Subresource, pWrittenRange);
}

D3D12_RESOURCE_DESC __stdcall FakeD3D12Resource::GetDesc(void)
{
	return real->GetDesc();
}

D3D12_GPU_VIRTUAL_ADDRESS __stdcall FakeD3D12Resource::GetGPUVirtualAddress(void)
{
	return real->GetGPUVirtualAddress();
}

HRESULT __stdcall FakeD3D12Resource::WriteToSubresource(UINT DstSubresource, const D3D12_BOX* pDstBox, const void* pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch)
{
	return real->WriteToSubresource(DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
}

HRESULT __stdcall FakeD3D12Resource::ReadFromSubresource(void* pDstData, UINT DstRowPitch, UINT DstDepthPitch, UINT SrcSubresource, const D3D12_BOX* pSrcBox)
{
	return real->ReadFromSubresource(pDstData, DstRowPitch, DstDepthPitch, SrcSubresource, pSrcBox);
}

HRESULT __stdcall FakeD3D12Resource::GetHeapProperties(D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS* pHeapFlags)
{
	return real->GetHeapProperties(pHeapProperties, pHeapFlags);
}

HRESULT __stdcall FakeD3D12Resource::GetProtectedResourceSession(REFIID riid, void** ppProtectedSession)
{
	return real->GetProtectedResourceSession(riid, ppProtectedSession);
}
