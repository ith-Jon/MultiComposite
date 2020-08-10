#include "VirtualCompositor.h"
#include "VRClient.h"

#include <d3d11.h>

#include "Logger.h"

void VirtualCompositor::SetTrackingSpace(vr::ETrackingUniverseOrigin eOrigin)
{
	//dlog::Println("[VirtualCompositor::SetTrackingSpace] Called.");

	VRClient::cInstance->pRuntime->setTrackingOrigin = eOrigin;

	//VRClient::cInstance->pRuntime->setTrackingSpace = true;
	//while (VRClient::cInstance->pRuntime->setTrackingSpace);

	//static_cast<IVRCompositor_026*>(steamCompositor)->SetTrackingSpace(eOrigin);
}

vr::ETrackingUniverseOrigin VirtualCompositor::GetTrackingSpace()
{
	//dlog::Println("[VirtualCompositor::GetTrackingSpace] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetTrackingSpace();
}

EVRCompositorError VirtualCompositor::WaitGetPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	//dlog::Println("[VirtualCompositor::WaitGetPoses] Called.");

	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
	{
		return VRCompositorError_None;
	}
	else if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_Renders) != ApplicationPermissions_Renders)
	{
		return GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
	}

	if (VRClient::cInstance->sState.GetWritableSharedState()->renderPoses.count != unRenderPoseArrayCount)
	{
		VRClient::cInstance->sState.GetWritableSharedState()->renderPoses.count = unRenderPoseArrayCount;
	}

	if (VRClient::cInstance->sState.GetWritableSharedState()->gamePoses.count != unGamePoseArrayCount)
	{
		VRClient::cInstance->sState.GetWritableSharedState()->gamePoses.count = unGamePoseArrayCount;
	}

	while (!VRClient::cInstance->sState.GetWritableSharedState()->waitGetPoses);
	VRClient::cInstance->sState.GetWritableSharedState()->waitGetPoses = false;

	TrackedDevicePose_t* gamePoses = VRClient::cInstance->sState.GetWritableSharedState()->gamePoses.devices;
	TrackedDevicePose_t* renderPoses = VRClient::cInstance->sState.GetWritableSharedState()->renderPoses.devices;

	for (int i = 0; i < unRenderPoseArrayCount || i < VRClient::cInstance->sState.GetWritableSharedState()->renderPoses.count; i++)
	{
		pRenderPoseArray[i] = renderPoses[i];
	}

	for (int i = 0; i < unGamePoseArrayCount || i < VRClient::cInstance->sState.GetWritableSharedState()->gamePoses.count; i++)
	{
		pGamePoseArray[i] = gamePoses[i];
	}

	return VRCompositorError_None;
}

EVRCompositorError VirtualCompositor::GetLastPoses(VR_ARRAY_COUNT(unRenderPoseArrayCount) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount, VR_ARRAY_COUNT(unGamePoseArrayCount) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
		return VRCompositorError_None;

	//dlog::Println("[VirtualCompositor::GetLastPoses] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetLastPoses(pRenderPoseArray, unRenderPoseArrayCount, pGamePoseArray, unGamePoseArrayCount);
}

EVRCompositorError VirtualCompositor::GetLastPoseForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex, vr::TrackedDevicePose_t* pOutputPose, vr::TrackedDevicePose_t* pOutputGamePose)
{
	//dlog::Println("[VirtualCompositor::GetLastPoseForTrackedDeviceIndex] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetLastPoseForTrackedDeviceIndex(unDeviceIndex, pOutputPose, pOutputGamePose);
}

