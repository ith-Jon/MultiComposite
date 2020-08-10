#include "VirtualSystem_017.h"
#include "VRClient.h"

void VirtualSystem_017::GetRecommendedRenderTargetSize(uint32_t* pnWidth, uint32_t* pnHeight)
{
	VRClient::cInstance->vSystem->GetRecommendedRenderTargetSize(pnWidth, pnHeight);
}

HmdMatrix44_t VirtualSystem_017::GetProjectionMatrix(EVREye eEye, float fNearZ, float fFarZ)
{
	return VRClient::cInstance->vSystem->GetProjectionMatrix(eEye, fNearZ, fFarZ);
}

void VirtualSystem_017::GetProjectionRaw(EVREye eEye, float* pfLeft, float* pfRight, float* pfTop, float* pfBottom)
{
	VRClient::cInstance->vSystem->GetProjectionRaw(eEye, pfLeft, pfRight, pfTop, pfBottom);
}

bool VirtualSystem_017::ComputeDistortion(EVREye eEye, float fU, float fV, DistortionCoordinates_t* pDistortionCoordinates)
{
	return VRClient::cInstance->vSystem->ComputeDistortion(eEye, fU, fV, pDistortionCoordinates);
}

HmdMatrix34_t VirtualSystem_017::GetEyeToHeadTransform(EVREye eEye)
{
	return VRClient::cInstance->vSystem->GetEyeToHeadTransform(eEye);
}

bool VirtualSystem_017::GetTimeSinceLastVsync(float* pfSecondsSinceLastVsync, uint64_t* pulFrameCounter)
{
	return VRClient::cInstance->vSystem->GetTimeSinceLastVsync(pfSecondsSinceLastVsync, pulFrameCounter);
}

int32_t VirtualSystem_017::GetD3D9AdapterIndex()
{
	return VRClient::cInstance->vSystem->GetD3D9AdapterIndex();
}

void VirtualSystem_017::GetDXGIOutputInfo(int32_t* pnAdapterIndex)
{
	VRClient::cInstance->vSystem->GetDXGIOutputInfo(pnAdapterIndex);
}

void VirtualSystem_017::GetOutputDevice(uint64_t* pnDevice, ETextureType textureType, VkInstance_T* pInstance)
{
	VRClient::cInstance->vSystem->GetOutputDevice(pnDevice, textureType, pInstance);
}

bool VirtualSystem_017::IsDisplayOnDesktop()
{
	return VRClient::cInstance->vSystem->IsDisplayOnDesktop();
}

bool VirtualSystem_017::SetDisplayVisibility(bool bIsVisibleOnDesktop)
{
	return VRClient::cInstance->vSystem->SetDisplayVisibility(bIsVisibleOnDesktop);
}

void VirtualSystem_017::GetDeviceToAbsoluteTrackingPose(ETrackingUniverseOrigin eOrigin, float fPredictedSecondsToPhotonsFromNow, VR_ARRAY_COUNT(unTrackedDevicePoseArrayCount)TrackedDevicePose_t* pTrackedDevicePoseArray, uint32_t unTrackedDevicePoseArrayCount)
{
	VRClient::cInstance->vSystem->GetDeviceToAbsoluteTrackingPose(eOrigin, fPredictedSecondsToPhotonsFromNow, pTrackedDevicePoseArray, unTrackedDevicePoseArrayCount);
}

void VirtualSystem_017::ResetSeatedZeroPose()
{
	VRClient::cInstance->vSystem->ResetSeatedZeroPose();
}

HmdMatrix34_t VirtualSystem_017::GetSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
	return VRClient::cInstance->vSystem->GetSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

HmdMatrix34_t VirtualSystem_017::GetRawZeroPoseToStandingAbsoluteTrackingPose()
{
	return VRClient::cInstance->vSystem->GetRawZeroPoseToStandingAbsoluteTrackingPose();
}

