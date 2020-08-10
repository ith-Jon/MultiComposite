#include "VirtualCompositor_019.h"
#include "VRClient.h"

void VirtualCompositor_019::SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	VRClient::cInstance->vCompositor->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin VirtualCompositor_019::GetTrackingSpace()
{
	return VRClient::cInstance->vCompositor->GetTrackingSpace();
}

EVRCompositorError VirtualCompositor_019::WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return VRClient::cInstance->vCompositor->WaitGetPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor_019::GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return VRClient::cInstance->vCompositor->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor_019::GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	return VRClient::cInstance->vCompositor->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError VirtualCompositor_019::Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	return VRClient::cInstance->vCompositor->Submit(eEye, pTexture, pBounds, nSubmitFlags);
}

void VirtualCompositor_019::ClearLastSubmittedFrame()
{
	VRClient::cInstance->vCompositor->ClearLastSubmittedFrame();
}

void VirtualCompositor_019::PostPresentHandoff()
{
	VRClient::cInstance->vCompositor->PostPresentHandoff();
}

uint32_t VirtualCompositor_019::GetFrameTimings(VR_ARRAY_COUNT(nFrames) Compositor_FrameTiming* pTiming, uint32_t nFrames)
{
	return VRClient::cInstance->vCompositor->GetFrameTimings(pTiming, nFrames);
}

float VirtualCompositor_019::GetFrameTimeRemaining()
{
	return VRClient::cInstance->vCompositor->GetFrameTimeRemaining();
}

void VirtualCompositor_019::GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes)
{
	VRClient::cInstance->vCompositor->GetCumulativeStats(pStats, nStatsSizeInBytes);
}

void VirtualCompositor_019::FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	VRClient::cInstance->vCompositor->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

vr::HmdColor_t VirtualCompositor_019::GetCurrentFadeColor(bool bBackground)
{
	return VRClient::cInstance->vCompositor->GetCurrentFadeColor(bBackground);;
}

void VirtualCompositor_019::FadeGrid(float fSeconds, bool bFadeIn)
{
	VRClient::cInstance->vCompositor->FadeGrid(fSeconds, bFadeIn);
}

float VirtualCompositor_019::GetCurrentGridAlpha()
{
	return VRClient::cInstance->vCompositor->GetCurrentGridAlpha();;
}

EVRCompositorError VirtualCompositor_019::SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	return VRClient::cInstance->vCompositor->SetSkyboxOverride(pTextures, unTextureCount);
}

void VirtualCompositor_019::ClearSkyboxOverride()
{
	VRClient::cInstance->vCompositor->ClearSkyboxOverride();
}

void VirtualCompositor_019::CompositorBringToFront()
{
	VRClient::cInstance->vCompositor->CompositorBringToFront();
}

void VirtualCompositor_019::CompositorGoToBack()
{
	VRClient::cInstance->vCompositor->CompositorGoToBack();
}

void VirtualCompositor_019::CompositorQuit()
{
	VRClient::cInstance->vCompositor->CompositorQuit();
}

bool VirtualCompositor_019::IsFullscreen()
{
	return VRClient::cInstance->vCompositor->IsFullscreen();
}

uint32_t VirtualCompositor_019::GetCurrentSceneFocusProcess()
{
	return VRClient::cInstance->vCompositor->GetCurrentSceneFocusProcess();
}

uint32_t VirtualCompositor_019::GetLastFrameRenderer()
{
	return VRClient::cInstance->vCompositor->GetLastFrameRenderer();
}

bool VirtualCompositor_019::CanRenderScene()
{
	return VRClient::cInstance->vCompositor->CanRenderScene();
}

void VirtualCompositor_019::ShowMirrorWindow()
{
	VRClient::cInstance->vCompositor->ShowMirrorWindow();
}

void VirtualCompositor_019::HideMirrorWindow()
{
	VRClient::cInstance->vCompositor->HideMirrorWindow();
}

bool VirtualCompositor_019::IsMirrorWindowVisible()
{
	return VRClient::cInstance->vCompositor->IsMirrorWindowVisible();
}

void VirtualCompositor_019::CompositorDumpImages()
{
	VRClient::cInstance->vCompositor->CompositorDumpImages();
}

bool VirtualCompositor_019::ShouldAppRenderWithLowResources()
{
	return VRClient::cInstance->vCompositor->ShouldAppRenderWithLowResources();
}

void VirtualCompositor_019::ForceInterleavedReprojectionOn(bool bOverride)
{
	VRClient::cInstance->vCompositor->ForceInterleavedReprojectionOn(bOverride);
}

void VirtualCompositor_019::ForceReconnectProcess()
{
	VRClient::cInstance->vCompositor->ForceReconnectProcess();
}

void VirtualCompositor_019::SuspendRendering(bool bSuspend)
{
	VRClient::cInstance->vCompositor->SuspendRendering(bSuspend);
}

EVRCompositorError VirtualCompositor_019::GetMirrorTextureD3D11(vr::EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView)
{
	return VRClient::cInstance->vCompositor->GetMirrorTextureD3D11(eEye, pD3D11DeviceOrResource, ppD3D11ShaderResourceView);
}

