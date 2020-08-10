#pragma once
#include "openvr.h"

#include "VRClient/VRClient_002.h"
#include "VRClient/VRClient_003.h"

#include "VirtualCompositor.h"
#include "VirtualInput.h"
#include "VirtualResources.h"
#include "VirtualSystem.h"

#include "VRIpcConstants.h"

#include <Windows.h>

#include "Logger.h"

extern "C" __declspec(dllexport) void* VRClientCoreFactory(const char* pInterfaceName, int* pReturnCode);

class VRClient
{
public:
	static VRClient* cInstance;

	void* client;

	vr::EVRApplicationType applicationType;

	uint32_t pID;

	VirtualCompositor* vCompositor;
	VirtualInput* vInput;
	VirtualResources* vResources;
	VirtualSystem* vSystem;

	VRRuntime_t* pRuntime;
	uint32_t pRuntimeID;

	SharedState sState;

	VRClient()
	{
		cInstance = nullptr;
		client = nullptr;
		vCompositor = nullptr;
		vInput = nullptr;
		vResources = nullptr;
		vSystem = nullptr;
	}

	/** Initializes the system */
	vr::EVRInitError Init(vr::EVRApplicationType eApplicationType);

	/** Initializes the system */
	vr::EVRInitError Init(vr::EVRApplicationType eApplicationType, const char* pStartupInfo);

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