uint32_t VirtualSystem_017::GetSortedTrackedDeviceIndicesOfClass(ETrackedDeviceClass eTrackedDeviceClass, VR_ARRAY_COUNT(unTrackedDeviceIndexArrayCount)vr::TrackedDeviceIndex_t* punTrackedDeviceIndexArray, uint32_t unTrackedDeviceIndexArrayCount, vr::TrackedDeviceIndex_t unRelativeToTrackedDeviceIndex)
{
	return VRClient::cInstance->vSystem->GetSortedTrackedDeviceIndicesOfClass(eTrackedDeviceClass, punTrackedDeviceIndexArray, unTrackedDeviceIndexArrayCount, unRelativeToTrackedDeviceIndex);
}

EDeviceActivityLevel VirtualSystem_017::GetTrackedDeviceActivityLevel(vr::TrackedDeviceIndex_t unDeviceId)
{
	return VRClient::cInstance->vSystem->GetTrackedDeviceActivityLevel(unDeviceId);
}

void VirtualSystem_017::ApplyTransform(TrackedDevicePose_t* pOutputPose, const TrackedDevicePose_t* pTrackedDevicePose, const HmdMatrix34_t* pTransform)
{
	VRClient::cInstance->vSystem->ApplyTransform(pOutputPose, pTrackedDevicePose, pTransform);
}

vr::TrackedDeviceIndex_t VirtualSystem_017::GetTrackedDeviceIndexForControllerRole(vr::ETrackedControllerRole unDeviceType)
{
	return VRClient::cInstance->vSystem->GetTrackedDeviceIndexForControllerRole(unDeviceType);
}

vr::ETrackedControllerRole VirtualSystem_017::GetControllerRoleForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	return VRClient::cInstance->vSystem->GetControllerRoleForTrackedDeviceIndex(unDeviceIndex);
}

ETrackedDeviceClass VirtualSystem_017::GetTrackedDeviceClass(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	return VRClient::cInstance->vSystem->GetTrackedDeviceClass(unDeviceIndex);
}

bool VirtualSystem_017::IsTrackedDeviceConnected(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	return VRClient::cInstance->vSystem->IsTrackedDeviceConnected(unDeviceIndex);
}

bool VirtualSystem_017::GetBoolTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return VRClient::cInstance->vSystem->GetBoolTrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

float VirtualSystem_017::GetFloatTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return VRClient::cInstance->vSystem->GetFloatTrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

int32_t VirtualSystem_017::GetInt32TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return VRClient::cInstance->vSystem->GetInt32TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

uint64_t VirtualSystem_017::GetUint64TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return VRClient::cInstance->vSystem->GetUint64TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

HmdMatrix34_t VirtualSystem_017::GetMatrix34TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return VRClient::cInstance->vSystem->GetMatrix34TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

uint32_t VirtualSystem_017::GetStringTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, VR_OUT_STRING() char* pchValue, uint32_t unBufferSize, ETrackedPropertyError* pErrorL)
{
	return VRClient::cInstance->vSystem->GetStringTrackedDeviceProperty(unDeviceIndex, prop, pchValue, unBufferSize, pErrorL);
}

const char* VirtualSystem_017::GetPropErrorNameFromEnum(ETrackedPropertyError error)
{
	return VRClient::cInstance->vSystem->GetPropErrorNameFromEnum(error);
}

bool VirtualSystem_017::PollNextEvent(VREvent_t* pEvent, uint32_t uncbVREvent)
{
	return VRClient::cInstance->vSystem->PollNextEvent(pEvent, uncbVREvent);
}

bool VirtualSystem_017::PollNextEventWithPose(ETrackingUniverseOrigin eOrigin, VREvent_t* pEvent, uint32_t uncbVREvent, vr::TrackedDevicePose_t* pTrackedDevicePose)
{
	return VRClient::cInstance->vSystem->PollNextEventWithPose(eOrigin, pEvent, uncbVREvent, pTrackedDevicePose);
}

const char* VirtualSystem_017::GetEventTypeNameFromEnum(EVREventType eType)
{
	return VRClient::cInstance->vSystem->GetEventTypeNameFromEnum(eType);
}

