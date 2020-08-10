#include "VirtualSystem.h"
#include "VRClient.h"

void VirtualSystem::GetRecommendedRenderTargetSize(uint32_t* pnWidth, uint32_t* pnHeight)
{
	//dlog::Println("[VirtualSystem::GetRecommendedRenderTargetSize] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->GetRecommendedRenderTargetSize(pnWidth, pnHeight);
}

HmdMatrix44_t VirtualSystem::GetProjectionMatrix(EVREye eEye, float fNearZ, float fFarZ)
{
	//dlog::Println("[VirtualSystem::GetProjectionMatrix] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetProjectionMatrix(eEye, fNearZ, fFarZ);
}

void VirtualSystem::GetProjectionRaw(EVREye eEye, float* pfLeft, float* pfRight, float* pfTop, float* pfBottom)
{
	//dlog::Println("[VirtualSystem::GetProjectionRaw] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->GetProjectionRaw(eEye, pfLeft, pfRight, pfTop, pfBottom);
}

bool VirtualSystem::ComputeDistortion(EVREye eEye, float fU, float fV, DistortionCoordinates_t* pDistortionCoordinates)
{
	//dlog::Println("[VirtualSystem::ComputeDistortion] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->ComputeDistortion(eEye, fU, fV, pDistortionCoordinates);
}

HmdMatrix34_t VirtualSystem::GetEyeToHeadTransform(EVREye eEye)
{
	//dlog::Println("[VirtualSystem::GetEyeToHeadTransform] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetEyeToHeadTransform(eEye);
}

bool VirtualSystem::GetTimeSinceLastVsync(float* pfSecondsSinceLastVsync, uint64_t* pulFrameCounter)
{
	//dlog::Println("[VirtualSystem::GetTimeSinceLastVsync] Called.");
	return static_cast<IVRSystem_011*>(steamSystem)->GetTimeSinceLastVsync(pfSecondsSinceLastVsync, pulFrameCounter);
}

int32_t VirtualSystem::GetD3D9AdapterIndex()
{
	//dlog::Println("[VirtualSystem::GetD3D9AdapterIndex] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetD3D9AdapterIndex();
}

void VirtualSystem::GetDXGIOutputInfo(int32_t* pnAdapterIndex)
{
	dlog::Println("[VirtualSystem::GetDXGIOutputInfo] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->GetDXGIOutputInfo(pnAdapterIndex);
}

void VirtualSystem::GetOutputDevice(uint64_t* pnDevice, ETextureType textureType, VkInstance_T* pInstance)
{
	//dlog::Println("[VirtualSystem::GetOutputDevice] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->GetOutputDevice(pnDevice, textureType, pInstance);
}

bool VirtualSystem::IsDisplayOnDesktop()
{
	//dlog::Println("[VirtualSystem::IsDisplayOnDesktop] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->IsDisplayOnDesktop();
}

bool VirtualSystem::SetDisplayVisibility(bool bIsVisibleOnDesktop)
{
	//dlog::Println("[VirtualSystem::SetDisplayVisibility] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->SetDisplayVisibility(bIsVisibleOnDesktop);
}

void VirtualSystem::GetDeviceToAbsoluteTrackingPose(ETrackingUniverseOrigin eOrigin, float fPredictedSecondsToPhotonsFromNow, VR_ARRAY_COUNT(unTrackedDevicePoseArrayCount)TrackedDevicePose_t* pTrackedDevicePoseArray, uint32_t unTrackedDevicePoseArrayCount)
{
	//dlog::Println("[VirtualSystem::GetDeviceToAbsoluteTrackingPose] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->GetDeviceToAbsoluteTrackingPose(eOrigin, fPredictedSecondsToPhotonsFromNow, pTrackedDevicePoseArray, unTrackedDevicePoseArrayCount);
}

void VirtualSystem::ResetSeatedZeroPose()
{
	//dlog::Println("[VirtualSystem::ResetSeatedZeroPose] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->ResetSeatedZeroPose();
}

HmdMatrix34_t VirtualSystem::GetSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
	//dlog::Println("[VirtualSystem::GetSeatedZeroPoseToStandingAbsoluteTrackingPose] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetRawZeroPoseToStandingAbsoluteTrackingPose();
}

HmdMatrix34_t VirtualSystem::GetRawZeroPoseToStandingAbsoluteTrackingPose()
{
	//dlog::Println("[VirtualSystem::GetRawZeroPoseToStandingAbsoluteTrackingPose] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetRawZeroPoseToStandingAbsoluteTrackingPose();
}