EVRCompositorError VirtualCompositor_019::GetMirrorTextureGL(vr::EVREye eEye, vr::glUInt_t* pglTextureId, vr::glSharedTextureHandle_t* pglSharedTextureHandle)
{
	return VRClient::cInstance->vCompositor->GetMirrorTextureGL(eEye, pglTextureId, pglSharedTextureHandle);
}

bool VirtualCompositor_019::ReleaseSharedGLTexture(vr::glUInt_t glTextureId, vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	return VRClient::cInstance->vCompositor->ReleaseSharedGLTexture(glTextureId, glSharedTextureHandle);
}

void VirtualCompositor_019::LockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	VRClient::cInstance->vCompositor->LockGLSharedTextureForAccess(glSharedTextureHandle);
}

void VirtualCompositor_019::UnlockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	VRClient::cInstance->vCompositor->UnlockGLSharedTextureForAccess(glSharedTextureHandle);
}

uint32_t VirtualCompositor_019::GetVulkanInstanceExtensionsRequired(char* pchValue, uint32_t unBufferSize)
{
	return VRClient::cInstance->vCompositor->GetVulkanInstanceExtensionsRequired(pchValue, unBufferSize);
}

uint32_t VirtualCompositor_019::GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, char* pchValue, uint32_t unBufferSize)
{
	return VRClient::cInstance->vCompositor->GetVulkanDeviceExtensionsRequired(pPhysicalDevice, pchValue, unBufferSize);
}

bool VirtualCompositor_019::GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	return VRClient::cInstance->vCompositor->GetFrameTiming(pTiming, unFramesAgo);
}

/**			Fn Table			*/

void __stdcall fntable_Compositor_019_impl_SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin __stdcall fntable_Compositor_019_impl_GetTrackingSpace()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetTrackingSpace();
}

EVRCompositorError __stdcall fntable_Compositor_019_impl_WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->WaitGetPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError __stdcall fntable_Compositor_019_impl_GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError __stdcall fntable_Compositor_019_impl_GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError __stdcall fntable_Compositor_019_impl_Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->Submit(eEye, pTexture, pBounds, nSubmitFlags);
}

void __stdcall fntable_Compositor_019_impl_ClearLastSubmittedFrame()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearLastSubmittedFrame();
}

void __stdcall fntable_Compositor_019_impl_PostPresentHandoff()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->PostPresentHandoff();
}

uint32_t __stdcall fntable_Compositor_019_impl_GetFrameTimings(VR_ARRAY_COUNT(nFrames) Compositor_FrameTiming* pTiming, uint32_t nFrames)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTimings(pTiming, nFrames);
}

float __stdcall fntable_Compositor_019_impl_GetFrameTimeRemaining()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTimeRemaining();
}

void __stdcall fntable_Compositor_019_impl_GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes)
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCumulativeStats(pStats, nStatsSizeInBytes);
}

void __stdcall fntable_Compositor_019_impl_FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

vr::HmdColor_t __stdcall fntable_Compositor_019_impl_GetCurrentFadeColor(bool bBackground)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCurrentFadeColor(bBackground);;
}

void __stdcall fntable_Compositor_019_impl_FadeGrid(float fSeconds, bool bFadeIn)
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->FadeGrid(fSeconds, bFadeIn);
}

float __stdcall fntable_Compositor_019_impl_GetCurrentGridAlpha()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCurrentGridAlpha();;
}

EVRCompositorError __stdcall fntable_Compositor_019_impl_SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetSkyboxOverride(pTextures, unTextureCount);
}

void __stdcall fntable_Compositor_019_impl_ClearSkyboxOverride()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearSkyboxOverride();
}

void __stdcall fntable_Compositor_019_impl_CompositorBringToFront()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorBringToFront();
}

void __stdcall fntable_Compositor_019_impl_CompositorGoToBack()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorGoToBack();
}

void __stdcall fntable_Compositor_019_impl_CompositorQuit()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorQuit();
}

bool __stdcall fntable_Compositor_019_impl_IsFullscreen()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsFullscreen();
}

uint32_t __stdcall fntable_Compositor_019_impl_GetCurrentSceneFocusProcess()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCurrentSceneFocusProcess();
}

uint32_t __stdcall fntable_Compositor_019_impl_GetLastFrameRenderer()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastFrameRenderer();
}

bool __stdcall fntable_Compositor_019_impl_CanRenderScene()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->CanRenderScene();
}

void __stdcall fntable_Compositor_019_impl_ShowMirrorWindow()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->ShowMirrorWindow();
}

void __stdcall fntable_Compositor_019_impl_HideMirrorWindow()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->HideMirrorWindow();
}

bool __stdcall fntable_Compositor_019_impl_IsMirrorWindowVisible()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsMirrorWindowVisible();
}

void __stdcall fntable_Compositor_019_impl_CompositorDumpImages()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorDumpImages();
}

bool __stdcall fntable_Compositor_019_impl_ShouldAppRenderWithLowResources()
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->ShouldAppRenderWithLowResources();
}

