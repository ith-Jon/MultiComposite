#pragma once
#include "openvr.h"

#include "VRIpcConstants.h"
#include "IpcTools.h"

#include <Windows.h>

#include <vector>
#include <iostream>
#include <time.h>

using namespace vr;

class MultiComposite
{
public:
	bool running = true;

	// Inputs
	VRActionSetHandle_t generalSetHandle;
	VRActionHandle_t alttabHandle;;

	// Paths
	std::string steamvrPath;
	std::string multicompositePath;

	Texture_t leftEyeTexture;
	Texture_t rightEyeTexture;

	VRRuntime_t* pRuntimes;
	VRRuntime_t* activeRuntime;

	time_t clock;
	uint32_t frames_Wait;
	uint32_t frames_Left;
	uint32_t frames_Right;

	uint32_t frames_dropped;

	void* vCompositor;

	SharedState sState;

	MultiComposite()
	{
	}
	~MultiComposite()
	{
	}

	void Init();
	void Update();
	void UpdateRuntimes();
	void WaitGetPoses();
	void GetFrameTiming();
	void SetTrackingSpace();
	void Render();
	EVRCompositorError RenderFrame(vr::Texture_t* texture, VREyeFrame_t* frame);
};
