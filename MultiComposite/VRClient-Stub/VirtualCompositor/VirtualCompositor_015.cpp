#include "VirtualCompositor_015.h"
#include "VRClient.h"

void VirtualCompositor_015::SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	VRClient::cInstance->vCompositor->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin VirtualCompositor_015::GetTrackingSpace()
{
	return VRClient::cInstance->vCompositor->GetTrackingSpace();
}

EVRCompositorError VirtualCompositor_015::WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount)TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount)TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return VRClient::cInstance->vCompositor->WaitGetPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor_015::GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount)TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount)TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return VRClient::cInstance->vCompositor->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor_015::GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	return VRClient::cInstance->vCompositor->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError VirtualCompositor_015::Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	return VRClient::cInstance->vCompositor->Submit(eEye, pTexture, pBounds, nSubmitFlags);
}

void VirtualCompositor_015::ClearLastSubmittedFrame()
{
	VRClient::cInstance->vCompositor->ClearLastSubmittedFrame();
}

void VirtualCompositor_015::PostPresentHandoff()
{
	VRClient::cInstance->vCompositor->PostPresentHandoff();
}

float VirtualCompositor_015::GetFrameTimeRemaining()
{
	return VRClient::cInstance->vCompositor->GetFrameTimeRemaining();
}

void VirtualCompositor_015::GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes)
{
	VRClient::cInstance->vCompositor->GetCumulativeStats(pStats, nStatsSizeInBytes);
}

void VirtualCompositor_015::FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	VRClient::cInstance->vCompositor->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

void VirtualCompositor_015::FadeGrid(float fSeconds, bool bFadeIn)
{
	VRClient::cInstance->vCompositor->FadeGrid(fSeconds, bFadeIn);
}

EVRCompositorError VirtualCompositor_015::SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	return VRClient::cInstance->vCompositor->SetSkyboxOverride(pTextures, unTextureCount);
}

void VirtualCompositor_015::ClearSkyboxOverride()
{
	VRClient::cInstance->vCompositor->ClearSkyboxOverride();
}

void VirtualCompositor_015::CompositorBringToFront()
{
	VRClient::cInstance->vCompositor->CompositorBringToFront();
}

void VirtualCompositor_015::CompositorGoToBack()
{
	VRClient::cInstance->vCompositor->CompositorGoToBack();
}

void VirtualCompositor_015::CompositorQuit()
{
	VRClient::cInstance->vCompositor->CompositorQuit();
}

bool VirtualCompositor_015::IsFullscreen()
{
	return VRClient::cInstance->vCompositor->IsFullscreen();
}

uint32_t VirtualCompositor_015::GetCurrentSceneFocusProcess()
{
	return VRClient::cInstance->vCompositor->GetCurrentSceneFocusProcess();
}

uint32_t VirtualCompositor_015::GetLastFrameRenderer()
{
	return VRClient::cInstance->vCompositor->GetLastFrameRenderer();
}

bool VirtualCompositor_015::CanRenderScene()
{
	return VRClient::cInstance->vCompositor->CanRenderScene();
}

void VirtualCompositor_015::ShowMirrorWindow()
{
	VRClient::cInstance->vCompositor->ShowMirrorWindow();
}

void VirtualCompositor_015::HideMirrorWindow()
{
	VRClient::cInstance->vCompositor->HideMirrorWindow();
}

bool VirtualCompositor_015::IsMirrorWindowVisible()
{
	return VRClient::cInstance->vCompositor->IsMirrorWindowVisible();
}

void VirtualCompositor_015::CompositorDumpImages()
{
	VRClient::cInstance->vCompositor->CompositorDumpImages();
}

bool VirtualCompositor_015::ShouldAppRenderWithLowResources()
{
	return VRClient::cInstance->vCompositor->ShouldAppRenderWithLowResources();
}

void VirtualCompositor_015::ForceInterleavedReprojectionOn(bool bOverride)
{
	VRClient::cInstance->vCompositor->ForceInterleavedReprojectionOn(bOverride);
}

void VirtualCompositor_015::ForceReconnectProcess()
{
	VRClient::cInstance->vCompositor->ForceReconnectProcess();
}

void VirtualCompositor_015::SuspendRendering(bool bSuspend)
{
	VRClient::cInstance->vCompositor->SuspendRendering(bSuspend);
}

EVRCompositorError VirtualCompositor_015::RequestScreenshot(EVRScreenshotType type, const char* pchDestinationFileName, const char* pchVRDestinationFileName)
{
	return VRCompositorError_RequestFailed;
}