void __stdcall fntable_Compositor_019_impl_ForceInterleavedReprojectionOn(bool bOverride)
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->ForceInterleavedReprojectionOn(bOverride);
}

void __stdcall fntable_Compositor_019_impl_ForceReconnectProcess()
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->ForceReconnectProcess();
}

void __stdcall fntable_Compositor_019_impl_SuspendRendering(bool bSuspend)
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->SuspendRendering(bSuspend);
}

EVRCompositorError __stdcall fntable_Compositor_019_impl_GetMirrorTextureD3D11(vr::EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetMirrorTextureD3D11(eEye, pD3D11DeviceOrResource, ppD3D11ShaderResourceView);
}

EVRCompositorError __stdcall fntable_Compositor_019_impl_GetMirrorTextureGL(vr::EVREye eEye, vr::glUInt_t* pglTextureId, vr::glSharedTextureHandle_t* pglSharedTextureHandle)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetMirrorTextureGL(eEye, pglTextureId, pglSharedTextureHandle);
}

bool __stdcall fntable_Compositor_019_impl_ReleaseSharedGLTexture(vr::glUInt_t glTextureId, vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->ReleaseSharedGLTexture(glTextureId, glSharedTextureHandle);
}

void __stdcall fntable_Compositor_019_impl_LockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->LockGLSharedTextureForAccess(glSharedTextureHandle);
}

void __stdcall fntable_Compositor_019_impl_UnlockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->UnlockGLSharedTextureForAccess(glSharedTextureHandle);
}

uint32_t __stdcall fntable_Compositor_019_impl_GetVulkanInstanceExtensionsRequired(char* pchValue, uint32_t unBufferSize)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetVulkanInstanceExtensionsRequired(pchValue, unBufferSize);
}

uint32_t __stdcall fntable_Compositor_019_impl_GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, char* pchValue, uint32_t unBufferSize)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetVulkanDeviceExtensionsRequired(pPhysicalDevice, pchValue, unBufferSize);
}

bool __stdcall fntable_Compositor_019_impl_GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	return static_cast<VirtualCompositor_019*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTiming(pTiming, unFramesAgo);
}

static void* fnTable_VirtualCompositor_019[] = {
	fntable_Compositor_019_impl_SetTrackingSpace,
	fntable_Compositor_019_impl_GetTrackingSpace,
	fntable_Compositor_019_impl_WaitGetPoses,
	fntable_Compositor_019_impl_GetLastPoses,
	fntable_Compositor_019_impl_GetLastPoseForTrackedDeviceIndex,
	fntable_Compositor_019_impl_Submit,
	fntable_Compositor_019_impl_ClearLastSubmittedFrame,
	fntable_Compositor_019_impl_PostPresentHandoff,
	fntable_Compositor_019_impl_GetFrameTiming,
	fntable_Compositor_019_impl_GetFrameTimings,
	fntable_Compositor_019_impl_GetFrameTimeRemaining,
	fntable_Compositor_019_impl_GetCumulativeStats,
	fntable_Compositor_019_impl_FadeToColor,
	fntable_Compositor_019_impl_GetCurrentFadeColor,
	fntable_Compositor_019_impl_FadeGrid,
	fntable_Compositor_019_impl_GetCurrentGridAlpha,
	fntable_Compositor_019_impl_SetSkyboxOverride,
	fntable_Compositor_019_impl_ClearSkyboxOverride,
	fntable_Compositor_019_impl_CompositorBringToFront,
	fntable_Compositor_019_impl_CompositorGoToBack,
	fntable_Compositor_019_impl_CompositorQuit,
	fntable_Compositor_019_impl_IsFullscreen,
	fntable_Compositor_019_impl_GetCurrentSceneFocusProcess,
	fntable_Compositor_019_impl_GetLastFrameRenderer,
	fntable_Compositor_019_impl_CanRenderScene,
	fntable_Compositor_019_impl_ShowMirrorWindow,
	fntable_Compositor_019_impl_HideMirrorWindow,
	fntable_Compositor_019_impl_IsMirrorWindowVisible,
	fntable_Compositor_019_impl_CompositorDumpImages,
	fntable_Compositor_019_impl_ShouldAppRenderWithLowResources,
	fntable_Compositor_019_impl_ForceInterleavedReprojectionOn,
	fntable_Compositor_019_impl_ForceReconnectProcess,
	fntable_Compositor_019_impl_SuspendRendering,
	fntable_Compositor_019_impl_GetMirrorTextureD3D11,
	fntable_Compositor_019_impl_GetMirrorTextureGL,
	fntable_Compositor_019_impl_ReleaseSharedGLTexture,
	fntable_Compositor_019_impl_LockGLSharedTextureForAccess,
	fntable_Compositor_019_impl_UnlockGLSharedTextureForAccess,
	fntable_Compositor_019_impl_GetVulkanInstanceExtensionsRequired,
	fntable_Compositor_019_impl_GetVulkanDeviceExtensionsRequired,
};

void* VirtualCompositor_019::GetFnTable()
{
	return fnTable_VirtualCompositor_019;
}
