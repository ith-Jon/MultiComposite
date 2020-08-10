#pragma once
#include <openvr.h>
#include <stdint.h>

#include "IpcTools.h"
#include "Win32Ipc.h"

#define MAX_RUNTIME_COUNT 10

inline ISharedMem* CreateSharedMem(const char* name, uint32_t size, ISharedMem::Role role)
{
#if defined(WIN32)
	CREATE_OBJECT(Win32SharedMemory, name, size, role);
#endif
}

struct VREyeFrame_t
{
	bool setup;
	bool submitted;
	vr::EVRCompositorError returnedError;
	uint32_t frameCounter; // Unsafe, dont rely on it as it is meant to overflow, just used for seeing that the correct left/right frames are submitted
	vr::EVREye eEye;
	vr::Texture_t pTexture;
	vr::VRTextureBounds_t pBounds;
	vr::EVRSubmitFlags nSubmitFlags;
};

struct VRTrackedDeviceFrame_t
{
	uint32_t count;
	vr::TrackedDevicePose_t devices[100];
};

enum ApplicationPermissions
{
	ApplicationPermissions_None = 0,
	ApplicationPermissions_Renders = 2,
	ApplicationPermissions_ReceivesPoses = 4,
	ApplicationPermissions_ReceivesInputs = 8,
	ApplicationPermissions_PlaysSounds = 16,
	ApplicationPermissions_RecordsSounds = 32,
};
DEFINE_ENUM_FLAG_OPERATORS(ApplicationPermissions)

struct VRRuntime_t
{
	uint32_t id;

	ApplicationPermissions permissions;

	bool sceneInitialized;
	bool sceneRegistered;
	bool sceneShutdown;

	// GetFrameTiming
	bool getFrameTiming;
	vr::Compositor_FrameTiming frameTiming;
	uint32_t framesAgo;
	bool getFrameTiming_Result;

	// SetTrackingSpace
	bool setTrackingSpace;
	vr::ETrackingUniverseOrigin setTrackingOrigin;

	// Submit/Rendering
	bool submit;
	VREyeFrame_t eyeFrames[2];
	vr::EVRCompositorError submit_Result;
};

struct VRSharedState_t
{
	bool managedInitialized;
	VRRuntime_t runtimes[MAX_RUNTIME_COUNT];

	// WaitGetPoses
	bool waitGetPoses;
	VRTrackedDeviceFrame_t renderPoses;
	VRTrackedDeviceFrame_t gamePoses;

	VREyeFrame_t eyeFrames[2];
};

class SharedState
{
public:
	bool Init(ISharedMem::Role role);
	//void LockSharedMem();
	//void UnlockSharedMem();
	const VRSharedState_t* GetSharedState();
	VRSharedState_t* GetWritableSharedState();

private:
	ISharedMem* m_pSharedStateMem;
	//IMutex* m_pSharedMutex;
};