EVRScreenshotType VirtualCompositor_015::GetCurrentScreenshotType()
{
	return VRScreenshotType_None;
}

EVRCompositorError VirtualCompositor_015::GetMirrorTextureD3D11(vr::EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView)
{
	return VRClient::cInstance->vCompositor->GetMirrorTextureD3D11(eEye, pD3D11DeviceOrResource, ppD3D11ShaderResourceView);
}

EVRCompositorError VirtualCompositor_015::GetMirrorTextureGL(vr::EVREye eEye, vr::glUInt_t* pglTextureId, vr::glSharedTextureHandle_t* pglSharedTextureHandle)
{
	return VRClient::cInstance->vCompositor->GetMirrorTextureGL(eEye, pglTextureId, pglSharedTextureHandle);
}

bool VirtualCompositor_015::ReleaseSharedGLTexture(vr::glUInt_t glTextureId, vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	return VRClient::cInstance->vCompositor->ReleaseSharedGLTexture(glTextureId, glSharedTextureHandle);
}

void VirtualCompositor_015::LockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	VRClient::cInstance->vCompositor->LockGLSharedTextureForAccess(glSharedTextureHandle);
}

void VirtualCompositor_015::UnlockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	VRClient::cInstance->vCompositor->UnlockGLSharedTextureForAccess(glSharedTextureHandle);
}

bool VirtualCompositor_015::GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	return VRClient::cInstance->vCompositor->GetFrameTiming(pTiming, unFramesAgo);
}

/**			Fn Table			*/

void __stdcall fntable_Compositor_015_impl_SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin __stdcall fntable_Compositor_015_impl_GetTrackingSpace()
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetTrackingSpace();
}

EVRCompositorError __stdcall fntable_Compositor_015_impl_WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount)TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount)TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->WaitGetPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError __stdcall fntable_Compositor_015_impl_GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount)TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount)TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError __stdcall fntable_Compositor_015_impl_GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError __stdcall fntable_Compositor_015_impl_Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->Submit(eEye, pTexture, pBounds, nSubmitFlags);
}

void __stdcall fntable_Compositor_015_impl_ClearLastSubmittedFrame()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearLastSubmittedFrame();
}

void __stdcall fntable_Compositor_015_impl_PostPresentHandoff()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->PostPresentHandoff();
}

float __stdcall fntable_Compositor_015_impl_GetFrameTimeRemaining()
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTimeRemaining();
}

void __stdcall fntable_Compositor_015_impl_GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes)
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCumulativeStats(pStats, nStatsSizeInBytes);
}

void __stdcall fntable_Compositor_015_impl_FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

void __stdcall fntable_Compositor_015_impl_FadeGrid(float fSeconds, bool bFadeIn)
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->FadeGrid(fSeconds, bFadeIn);
}

EVRCompositorError __stdcall fntable_Compositor_015_impl_SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetSkyboxOverride(pTextures, unTextureCount);
}

void __stdcall fntable_Compositor_015_impl_ClearSkyboxOverride()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearSkyboxOverride();
}

void __stdcall fntable_Compositor_015_impl_CompositorBringToFront()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorBringToFront();
}

void __stdcall fntable_Compositor_015_impl_CompositorGoToBack()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorGoToBack();
}

void __stdcall fntable_Compositor_015_impl_CompositorQuit()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorQuit();
}

bool __stdcall fntable_Compositor_015_impl_IsFullscreen()
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsFullscreen();
}

uint32_t __stdcall fntable_Compositor_015_impl_GetCurrentSceneFocusProcess()
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCurrentSceneFocusProcess();
}

uint32_t __stdcall fntable_Compositor_015_impl_GetLastFrameRenderer()
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastFrameRenderer();
}

bool __stdcall fntable_Compositor_015_impl_CanRenderScene()
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->CanRenderScene();
}

void __stdcall fntable_Compositor_015_impl_ShowMirrorWindow()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->ShowMirrorWindow();
}

void __stdcall fntable_Compositor_015_impl_HideMirrorWindow()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->HideMirrorWindow();
}

bool __stdcall fntable_Compositor_015_impl_IsMirrorWindowVisible()
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsMirrorWindowVisible();
}

void __stdcall fntable_Compositor_015_impl_CompositorDumpImages()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorDumpImages();
}

bool __stdcall fntable_Compositor_015_impl_ShouldAppRenderWithLowResources()
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->ShouldAppRenderWithLowResources();
}

void __stdcall fntable_Compositor_015_impl_ForceInterleavedReprojectionOn(bool bOverride)
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->ForceInterleavedReprojectionOn(bOverride);
}