HiddenAreaMesh_t VirtualSystem_017::GetHiddenAreaMesh(EVREye eEye, EHiddenAreaMeshType type)
{
	return VRClient::cInstance->vSystem->GetHiddenAreaMesh(eEye, type);
}

bool VirtualSystem_017::GetControllerState(vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState, uint32_t unControllerStateSize)
{
	return VRClient::cInstance->vSystem->GetControllerState(unControllerDeviceIndex, pControllerState, unControllerStateSize);
}

bool VirtualSystem_017::GetControllerStateWithPose(ETrackingUniverseOrigin eOrigin, vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState, uint32_t unControllerStateSize, TrackedDevicePose_t* pTrackedDevicePose)
{
	return VRClient::cInstance->vSystem->GetControllerStateWithPose(eOrigin, unControllerDeviceIndex, pControllerState, unControllerStateSize, pTrackedDevicePose);
}

void VirtualSystem_017::TriggerHapticPulse(vr::TrackedDeviceIndex_t unControllerDeviceIndex, uint32_t unAxisId, unsigned short usDurationMicroSec)
{
	VRClient::cInstance->vSystem->TriggerHapticPulse(unControllerDeviceIndex, unAxisId, usDurationMicroSec);
}

const char* VirtualSystem_017::GetButtonIdNameFromEnum(EVRButtonId eButtonId)
{
	return VRClient::cInstance->vSystem->GetButtonIdNameFromEnum(eButtonId);
}

const char* VirtualSystem_017::GetControllerAxisTypeNameFromEnum(EVRControllerAxisType eAxisType)
{
	return VRClient::cInstance->vSystem->GetControllerAxisTypeNameFromEnum(eAxisType);
}

bool VirtualSystem_017::CaptureInputFocus()
{
	return VRClient::cInstance->vSystem->CaptureInputFocus();
}

void VirtualSystem_017::ReleaseInputFocus()
{
	VRClient::cInstance->vSystem->CaptureInputFocus();
}

bool VirtualSystem_017::IsInputFocusCapturedByAnotherProcess()
{
	return VRClient::cInstance->vSystem->IsInputFocusCapturedByAnotherProcess();
}

uint32_t VirtualSystem_017::DriverDebugRequest(vr::TrackedDeviceIndex_t unDeviceIndex, const char* pchRequest, char* pchResponseBuffer, uint32_t unResponseBufferSize)
{
	return VRClient::cInstance->vSystem->DriverDebugRequest(unDeviceIndex, pchRequest, pchResponseBuffer, unResponseBufferSize);
}

vr::EVRFirmwareError VirtualSystem_017::PerformFirmwareUpdate(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	return VRClient::cInstance->vSystem->PerformFirmwareUpdate(unDeviceIndex);
}

void VirtualSystem_017::AcknowledgeQuit_Exiting()
{
	VRClient::cInstance->vSystem->AcknowledgeQuit_Exiting();
}

void VirtualSystem_017::AcknowledgeQuit_UserPrompt()
{
	VRClient::cInstance->vSystem->AcknowledgeQuit_UserPrompt();
}

/**			Fn Table			*/

void __stdcall fntable_System_017_impl_GetRecommendedRenderTargetSize(uint32_t* pnWidth, uint32_t* pnHeight)
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetRecommendedRenderTargetSize(pnWidth, pnHeight);
}

HmdMatrix44_t __stdcall fntable_System_017_impl_GetProjectionMatrix(EVREye eEye, float fNearZ, float fFarZ)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetProjectionMatrix(eEye, fNearZ, fFarZ);
}

void __stdcall fntable_System_017_impl_GetProjectionRaw(EVREye eEye, float* pfLeft, float* pfRight, float* pfTop, float* pfBottom)
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetProjectionRaw(eEye, pfLeft, pfRight, pfTop, pfBottom);
}

bool __stdcall fntable_System_017_impl_ComputeDistortion(EVREye eEye, float fU, float fV, DistortionCoordinates_t* pDistortionCoordinates)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->ComputeDistortion(eEye, fU, fV, pDistortionCoordinates);
}

HmdMatrix34_t __stdcall fntable_System_017_impl_GetEyeToHeadTransform(EVREye eEye)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetEyeToHeadTransform(eEye);
}

