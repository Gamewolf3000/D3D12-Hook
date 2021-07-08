#pragma once

#include <d3d12.h>

class FakeD3D12Resource : public ID3D12Resource1
{
private:
	ID3D12Resource1* real;

public:
	FakeD3D12Resource(ID3D12Resource1* real);
	~FakeD3D12Resource() = default;

	ID3D12Resource1* GetReal();

	// Inherited via ID3D12Resource1
	virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override;

	virtual ULONG __stdcall AddRef(void) override;

	virtual ULONG __stdcall Release(void) override;

	virtual HRESULT __stdcall GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData) override;

	virtual HRESULT __stdcall SetPrivateData(REFGUID guid, UINT DataSize, const void* pData) override;

	virtual HRESULT __stdcall SetPrivateDataInterface(REFGUID guid, const IUnknown* pData) override;

	virtual HRESULT __stdcall SetName(LPCWSTR Name) override;

	virtual HRESULT __stdcall GetDevice(REFIID riid, void** ppvDevice) override;

	virtual HRESULT __stdcall Map(UINT Subresource, const D3D12_RANGE* pReadRange, void** ppData) override;

	virtual void __stdcall Unmap(UINT Subresource, const D3D12_RANGE* pWrittenRange) override;

	virtual D3D12_RESOURCE_DESC __stdcall GetDesc(void) override;

	virtual D3D12_GPU_VIRTUAL_ADDRESS __stdcall GetGPUVirtualAddress(void) override;

	virtual HRESULT __stdcall WriteToSubresource(UINT DstSubresource, const D3D12_BOX* pDstBox, const void* pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch) override;

	virtual HRESULT __stdcall ReadFromSubresource(void* pDstData, UINT DstRowPitch, UINT DstDepthPitch, UINT SrcSubresource, const D3D12_BOX* pSrcBox) override;

	virtual HRESULT __stdcall GetHeapProperties(D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS* pHeapFlags) override;

	virtual HRESULT __stdcall GetProtectedResourceSession(REFIID riid, void** ppProtectedSession) override;

};