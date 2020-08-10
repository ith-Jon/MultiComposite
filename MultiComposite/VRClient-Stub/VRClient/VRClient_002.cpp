#include "VRClient_002.h"
#include "VRClient.h"

/** Initializes the system */
vr::EVRInitError VRClient_002::Init(vr::EVRApplicationType eApplicationType)
{
	return VRClient::cInstance->Init(eApplicationType);
}

/** cleans up everything in vrclient.dll and prepares the DLL to be unloaded */
void VRClient_002::Cleanup()
{
	VRClient::cInstance->Cleanup();
}

/** checks to see if the specified interface/version is supported in this vrclient.dll */
vr::EVRInitError VRClient_002::IsInterfaceVersionValid(const char* pchInterfaceVersion)
{
	return VRClient::cInstance->IsInterfaceVersionValid(pchInterfaceVersion);
}

/** Retrieves any interface from vrclient.dll */
void* VRClient_002::GetGenericInterface(const char* pchNameAndVersion, vr::EVRInitError* peError)
{
	return VRClient::cInstance->GetGenericInterface(pchNameAndVersion, peError);
}

/** Returns true if any driver has an HMD attached. Can be called outside of Init/Cleanup */
bool VRClient_002::BIsHmdPresent()
{
	return VRClient::cInstance->BIsHmdPresent();
}

/** Returns an English error string from inside vrclient.dll which might be newer than the API DLL */
const char* VRClient_002::GetEnglishStringForHmdError(vr::EVRInitError eError)
{
	return VRClient::cInstance->GetEnglishStringForHmdError(eError);
}

/** Returns an error symbol from inside vrclient.dll which might be newer than the API DLL */
const char* VRClient_002::GetIDForVRInitError(vr::EVRInitError eError)
{
	return VRClient::cInstance->GetIDForVRInitError(eError);
}