bool __stdcall fntable_System_017_impl_GetTimeSinceLastVsync(float* pfSecondsSinceLastVsync, uint64_t* pulFrameCounter)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetTimeSinceLastVsync(pfSecondsSinceLastVsync, pulFrameCounter);
}

int32_t __stdcall fntable_System_017_impl_GetD3D9AdapterIndex()
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetD3D9AdapterIndex();
}

void __stdcall fntable_System_017_impl_GetDXGIOutputInfo(int32_t* pnAdapterIndex)
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetDXGIOutputInfo(pnAdapterIndex);
}

void __stdcall fntable_System_017_impl_GetOutputDevice(uint64_t* pnDevice, ETextureType textureType, VkInstance_T* pInstance)
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetOutputDevice(pnDevice, textureType, pInstance);
}

bool __stdcall fntable_System_017_impl_IsDisplayOnDesktop()
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->IsDisplayOnDesktop();
}

bool __stdcall fntable_System_017_impl_SetDisplayVisibility(bool bIsVisibleOnDesktop)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->SetDisplayVisibility(bIsVisibleOnDesktop);
}

void __stdcall fntable_System_017_impl_GetDeviceToAbsoluteTrackingPose(ETrackingUniverseOrigin eOrigin, float fPredictedSecondsToPhotonsFromNow, VR_ARRAY_COUNT(unTrackedDevicePoseArrayCount)TrackedDevicePose_t* pTrackedDevicePoseArray, uint32_t unTrackedDevicePoseArrayCount)
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetDeviceToAbsoluteTrackingPose(eOrigin, fPredictedSecondsToPhotonsFromNow, pTrackedDevicePoseArray, unTrackedDevicePoseArrayCount);
}

void __stdcall fntable_System_017_impl_ResetSeatedZeroPose()
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->ResetSeatedZeroPose();
}

HmdMatrix34_t __stdcall fntable_System_017_impl_GetSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

HmdMatrix34_t __stdcall fntable_System_017_impl_GetRawZeroPoseToStandingAbsoluteTrackingPose()
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetRawZeroPoseToStandingAbsoluteTrackingPose();
}

uint32_t __stdcall fntable_System_017_impl_GetSortedTrackedDeviceIndicesOfClass(ETrackedDeviceClass eTrackedDeviceClass, VR_ARRAY_COUNT(unTrackedDeviceIndexArrayCount)vr::TrackedDeviceIndex_t* punTrackedDeviceIndexArray, uint32_t unTrackedDeviceIndexArrayCount, vr::TrackedDeviceIndex_t unRelativeToTrackedDeviceIndex)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetSortedTrackedDeviceIndicesOfClass(eTrackedDeviceClass, punTrackedDeviceIndexArray, unTrackedDeviceIndexArrayCount, unRelativeToTrackedDeviceIndex);
}

EDeviceActivityLevel __stdcall fntable_System_017_impl_GetTrackedDeviceActivityLevel(vr::TrackedDeviceIndex_t unDeviceId)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetTrackedDeviceActivityLevel(unDeviceId);
}

void __stdcall fntable_System_017_impl_ApplyTransform(TrackedDevicePose_t* pOutputPose, const TrackedDevicePose_t* pTrackedDevicePose, const HmdMatrix34_t* pTransform)
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->ApplyTransform(pOutputPose, pTrackedDevicePose, pTransform);
}

vr::TrackedDeviceIndex_t __stdcall fntable_System_017_impl_GetTrackedDeviceIndexForControllerRole(vr::ETrackedControllerRole unDeviceType)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetTrackedDeviceIndexForControllerRole(unDeviceType);
}

vr::ETrackedControllerRole __stdcall fntable_System_017_impl_GetControllerRoleForTrackedDeviceIndex(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetControllerRoleForTrackedDeviceIndex(unDeviceIndex);
}

ETrackedDeviceClass __stdcall fntable_System_017_impl_GetTrackedDeviceClass(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetTrackedDeviceClass(unDeviceIndex);
}

