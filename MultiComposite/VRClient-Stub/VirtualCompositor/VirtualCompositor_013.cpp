#include "VirtualCompositor_013.h"
#include "VRClient.h"

void VirtualCompositor_013::SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	VRClient::cInstance->vCompositor->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin VirtualCompositor_013::GetTrackingSpace()
{
	return VRClient::cInstance->vCompositor->GetTrackingSpace();
}

EVRCompositorError VirtualCompositor_013::WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return VRClient::cInstance->vCompositor->WaitGetPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor_013::GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return VRClient::cInstance->vCompositor->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor_013::GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	return VRClient::cInstance->vCompositor->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError VirtualCompositor_013::Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	return VRClient::cInstance->vCompositor->Submit(eEye, pTexture, pBounds, nSubmitFlags);
}

void VirtualCompositor_013::ClearLastSubmittedFrame()
{
	VRClient::cInstance->vCompositor->ClearLastSubmittedFrame();
}

void VirtualCompositor_013::PostPresentHandoff()
{
	VRClient::cInstance->vCompositor->PostPresentHandoff();
}

bool VirtualCompositor_013::GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	return VRClient::cInstance->vCompositor->GetFrameTiming(pTiming, unFramesAgo);
}

float VirtualCompositor_013::GetFrameTimeRemaining()
{
	return VRClient::cInstance->vCompositor->GetFrameTimeRemaining();
}

void VirtualCompositor_013::FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	VRClient::cInstance->vCompositor->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

void VirtualCompositor_013::FadeGrid(float fSeconds, bool bFadeIn)
{
	VRClient::cInstance->vCompositor->FadeGrid(fSeconds, bFadeIn);
}

EVRCompositorError VirtualCompositor_013::SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	return VRClient::cInstance->vCompositor->SetSkyboxOverride(pTextures, unTextureCount);
}

void VirtualCompositor_013::ClearSkyboxOverride()
{
	VRClient::cInstance->vCompositor->ClearSkyboxOverride();
}

void VirtualCompositor_013::CompositorBringToFront()
{
	VRClient::cInstance->vCompositor->CompositorBringToFront();
}

void VirtualCompositor_013::CompositorGoToBack()
{
	VRClient::cInstance->vCompositor->CompositorGoToBack();
}

void VirtualCompositor_013::CompositorQuit()
{
	VRClient::cInstance->vCompositor->CompositorQuit();
}

bool VirtualCompositor_013::IsFullscreen()
{
	return VRClient::cInstance->vCompositor->IsFullscreen();
}

uint32_t VirtualCompositor_013::GetCurrentSceneFocusProcess()
{
	return VRClient::cInstance->vCompositor->GetCurrentSceneFocusProcess();
}

uint32_t VirtualCompositor_013::GetLastFrameRenderer()
{
	return VRClient::cInstance->vCompositor->GetLastFrameRenderer();
}

bool VirtualCompositor_013::CanRenderScene()
{
	return VRClient::cInstance->vCompositor->CanRenderScene();
}

void VirtualCompositor_013::ShowMirrorWindow()
{
	VRClient::cInstance->vCompositor->ShowMirrorWindow();
}

void VirtualCompositor_013::HideMirrorWindow()
{
	VRClient::cInstance->vCompositor->HideMirrorWindow();
}

bool VirtualCompositor_013::IsMirrorWindowVisible()
{
	return VRClient::cInstance->vCompositor->IsMirrorWindowVisible();
}

void VirtualCompositor_013::CompositorDumpImages()
{
	VRClient::cInstance->vCompositor->CompositorDumpImages();
}

bool VirtualCompositor_013::ShouldAppRenderWithLowResources()
{
	return VRClient::cInstance->vCompositor->ShouldAppRenderWithLowResources();
}

void VirtualCompositor_013::ForceInterleavedReprojectionOn(bool bOverride)
{
	VRClient::cInstance->vCompositor->ForceInterleavedReprojectionOn(bOverride);
}

/**			Fn Table			*/

void __stdcall fntable_Compositor_013_impl_SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin __stdcall fntable_Compositor_013_impl_GetTrackingSpace()
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetTrackingSpace();
}

EVRCompositorError __stdcall fntable_Compositor_013_impl_WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->WaitGetPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError __stdcall fntable_Compositor_013_impl_GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError __stdcall fntable_Compositor_013_impl_GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError __stdcall fntable_Compositor_013_impl_Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->Submit(eEye, pTexture, pBounds, nSubmitFlags);
}

void __stdcall fntable_Compositor_013_impl_ClearLastSubmittedFrame()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearLastSubmittedFrame();
}

