#include "VirtualCompositor_026.h"
#include "VRClient.h"

void VirtualCompositor_026::SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	VRClient::cInstance->vCompositor->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin VirtualCompositor_026::GetTrackingSpace()
{
	return VRClient::cInstance->vCompositor->GetTrackingSpace();
}

EVRCompositorError VirtualCompositor_026::WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return VRClient::cInstance->vCompositor->WaitGetPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor_026::GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return VRClient::cInstance->vCompositor->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor_026::GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	return VRClient::cInstance->vCompositor->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError VirtualCompositor_026::Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	return VRClient::cInstance->vCompositor->Submit(eEye, pTexture, pBounds, nSubmitFlags);
}

void VirtualCompositor_026::ClearLastSubmittedFrame()
{
	VRClient::cInstance->vCompositor->ClearLastSubmittedFrame();
}

void VirtualCompositor_026::PostPresentHandoff()
{
	VRClient::cInstance->vCompositor->PostPresentHandoff();
}

uint32_t VirtualCompositor_026::GetFrameTimings(VR_ARRAY_COUNT(nFrames) Compositor_FrameTiming* pTiming, uint32_t nFrames)
{
	return VRClient::cInstance->vCompositor->GetFrameTimings(pTiming, nFrames);
}

float VirtualCompositor_026::GetFrameTimeRemaining()
{
	return VRClient::cInstance->vCompositor->GetFrameTimeRemaining();
}

void VirtualCompositor_026::GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes)
{
	VRClient::cInstance->vCompositor->GetCumulativeStats(pStats, nStatsSizeInBytes);
}

void VirtualCompositor_026::FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	VRClient::cInstance->vCompositor->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

vr::HmdColor_t VirtualCompositor_026::GetCurrentFadeColor(bool bBackground)
{
	return VRClient::cInstance->vCompositor->GetCurrentFadeColor(bBackground);;
}

void VirtualCompositor_026::FadeGrid(float fSeconds, bool bFadeIn)
{
	VRClient::cInstance->vCompositor->FadeGrid(fSeconds, bFadeIn);
}

float VirtualCompositor_026::GetCurrentGridAlpha()
{
	return VRClient::cInstance->vCompositor->GetCurrentGridAlpha();;
}

EVRCompositorError VirtualCompositor_026::SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	return VRClient::cInstance->vCompositor->SetSkyboxOverride(pTextures, unTextureCount);
}

void VirtualCompositor_026::ClearSkyboxOverride()
{
	VRClient::cInstance->vCompositor->ClearSkyboxOverride();
}

void VirtualCompositor_026::CompositorBringToFront()
{
	VRClient::cInstance->vCompositor->CompositorBringToFront();
}

void VirtualCompositor_026::CompositorGoToBack()
{
	VRClient::cInstance->vCompositor->CompositorGoToBack();
}

void VirtualCompositor_026::CompositorQuit()
{
	VRClient::cInstance->vCompositor->CompositorQuit();
}

bool VirtualCompositor_026::IsFullscreen()
{
	return VRClient::cInstance->vCompositor->IsFullscreen();
}

uint32_t VirtualCompositor_026::GetCurrentSceneFocusProcess()
{
	return VRClient::cInstance->vCompositor->GetCurrentSceneFocusProcess();
}

uint32_t VirtualCompositor_026::GetLastFrameRenderer()
{
	return VRClient::cInstance->vCompositor->GetLastFrameRenderer();
}

bool VirtualCompositor_026::CanRenderScene()
{
	return VRClient::cInstance->vCompositor->CanRenderScene();
}

void VirtualCompositor_026::ShowMirrorWindow()
{
	VRClient::cInstance->vCompositor->ShowMirrorWindow();
}

void VirtualCompositor_026::HideMirrorWindow()
{
	VRClient::cInstance->vCompositor->HideMirrorWindow();
}

bool VirtualCompositor_026::IsMirrorWindowVisible()
{
	return VRClient::cInstance->vCompositor->IsMirrorWindowVisible();
}

void VirtualCompositor_026::CompositorDumpImages()
{
	VRClient::cInstance->vCompositor->CompositorDumpImages();
}

