#include "VirtualResources.h"
#include "VirtualResources/VirtualResources_001.h"

uint32_t VirtualResources::LoadSharedResource(const char* pchResourceName, char* pchBuffer, uint32_t unBufferLen)
{
	// TODO: Reimplement to use actual steamvr installation path instead of the installation path of multicomposite
	return static_cast<IVRResources_001*>(virtualResources)->LoadSharedResource(pchResourceName, pchBuffer, unBufferLen);
}

uint32_t VirtualResources::GetResourceFullPath(const char* pchResourceName, const char* pchResourceTypeDirectory, VR_OUT_STRING() char* pchPathBuffer, uint32_t unBufferLen)
{
	// TODO: Reimplement to use actual steamvr installation path instead of the installation path of multicomposite
	return static_cast<IVRResources_001*>(virtualResources)->GetResourceFullPath(pchResourceName, pchResourceTypeDirectory, pchPathBuffer, unBufferLen);
}