void __stdcall fntable_Compositor_013_impl_PostPresentHandoff()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->PostPresentHandoff();
}

bool __stdcall fntable_Compositor_013_impl_GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTiming(pTiming, unFramesAgo);
}

float __stdcall fntable_Compositor_013_impl_GetFrameTimeRemaining()
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetFrameTimeRemaining();
}

void __stdcall fntable_Compositor_013_impl_FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

void __stdcall fntable_Compositor_013_impl_FadeGrid(float fSeconds, bool bFadeIn)
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->FadeGrid(fSeconds, bFadeIn);
}

EVRCompositorError __stdcall fntable_Compositor_013_impl_SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->SetSkyboxOverride(pTextures, unTextureCount);
}

void __stdcall fntable_Compositor_013_impl_ClearSkyboxOverride()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->ClearSkyboxOverride();
}

void __stdcall fntable_Compositor_013_impl_CompositorBringToFront()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorBringToFront();
}

void __stdcall fntable_Compositor_013_impl_CompositorGoToBack()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorGoToBack();
}

void __stdcall fntable_Compositor_013_impl_CompositorQuit()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorQuit();
}

bool __stdcall fntable_Compositor_013_impl_IsFullscreen()
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsFullscreen();
}

uint32_t __stdcall fntable_Compositor_013_impl_GetCurrentSceneFocusProcess()
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetCurrentSceneFocusProcess();
}

uint32_t __stdcall fntable_Compositor_013_impl_GetLastFrameRenderer()
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->GetLastFrameRenderer();
}

bool __stdcall fntable_Compositor_013_impl_CanRenderScene()
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->CanRenderScene();
}

void __stdcall fntable_Compositor_013_impl_ShowMirrorWindow()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->ShowMirrorWindow();
}

void __stdcall fntable_Compositor_013_impl_HideMirrorWindow()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->HideMirrorWindow();
}

bool __stdcall fntable_Compositor_013_impl_IsMirrorWindowVisible()
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->IsMirrorWindowVisible();
}

void __stdcall fntable_Compositor_013_impl_CompositorDumpImages()
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->CompositorDumpImages();
}

bool __stdcall fntable_Compositor_013_impl_ShouldAppRenderWithLowResources()
{
	return static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->ShouldAppRenderWithLowResources();
}

void __stdcall fntable_Compositor_013_impl_ForceInterleavedReprojectionOn(bool bOverride)
{
	static_cast<VirtualCompositor_013*>(VRClient::cInstance->vCompositor->virtualCompositor)->ForceInterleavedReprojectionOn(bOverride);
}

static void* fnTable_VirtualCompositor_013[] = {
	fntable_Compositor_013_impl_SetTrackingSpace,
	fntable_Compositor_013_impl_GetTrackingSpace,
	fntable_Compositor_013_impl_WaitGetPoses,
	fntable_Compositor_013_impl_GetLastPoses,
	fntable_Compositor_013_impl_GetLastPoseForTrackedDeviceIndex,
	fntable_Compositor_013_impl_Submit,
	fntable_Compositor_013_impl_ClearLastSubmittedFrame,
	fntable_Compositor_013_impl_PostPresentHandoff,
	fntable_Compositor_013_impl_GetFrameTiming,
	fntable_Compositor_013_impl_GetFrameTimeRemaining,
	fntable_Compositor_013_impl_FadeToColor,
	fntable_Compositor_013_impl_FadeGrid,
	fntable_Compositor_013_impl_SetSkyboxOverride,
	fntable_Compositor_013_impl_ClearSkyboxOverride,
	fntable_Compositor_013_impl_CompositorBringToFront,
	fntable_Compositor_013_impl_CompositorGoToBack,
	fntable_Compositor_013_impl_CompositorQuit,
	fntable_Compositor_013_impl_IsFullscreen,
	fntable_Compositor_013_impl_GetCurrentSceneFocusProcess,
	fntable_Compositor_013_impl_GetLastFrameRenderer,
	fntable_Compositor_013_impl_CanRenderScene,
	fntable_Compositor_013_impl_ShowMirrorWindow,
	fntable_Compositor_013_impl_HideMirrorWindow,
	fntable_Compositor_013_impl_IsMirrorWindowVisible,
	fntable_Compositor_013_impl_CompositorDumpImages,
	fntable_Compositor_013_impl_ShouldAppRenderWithLowResources,
	fntable_Compositor_013_impl_ForceInterleavedReprojectionOn,
};

void* VirtualCompositor_013::GetFnTable()
{
	return fnTable_VirtualCompositor_013;
}