EVRCompositorError VirtualCompositor::Submit(vr::EVREye eEye, const vr::Texture_t* pTexture, const vr::VRTextureBounds_t* pBounds, vr::EVRSubmitFlags nSubmitFlags)
{
	//dlog::Println("[VirtualCompositor::Submit] Called.");

	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_Renders) != ApplicationPermissions_Renders)
		return VRCompositorError_None;

	VREyeFrame_t* rFrame = eEye == Eye_Left ? &VRClient::cInstance->sState.GetWritableSharedState()->eyeFrames[0] : &VRClient::cInstance->sState.GetWritableSharedState()->eyeFrames[1];
	VREyeFrame_t* lFrame = eEye == Eye_Left ? &VRClient::cInstance->pRuntime->eyeFrames[0] : &VRClient::cInstance->pRuntime->eyeFrames[1];;

	if (pTexture->eType == TextureType_DirectX)
	{
		ID3D11Texture2D* tex2D = static_cast<ID3D11Texture2D*>(pTexture->handle);

		ID3D11Device* device;
		tex2D->GetDevice(&device);

		ID3D11DeviceContext* context;
		device->GetImmediateContext(&context);

		ID3D11Texture2D* rTex2D = eEye == Eye_Left ? (ID3D11Texture2D*)VRClient::cInstance->vCompositor->leftEye : (ID3D11Texture2D*)VRClient::cInstance->vCompositor->rightEye;

		if (rTex2D == nullptr && lFrame->setup)
		{
			//dlog::Println("FUCK");
			return VRCompositorError_None;
		}

		// If the frame isn't set up to be shared we need to do so
		if (!lFrame->setup)
		{
			dlog::Println("[Runtime " + std::to_string(VRClient::cInstance->pRuntime->id) + "] Setting up Eye...");

			if (!rFrame->setup)
			{
				dlog::Println("[Runtime " + std::to_string(VRClient::cInstance->pRuntime->id) + "] Setting up Remote Eye...");
				D3D11_TEXTURE2D_DESC rTex2DDesc;
				tex2D->GetDesc(&rTex2DDesc);
				rTex2DDesc.MiscFlags |= D3D11_RESOURCE_MISC_SHARED;
				rTex2DDesc.BindFlags = 0;

				device->CreateTexture2D(&rTex2DDesc, NULL, &rTex2D);

				if (eEye == Eye_Left)
					VRClient::cInstance->vCompositor->leftEye = rTex2D;
				if (eEye == Eye_Right)
					VRClient::cInstance->vCompositor->rightEye = rTex2D;

				IDXGIResource* pDXGITex2D;
				rTex2D->QueryInterface(__uuidof(IDXGIResource), (void**)&pDXGITex2D);

				HANDLE rTex2DHandle;
				pDXGITex2D->GetSharedHandle(&rTex2DHandle);

				rFrame->pTexture.handle = rTex2DHandle;
				
				pDXGITex2D->Release();
				rFrame->setup = true;
				lFrame->setup = true;
			}
			else
			{
				dlog::Println("[Runtime " + std::to_string(VRClient::cInstance->pRuntime->id) + "] Setting up Local Eye...");

				device->OpenSharedResource(rFrame->pTexture.handle, __uuidof(ID3D11Texture2D), (void**)&rTex2D);

				if (eEye == Eye_Left)
					VRClient::cInstance->vCompositor->leftEye = rTex2D;
				if (eEye == Eye_Right)
					VRClient::cInstance->vCompositor->rightEye = rTex2D;

				lFrame->setup = true;
			}
		}

		//dlog::Println("Copying Frame...");
		// Copy the frame to the shared texture
		context->CopyResource(rTex2D, tex2D);
		context->Flush();

		//tex2D->Release();
		device->Release();
		context->Release();
	}

	rFrame->eEye = eEye;
	rFrame->pTexture.eColorSpace = pTexture->eColorSpace;
	rFrame->pTexture.eType = pTexture->eType;
	//frame->pTexture.handle = pTexture->handle; Done above
	rFrame->pBounds = *pBounds;
	rFrame->nSubmitFlags = nSubmitFlags;

	rFrame->submitted = true;

	return VRCompositorError_None;
}