uint32_t VirtualSystem::GetSortedTrackedDeviceIndicesOfClass(ETrackedDeviceClass eTrackedDeviceClass, VR_ARRAY_COUNT(unTrackedDeviceIndexArrayCount)vr::TrackedDeviceIndex_t* punTrackedDeviceIndexArray, uint32_t unTrackedDeviceIndexArrayCount, vr::TrackedDeviceIndex_t unRelativeToTrackedDeviceIndex)
{
	//dlog::Println("[VirtualSystem::GetSortedTrackedDeviceIndicesOfClass] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetSortedTrackedDeviceIndicesOfClass(eTrackedDeviceClass, punTrackedDeviceIndexArray, unTrackedDeviceIndexArrayCount, unRelativeToTrackedDeviceIndex);
}

EDeviceActivityLevel VirtualSystem::GetTrackedDeviceActivityLevel(vr::TrackedDeviceIndex_t unDeviceId)
{
	//dlog::Println("[VirtualSystem::GetTrackedDeviceActivityLevel] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetTrackedDeviceActivityLevel(unDeviceId);
}

void VirtualSystem::ApplyTransform(TrackedDevicePose_t* pOutputPose, const TrackedDevicePose_t* pTrackedDevicePose, const HmdMatrix34_t* pTransform)
{
	//dlog::Println("[VirtualSystem::ApplyTransform] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->ApplyTransform(pOutputPose, pTrackedDevicePose, pTransform);
}

vr::TrackedDeviceIndex_t VirtualSystem::GetTrackedDeviceIndexForControllerRole(vr::ETrackedControllerRole unDeviceType)
{
	//dlog::Println("[VirtualSystem::GetTrackedDeviceIndexForControllerRole] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetTrackedDeviceIndexForControllerRole(unDeviceType);
}

vr::ETrackedControllerRole VirtualSystem::GetControllerRoleForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	//dlog::Println("[VirtualSystem::GetControllerRoleForTrackedDeviceIndex] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetControllerRoleForTrackedDeviceIndex(unDeviceIndex);
}

ETrackedDeviceClass VirtualSystem::GetTrackedDeviceClass(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	//dlog::Println("[VirtualSystem::GetTrackedDeviceClass] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetTrackedDeviceClass(unDeviceIndex);
}

bool VirtualSystem::IsTrackedDeviceConnected(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	//dlog::Println("[VirtualSystem::IsTrackedDeviceConnected] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->IsTrackedDeviceConnected(unDeviceIndex);
}

bool VirtualSystem::GetBoolTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
	{
		*pErrorL = TrackedProp_NotYetAvailable;
		return false;
	}

	//dlog::Println("[VirtualSystem::GetBoolTrackedDeviceProperty] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetBoolTrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

float VirtualSystem::GetFloatTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
	{
		*pErrorL = TrackedProp_NotYetAvailable;
		return 0;
	}

	//dlog::Println("[VirtualSystem::GetFloatTrackedDeviceProperty] Called.");
	return static_cast<IVRSystem_011*>(steamSystem)->GetFloatTrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

int32_t VirtualSystem::GetInt32TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
	{
		*pErrorL = TrackedProp_NotYetAvailable;
		return 0;
	}

	//dlog::Println("[VirtualSystem::GetInt32TrackedDeviceProperty] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetInt32TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

uint64_t VirtualSystem::GetUint64TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
	{
		*pErrorL = TrackedProp_NotYetAvailable;
		return 0;
	}

	//dlog::Println("[VirtualSystem::GetUint64TrackedDeviceProperty] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetUint64TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

HmdMatrix34_t VirtualSystem::GetMatrix34TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
	{
		*pErrorL = TrackedProp_NotYetAvailable;
		return HmdMatrix34_t{};
	}

	//dlog::Println("[VirtualSystem::GetMatrix34TrackedDeviceProperty] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetMatrix34TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

uint32_t VirtualSystem::GetArrayTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, PropertyTypeTag_t propType, void* pBuffer, uint32_t unBufferSize, ETrackedPropertyError* pError)
{
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
	{
		*pError = TrackedProp_NotYetAvailable;
		return 0;
	}

	//dlog::Println("[VirtualSystem::GetArrayTrackedDeviceProperty] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetArrayTrackedDeviceProperty(unDeviceIndex, prop, propType, pBuffer, unBufferSize, pError);
}