void __stdcall fntable_Compositor_015_impl_ForceReconnectProcess()
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->ForceReconnectProcess();
}

void __stdcall fntable_Compositor_015_impl_SuspendRendering(bool bSuspend)
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->SuspendRendering(bSuspend);
}

EVRCompositorError __stdcall fntable_Compositor_015_impl_RequestScreenshot(EVRScreenshotType type, const char* pchDestinationFileName, const char* pchVRDestinationFileName)
{
	return VRCompositorError_RequestFailed;
}

EVRScreenshotType __stdcall fntable_Compositor_015_impl_GetCurrentScreenshotType()
{
	return VRScreenshotType_None;
}

EVRCompositorError __stdcall fntable_Compositor_015_impl_GetMirrorTextureD3D11(vr::EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetMirrorTextureD3D11(eEye, pD3D11DeviceOrResource, ppD3D11ShaderResourceView);
}

EVRCompositorError __stdcall fntable_Compositor_015_impl_GetMirrorTextureGL(vr::EVREye eEye, vr::glUInt_t* pglTextureId, vr::glSharedTextureHandle_t* pglSharedTextureHandle)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetMirrorTextureGL(eEye, pglTextureId, pglSharedTextureHandle);
}

bool __stdcall fntable_Compositor_015_impl_ReleaseSharedGLTexture(vr::glUInt_t glTextureId, vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->ReleaseSharedGLTexture(glTextureId, glSharedTextureHandle);
}

void __stdcall fntable_Compositor_015_impl_LockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->LockGLSharedTextureForAccess(glSharedTextureHandle);
}

void __stdcall fntable_Compositor_015_impl_UnlockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->UnlockGLSharedTextureForAccess(glSharedTextureHandle);
}

bool __stdcall fntable_Compositor_015_impl_GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	return static_cast<VirtualCompositor_015*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTiming(pTiming, unFramesAgo);
}

static void* fnTable_VirtualCompositor_015[] = {
	fntable_Compositor_015_impl_SetTrackingSpace,
	fntable_Compositor_015_impl_GetTrackingSpace,
	fntable_Compositor_015_impl_WaitGetPoses,
	fntable_Compositor_015_impl_GetLastPoses,
	fntable_Compositor_015_impl_GetLastPoseForTrackedDeviceIndex,
	fntable_Compositor_015_impl_Submit,
	fntable_Compositor_015_impl_ClearLastSubmittedFrame,
	fntable_Compositor_015_impl_PostPresentHandoff,
	fntable_Compositor_015_impl_GetFrameTiming,
	fntable_Compositor_015_impl_GetFrameTimeRemaining,
	fntable_Compositor_015_impl_GetCumulativeStats,
	fntable_Compositor_015_impl_FadeToColor,
	fntable_Compositor_015_impl_FadeGrid,
	fntable_Compositor_015_impl_SetSkyboxOverride,
	fntable_Compositor_015_impl_ClearSkyboxOverride,
	fntable_Compositor_015_impl_CompositorBringToFront,
	fntable_Compositor_015_impl_CompositorGoToBack,
	fntable_Compositor_015_impl_CompositorQuit,
	fntable_Compositor_015_impl_IsFullscreen,
	fntable_Compositor_015_impl_GetCurrentSceneFocusProcess,
	fntable_Compositor_015_impl_GetLastFrameRenderer,
	fntable_Compositor_015_impl_CanRenderScene,
	fntable_Compositor_015_impl_ShowMirrorWindow,
	fntable_Compositor_015_impl_HideMirrorWindow,
	fntable_Compositor_015_impl_IsMirrorWindowVisible,
	fntable_Compositor_015_impl_CompositorDumpImages,
	fntable_Compositor_015_impl_ShouldAppRenderWithLowResources,
	fntable_Compositor_015_impl_ForceInterleavedReprojectionOn,
	fntable_Compositor_015_impl_ForceReconnectProcess,
	fntable_Compositor_015_impl_SuspendRendering,
	fntable_Compositor_015_impl_RequestScreenshot,
	fntable_Compositor_015_impl_GetCurrentScreenshotType,
	fntable_Compositor_015_impl_GetMirrorTextureD3D11,
	fntable_Compositor_015_impl_GetMirrorTextureGL,
	fntable_Compositor_015_impl_ReleaseSharedGLTexture,
	fntable_Compositor_015_impl_LockGLSharedTextureForAccess,
	fntable_Compositor_015_impl_UnlockGLSharedTextureForAccess,
};

void* VirtualCompositor_015::GetFnTable()
{
	return fnTable_VirtualCompositor_015;
}