void VirtualCompositor::ClearLastSubmittedFrame()
{
	dlog::Println("[VirtualCompositor::ClearLastSubmittedFrame] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->ClearLastSubmittedFrame();
}

void VirtualCompositor::PostPresentHandoff()
{
	//dlog::Println("[VirtualCompositor::PostPresentHandoff] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->PostPresentHandoff();
}

uint32_t VirtualCompositor::GetFrameTimings(Compositor_FrameTiming* pTiming, uint32_t nFrames)
{
	//dlog::Println("[VirtualCompositor::GetFrameTimings] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetFrameTimings(pTiming, nFrames);
}

float VirtualCompositor::GetFrameTimeRemaining()
{
	//dlog::Println("[VirtualCompositor::GetFrameTimeRemaining] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetFrameTimeRemaining();
}

void VirtualCompositor::GetCumulativeStats(Compositor_CumulativeStats* pStats, uint32_t nStatsSizeInBytes)
{
	//dlog::Println("[VirtualCompositor::GetCumulativeStats] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->GetCumulativeStats(pStats, nStatsSizeInBytes);
}

void VirtualCompositor::FadeToColor(float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground)
{
	//dlog::Println("[VirtualCompositor::FadeToColor] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->FadeToColor(fSeconds, fRed, fGreen, fBlue, fAlpha, bBackground);
}

vr::HmdColor_t VirtualCompositor::GetCurrentFadeColor(bool bBackground)
{
	//dlog::Println("[VirtualCompositor::GetCurrentFadeColor] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetCurrentFadeColor(bBackground);;
}

void VirtualCompositor::FadeGrid(float fSeconds, bool bFadeIn)
{
	//dlog::Println("[VirtualCompositor::FadeGrid] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->FadeGrid(fSeconds, bFadeIn);
}

float VirtualCompositor::GetCurrentGridAlpha()
{
	//dlog::Println("[VirtualCompositor::GetCurrentGridAlpha] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetCurrentGridAlpha();;
}

EVRCompositorError VirtualCompositor::SetSkyboxOverride(VR_ARRAY_COUNT(unTextureCount) const Texture_t* pTextures, uint32_t unTextureCount)
{
	//dlog::Println("[VirtualCompositor::SetSkyboxOverride] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->SetSkyboxOverride(pTextures, unTextureCount);
}

void VirtualCompositor::ClearSkyboxOverride()
{
	//dlog::Println("[VirtualCompositor::ClearSkyboxOverride] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->ClearSkyboxOverride();
}

void VirtualCompositor::CompositorBringToFront()
{
	//dlog::Println("[VirtualCompositor::CompositorBringToFront] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->CompositorBringToFront();
}

void VirtualCompositor::CompositorGoToBack()
{
	//dlog::Println("[VirtualCompositor::CompositorGoToBack] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->CompositorGoToBack();
}

void VirtualCompositor::CompositorQuit()
{
	//dlog::Println("[VirtualCompositor::CompositorQuit] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->CompositorQuit();
}

bool VirtualCompositor::IsFullscreen()
{
	//dlog::Println("[VirtualCompositor::IsFullscreen] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->IsFullscreen();
}

uint32_t VirtualCompositor::GetCurrentSceneFocusProcess()
{
	//dlog::Println("[VirtualCompositor::GetCurrentSceneFocusProcess] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetCurrentSceneFocusProcess();
}

uint32_t VirtualCompositor::GetLastFrameRenderer()
{
	//dlog::Println("[VirtualCompositor::GetLastFrameRenderer] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetLastFrameRenderer();
}

bool VirtualCompositor::CanRenderScene()
{
	//dlog::Println("[VirtualCompositor::CanRenderScene] Called.");
	return VRClient::cInstance->applicationType == VRApplication_Scene; //static_cast<IVRCompositor_026*>(steamCompositor)->CanRenderScene();
}

void VirtualCompositor::ShowMirrorWindow()
{
	//dlog::Println("[VirtualCompositor::ShowMirrorWindow] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->ShowMirrorWindow();
}

void VirtualCompositor::HideMirrorWindow()
{
	//dlog::Println("[VirtualCompositor::HideMirrorWindow] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->HideMirrorWindow();
}

bool VirtualCompositor::IsMirrorWindowVisible()
{
	//dlog::Println("[VirtualCompositor::IsMirrorWindowVisible] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->IsMirrorWindowVisible();
}

void VirtualCompositor::CompositorDumpImages()
{
	//dlog::Println("[VirtualCompositor::CompositorDumpImages] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->CompositorDumpImages();
}

bool VirtualCompositor::ShouldAppRenderWithLowResources()
{
	//dlog::Println("[VirtualCompositor::ShouldAppRenderWithLowResources] Called.");

	return static_cast<IVRCompositor_026*>(steamCompositor)->ShouldAppRenderWithLowResources();
}

void VirtualCompositor::ForceInterleavedReprojectionOn(bool bOverride)
{
	//dlog::Println("[VirtualCompositor::ForceInterleavedReprojectionOn] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->ForceInterleavedReprojectionOn(bOverride);
}

void VirtualCompositor::ForceReconnectProcess()
{
	//dlog::Println("[VirtualCompositor::ForceReconnectProcess] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->ForceReconnectProcess();
}

void VirtualCompositor::SuspendRendering(bool bSuspend)
{
	//dlog::Println("[VirtualCompositor::SuspendRendering] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->SuspendRendering(bSuspend);
}

EVRCompositorError VirtualCompositor::GetMirrorTextureD3D11(vr::EVREye eEye, void* pD3D11DeviceOrResource, void** ppD3D11ShaderResourceView)
{
	//dlog::Println("[VirtualCompositor::GetMirrorTextureD3D11] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetMirrorTextureD3D11(eEye, pD3D11DeviceOrResource, ppD3D11ShaderResourceView);
}

void VirtualCompositor::ReleaseMirrorTextureD3D11(void* pD3D11ShaderResourceView)
{
	//dlog::Println("[VirtualCompositor::ReleaseMirrorTextureD3D11] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->ReleaseMirrorTextureD3D11(pD3D11ShaderResourceView);
}

EVRCompositorError VirtualCompositor::GetMirrorTextureGL(vr::EVREye eEye, vr::glUInt_t* pglTextureId, vr::glSharedTextureHandle_t* pglSharedTextureHandle)
{
	//dlog::Println("[VirtualCompositor::GetMirrorTextureGL] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetMirrorTextureGL(eEye, pglTextureId, pglSharedTextureHandle);
}

bool VirtualCompositor::ReleaseSharedGLTexture(vr::glUInt_t glTextureId, vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	//dlog::Println("[VirtualCompositor::ReleaseSharedGLTexture] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->ReleaseSharedGLTexture(glTextureId, glSharedTextureHandle);
}

void VirtualCompositor::LockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	//dlog::Println("[VirtualCompositor::LockGLSharedTextureForAccess] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->LockGLSharedTextureForAccess(glSharedTextureHandle);
}

