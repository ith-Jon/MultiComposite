#include "VRClient.h"

typedef void* (*VRClientCoreFactoryFn)(const char* pInterfaceName, int* pReturnCode);

extern "C" __declspec(dllexport) void* VRClientCoreFactory(const char* pInterfaceName, int* pReturnCode)
{
	dlog::Println("[VRClientCoreFactory] Called.");

	dlog::Println("Got interface [" + std::string(pInterfaceName) + "].");

	VRClientCoreFactoryFn factoryFn = (VRClientCoreFactoryFn)GetProcAddress(LoadLibraryEx(TEXT("C:\\Program Files (x86)\\Steam\\steamapps\\common\\SteamVR\\bin\\vrclient_x64.dll"), NULL, LOAD_WITH_ALTERED_SEARCH_PATH), "VRClientCoreFactory");
	
	void* cRet = nullptr;
	VRClient::cInstance = new VRClient();

	VRClient::cInstance->client = factoryFn(pInterfaceName, pReturnCode);

	if (pInterfaceName == std::string("IVRClientCore_002"))
	{
		dlog::Println("Setting client to IVRClientCore_002");

		cRet = new VRClient_002();
	}
	else if (pInterfaceName == std::string("IVRClientCore_003"))
	{
		dlog::Println("Setting client to IVRClientCore_003");

		cRet = new VRClient_003();
	}
	else
	{
		dlog::Println("Unable to find correct IVRClientCore!");

		*pReturnCode = vr::VRInitError_Init_FactoryNotFound;
		return nullptr;
	}

	dlog::Println("Factory Init Complete!");
	return cRet;
}

VRClient* VRClient::cInstance;

vr::EVRInitError VRClient::Init(vr::EVRApplicationType eApplicationType)
{
	dlog::Println("[VRClient::Init] Called.");

	// VRClient_002 not supported currently.

	return static_cast<VRClient_002*>(client)->Init(eApplicationType);
}

vr::EVRInitError VRClient::Init(vr::EVRApplicationType eApplicationType, const char* pStartupInfo)
{
	dlog::Println("[VRClient::Init] Called.");

	if (eApplicationType == VRApplication_Scene)
	{
		dlog::Println("Setting up \"Scene\" (It's really an overlay, but shhhhh)...");

		sState.Init(ISharedMem::Client);

		EVRInitError err = static_cast<VRClient_003*>(client)->Init(VRApplication_Overlay, pStartupInfo);
		applicationType = VRApplication_Scene;

		VRRuntime_t* runtimes = sState.GetWritableSharedState()->runtimes;
		for (int i = 0; i < MAX_RUNTIME_COUNT; i++)
		{
			VRRuntime_t* r = &runtimes[i];

			if (!r->sceneInitialized && !r->sceneShutdown)
			{
				pRuntime = r;
				pRuntimeID = i;
			}
		}

		pRuntime->sceneInitialized = true;
		while (!pRuntime->sceneRegistered);

		dlog::Println("Got runtime [" + std::to_string(pRuntime->id) + "].");

		return err;
	}

	if (eApplicationType == VRApplication_SceneManager)
	{
		dlog::Println("Setting up Scene Manager...");

		EVRInitError err = static_cast<VRClient_003*>(client)->Init(VRApplication_Scene, pStartupInfo);
		applicationType = VRApplication_SceneManager;

		return err;
	}

	dlog::Println("Not a Scene.");
	applicationType = eApplicationType;
	return static_cast<VRClient_003*>(client)->Init(eApplicationType, pStartupInfo);
}

void VRClient::Cleanup()
{
	dlog::Println("[VRClient::Cleanup] Called.");
	pRuntime->sceneInitialized = false;
	pRuntime->sceneShutdown = true;
	static_cast<VRClient_003*>(client)->Cleanup();
}

vr::EVRInitError VRClient::IsInterfaceVersionValid(const char* pchInterfaceVersion)
{
	//dlog::Println("[VRClient::IsInterfaceVersionValid] Called.");
	return static_cast<VRClient_003*>(client)->IsInterfaceVersionValid(pchInterfaceVersion);
}

