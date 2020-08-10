#include "Compositor.h"
#include <cassert>

#include "Logger.h"
#include <string>

ICompositor* ICompositor::pD11Compositor;

D3D_FEATURE_LEVEL featureLevel;
UINT flags = D3D11_CREATE_DEVICE_SINGLETHREADED;

void D3D11Compositor::Init()
{
    HRESULT hr = D3D11CreateDevice(
        NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        D3D11_CREATE_DEVICE_DEBUG,
        NULL,
        0,
        D3D11_SDK_VERSION,
        &pDevice,
        &featureLevel,
        &pContext);

    assert(S_OK == hr && pDevice && pContext);
}

void D3D11Compositor::SetupTexture(vr::Texture_t* texture, HANDLE handle)
{
    if (handle == nullptr)
        return;

    pDevice->OpenSharedResource(handle, __uuidof(ID3D11Texture2D), (void**)&texture->handle);
}

void D3D11Compositor::ReleaseTexture(vr::Texture_t* texture)
{
    ((ID3D11Texture2D*)texture->handle)->Release();
    texture->handle = nullptr;
}
