#pragma once
#include "openvr.h"
#include "VirtualCommon.h"

using namespace vr;

/** Allows the application to interact with the compositor */
class IVRCompositor_021
{
public:
	/** Sets tracking space returned by WaitGetPoses */
	virtual void SetTrackingSpace(ETrackingUniverseOrigin eOrigin) = 0;

	/** Gets current tracking space returned by WaitGetPoses */
	virtual ETrackingUniverseOrigin GetTrackingSpace() = 0;

	/** Scene applications should call this function to get poses to render with (and optionally poses predicted an additional frame out to use for gameplay).
	* This function will block until "running start" milliseconds before the start of the frame, and should be called at the last moment before needing to
	* start rendering.
	*
	* Return codes:
	*	- IsNotSceneApplication (make sure to call VR_Init with VRApplicaiton_Scene)
	*	- DoNotHaveFocus (some other app has taken focus - this will throttle the call to 10hz to reduce the impact on that app)
	*/
	virtual EVRCompositorError WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount,
		VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount) = 0;

	/** Get the last set of poses returned by WaitGetPoses. */
	virtual EVRCompositorError GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount,
		VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount) = 0;

	/** Interface for accessing last set of poses returned by WaitGetPoses one at a time.
	* Returns VRCompositorError_IndexOutOfRange if unDeviceIndex not less than k_unMaxTrackedDeviceCount otherwise VRCompositorError_None.
	* It is okay to pass NULL for either pose if you only want one of the values. */
	virtual EVRCompositorError GetLastPoseForTrackedDeviceIndex(TrackedDeviceIndex_t unDeviceIndex, TrackedDevicePose_t* pOutputPose, TrackedDevicePose_t* pOutputGamePose) = 0;

	/** Updated scene texture to display. If pBounds is NULL the entire texture will be used.  If called from an OpenGL app, consider adding a glFlush after
	* Submitting both frames to signal the driver to start processing, otherwise it may wait until the command buffer fills up, causing the app to miss frames.
	*
	* OpenGL dirty state:
	*	glBindTexture
	*
	* Return codes:
	*	- IsNotSceneApplication (make sure to call VR_Init with VRApplicaiton_Scene)
	*	- DoNotHaveFocus (some other app has taken focus)
	*	- TextureIsOnWrongDevice (application did not use proper AdapterIndex - see IVRSystem.GetDXGIOutputInfo)
	*	- SharedTexturesNotSupported (application needs to call CreateDXGIFactory1 or later before creating DX device)
	*	- TextureUsesUnsupportedFormat (scene textures must be compatible with DXGI sharing rules - e.g. uncompressed, no mips, etc.)
	*	- InvalidTexture (usually means bad arguments passed in)
	*	- AlreadySubmitted (app has submitted two left textures or two right textures in a single frame - i.e. before calling WaitGetPoses again)
	*/
	virtual EVRCompositorError Submit(EVREye eEye, const Texture_t* pTexture, const VRTextureBounds_t* pBounds = 0, EVRSubmitFlags nSubmitFlags = Submit_Default) = 0;

	/** Clears the frame that was sent with the last call to Submit. This will cause the
	* compositor to show the grid until Submit is called again. */
	virtual void ClearLastSubmittedFrame() = 0;

	/** Call immediately after presenting your app's window (i.e. companion window) to unblock the compositor.
	* This is an optional call, which only needs to be used if you can't instead call WaitGetPoses immediately after Present.
	* For example, if your engine's render and game loop are not on separate threads, or blocking the render thread until 3ms before the next vsync would
	* introduce a deadlock of some sort.  This function tells the compositor that you have finished all rendering after having Submitted buffers for both
	* eyes, and it is free to start its rendering work.  This should only be called from the same thread you are rendering on. */
	virtual void PostPresentHandoff() = 0;

	/** Returns true if timing data is filled it.  Sets oldest timing info if nFramesAgo is larger than the stored history.
	* Be sure to set timing.size = sizeof(Compositor_FrameTiming) on struct passed in before calling this function. */
	virtual bool GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo = 0) = 0;

	/** Interface for copying a range of timing data.  Frames are returned in ascending order (oldest to newest) with the last being the most recent frame.
	* Only the first entry's m_nSize needs to be set, as the rest will be inferred from that.  Returns total number of entries filled out. */
	virtual uint32_t GetFrameTimings(Compositor_FrameTiming* pTiming, uint32_t nFrames) = 0;

	/** Returns the time in seconds left in the current (as identified by FrameTiming's frameIndex) frame.
	* Due to "running start", this value may roll over to the next frame before ever reaching 0.0. */
	virtual float GetFrameTimeRemaining() = 0;

	/** Fills out stats accumulated for the last connected application.  Pass in sizeof( Compositor_CumulativeStats ) as second parameter. */
	virtual void GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes) = 0;

	/** Fades the view on the HMD to the specified color. The fade will take fSeconds, and the color values are between
	* 0.0 and 1.0. This color is faded on top of the scene based on the alpha parameter. Removing the fade color instantly
	* would be FadeToColor( 0.0, 0.0, 0.0, 0.0, 0.0 ).  Values are in un-premultiplied alpha space. */
	virtual void FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground = false) = 0;

	/** Get current fade color value. */
	virtual HmdColor_t GetCurrentFadeColor(bool bBackground = false) = 0;

	/** Fading the Grid in or out in fSeconds */
	virtual void FadeGrid(float fSeconds, bool bFadeIn) = 0;

	/** Get current alpha value of grid. */
	virtual float GetCurrentGridAlpha() = 0;

	/** Override the skybox used in the compositor (e.g. for during level loads when the app can't feed scene images fast enough)
	* Order is Front, Back, Left, Right, Top, Bottom.  If only a single texture is passed, it is assumed in lat-long format.
	* If two are passed, it is assumed a lat-long stereo pair. */
	virtual EVRCompositorError SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount) = 0;

	/** Resets compositor skybox back to defaults. */
	virtual void ClearSkyboxOverride() = 0;

	/** Brings the compositor window to the front. This is useful for covering any other window that may be on the HMD
	* and is obscuring the compositor window. */
	virtual void CompositorBringToFront() = 0;

	/** Pushes the compositor window to the back. This is useful for allowing other applications to draw directly to the HMD. */
	virtual void CompositorGoToBack() = 0;

	/** Tells the compositor process to clean up and exit. You do not need to call this function at shutdown. Under normal
	* circumstances the compositor will manage its own life cycle based on what applications are running. */
	virtual void CompositorQuit() = 0;

	/** Return whether the compositor is fullscreen */
	virtual bool IsFullscreen() = 0;

	/** Returns the process ID of the process that is currently rendering the scene */
	virtual uint32_t GetCurrentSceneFocusProcess() = 0;

	/** Returns the process ID of the process that rendered the last frame (or 0 if the compositor itself rendered the frame.)
	* Returns 0 when fading out from an app and the app's process Id when fading into an app. */
	virtual uint32_t GetLastFrameRenderer() = 0;

	/** Returns true if the current process has the scene focus */
	virtual bool CanRenderScene() = 0;

	/** Creates a window on the primary monitor to display what is being shown in the headset. */
	virtual void ShowMirrorWindow() = 0;

	/** Closes the mirror window. */
	virtual void HideMirrorWindow() = 0;

	/** Returns true if the mirror window is shown. */
	virtual bool IsMirrorWindowVisible() = 0;

	/** Writes all images that the compositor knows about (including overlays) to a 'screenshots' folder in the SteamVR runtime root. */
	virtual void CompositorDumpImages() = 0;

	/** Let an app know it should be rendering with low resources. */
	virtual bool ShouldAppRenderWithLowResources() = 0;

	/** Override interleaved reprojection logic to force on. */
	virtual void ForceInterleavedReprojectionOn(bool bOverride) = 0;

	/** Force reconnecting to the compositor process. */
	virtual void ForceReconnectProcess() = 0;

	/** Temporarily suspends rendering (useful for finer control over scene transitions). */
	virtual void SuspendRendering(bool bSuspend) = 0;

	/** Opens a shared D3D11 texture with the undistorted composited image for each eye.  Use ReleaseMirrorTextureD3D11 when finished
	* instead of calling Release on the resource itself. */
	virtual EVRCompositorError GetMirrorTextureD3D11(EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView) = 0;
	virtual void ReleaseMirrorTextureD3D11(void* pD3D11ShaderResourceView) = 0;

	/** Access to mirror textures from OpenGL. */
	virtual EVRCompositorError GetMirrorTextureGL(EVREye eEye, glUInt_t* pglTextureId, glSharedTextureHandle_t* pglSharedTextureHandle) = 0;
	virtual bool ReleaseSharedGLTexture(glUInt_t glTextureId, glSharedTextureHandle_t glSharedTextureHandle) = 0;
	virtual void LockGLSharedTextureForAccess(glSharedTextureHandle_t glSharedTextureHandle) = 0;
	virtual void UnlockGLSharedTextureForAccess(glSharedTextureHandle_t glSharedTextureHandle) = 0;

	/** [Vulkan Only]
	* return 0. Otherwise it returns the length of the number of bytes necessary to hold this string including the trailing
	* null.  The string will be a space separated list of-required instance extensions to enable in VkCreateInstance */
	virtual uint32_t GetVulkanInstanceExtensionsRequired(VR_OUT_STRING() char* pchValue, uint32_t unBufferSize) = 0;

	/** [Vulkan only]
	* return 0. Otherwise it returns the length of the number of bytes necessary to hold this string including the trailing
	* null.  The string will be a space separated list of required device extensions to enable in VkCreateDevice */
	virtual uint32_t GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, VR_OUT_STRING() char* pchValue, uint32_t unBufferSize) = 0;

	/** [ Vulkan/D3D12 Only ]
	* There are two purposes for SetExplicitTimingMode:
	*	1. To get a more accurate GPU timestamp for when the frame begins in Vulkan/D3D12 applications.
	*	2. (Optional) To avoid having WaitGetPoses access the Vulkan queue so that the queue can be accessed from
	*	another thread while WaitGetPoses is executing.
	*
	* More accurate GPU timestamp for the start of the frame is achieved by the application calling
	* SubmitExplicitTimingData immediately before its first submission to the Vulkan/D3D12 queue.
	* This is more accurate because normally this GPU timestamp is recorded during WaitGetPoses.  In D3D11,
	* WaitGetPoses queues a GPU timestamp write, but it does not actually get submitted to the GPU until the
	* application flushes.  By using SubmitExplicitTimingData, the timestamp is recorded at the same place for
	* Vulkan/D3D12 as it is for D3D11, resulting in a more accurate GPU time measurement for the frame.
	*
	* Avoiding WaitGetPoses accessing the Vulkan queue can be achieved using SetExplicitTimingMode as well.  If this is desired,
	* the application *MUST* call PostPresentHandoff itself prior to WaitGetPoses.  If SetExplicitTimingMode is true and the
	* application calls PostPresentHandoff, then WaitGetPoses is guaranteed not to access the queue.  Note that PostPresentHandoff
	* and SubmitExplicitTimingData will access the queue, so only WaitGetPoses becomes safe for accessing the queue from another
	* thread. */
	virtual void SetExplicitTimingMode(bool bExplicitTimingMode) = 0;

	/** [ Vulkan/D3D12 Only ]
	* Submit explicit timing data.  When SetExplicitTimingMode is true, this must be called immediately before
	* the application's first vkQueueSubmit (Vulkan) or ID3D12CommandQueue::ExecuteCommandLists (D3D12) of each frame.
	* This function will insert a GPU timestamp write just before the application starts its rendering.  This function
	* will perform a vkQueueSubmit on Vulkan so must not be done simultaneously with VkQueue operations on another thread.
	* Returns VRCompositorError_RequestFailed if SetExplicitTimingMode is not enabled. */
	virtual EVRCompositorError SubmitExplicitTimingData() = 0;
};