void* VRClient::GetGenericInterface(const char* pchNameAndVersion, vr::EVRInitError* peError)
{
	dlog::Println("[VRClient::GetGenericInterface] Called.");

	void* svrInterface = static_cast<VRClient_003*>(client)->GetGenericInterface(pchNameAndVersion, peError);

	std::string str = pchNameAndVersion;

	dlog::Println("Getting interface for " + str);

	// Client
	if (str.find("VRClient") != std::string::npos)
	{
		return VRClient::cInstance;
	}

	// Compositor
	if (str.find("IVRCompositor") != std::string::npos)
	{
		if (vCompositor == nullptr)
		{
			vCompositor = new VirtualCompositor();
		}

		if (str.find("FnTable") != std::string::npos && vCompositor->steamCompositor == nullptr)
		{
			vCompositor->steamCompositor = static_cast<VRClient_003*>(client)->GetGenericInterface(pchNameAndVersion + 8, peError); // 8 is the size of string FnTable: that appears at the front of function table requests
		}
		else if (vCompositor->steamCompositor == nullptr)
		{
			vCompositor->steamCompositor = svrInterface;
		}

		if (str.find("IVRCompositor_012") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_012();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_012");

				*peError = VRInitError_None;
				IVRCompositor_012* ivrCompositor = static_cast<IVRCompositor_012*>(static_cast<VirtualCompositor_012*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_012().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_013") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_013();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_013");

				*peError = VRInitError_None;
				IVRCompositor_013* ivrCompositor = static_cast<IVRCompositor_013*>(static_cast<VirtualCompositor_013*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_013().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_014") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_014();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_014");

				*peError = VRInitError_None;
				IVRCompositor_014* ivrCompositor = static_cast<IVRCompositor_014*>(static_cast<VirtualCompositor_014*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_014().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_015") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_015();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_015");

				*peError = VRInitError_None;
				IVRCompositor_015* ivrCompositor = static_cast<IVRCompositor_015*>(static_cast<VirtualCompositor_015*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_015().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_016") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_016();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_016");

				*peError = VRInitError_None;
				IVRCompositor_016* ivrCompositor = static_cast<IVRCompositor_016*>(static_cast<VirtualCompositor_016*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_016().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_017") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_017();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_017");

				*peError = VRInitError_None;
				IVRCompositor_017* ivrCompositor = static_cast<IVRCompositor_017*>(static_cast<VirtualCompositor_017*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_017().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_018") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_018();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_018");

				*peError = VRInitError_None;
				IVRCompositor_018* ivrCompositor = static_cast<IVRCompositor_018*>(static_cast<VirtualCompositor_018*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_018().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_019") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_019();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_019");

				*peError = VRInitError_None;
				IVRCompositor_019* ivrCompositor = static_cast<IVRCompositor_019*>(static_cast<VirtualCompositor_019*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_019().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_020") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_020();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_020");

				*peError = VRInitError_None;
				IVRCompositor_020* ivrCompositor = static_cast<IVRCompositor_020*>(static_cast<VirtualCompositor_020*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_020().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_021") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_021();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_021");

				*peError = VRInitError_None;
				IVRCompositor_021* ivrCompositor = static_cast<IVRCompositor_021*>(static_cast<VirtualCompositor_021*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_021().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_022") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_022();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_022");

				*peError = VRInitError_None;
				IVRCompositor_022* ivrCompositor = static_cast<IVRCompositor_022*>(static_cast<VirtualCompositor_022*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_022().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_024") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_024();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_024");

				*peError = VRInitError_None;
				IVRCompositor_024* ivrCompositor = static_cast<IVRCompositor_024*>(static_cast<VirtualCompositor_024*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_024().GetFnTable();
			}
		}
		else if (str.find("IVRCompositor_026") != std::string::npos)
		{
			// Todo
			//vCompositor->version = VirtualInput_Version_012;

			if (vCompositor->virtualCompositor == nullptr)
			{
				vCompositor->virtualCompositor = new VirtualCompositor_026();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualCompositor_026");

				*peError = VRInitError_None;
				IVRCompositor_026* ivrCompositor = static_cast<IVRCompositor_026*>(static_cast<VirtualCompositor_026*>(vCompositor->virtualCompositor));
				return ivrCompositor;
			}
			else
			{
				dlog::Println("Returning VirtualCompositor's FnTable.");
				return VirtualCompositor_026().GetFnTable();
			}
		}
	}

	// Input
	if (str.find("IVRInput") != std::string::npos)
	{
		if (vInput == nullptr)
		{
			vInput = new VirtualInput();
		}

		if (str.find("FnTable") != std::string::npos && vInput->steamInput == nullptr)
		{
			vInput->steamInput = static_cast<VRClient_003*>(client)->GetGenericInterface(pchNameAndVersion + 8, peError); // 8 is the size of string FnTable: that appears at the front of function table requests
		}
		else if (vInput->steamInput == nullptr)
		{
			vInput->steamInput = svrInterface;
		}

		if (str.find("IVRInput_004") != std::string::npos)
		{
			if (vInput->virtualInput == nullptr)
			{
				vInput->virtualInput = new VirtualInput_004();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualInput_004");

				*peError = VRInitError_None;
				IVRInput_004* ivrInput = static_cast<IVRInput_004*>(static_cast<VirtualInput_004*>(vInput->virtualInput));
				return ivrInput;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualInput_004().GetFnTable();
			}
		}
		else if (str.find("IVRInput_005") != std::string::npos)
		{
			if (vInput->virtualInput == nullptr)
			{
				vInput->virtualInput = new VirtualInput_005();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualInput_005");

				*peError = VRInitError_None;
				IVRInput_005* ivrInput = static_cast<IVRInput_005*>(static_cast<VirtualInput_005*>(vInput->virtualInput));
				return ivrInput;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualInput_005().GetFnTable();
			}
		}
		else if (str.find("IVRInput_006") != std::string::npos)
		{
			if (vInput->virtualInput == nullptr)
			{
				vInput->virtualInput = new VirtualInput_006();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualInput_006");

				*peError = VRInitError_None;
				IVRInput_006* ivrInput = static_cast<IVRInput_006*>(static_cast<VirtualInput_006*>(vInput->virtualInput));
				return ivrInput;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualInput_006().GetFnTable();
			}
		}
		else if (str.find("IVRInput_007") != std::string::npos)
		{
			if (vInput->virtualInput == nullptr)
			{
				vInput->virtualInput = new VirtualInput_007();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualInput_007");

				*peError = VRInitError_None;
				IVRInput_007* ivrInput = static_cast<IVRInput_007*>(static_cast<VirtualInput_007*>(vInput->virtualInput));
				return ivrInput;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualInput_007().GetFnTable();
			}
		}
		else if (str.find("IVRInput_010") != std::string::npos)
		{
			if (vInput->virtualInput == nullptr)
			{
				vInput->virtualInput = new VirtualInput_010();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualInput_010");

				*peError = VRInitError_None;
				IVRInput_010* ivrInput = static_cast<IVRInput_010*>(static_cast<VirtualInput_010*>(vInput->virtualInput));
				return ivrInput;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualInput_010().GetFnTable();
			}
		}
	}
 
	// Resources
	// TODO: Fix VirtualResources Implementation
	/*
	if (str.find("IVRResources") != std::string::npos)
	{
		if (vResources == nullptr)
		{
			if (str == IVRResources_001::IVRResources_Version)
			{
				vResources = new IVRResources_001::VirtualResources();
			}
		}

		if (vResources != nullptr)
		{
			*peError = VRInitError_None;
		}
		else
		{
			*peError = VRInitError_Init_InterfaceNotFound;
		}

		return vResources;
	}
	*/

	// System
	// Bug: Causes vrc to lag heavily
	if (false)//str.find("IVRSystem") != std::string::npos)
	{
		if (vSystem == nullptr)
		{
			vSystem = new VirtualSystem();
		}

		if (str.find("FnTable") != std::string::npos && vSystem->steamSystem == nullptr)
		{
			vSystem->steamSystem = static_cast<VRClient_003*>(client)->GetGenericInterface(pchNameAndVersion + 8, peError); // 8 is the size of string FnTable: that appears at the front of function table requests
		}
		else if (vSystem->steamSystem == nullptr)
		{
			vSystem->steamSystem = svrInterface;
		}

		if (str.find("IVRSystem_011") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_011();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_011");

				*peError = VRInitError_None;
				IVRSystem_011* ivrSystem = static_cast<IVRSystem_011*>(static_cast<VirtualSystem_011*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_011().GetFnTable();
			}
		}
		else if (str.find("IVRSystem_012") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_012();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_012");

				*peError = VRInitError_None;
				IVRSystem_012* ivrSystem = static_cast<IVRSystem_012*>(static_cast<VirtualSystem_012*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_012().GetFnTable();
			}
		}
		else if (str.find("IVRSystem_014") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_014();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_014");

				*peError = VRInitError_None;
				IVRSystem_014* ivrSystem = static_cast<IVRSystem_014*>(static_cast<VirtualSystem_014*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_014().GetFnTable();
			}
		}
		else if (str.find("IVRSystem_015") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_015();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_015");

				*peError = VRInitError_None;
				IVRSystem_015* ivrSystem = static_cast<IVRSystem_015*>(static_cast<VirtualSystem_015*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_015().GetFnTable();
			}
		}
		else if (str.find("IVRSystem_016") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_016();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_016");

				*peError = VRInitError_None;
				IVRSystem_016* ivrSystem = static_cast<IVRSystem_016*>(static_cast<VirtualSystem_016*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_016().GetFnTable();
			}
		}
		else if (str.find("IVRSystem_017") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_017();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_017");

				*peError = VRInitError_None;
				IVRSystem_017* ivrSystem = static_cast<IVRSystem_017*>(static_cast<VirtualSystem_017*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_017().GetFnTable();
			}
		}
		else if (str.find("IVRSystem_019") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_019();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_019");

				*peError = VRInitError_None;
				IVRSystem_019* ivrSystem = static_cast<IVRSystem_019*>(static_cast<VirtualSystem_019*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_019().GetFnTable();
			}
		}
		else if (str.find("IVRSystem_020") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_020();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_020");

				*peError = VRInitError_None;
				IVRSystem_020* ivrSystem = static_cast<IVRSystem_020*>(static_cast<VirtualSystem_020*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_020().GetFnTable();
			}
		}
		else if (str.find("IVRSystem_021") != std::string::npos)
		{
			if (vSystem->virtualSystem == nullptr)
			{
				vSystem->virtualSystem = new VirtualSystem_021();
			}

			if (str.find("FnTable") == std::string::npos)
			{

				dlog::Println("Returning VirtualSystem_021");

				*peError = VRInitError_None;
				IVRSystem_021* ivrSystem = static_cast<IVRSystem_021*>(static_cast<VirtualSystem_021*>(vSystem->virtualSystem));
				return ivrSystem;
			}
			else
			{
				dlog::Println("Returning VirtualInput's FnTable.");
				return VirtualSystem_021().GetFnTable();
			}
		}
	}

	dlog::Println("Returning SteamVR Interface...");
	return svrInterface;
}

bool VRClient::BIsHmdPresent()
{
	// This function is spammed, called once per frame afaik
	//dlog::Println("[VRClient::BIsHmdPresent] Called.");

	return static_cast<VRClient_003*>(client)->BIsHmdPresent();
}

const char* VRClient::GetEnglishStringForHmdError(vr::EVRInitError eError)
{
	//dlog::Println("[VRClient::GetEnglishStringForHmdError] Called.");

	const char* error = static_cast<VRClient_003*>(client)->GetEnglishStringForHmdError(eError);

	dlog::Println(std::string(error));

	return error;
}

const char* VRClient::GetIDForVRInitError(vr::EVRInitError eError)
{
	//dlog::Println("[VRClient::GetIDForVRInitError] Called.");

	return static_cast<VRClient_003*>(client)->GetIDForVRInitError(eError);
}