bool VirtualCompositor_026::ShouldAppRenderWithLowResources()
{
	return VRClient::cInstance->vCompositor->ShouldAppRenderWithLowResources();
}

void VirtualCompositor_026::ForceInterleavedReprojectionOn(bool bOverride)
{
	VRClient::cInstance->vCompositor->ForceInterleavedReprojectionOn(bOverride);
}

void VirtualCompositor_026::ForceReconnectProcess()
{
	VRClient::cInstance->vCompositor->ForceReconnectProcess();
}

void VirtualCompositor_026::SuspendRendering(bool bSuspend)
{
	VRClient::cInstance->vCompositor->SuspendRendering(bSuspend);
}

EVRCompositorError VirtualCompositor_026::GetMirrorTextureD3D11(vr::EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView)
{
	return VRClient::cInstance->vCompositor->GetMirrorTextureD3D11(eEye, pD3D11DeviceOrResource, ppD3D11ShaderResourceView);
}

void VirtualCompositor_026::ReleaseMirrorTextureD3D11(void* pD3D11ShaderResourceView)
{
	VRClient::cInstance->vCompositor->ReleaseMirrorTextureD3D11(pD3D11ShaderResourceView);
}

EVRCompositorError VirtualCompositor_026::GetMirrorTextureGL(vr::EVREye eEye, vr::glUInt_t* pglTextureId, vr::glSharedTextureHandle_t* pglSharedTextureHandle)
{
	return VRClient::cInstance->vCompositor->GetMirrorTextureGL(eEye, pglTextureId, pglSharedTextureHandle);
}

bool VirtualCompositor_026::ReleaseSharedGLTexture(vr::glUInt_t glTextureId, vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	return VRClient::cInstance->vCompositor->ReleaseSharedGLTexture(glTextureId, glSharedTextureHandle);
}

void VirtualCompositor_026::LockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	VRClient::cInstance->vCompositor->LockGLSharedTextureForAccess(glSharedTextureHandle);
}

void VirtualCompositor_026::UnlockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	VRClient::cInstance->vCompositor->UnlockGLSharedTextureForAccess(glSharedTextureHandle);
}

uint32_t VirtualCompositor_026::GetVulkanInstanceExtensionsRequired(VR_OUT_STRING() char* pchValue, uint32_t unBufferSize)
{
	return VRClient::cInstance->vCompositor->GetVulkanInstanceExtensionsRequired(pchValue, unBufferSize);
}

uint32_t VirtualCompositor_026::GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, VR_OUT_STRING() char* pchValue, uint32_t unBufferSize)
{
	return VRClient::cInstance->vCompositor->GetVulkanDeviceExtensionsRequired(pPhysicalDevice, pchValue, unBufferSize);
}

void VirtualCompositor_026::SetExplicitTimingMode(EVRCompositorTimingMode eTimingMode)
{
	VRClient::cInstance->vCompositor->SetExplicitTimingMode(eTimingMode);
}

EVRCompositorError VirtualCompositor_026::SubmitExplicitTimingData()
{
	return VRClient::cInstance->vCompositor->SubmitExplicitTimingData();
}

bool VirtualCompositor_026::IsMotionSmoothingEnabled()
{
	return VRClient::cInstance->vCompositor->IsMotionSmoothingEnabled();
}

bool VirtualCompositor_026::IsMotionSmoothingSupported()
{
	return VRClient::cInstance->vCompositor->IsMotionSmoothingSupported();
}

bool VirtualCompositor_026::IsCurrentSceneFocusAppLoading()
{
	return VRClient::cInstance->vCompositor->IsCurrentSceneFocusAppLoading();
}

EVRCompositorError VirtualCompositor_026::SetStageOverride_Async(const char* pchRenderModelPath, const vr::HmdMatrix34_t* pTransform, const Compositor_StageRenderSettings* pRenderSettings, uint32_t nSizeOfRenderSettings)
{
	return VRClient::cInstance->vCompositor->SetStageOverride_Async(pchRenderModelPath, pTransform, pRenderSettings, nSizeOfRenderSettings);
}

void VirtualCompositor_026::ClearStageOverride()
{
	VRClient::cInstance->vCompositor->ClearStageOverride();
}

