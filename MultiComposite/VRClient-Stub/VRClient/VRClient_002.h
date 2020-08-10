#pragma once
#include "openvr.h"
#include "VRClient.h"

class IVRClientCore_002
{
public:
	/** Initializes the system */
	virtual vr::EVRInitError Init(vr::EVRApplicationType eApplicationType) = 0;

	/** cleans up everything in vrclient.dll and prepares the DLL to be unloaded */
	virtual void Cleanup() = 0;

	/** checks to see if the specified interface/version is supported in this vrclient.dll */
	virtual vr::EVRInitError IsInterfaceVersionValid(const char* pchInterfaceVersion) = 0;

	/** Retrieves any interface from vrclient.dll */
	virtual void* GetGenericInterface(const char* pchNameAndVersion, vr::EVRInitError* peError) = 0;

	/** Returns true if any driver has an HMD attached. Can be called outside of Init/Cleanup */
	virtual bool BIsHmdPresent() = 0;

	/** Returns an English error string from inside vrclient.dll which might be newer than the API DLL */
	virtual const char* GetEnglishStringForHmdError(vr::EVRInitError eError) = 0;

	/** Returns an error symbol from inside vrclient.dll which might be newer than the API DLL */
	virtual const char* GetIDForVRInitError(vr::EVRInitError eError) = 0;
};

class VRClient_002 : public IVRClientCore_002
{
public:
	/** Initializes the system */
	vr::EVRInitError Init(vr::EVRApplicationType eApplicationType);

	/** cleans up everything in vrclient.dll and prepares the DLL to be unloaded */
	void Cleanup();

	/** checks to see if the specified interface/version is supported in this vrclient.dll */
	vr::EVRInitError IsInterfaceVersionValid(const char* pchInterfaceVersion);

	/** Retrieves any interface from vrclient.dll */
	void* GetGenericInterface(const char* pchNameAndVersion, vr::EVRInitError* peError);

	/** Returns true if any driver has an HMD attached. Can be called outside of Init/Cleanup */
	bool BIsHmdPresent();

	/** Returns an English error string from inside vrclient.dll which might be newer than the API DLL */
	const char* GetEnglishStringForHmdError(vr::EVRInitError eError);

	/** Returns an error symbol from inside vrclient.dll which might be newer than the API DLL */
	const char* GetIDForVRInitError(vr::EVRInitError eError);
};