uint32_t VirtualSystem::GetStringTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, VR_OUT_STRING() char* pchValue, uint32_t unBufferSize, ETrackedPropertyError* pErrorL)
{
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
	{
		*pErrorL = TrackedProp_NotYetAvailable;
		return 0;
	}

	//dlog::Println("[VirtualSystem::GetStringTrackedDeviceProperty] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetStringTrackedDeviceProperty(unDeviceIndex, prop, pchValue, unBufferSize, pErrorL);
}

const char* VirtualSystem::GetPropErrorNameFromEnum(ETrackedPropertyError error)
{
	//dlog::Println("[VirtualSystem::GetPropErrorNameFromEnum] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetPropErrorNameFromEnum(error);
}

bool VirtualSystem::IsInputAvailable()
{
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
	{
		return false;
	}

	//dlog::Println("[VirtualSystem::IsInputAvailable] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->IsInputAvailable();
}

bool VirtualSystem::IsSteamVRDrawingControllers()
{
	//dlog::Println("[VirtualSystem::IsSteamVRDrawingControllers] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->IsSteamVRDrawingControllers();
}

bool VirtualSystem::ShouldApplicationPause()
{
	//dlog::Println("[VirtualSystem::ShouldApplicationPause] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->ShouldApplicationPause();
}

bool VirtualSystem::ShouldApplicationReduceRenderingWork()
{
	//dlog::Println("[VirtualSystem::ShouldApplicationReduceRenderingWork] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->ShouldApplicationReduceRenderingWork();
}

bool VirtualSystem::PollNextEvent(VREvent_t* pEvent, uint32_t uncbVREvent)
{
	//dlog::Println("[VirtualSystem::PollNextEvent] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->PollNextEvent(pEvent, uncbVREvent);
}

bool VirtualSystem::PollNextEventWithPose(ETrackingUniverseOrigin eOrigin, VREvent_t* pEvent, uint32_t uncbVREvent, vr::TrackedDevicePose_t* pTrackedDevicePose)
{
	//dlog::Println("[VirtualSystem::PollNextEventWithPose] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->PollNextEventWithPose(eOrigin, pEvent, uncbVREvent, pTrackedDevicePose);
}

const char* VirtualSystem::GetEventTypeNameFromEnum(EVREventType eType)
{
	//dlog::Println("[VirtualSystem::GetEventTypeNameFromEnum] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetEventTypeNameFromEnum(eType);
}

HiddenAreaMesh_t VirtualSystem::GetHiddenAreaMesh(EVREye eEye, EHiddenAreaMeshType type)
{
	//dlog::Println("[VirtualSystem::GetHiddenAreaMesh] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetHiddenAreaMesh(eEye, type);
}

bool VirtualSystem::GetControllerState(vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState, uint32_t unControllerStateSize)
{
	//dlog::Println("[VirtualSystem::GetControllerState] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetControllerState(unControllerDeviceIndex, pControllerState, unControllerStateSize);
}

bool VirtualSystem::GetControllerState(vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState)
{
	//dlog::Println("[VirtualSystem::GetControllerState] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetControllerState(unControllerDeviceIndex, pControllerState, sizeof(VRControllerState_t));
}

bool VirtualSystem::GetControllerStateWithPose(ETrackingUniverseOrigin eOrigin, vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState, uint32_t unControllerStateSize, TrackedDevicePose_t* pTrackedDevicePose)
{
	//dlog::Println("[VirtualSystem::GetControllerStateWithPose] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetControllerStateWithPose(eOrigin, unControllerDeviceIndex, pControllerState, unControllerStateSize, pTrackedDevicePose);
}

bool VirtualSystem::GetControllerStateWithPose(ETrackingUniverseOrigin eOrigin, vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState, TrackedDevicePose_t* pTrackedDevicePose)
{
	//dlog::Println("[VirtualSystem::GetControllerStateWithPose] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetControllerStateWithPose(eOrigin, unControllerDeviceIndex, pControllerState, sizeof(VRControllerState_t), pTrackedDevicePose);
}

void VirtualSystem::TriggerHapticPulse(vr::TrackedDeviceIndex_t unControllerDeviceIndex, uint32_t unAxisId, unsigned short usDurationMicroSec)
{
	//dlog::Println("[VirtualSystem::TriggerHapticPulse] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->TriggerHapticPulse(unControllerDeviceIndex, unAxisId, usDurationMicroSec);
}