bool VirtualCompositor_026::GetCompositorBenchmarkResults(Compositor_BenchmarkResults* pBenchmarkResults, uint32_t nSizeOfBenchmarkResults)
{
	return VRClient::cInstance->vCompositor->GetCompositorBenchmarkResults(pBenchmarkResults, nSizeOfBenchmarkResults);
}

EVRCompositorError VirtualCompositor_026::GetLastPosePredictionIDs(uint32_t* pRenderPosePredictionID, uint32_t* pGamePosePredictionID)
{
	return VRClient::cInstance->vCompositor->GetLastPosePredictionIDs(pRenderPosePredictionID, pGamePosePredictionID);
}

EVRCompositorError VirtualCompositor_026::GetPosesForFrame(uint32_t unPosePredictionID, VR_ARRAY_COUNT(unPoseArrayCount) TrackedDevicePose_t* pPoseArray, uint32_t unPoseArrayCount)
{
	return VRClient::cInstance->vCompositor->GetPosesForFrame(unPosePredictionID, pPoseArray, unPoseArrayCount);
}

bool VirtualCompositor_026::GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	return VRClient::cInstance->vCompositor->GetFrameTiming(pTiming, unFramesAgo);
}

/**			Fn Table			*/

void __stdcall fntable_Compositor_026_impl_SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin __stdcall fntable_Compositor_026_impl_GetTrackingSpace()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetTrackingSpace();
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->WaitGetPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->Submit(eEye, pTexture, pBounds, nSubmitFlags);
}

void __stdcall fntable_Compositor_026_impl_ClearLastSubmittedFrame()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearLastSubmittedFrame();
}

void __stdcall fntable_Compositor_026_impl_PostPresentHandoff()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->PostPresentHandoff();
}

uint32_t __stdcall fntable_Compositor_026_impl_GetFrameTimings(VR_ARRAY_COUNT(nFrames) Compositor_FrameTiming* pTiming, uint32_t nFrames)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTimings(pTiming, nFrames);
}

float __stdcall fntable_Compositor_026_impl_GetFrameTimeRemaining()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTimeRemaining();
}

void __stdcall fntable_Compositor_026_impl_GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCumulativeStats(pStats, nStatsSizeInBytes);
}

void __stdcall fntable_Compositor_026_impl_FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

vr::HmdColor_t __stdcall fntable_Compositor_026_impl_GetCurrentFadeColor(bool bBackground)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCurrentFadeColor(bBackground);;
}

void __stdcall fntable_Compositor_026_impl_FadeGrid(float fSeconds, bool bFadeIn)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->FadeGrid(fSeconds, bFadeIn);
}

float __stdcall fntable_Compositor_026_impl_GetCurrentGridAlpha()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCurrentGridAlpha();;
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetSkyboxOverride(pTextures, unTextureCount);
}

void __stdcall fntable_Compositor_026_impl_ClearSkyboxOverride()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearSkyboxOverride();
}

void __stdcall fntable_Compositor_026_impl_CompositorBringToFront()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorBringToFront();
}

void __stdcall fntable_Compositor_026_impl_CompositorGoToBack()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorGoToBack();
}

void __stdcall fntable_Compositor_026_impl_CompositorQuit()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorQuit();
}

bool __stdcall fntable_Compositor_026_impl_IsFullscreen()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsFullscreen();
}

uint32_t __stdcall fntable_Compositor_026_impl_GetCurrentSceneFocusProcess()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCurrentSceneFocusProcess();
}

uint32_t __stdcall fntable_Compositor_026_impl_GetLastFrameRenderer()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastFrameRenderer();
}

bool __stdcall fntable_Compositor_026_impl_CanRenderScene()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->CanRenderScene();
}

void __stdcall fntable_Compositor_026_impl_ShowMirrorWindow()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ShowMirrorWindow();
}

void __stdcall fntable_Compositor_026_impl_HideMirrorWindow()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->HideMirrorWindow();
}

bool __stdcall fntable_Compositor_026_impl_IsMirrorWindowVisible()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsMirrorWindowVisible();
}

