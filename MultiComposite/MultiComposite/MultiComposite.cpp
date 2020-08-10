#include "MultiComposite.h"
#include "VirtualCommon.h"
#include "Compositor.h"

#include "VRClient.h"

void MultiComposite::Init()
{
	// Initialize shared mem
	sState.Init(ISharedMem::Server);
	pRuntimes = sState.GetWritableSharedState()->runtimes;

	// Initialize VR
	vr::EVRInitError error;
	vr::VR_Init(&error, vr::VRApplication_Scene, nullptr);

	vCompositor = ((IVRCompositor_022*)VR_GetGenericInterface("IVRCompositor_022", nullptr));

	sState.GetWritableSharedState()->managedInitialized = true;

	// Todo: Setup Inputs
	vr::VRInput()->SetActionManifestPath("C:\\Users\\DrPotato\\Documents\\GitHub\\MultiComposite\\MultiComposite\\x64\\Debug\\manifest.json");

	vr::VRInput()->GetActionSetHandle("/actions/main", &generalSetHandle);
	vr::VRInput()->GetActionHandle("/actions/main/in/alttab", &alttabHandle);

	clock = time(0);
}

void MultiComposite::Update()
{
	double sec = difftime(time(0), clock);

	if (sec > 0)
	{
		std::string title = "[MultiComposite]    ";
		std::string s = title +
			"Wait:     " + std::to_string(frames_Wait) + " FPS          " +
			"LeftEye:     " + std::to_string(frames_Left) + " FPS          " +
			"RightEye:     " + std::to_string(frames_Right) + " FPS          ";

		SetConsoleTitleA(s.c_str());

		frames_Wait = 0;
		frames_Left = 0;
		frames_Right = 0;
		clock = time(0);
	}

	// Todo: Update Inputs
	VRActiveActionSet_t activeSet
	{
		generalSetHandle
	};

	vr::VRInput()->UpdateActionState(&activeSet, sizeof(VRActiveActionSet_t), 1);

	UpdateRuntimes();
}

void MultiComposite::UpdateRuntimes()
{
	if (sState.GetSharedState() == nullptr || !sState.GetSharedState()->managedInitialized)
	{
		std::cout << "Something went wrong!" << '\n';
		return;
	}

	vr::InputDigitalActionData_t alttabData;
	vr::VRInput()->GetDigitalActionData(alttabHandle, &alttabData, sizeof(InputDigitalActionData_t), vr::k_ulInvalidInputValueHandle);

	bool changingRuntimes = alttabData.bState && alttabData.bChanged;

	// Handle Runtime Switching and Perm Setup
	for (int i = 0; i < MAX_RUNTIME_COUNT; i++)
	{
		VRRuntime_t* runtime = &pRuntimes[i];

		if (activeRuntime == nullptr)
		{
			if (runtime->sceneInitialized)
				activeRuntime = runtime;
			else
				continue;
		}

		runtime->id = i;

		if (changingRuntimes && &pRuntimes[i] == activeRuntime)
		{
			std::cout << "Switching Runtimes..." << '\n';

			for (int ii = i; ii < MAX_RUNTIME_COUNT + i; ii++)
			{
				ii++;
				VRRuntime_t* nextRuntime = ii >= MAX_RUNTIME_COUNT ? &pRuntimes[ii - MAX_RUNTIME_COUNT] : &pRuntimes[ii];

				if (!nextRuntime->sceneInitialized || !nextRuntime->sceneRegistered)
					continue;

				std::cout << "Setting Runtime [" << std::to_string(ii >= MAX_RUNTIME_COUNT ? ii - MAX_RUNTIME_COUNT : ii) << "] as active runtime." << '\n';

				activeRuntime->permissions = ApplicationPermissions_ReceivesPoses;
				nextRuntime->permissions = ApplicationPermissions_Renders | ApplicationPermissions_ReceivesInputs | ApplicationPermissions_ReceivesPoses;

				activeRuntime = nextRuntime;
				break;
			}

			break;
		}

		if (!runtime->sceneInitialized || runtime->sceneRegistered)
			continue;

		std::cout << "Setting up runtime [" << std::to_string(i) << "]..." << '\n';

		// Todo: Setup app perms
		if (runtime == activeRuntime && !activeRuntime->sceneRegistered)
		{
			std::cout << "Setting runtime [" << std::to_string(i) << "] as active runtime..." << '\n';
			runtime->permissions = ApplicationPermissions_Renders | ApplicationPermissions_ReceivesInputs | ApplicationPermissions_ReceivesPoses;
			runtime->sceneRegistered = true;
		}
		else if (runtime != activeRuntime)
		{
			std::cout << "Setting runtime [" << std::to_string(i) << "] as passive runtime..." << '\n';
			runtime->permissions = ApplicationPermissions_None;
			runtime->sceneRegistered = true;
		}
	}

	// Handle SHutdowns
	for (int i = 0; i < MAX_RUNTIME_COUNT; i++)
	{
		VRRuntime_t* runtime = &pRuntimes[i];

		if (!runtime->sceneInitialized || !runtime->sceneRegistered)
			continue;

		if (runtime->sceneShutdown)
		{
			std::cout << "Shutting down runtime..." << '\n';

			leftEyeTexture.handle = nullptr;
			rightEyeTexture.handle = nullptr;

			runtime->eyeFrames[0].setup = false;
			runtime->eyeFrames[0].submitted = false;
			runtime->eyeFrames[0].pTexture.handle = nullptr;

			runtime->eyeFrames[1].setup = false;
			runtime->eyeFrames[1].submitted = false;
			runtime->eyeFrames[1].pTexture.handle = nullptr;

			runtime->sceneShutdown = false;

			continue;
		}
	}
}