void VirtualCompositor::UnlockGLSharedTextureForAccess(vr::glSharedTextureHandle_t glSharedTextureHandle)
{
	//dlog::Println("[VirtualCompositor::UnlockGLSharedTextureForAccess] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->UnlockGLSharedTextureForAccess(glSharedTextureHandle);
}

uint32_t VirtualCompositor::GetVulkanInstanceExtensionsRequired(VR_OUT_STRING() char* pchValue, uint32_t unBufferSize)
{
	//dlog::Println("[VirtualCompositor::GetVulkanInstanceExtensionsRequired] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetVulkanInstanceExtensionsRequired(pchValue, unBufferSize);
}

uint32_t VirtualCompositor::GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, VR_OUT_STRING() char* pchValue, uint32_t unBufferSize)
{
	//dlog::Println("[VirtualCompositor::GetVulkanDeviceExtensionsRequired] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetVulkanDeviceExtensionsRequired(pPhysicalDevice, pchValue, unBufferSize);
}

void VirtualCompositor::SetExplicitTimingMode(EVRCompositorTimingMode eTimingMode)
{
	//dlog::Println("[VirtualCompositor::SetExplicitTimingMode] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->SetExplicitTimingMode(eTimingMode);
}

EVRCompositorError VirtualCompositor::SubmitExplicitTimingData()
{
	//dlog::Println("[VirtualCompositor::SubmitExplicitTimingData] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->SubmitExplicitTimingData();
}