class VirtualCompositor_021 : public VirtualCommon, public IVRCompositor_021
{
public:
	void* GetFnTable();

	/** Sets tracking space returned by WaitGetPoses */
	void SetTrackingSpace(ETrackingUniverseOrigin eOrigin);

	/** Gets current tracking space returned by WaitGetPoses */
	ETrackingUniverseOrigin GetTrackingSpace();

	/** Scene applications should call this function to get poses to render with (and optionally poses predicted an additional frame out to use for gameplay).
	* This function will block until "running start" milliseconds before the start of the frame, and should be called at the last moment before needing to
	* start rendering.
	*
	* Return codes:
	*	- IsNotSceneApplication (make sure to call VR_Init with VRApplicaiton_Scene)
	*	- DoNotHaveFocus (some other app has taken focus - this will throttle the call to 10hz to reduce the impact on that app)
	*/
	EVRCompositorError WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount,
		VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount);

	/** Get the last set of poses returned by WaitGetPoses. */
	EVRCompositorError GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount,
		VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount);

	/** Interface for accessing last set of poses returned by WaitGetPoses one at a time.
	* Returns VRCompositorError_IndexOutOfRange if unDeviceIndex not less than k_unMaxTrackedDeviceCount otherwise VRCompositorError_None.
	* It is okay to pass NULL for either pose if you only want one of the values. */
	EVRCompositorError GetLastPoseForTrackedDeviceIndex(TrackedDeviceIndex_t unDeviceIndex, TrackedDevicePose_t* pOutputPose, TrackedDevicePose_t* pOutputGamePose);

	/** Updated scene texture to display. If pBounds is NULL the entire texture will be used.  If called from an OpenGL app, consider adding a glFlush after
	* Submitting both frames to signal the driver to start processing, otherwise it may wait until the command buffer fills up, causing the app to miss frames.
	*
	* OpenGL dirty state:
	*	glBindTexture
	*
	* Return codes:
	*	- IsNotSceneApplication (make sure to call VR_Init with VRApplicaiton_Scene)
	*	- DoNotHaveFocus (some other app has taken focus)
	*	- TextureIsOnWrongDevice (application did not use proper AdapterIndex - see IVRSystem.GetDXGIOutputInfo)
	*	- SharedTexturesNotSupported (application needs to call CreateDXGIFactory1 or later before creating DX device)
	*	- TextureUsesUnsupportedFormat (scene textures must be compatible with DXGI sharing rules - e.g. uncompressed, no mips, etc.)
	*	- InvalidTexture (usually means bad arguments passed in)
	*	- AlreadySubmitted (app has submitted two left textures or two right textures in a single frame - i.e. before calling WaitGetPoses again)
	*/
	EVRCompositorError Submit(EVREye eEye, const Texture_t* pTexture, const VRTextureBounds_t* pBounds, EVRSubmitFlags nSubmitFlags = Submit_Default);

	/** Clears the frame that was sent with the last call to Submit. This will cause the
	* compositor to show the grid until Submit is called again. */
	void ClearLastSubmittedFrame();

	/** Call immediately after presenting your app's window (i.e. companion window) to unblock the compositor.
	* This is an optional call, which only needs to be used if you can't instead call WaitGetPoses immediately after Present.
	* For example, if your engine's render and game loop are not on separate threads, or blocking the render thread until 3ms before the next vsync would
	* introduce a deadlock of some sort.  This function tells the compositor that you have finished all rendering after having Submitted buffers for both
	* eyes, and it is free to start its rendering work.  This should only be called from the same thread you are rendering on. */
	void PostPresentHandoff();

	/** Returns true if timing data is filled it.  Sets oldest timing info if nFramesAgo is larger than the stored history.
	* Be sure to set timing.size = sizeof(Compositor_FrameTiming) on struct passed in before calling this function. */
	bool GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo);

	/** Interface for copying a range of timing data.  Frames are returned in ascending order (oldest to newest) with the last being the most recent frame.
	* Only the first entry's m_nSize needs to be set, as the rest will be inferred from that.  Returns total number of entries filled out. */
	uint32_t GetFrameTimings(VR_ARRAY_COUNT(nFrames) Compositor_FrameTiming* pTiming, uint32_t nFrames);

	/** Returns the time in seconds left in the current (as identified by FrameTiming's frameIndex) frame.
	* Due to "running start", this value may roll over to the next frame before ever reaching 0.0. */
	float GetFrameTimeRemaining();

	/** Fills out stats accumulated for the last connected application.  Pass in sizeof( Compositor_CumulativeStats ) as second parameter. */
	void GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes);

	/** Fades the view on the HMD to the specified color. The fade will take fSeconds, and the color values are between
	* 0.0 and 1.0. This color is faded on top of the scene based on the alpha parameter. Removing the fade color instantly
	* would be FadeToColor( 0.0, 0.0, 0.0, 0.0, 0.0 ).  Values are in un-premultiplied alpha space. */
	void FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground = false);

	/** Get current fade color value. */
	HmdColor_t GetCurrentFadeColor(bool bBackground = false);

	/** Fading the Grid in or out in fSeconds */
	void FadeGrid(float fSeconds, bool bFadeIn);

	/** Get current alpha value of grid. */
	float GetCurrentGridAlpha();

	/** Override the skybox used in the compositor (e.g. for during level loads when the app can't feed scene images fast enough)
	* Order is Front, Back, Left, Right, Top, Bottom.  If only a single texture is passed, it is assumed in lat-long format.
	* If two are passed, it is assumed a lat-long stereo pair. */
	EVRCompositorError SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount);

	/** Resets compositor skybox back to defaults. */
	void ClearSkyboxOverride();

	/** Brings the compositor window to the front. This is useful for covering any other window that may be on the HMD
	* and is obscuring the compositor window. */
	void CompositorBringToFront();

	/** Pushes the compositor window to the back. This is useful for allowing other applications to draw directly to the HMD. */
	void CompositorGoToBack();

	/** Tells the compositor process to clean up and exit. You do not need to call this function at shutdown. Under normal
	* circumstances the compositor will manage its own life cycle based on what applications are running. */
	void CompositorQuit();

	/** Return whether the compositor is fullscreen */
	bool IsFullscreen();

	/** Returns the process ID of the process that is currently rendering the scene */
	uint32_t GetCurrentSceneFocusProcess();

	/** Returns the process ID of the process that rendered the last frame (or 0 if the compositor itself rendered the frame.)
	* Returns 0 when fading out from an app and the app's process Id when fading into an app. */
	uint32_t GetLastFrameRenderer();

	/** Returns true if the current process has the scene focus */
	bool CanRenderScene();

	/** Creates a window on the primary monitor to display what is being shown in the headset. */
	void ShowMirrorWindow();

	/** Closes the mirror window. */
	void HideMirrorWindow();

	/** Returns true if the mirror window is shown. */
	bool IsMirrorWindowVisible();

	/** Writes all images that the compositor knows about (including overlays) to a 'screenshots' folder in the SteamVR runtime root. */
	void CompositorDumpImages();

	/** Let an app know it should be rendering with low resources. */
	bool ShouldAppRenderWithLowResources();

	/** Override interleaved reprojection logic to force on. */
	void ForceInterleavedReprojectionOn(bool bOverride);

	/** Force reconnecting to the compositor process. */
	void ForceReconnectProcess();

	/** Temporarily suspends rendering (useful for finer control over scene transitions). */
	void SuspendRendering(bool bSuspend);

	/** Opens a shared D3D11 texture with the undistorted composited image for each eye.  Use ReleaseMirrorTextureD3D11 when finished
	* instead of calling Release on the resource itself. */
	EVRCompositorError GetMirrorTextureD3D11(EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView);
	void ReleaseMirrorTextureD3D11(void* pD3D11ShaderResourceView);

	/** Access to mirror textures from OpenGL. */
	EVRCompositorError GetMirrorTextureGL(EVREye eEye, glUInt_t* pglTextureId, glSharedTextureHandle_t* pglSharedTextureHandle);
	bool ReleaseSharedGLTexture(glUInt_t glTextureId, glSharedTextureHandle_t glSharedTextureHandle);
	void LockGLSharedTextureForAccess(glSharedTextureHandle_t glSharedTextureHandle);
	void UnlockGLSharedTextureForAccess(glSharedTextureHandle_t glSharedTextureHandle);

	/** [Vulkan Only]
	* return 0. Otherwise it returns the length of the number of bytes necessary to hold this string including the trailing
	* null.  The string will be a space separated list of-required instance extensions to enable in VkCreateInstance */
	uint32_t GetVulkanInstanceExtensionsRequired(VR_OUT_STRING() char* pchValue, uint32_t unBufferSize);

	/** [Vulkan only]
	* return 0. Otherwise it returns the length of the number of bytes necessary to hold this string including the trailing
	* null.  The string will be a space separated list of required device extensions to enable in VkCreateDevice */
	uint32_t GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, VR_OUT_STRING() char* pchValue, uint32_t unBufferSize);

	/** [ Vulkan/D3D12 Only ]
	* There are two purposes for SetExplicitTimingMode:
	*	1. To get a more accurate GPU timestamp for when the frame begins in Vulkan/D3D12 applications.
	*	2. (Optional) To avoid having WaitGetPoses access the Vulkan queue so that the queue can be accessed from
	*	another thread while WaitGetPoses is executing.
	*
	* More accurate GPU timestamp for the start of the frame is achieved by the application calling
	* SubmitExplicitTimingData immediately before its first submission to the Vulkan/D3D12 queue.
	* This is more accurate because normally this GPU timestamp is recorded during WaitGetPoses.  In D3D11,
	* WaitGetPoses queues a GPU timestamp write, but it does not actually get submitted to the GPU until the
	* application flushes.  By using SubmitExplicitTimingData, the timestamp is recorded at the same place for
	* Vulkan/D3D12 as it is for D3D11, resulting in a more accurate GPU time measurement for the frame.
	*
	* Avoiding WaitGetPoses accessing the Vulkan queue can be achieved using SetExplicitTimingMode as well.  If this is desired,
	* the application *MUST* call PostPresentHandoff itself prior to WaitGetPoses.  If SetExplicitTimingMode is true and the
	* application calls PostPresentHandoff, then WaitGetPoses is guaranteed not to access the queue.  Note that PostPresentHandoff
	* and SubmitExplicitTimingData will access the queue, so only WaitGetPoses becomes safe for accessing the queue from another
	* thread. */
	void SetExplicitTimingMode(bool bExplicitTimingMode);

	/** [ Vulkan/D3D12 Only ]
	* Submit explicit timing data.  When SetExplicitTimingMode is true, this must be called immediately before
	* the application's first vkQueueSubmit (Vulkan) or ID3D12CommandQueue::ExecuteCommandLists (D3D12) of each frame.
	* This function will insert a GPU timestamp write just before the application starts its rendering.  This function
	* will perform a vkQueueSubmit on Vulkan so must not be done simultaneously with VkQueue operations on another thread.
	* Returns VRCompositorError_RequestFailed if SetExplicitTimingMode is not enabled. */
	EVRCompositorError SubmitExplicitTimingData();
};
