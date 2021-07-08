#include "FakeDXGIFactory.h"

FakeDXGIFactory::FakeDXGIFactory(IDXGIFactory7* real) : real(real)
{
	// EMPTY
}

HRESULT __stdcall FakeDXGIFactory::QueryInterface(REFIID riid, void** ppvObject)
{
	return real->QueryInterface(riid, ppvObject);
}

ULONG __stdcall FakeDXGIFactory::AddRef(void)
{
	return real->AddRef();
}

ULONG __stdcall FakeDXGIFactory::Release(void)
{
	return real->Release();
}

HRESULT __stdcall FakeDXGIFactory::SetPrivateData(REFGUID Name, UINT DataSize, const void* pData)
{
	return real->SetPrivateData(Name, DataSize, pData);
}

HRESULT __stdcall FakeDXGIFactory::SetPrivateDataInterface(REFGUID Name, const IUnknown* pUnknown)
{
	return real->SetPrivateDataInterface(Name, pUnknown);
}

HRESULT __stdcall FakeDXGIFactory::GetPrivateData(REFGUID Name, UINT* pDataSize, void* pData)
{
	return real->GetPrivateData(Name, pDataSize, pData);
}

HRESULT __stdcall FakeDXGIFactory::GetParent(REFIID riid, void** ppParent)
{
	return real->GetParent(riid, ppParent);
}

HRESULT __stdcall FakeDXGIFactory::EnumAdapters(UINT Adapter, IDXGIAdapter** ppAdapter)
{
	return real->EnumAdapters(Adapter, ppAdapter);
}

HRESULT __stdcall FakeDXGIFactory::MakeWindowAssociation(HWND WindowHandle, UINT Flags)
{
	return real->MakeWindowAssociation(WindowHandle, Flags);
}

HRESULT __stdcall FakeDXGIFactory::GetWindowAssociation(HWND* pWindowHandle)
{
	return real->GetWindowAssociation(pWindowHandle);
}

HRESULT __stdcall FakeDXGIFactory::CreateSwapChain(IUnknown* pDevice, DXGI_SWAP_CHAIN_DESC* pDesc, IDXGISwapChain** ppSwapChain)
{
	return real->CreateSwapChain(pDevice, pDesc, ppSwapChain);
}

HRESULT __stdcall FakeDXGIFactory::CreateSoftwareAdapter(HMODULE Module, IDXGIAdapter** ppAdapter)
{
	return real->CreateSoftwareAdapter(Module, ppAdapter);
}

HRESULT __stdcall FakeDXGIFactory::EnumAdapters1(UINT Adapter, IDXGIAdapter1** ppAdapter)
{
	return real->EnumAdapters1(Adapter, ppAdapter);
}

BOOL __stdcall FakeDXGIFactory::IsCurrent(void)
{
	return real->IsCurrent();
}

BOOL __stdcall FakeDXGIFactory::IsWindowedStereoEnabled(void)
{
	return real->IsWindowedStereoEnabled();
}

HRESULT __stdcall FakeDXGIFactory::CreateSwapChainForHwnd(IUnknown* pDevice, HWND hWnd, const DXGI_SWAP_CHAIN_DESC1* pDesc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc, IDXGIOutput* pRestrictToOutput, IDXGISwapChain1** ppSwapChain)
{
	return real->CreateSwapChainForHwnd(pDevice, hWnd, pDesc, pFullscreenDesc, pRestrictToOutput, ppSwapChain);
}

HRESULT __stdcall FakeDXGIFactory::CreateSwapChainForCoreWindow(IUnknown* pDevice, IUnknown* pWindow, const DXGI_SWAP_CHAIN_DESC1* pDesc, IDXGIOutput* pRestrictToOutput, IDXGISwapChain1** ppSwapChain)
{
	return real->CreateSwapChainForCoreWindow(pDevice, pWindow, pDesc, pRestrictToOutput, ppSwapChain);
}

HRESULT __stdcall FakeDXGIFactory::GetSharedResourceAdapterLuid(HANDLE hResource, LUID* pLuid)
{
	return real->GetSharedResourceAdapterLuid(hResource, pLuid);
}

HRESULT __stdcall FakeDXGIFactory::RegisterStereoStatusWindow(HWND WindowHandle, UINT wMsg, DWORD* pdwCookie)
{
	return real->RegisterStereoStatusWindow(WindowHandle, wMsg, pdwCookie);
}

HRESULT __stdcall FakeDXGIFactory::RegisterStereoStatusEvent(HANDLE hEvent, DWORD* pdwCookie)
{
	return real->RegisterStereoStatusEvent(hEvent, pdwCookie);
}

void __stdcall FakeDXGIFactory::UnregisterStereoStatus(DWORD dwCookie)
{
	real->UnregisterStereoStatus(dwCookie);
}

HRESULT __stdcall FakeDXGIFactory::RegisterOcclusionStatusWindow(HWND WindowHandle, UINT wMsg, DWORD* pdwCookie)
{
	return real->RegisterOcclusionStatusWindow(WindowHandle, wMsg, pdwCookie);
}

HRESULT __stdcall FakeDXGIFactory::RegisterOcclusionStatusEvent(HANDLE hEvent, DWORD* pdwCookie)
{
	return real->RegisterOcclusionStatusEvent(hEvent, pdwCookie);
}

void __stdcall FakeDXGIFactory::UnregisterOcclusionStatus(DWORD dwCookie)
{
	real->UnregisterOcclusionStatus(dwCookie);
}

HRESULT __stdcall FakeDXGIFactory::CreateSwapChainForComposition(IUnknown* pDevice, const DXGI_SWAP_CHAIN_DESC1* pDesc, IDXGIOutput* pRestrictToOutput, IDXGISwapChain1** ppSwapChain)
{
	return real->CreateSwapChainForComposition(pDevice, pDesc, pRestrictToOutput, ppSwapChain);
}

UINT __stdcall FakeDXGIFactory::GetCreationFlags(void)
{
	return real->GetCreationFlags();
}

HRESULT __stdcall FakeDXGIFactory::EnumAdapterByLuid(LUID AdapterLuid, REFIID riid, void** ppvAdapter)
{
	return real->EnumAdapterByLuid(AdapterLuid, riid, ppvAdapter);
}

HRESULT __stdcall FakeDXGIFactory::EnumWarpAdapter(REFIID riid, void** ppvAdapter)
{
	return real->EnumWarpAdapter(riid, ppvAdapter);
}

HRESULT __stdcall FakeDXGIFactory::CheckFeatureSupport(DXGI_FEATURE Feature, void* pFeatureSupportData, UINT FeatureSupportDataSize)
{
	return real->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize);
}

HRESULT __stdcall FakeDXGIFactory::EnumAdapterByGpuPreference(UINT Adapter, DXGI_GPU_PREFERENCE GpuPreference, REFIID riid, void** ppvAdapter)
{
	return real->EnumAdapterByGpuPreference(Adapter, GpuPreference, riid, ppvAdapter);
}

HRESULT __stdcall FakeDXGIFactory::RegisterAdaptersChangedEvent(HANDLE hEvent, DWORD* pdwCookie)
{
	return real->RegisterAdaptersChangedEvent(hEvent, pdwCookie);
}

HRESULT __stdcall FakeDXGIFactory::UnregisterAdaptersChangedEvent(DWORD dwCookie)
{
	return real->UnregisterAdaptersChangedEvent(dwCookie);
}