void __stdcall fntable_Compositor_026_impl_CompositorDumpImages()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorDumpImages();
}

bool __stdcall fntable_Compositor_026_impl_ShouldAppRenderWithLowResources()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ShouldAppRenderWithLowResources();
}

void __stdcall fntable_Compositor_026_impl_ForceInterleavedReprojectionOn(bool bOverride)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ForceInterleavedReprojectionOn(bOverride);
}

void __stdcall fntable_Compositor_026_impl_ForceReconnectProcess()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ForceReconnectProcess();
}

void __stdcall fntable_Compositor_026_impl_SuspendRendering(bool bSuspend)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->SuspendRendering(bSuspend);
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_GetMirrorTextureD3D11(vr::EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetMirrorTextureD3D11(eEye, pD3D11DeviceOrResource, ppD3D11ShaderResourceView);
}

void __stdcall fntable_Compositor_026_impl_ReleaseMirrorTextureD3D11(void* pD3D11ShaderResourceView)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ReleaseMirrorTextureD3D11(pD3D11ShaderResourceView);
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_GetMirrorTextureGL(vr::EVREye eEye, vr::glUInt_t* pglTextureId, vr::glSharedTextureHandle_t* pglSharedTextureHandle)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetMirrorTextureGL(eEye, pglTextureId, pglSharedTextureHandle);
}

bool __stdcall fntable_Compositor_026_impl_ReleaseSharedGLTexture(vr::glUInt_t glTextureId, vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ReleaseSharedGLTexture(glTextureId, glSharedTextureHandle);
}

void __stdcall fntable_Compositor_026_impl_LockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->LockGLSharedTextureForAccess(glSharedTextureHandle);
}

void __stdcall fntable_Compositor_026_impl_UnlockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->UnlockGLSharedTextureForAccess(glSharedTextureHandle);
}

uint32_t __stdcall fntable_Compositor_026_impl_GetVulkanInstanceExtensionsRequired(VR_OUT_STRING() char* pchValue, uint32_t unBufferSize)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetVulkanInstanceExtensionsRequired(pchValue, unBufferSize);
}

uint32_t __stdcall fntable_Compositor_026_impl_GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, VR_OUT_STRING() char* pchValue, uint32_t unBufferSize)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetVulkanDeviceExtensionsRequired(pPhysicalDevice, pchValue, unBufferSize);
}

void __stdcall fntable_Compositor_026_impl_SetExplicitTimingMode(EVRCompositorTimingMode eTimingMode)
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetExplicitTimingMode(eTimingMode);
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_SubmitExplicitTimingData()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->SubmitExplicitTimingData();
}

bool __stdcall fntable_Compositor_026_impl_IsMotionSmoothingEnabled()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsMotionSmoothingEnabled();
}

bool __stdcall fntable_Compositor_026_impl_IsMotionSmoothingSupported()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsMotionSmoothingSupported();
}

bool __stdcall fntable_Compositor_026_impl_IsCurrentSceneFocusAppLoading()
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsCurrentSceneFocusAppLoading();
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_SetStageOverride_Async(const char* pchRenderModelPath, const vr::HmdMatrix34_t* pTransform, const Compositor_StageRenderSettings* pRenderSettings, uint32_t nSizeOfRenderSettings)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetStageOverride_Async(pchRenderModelPath, pTransform, pRenderSettings, nSizeOfRenderSettings);
}

void __stdcall fntable_Compositor_026_impl_ClearStageOverride()
{
	static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearStageOverride();
}

bool __stdcall fntable_Compositor_026_impl_GetCompositorBenchmarkResults(Compositor_BenchmarkResults* pBenchmarkResults, uint32_t nSizeOfBenchmarkResults)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCompositorBenchmarkResults(pBenchmarkResults, nSizeOfBenchmarkResults);
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_GetLastPosePredictionIDs(uint32_t* pRenderPosePredictionID, uint32_t* pGamePosePredictionID)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPosePredictionIDs(pRenderPosePredictionID, pGamePosePredictionID);
}