const char* VirtualSystem::GetButtonIdNameFromEnum(EVRButtonId eButtonId)
{
	//dlog::Println("[VirtualSystem::GetButtonIdNameFromEnum] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetButtonIdNameFromEnum(eButtonId);
}

const char* VirtualSystem::GetControllerAxisTypeNameFromEnum(EVRControllerAxisType eAxisType)
{
	//dlog::Println("[VirtualSystem::GetControllerAxisTypeNameFromEnum] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetControllerAxisTypeNameFromEnum(eAxisType);
}

bool VirtualSystem::CaptureInputFocus()
{
	//dlog::Println("[VirtualSystem::CaptureInputFocus] Called.");
	return static_cast<IVRSystem_017*>(steamSystem)->CaptureInputFocus();
}

void VirtualSystem::ReleaseInputFocus()
{
	//dlog::Println("[VirtualSystem::ReleaseInputFocus] Called.");
	static_cast<IVRSystem_017*>(steamSystem)->ReleaseInputFocus();
}

bool VirtualSystem::IsInputFocusCapturedByAnotherProcess()
{
	//dlog::Println("[VirtualSystem::IsInputFocusCapturedByAnotherProcess] Called.");
	return static_cast<IVRSystem_017*>(steamSystem)->IsInputFocusCapturedByAnotherProcess();
}

uint32_t VirtualSystem::DriverDebugRequest(vr::TrackedDeviceIndex_t unDeviceIndex, const char* pchRequest, char* pchResponseBuffer, uint32_t unResponseBufferSize)
{
	//dlog::Println("[VirtualSystem::DriverDebugRequest] Called.");
	return static_cast<IVRSystem_019*>(steamSystem)->DriverDebugRequest(unDeviceIndex, pchRequest, pchResponseBuffer, unResponseBufferSize);
}

vr::EVRFirmwareError VirtualSystem::PerformFirmwareUpdate(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	//dlog::Println("[VirtualSystem::PerformFirmwareUpdate] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->PerformFirmwareUpdate(unDeviceIndex);
}

void VirtualSystem::AcknowledgeQuit_Exiting()
{
	//dlog::Println("[VirtualSystem::AcknowledgeQuit_Exiting] Called.");
	static_cast<IVRSystem_021*>(steamSystem)->AcknowledgeQuit_Exiting();
}

void VirtualSystem::AcknowledgeQuit_UserPrompt()
{
	//dlog::Println("[VirtualSystem::AcknowledgeQuit_UserPrompt] Called.");
	static_cast<IVRSystem_020*>(steamSystem)->AcknowledgeQuit_UserPrompt();
}

uint32_t VirtualSystem::GetAppContainerFilePaths(VR_OUT_STRING() char* pchBuffer, uint32_t unBufferSize)
{
	//dlog::Println("[VirtualSystem::GetAppContainerFilePaths] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetAppContainerFilePaths(pchBuffer, unBufferSize);
}

const char* VirtualSystem::GetRuntimeVersion()
{
	//dlog::Println("[VirtualSystem::GetRuntimeVersion] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetRuntimeVersion();
}

DistortionCoordinates_t VirtualSystem::ComputeDistortion(EVREye eEye, float fU, float fV)
{
	//dlog::Println("[VirtualSystem::ComputeDistortion] Called.");
	DistortionCoordinates_t out;
	static_cast<IVRSystem_021*>(steamSystem)->ComputeDistortion(eEye, fU, fV, &out);
	return out;
}

HmdMatrix44_t VirtualSystem::GetProjectionMatrix(EVREye eEye, float fNearZ, float fFarZ, EGraphicsAPIConvention convention)
{
	//dlog::Println("[VirtualSystem::GetProjectionMatrix] Called.");
	return static_cast<IVRSystem_021*>(steamSystem)->GetProjectionMatrix(eEye, fNearZ, fFarZ);
}

void VirtualSystem::PerformanceTestEnableCapture(bool bEnable)
{
	//dlog::Println("[VirtualSystem::PerformanceTestEnableCapture] Called.");
	return static_cast<IVRSystem_011*>(steamSystem)->PerformanceTestEnableCapture(bEnable);
}

void VirtualSystem::PerformanceTestReportFidelityLevelChange(int nFidelityLevel)
{
	//dlog::Println("[VirtualSystem::PerformanceTestReportFidelityLevelChange] Called.");
	static_cast<IVRSystem_011*>(steamSystem)->PerformanceTestReportFidelityLevelChange(nFidelityLevel);
}