bool VirtualCompositor::IsMotionSmoothingEnabled()
{
	//dlog::Println("[VirtualCompositor::IsMotionSmoothingEnabled] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->IsMotionSmoothingEnabled();
}

bool VirtualCompositor::IsMotionSmoothingSupported()
{
	//dlog::Println("[VirtualCompositor::IsMotionSmoothingSupported] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->IsMotionSmoothingSupported();
}

bool VirtualCompositor::IsCurrentSceneFocusAppLoading()
{
	//dlog::Println("[VirtualCompositor::IsCurrentSceneFocusAppLoading] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->IsCurrentSceneFocusAppLoading();
}

EVRCompositorError VirtualCompositor::SetStageOverride_Async(const char* pchRenderModelPath, const vr::HmdMatrix34_t* pTransform, const Compositor_StageRenderSettings* pRenderSettings, uint32_t nSizeOfRenderSettings)
{
	//dlog::Println("[VirtualCompositor::SetStageOverride_Async] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->SetStageOverride_Async(pchRenderModelPath, pTransform, pRenderSettings, nSizeOfRenderSettings);
}

void VirtualCompositor::ClearStageOverride()
{
	//dlog::Println("[VirtualCompositor::ClearStageOverride] Called.");
	static_cast<IVRCompositor_026*>(steamCompositor)->ClearStageOverride();
}

bool VirtualCompositor::GetCompositorBenchmarkResults(Compositor_BenchmarkResults* pBenchmarkResults, uint32_t nSizeOfBenchmarkResults)
{
	//dlog::Println("[VirtualCompositor::GetCompositorBenchmarkResults] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetCompositorBenchmarkResults(pBenchmarkResults, nSizeOfBenchmarkResults);
}

EVRCompositorError VirtualCompositor::GetLastPosePredictionIDs(uint32_t* pRenderPosePredictionID, uint32_t* pGamePosePredictionID)
{
	//dlog::Println("[VirtualCompositor::GetLastPosePredictionIDs] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetLastPosePredictionIDs(pRenderPosePredictionID, pGamePosePredictionID);
}

EVRCompositorError VirtualCompositor::GetPosesForFrame(uint32_t unPosePredictionID, vr::TrackedDevicePose_t* pPoseArray, uint32_t unPoseArrayCount)
{
	//dlog::Println("[VirtualCompositor::GetPosesForFrame] Called.");
	return static_cast<IVRCompositor_026*>(steamCompositor)->GetPosesForFrame(unPosePredictionID, pPoseArray, unPoseArrayCount);
}

bool VirtualCompositor::GetFrameTiming(Compositor_FrameTiming* pTiming, uint32_t unFramesAgo)
{
	//dlog::Println("[VirtualCompositor::GetFrameTiming] Called.");

	VRClient::cInstance->pRuntime->framesAgo = unFramesAgo;

	//VRClient::cInstance->pRuntime->getFrameTiming = true;
	//while (VRClient::cInstance->pRuntime->getFrameTiming);

	*pTiming = VRClient::cInstance->pRuntime->frameTiming;

	return static_cast<IVRCompositor_026*>(steamCompositor)->GetFrameTiming(pTiming, unFramesAgo);
}