bool __stdcall fntable_System_017_impl_IsTrackedDeviceConnected(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->IsTrackedDeviceConnected(unDeviceIndex);
}

bool __stdcall fntable_System_017_impl_GetBoolTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetBoolTrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

float __stdcall fntable_System_017_impl_GetFloatTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetFloatTrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

int32_t __stdcall fntable_System_017_impl_GetInt32TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetInt32TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

uint64_t __stdcall fntable_System_017_impl_GetUint64TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetUint64TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

HmdMatrix34_t __stdcall fntable_System_017_impl_GetMatrix34TrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError* pErrorL)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetMatrix34TrackedDeviceProperty(unDeviceIndex, prop, pErrorL);
}

uint32_t __stdcall fntable_System_017_impl_GetStringTrackedDeviceProperty(vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, VR_OUT_STRING() char* pchValue, uint32_t unBufferSize, ETrackedPropertyError* pErrorL)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetStringTrackedDeviceProperty(unDeviceIndex, prop, pchValue, unBufferSize, pErrorL);
}

const char* __stdcall fntable_System_017_impl_GetPropErrorNameFromEnum(ETrackedPropertyError error)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetPropErrorNameFromEnum(error);
}

bool __stdcall fntable_System_017_impl_PollNextEvent(VREvent_t* pEvent, uint32_t uncbVREvent)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->PollNextEvent(pEvent, uncbVREvent);
}

bool __stdcall fntable_System_017_impl_PollNextEventWithPose(ETrackingUniverseOrigin eOrigin, VREvent_t* pEvent, uint32_t uncbVREvent, vr::TrackedDevicePose_t* pTrackedDevicePose)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->PollNextEventWithPose(eOrigin, pEvent, uncbVREvent, pTrackedDevicePose);
}

const char* __stdcall fntable_System_017_impl_GetEventTypeNameFromEnum(EVREventType eType)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetEventTypeNameFromEnum(eType);
}

HiddenAreaMesh_t __stdcall fntable_System_017_impl_GetHiddenAreaMesh(EVREye eEye, EHiddenAreaMeshType type)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetHiddenAreaMesh(eEye, type);
}

bool __stdcall fntable_System_017_impl_GetControllerState(vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState, uint32_t unControllerStateSize)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetControllerState(unControllerDeviceIndex, pControllerState, unControllerStateSize);
}

bool __stdcall fntable_System_017_impl_GetControllerStateWithPose(ETrackingUniverseOrigin eOrigin, vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState, uint32_t unControllerStateSize, TrackedDevicePose_t* pTrackedDevicePose)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetControllerStateWithPose(eOrigin, unControllerDeviceIndex, pControllerState, unControllerStateSize, pTrackedDevicePose);
}

void __stdcall fntable_System_017_impl_TriggerHapticPulse(vr::TrackedDeviceIndex_t unControllerDeviceIndex, uint32_t unAxisId, unsigned short usDurationMicroSec)
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->TriggerHapticPulse(unControllerDeviceIndex, unAxisId, usDurationMicroSec);
}

const char* __stdcall fntable_System_017_impl_GetButtonIdNameFromEnum(EVRButtonId eButtonId)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetButtonIdNameFromEnum(eButtonId);
}

const char* __stdcall fntable_System_017_impl_GetControllerAxisTypeNameFromEnum(EVRControllerAxisType eAxisType)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->GetControllerAxisTypeNameFromEnum(eAxisType);
}

bool __stdcall fntable_System_017_impl_CaptureInputFocus()
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->CaptureInputFocus();
}

void __stdcall fntable_System_017_impl_ReleaseInputFocus()
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->CaptureInputFocus();
}

bool __stdcall fntable_System_017_impl_IsInputFocusCapturedByAnotherProcess()
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->IsInputFocusCapturedByAnotherProcess();
}

uint32_t __stdcall fntable_System_017_impl_DriverDebugRequest(vr::TrackedDeviceIndex_t unDeviceIndex, const char* pchRequest, char* pchResponseBuffer, uint32_t unResponseBufferSize)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->DriverDebugRequest(unDeviceIndex, pchRequest, pchResponseBuffer, unResponseBufferSize);
}