void MultiComposite::WaitGetPoses()
{
	if (activeRuntime != nullptr)
		if (activeRuntime->sceneRegistered)
			while (sState.GetWritableSharedState()->waitGetPoses);

	VRCompositor()->WaitGetPoses(sState.GetWritableSharedState()->renderPoses.devices, sState.GetWritableSharedState()->renderPoses.count,
		sState.GetWritableSharedState()->gamePoses.devices, sState.GetWritableSharedState()->gamePoses.count);

	frames_Wait++;
	sState.GetWritableSharedState()->waitGetPoses = true;
}

void MultiComposite::Render()
{
	VREyeFrame_t* leftEyeFrame = &sState.GetWritableSharedState()->eyeFrames[0];
	VREyeFrame_t* rightEyeFrame = &sState.GetWritableSharedState()->eyeFrames[1];

	EVRCompositorError err = VRCompositorError_None;

	//std::cout << "Rendering..." << '\n';

	int threshold = 0;

	if (activeRuntime != nullptr)
		if (activeRuntime->sceneRegistered)
			while (!leftEyeFrame->submitted)
				threshold++;

	threshold = 0;

	if (activeRuntime != nullptr)
		if (activeRuntime->sceneRegistered)
			while (!rightEyeFrame->submitted && threshold < 50000)
				threshold++;

	if (!leftEyeFrame->submitted || !rightEyeFrame->submitted)
	{
		frames_dropped++;
		leftEyeFrame->submitted = false;
		rightEyeFrame->submitted = false;

		return;
	}

	frames_Left++;
	err = RenderFrame(&leftEyeTexture, leftEyeFrame);

	frames_Right++;
	err = RenderFrame(&rightEyeTexture, rightEyeFrame);

	leftEyeFrame->submitted = false;
	rightEyeFrame->submitted = false;
}

EVRCompositorError MultiComposite::RenderFrame(vr::Texture_t* texture, VREyeFrame_t* frame)
{
	if (activeRuntime == nullptr)
		return VRCompositorError_None;

	//std::cout << "Rendering Frame..." << '\n';

	EVRCompositorError err = VRCompositorError_None;

	if (texture->handle == nullptr && frame->pTexture.handle != nullptr)
	{
		std::cout << "Setting up D3D11 Shared Texture" << '\n';
		D3D11Compositor::pD11Compositor->SetupTexture(texture, frame->pTexture.handle);
	}

	const vr::Texture_t* frameSubmit = texture;
	err = VRCompositor()->Submit(frame->eEye, frameSubmit, &frame->pBounds, frame->nSubmitFlags);

	if (err != VRCompositorError_None && activeRuntime->sceneInitialized && activeRuntime->sceneRegistered)
		dlog::Println("[MultiComposite Remote] Error Rendering Frame: " + std::to_string(err));

	return err;
}
