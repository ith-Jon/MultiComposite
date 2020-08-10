#include "VRClient_003.h"
#include "VRClient.h"

/** Initializes the system */
vr::EVRInitError VRClient_003::Init(vr::EVRApplicationType eApplicationType, const char* pStartupInfo)
{
	return VRClient::cInstance->Init(eApplicationType, pStartupInfo);
}

/** cleans up everything in vrclient.dll and prepares the DLL to be unloaded */
void VRClient_003::Cleanup()
{
	VRClient::cInstance->Cleanup();
}

/** checks to see if the specified interface/version is supported in this vrclient.dll */
vr::EVRInitError VRClient_003::IsInterfaceVersionValid(const char* pchInterfaceVersion)
{
	return VRClient::cInstance->IsInterfaceVersionValid(pchInterfaceVersion);
}

/** Retrieves any interface from vrclient.dll */
void* VRClient_003::GetGenericInterface(const char* pchNameAndVersion, vr::EVRInitError* peError)
{
	return VRClient::cInstance->GetGenericInterface(pchNameAndVersion, peError);
}

/** Returns true if any driver has an HMD attached. Can be called outside of Init/Cleanup */
bool VRClient_003::BIsHmdPresent()
{
	return VRClient::cInstance->BIsHmdPresent();
}

/** Returns an English error string from inside vrclient.dll which might be newer than the API DLL */
const char* VRClient_003::GetEnglishStringForHmdError(vr::EVRInitError eError)
{
	return VRClient::cInstance->GetEnglishStringForHmdError(eError);
}

/** Returns an error symbol from inside vrclient.dll which might be newer than the API DLL */
const char* VRClient_003::GetIDForVRInitError(vr::EVRInitError eError)
{
	return VRClient::cInstance->GetIDForVRInitError(eError);
}