EVRCompositorError __stdcall fntable_Compositor_026_impl_GetPosesForFrame(uint32_t unPosePredictionID, VR_ARRAY_COUNT(unPoseArrayCount) TrackedDevicePose_t* pPoseArray, uint32_t unPoseArrayCount)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetPosesForFrame(unPosePredictionID, pPoseArray, unPoseArrayCount);
}

bool __stdcall fntable_Compositor_026_impl_GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	return static_cast<VirtualCompositor_026*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTiming(pTiming, unFramesAgo);
}

static void* fnTable_VirtualCompositor_026[] = {
	fntable_Compositor_026_impl_SetTrackingSpace,
	fntable_Compositor_026_impl_GetTrackingSpace,
	fntable_Compositor_026_impl_WaitGetPoses,
	fntable_Compositor_026_impl_GetLastPoses,
	fntable_Compositor_026_impl_GetLastPoseForTrackedDeviceIndex,
	fntable_Compositor_026_impl_Submit,
	fntable_Compositor_026_impl_ClearLastSubmittedFrame,
	fntable_Compositor_026_impl_PostPresentHandoff,
	fntable_Compositor_026_impl_GetFrameTiming,
	fntable_Compositor_026_impl_GetFrameTimings,
	fntable_Compositor_026_impl_GetFrameTimeRemaining,
	fntable_Compositor_026_impl_GetCumulativeStats,
	fntable_Compositor_026_impl_FadeToColor,
	fntable_Compositor_026_impl_GetCurrentFadeColor,
	fntable_Compositor_026_impl_FadeGrid,
	fntable_Compositor_026_impl_GetCurrentGridAlpha,
	fntable_Compositor_026_impl_SetSkyboxOverride,
	fntable_Compositor_026_impl_ClearSkyboxOverride,
	fntable_Compositor_026_impl_CompositorBringToFront,
	fntable_Compositor_026_impl_CompositorGoToBack,
	fntable_Compositor_026_impl_CompositorQuit,
	fntable_Compositor_026_impl_IsFullscreen,
	fntable_Compositor_026_impl_GetCurrentSceneFocusProcess,
	fntable_Compositor_026_impl_GetLastFrameRenderer,
	fntable_Compositor_026_impl_CanRenderScene,
	fntable_Compositor_026_impl_ShowMirrorWindow,
	fntable_Compositor_026_impl_HideMirrorWindow,
	fntable_Compositor_026_impl_IsMirrorWindowVisible,
	fntable_Compositor_026_impl_CompositorDumpImages,
	fntable_Compositor_026_impl_ShouldAppRenderWithLowResources,
	fntable_Compositor_026_impl_ForceInterleavedReprojectionOn,
	fntable_Compositor_026_impl_ForceReconnectProcess,
	fntable_Compositor_026_impl_SuspendRendering,
	fntable_Compositor_026_impl_GetMirrorTextureD3D11,
	fntable_Compositor_026_impl_ReleaseMirrorTextureD3D11,
	fntable_Compositor_026_impl_GetMirrorTextureGL,
	fntable_Compositor_026_impl_ReleaseSharedGLTexture,
	fntable_Compositor_026_impl_LockGLSharedTextureForAccess,
	fntable_Compositor_026_impl_UnlockGLSharedTextureForAccess,
	fntable_Compositor_026_impl_GetVulkanInstanceExtensionsRequired,
	fntable_Compositor_026_impl_GetVulkanDeviceExtensionsRequired,
	fntable_Compositor_026_impl_SetExplicitTimingMode,
	fntable_Compositor_026_impl_SubmitExplicitTimingData,
	fntable_Compositor_026_impl_IsMotionSmoothingEnabled,
	fntable_Compositor_026_impl_IsMotionSmoothingSupported,
	fntable_Compositor_026_impl_IsCurrentSceneFocusAppLoading,
	fntable_Compositor_026_impl_SetStageOverride_Async,
	fntable_Compositor_026_impl_ClearStageOverride,
	fntable_Compositor_026_impl_GetCompositorBenchmarkResults,
	fntable_Compositor_026_impl_GetLastPosePredictionIDs,
	fntable_Compositor_026_impl_GetPosesForFrame,
};

void* VirtualCompositor_026::GetFnTable()
{
	return fnTable_VirtualCompositor_026;
}
