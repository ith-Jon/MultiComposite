#include "VirtualResources_001.h"
#include "VRClient.h"

uint32_t VirtualResources_001::LoadSharedResource(const char* pchResourceName, char* pchBuffer, uint32_t unBufferLen)
{
	// Still doesn't work :/
	return 0;
	//return VRClient::cInstance->vResources->LoadSharedResource(pchResourceName, pchBuffer, unBufferLen);
}

uint32_t VirtualResources_001::GetResourceFullPath(const char* pchResourceName, const char* pchResourceTypeDirectory, VR_OUT_STRING() char* pchPathBuffer, uint32_t unBufferLen)
{
	// Still doesn't work :/
	return 0;
	//return VRClient::cInstance->vResources->GetResourceFullPath(pchResourceName, pchResourceTypeDirectory, pchPathBuffer, unBufferLen);
}

/**              Fn Table                   */

uint32_t __stdcall fntable_Resources_001_impl_LoadSharedResource(const char* pchResourceName, char* pchBuffer, uint32_t unBufferLen)
{
	return static_cast<IVRResources_001*>(VRClient::cInstance->vResources->virtualResources)->LoadSharedResource(pchResourceName, pchBuffer, unBufferLen);
}

uint32_t __stdcall fntable_Resources_001_impl_GetResourceFullPath(const char* pchResourceName, const char* pchResourceTypeDirectory, VR_OUT_STRING() char* pchPathBuffer, uint32_t unBufferLen)
{
	return static_cast<IVRResources_001*>(VRClient::cInstance->vResources->virtualResources)->GetResourceFullPath(pchResourceName, pchResourceTypeDirectory, pchPathBuffer, unBufferLen);
}

void* fnTable_VirtualResources_001[] = {
	fntable_Resources_001_impl_LoadSharedResource,
	fntable_Resources_001_impl_GetResourceFullPath,
};

void* VirtualResources_001::GetFnTable()
{
	return fnTable_VirtualResources_001;
}