vr::EVRFirmwareError __stdcall fntable_System_017_impl_PerformFirmwareUpdate(vr::TrackedDeviceIndex_t unDeviceIndex)
{
	return static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->PerformFirmwareUpdate(unDeviceIndex);
}

void __stdcall fntable_System_017_impl_AcknowledgeQuit_Exiting()
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->AcknowledgeQuit_Exiting();
}

void __stdcall fntable_System_017_impl_AcknowledgeQuit_UserPrompt()
{
	static_cast<VirtualSystem_017*>(VRClient::cInstance->vSystem->virtualSystem)->AcknowledgeQuit_UserPrompt();
}

static void* fnTable_VirtualSystem_017[] = {
	fntable_System_017_impl_GetRecommendedRenderTargetSize,
	fntable_System_017_impl_GetProjectionMatrix,
	fntable_System_017_impl_GetProjectionRaw,
	fntable_System_017_impl_ComputeDistortion,
	fntable_System_017_impl_GetEyeToHeadTransform,
	fntable_System_017_impl_GetTimeSinceLastVsync,
	fntable_System_017_impl_GetD3D9AdapterIndex,
	fntable_System_017_impl_GetDXGIOutputInfo,
	fntable_System_017_impl_GetOutputDevice,
	fntable_System_017_impl_IsDisplayOnDesktop,
	fntable_System_017_impl_SetDisplayVisibility,
	fntable_System_017_impl_GetDeviceToAbsoluteTrackingPose,
	fntable_System_017_impl_ResetSeatedZeroPose,
	fntable_System_017_impl_GetSeatedZeroPoseToStandingAbsoluteTrackingPose,
	fntable_System_017_impl_GetRawZeroPoseToStandingAbsoluteTrackingPose,
	fntable_System_017_impl_GetSortedTrackedDeviceIndicesOfClass,
	fntable_System_017_impl_GetTrackedDeviceActivityLevel,
	fntable_System_017_impl_ApplyTransform,
	fntable_System_017_impl_GetTrackedDeviceIndexForControllerRole,
	fntable_System_017_impl_GetControllerRoleForTrackedDeviceIndex,
	fntable_System_017_impl_GetTrackedDeviceClass,
	fntable_System_017_impl_IsTrackedDeviceConnected,
	fntable_System_017_impl_GetBoolTrackedDeviceProperty,
	fntable_System_017_impl_GetFloatTrackedDeviceProperty,
	fntable_System_017_impl_GetInt32TrackedDeviceProperty,
	fntable_System_017_impl_GetUint64TrackedDeviceProperty,
	fntable_System_017_impl_GetMatrix34TrackedDeviceProperty,
	fntable_System_017_impl_GetStringTrackedDeviceProperty,
	fntable_System_017_impl_GetPropErrorNameFromEnum,
	fntable_System_017_impl_PollNextEvent,
	fntable_System_017_impl_PollNextEventWithPose,
	fntable_System_017_impl_GetEventTypeNameFromEnum,
	fntable_System_017_impl_GetHiddenAreaMesh,
	fntable_System_017_impl_GetControllerState,
	fntable_System_017_impl_GetControllerStateWithPose,
	fntable_System_017_impl_TriggerHapticPulse,
	fntable_System_017_impl_GetButtonIdNameFromEnum,
	fntable_System_017_impl_GetControllerAxisTypeNameFromEnum,
	fntable_System_017_impl_CaptureInputFocus,
	fntable_System_017_impl_ReleaseInputFocus,
	fntable_System_017_impl_IsInputFocusCapturedByAnotherProcess,
	fntable_System_017_impl_DriverDebugRequest,
	fntable_System_017_impl_PerformFirmwareUpdate,
	fntable_System_017_impl_AcknowledgeQuit_Exiting,
	fntable_System_017_impl_AcknowledgeQuit_UserPrompt,
};

void* VirtualSystem_017::GetFnTable()
{
	return fnTable_VirtualSystem_017;
}
