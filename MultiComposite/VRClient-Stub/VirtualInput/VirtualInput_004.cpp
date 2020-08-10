#include "VirtualInput_004.h"
#include "VRClient.h"

vr::EVRInputError VirtualInput_004::SetActionManifestPath(const char* pchActionManifestPath)
{
	return VRClient::cInstance->vInput->SetActionManifestPath(pchActionManifestPath);
}

vr::EVRInputError VirtualInput_004::GetActionSetHandle(const char* pchActionSetName, vr::VRActionSetHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetActionSetHandle(pchActionSetName, pHandle);
}

vr::EVRInputError VirtualInput_004::GetActionHandle(const char* pchActionName, vr::VRActionHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetActionHandle(pchActionName, pHandle);
}

vr::EVRInputError VirtualInput_004::GetInputSourceHandle(const char* pchInputSourcePath, vr::VRInputValueHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetInputSourceHandle(pchInputSourcePath, pHandle);
}

vr::EVRInputError VirtualInput_004::UpdateActionState(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount)
{
	return VRClient::cInstance->vInput->UpdateActionState(pSets, unSizeOfVRSelectedActionSet_t, unSetCount);
}

vr::EVRInputError VirtualInput_004::GetDigitalActionData(vr::VRActionHandle_t action, vr::InputDigitalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetDigitalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_004::GetAnalogActionData(vr::VRActionHandle_t action, vr::InputAnalogActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetAnalogActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_004::GetPoseActionData(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetPoseActionData(action, eOrigin, fPredictedSecondsFromNow, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_004::GetSkeletalActionData(vr::VRActionHandle_t action, vr::InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetSkeletalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_004::GetSkeletalBoneData(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetSkeletalBoneData(action, eTransformSpace, eMotionRange, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput_004::GetSkeletalBoneDataCompressed(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetSkeletalBoneDataCompressed(action, eTransformSpace, eMotionRange, pvCompressedData, unCompressedSize, punRequiredCompressedSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_004::DecompressSkeletalBoneData(void* pvCompressedBuffer, uint32_t unCompressedBufferSize, vr::EVRSkeletalTransformSpace* peTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return VRClient::cInstance->vInput->DecompressSkeletalBoneData(pvCompressedBuffer, unCompressedBufferSize, peTransformSpace, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput_004::TriggerHapticVibrationAction(vr::VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->TriggerHapticVibrationAction(action, fStartSecondsFromNow, fDurationSeconds, fFrequency, fAmplitude, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_004::GetActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT(originOutCount)vr::VRInputValueHandle_t* originsOut, uint32_t originOutCount)
{
	return VRClient::cInstance->vInput->GetActionOrigins(actionSetHandle, digitalActionHandle, originsOut, originOutCount);
}

vr::EVRInputError VirtualInput_004::GetOriginLocalizedName(vr::VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize)
{
	return VRClient::cInstance->vInput->GetOriginLocalizedName(origin, pchNameArray, unNameArraySize);
}

vr::EVRInputError VirtualInput_004::GetOriginTrackedDeviceInfo(vr::VRInputValueHandle_t origin, vr::InputOriginInfo_t* pOriginInfo, uint32_t unOriginInfoSize)
{
	return VRClient::cInstance->vInput->GetOriginTrackedDeviceInfo(origin, pOriginInfo, unOriginInfoSize);
}

vr::EVRInputError VirtualInput_004::ShowActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t ulActionHandle)
{
	return VRClient::cInstance->vInput->ShowActionOrigins(actionSetHandle, ulActionHandle);
}

vr::EVRInputError VirtualInput_004::ShowBindingsForActionSet(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, vr::VRInputValueHandle_t originToHighlight)
{
	return VRClient::cInstance->vInput->ShowBindingsForActionSet(pSets, unSizeOfVRSelectedActionSet_t, unSetCount, originToHighlight);
}

/**			Fn Table			*/


vr::EVRInputError __stdcall fntable_Input_004_impl_SetActionManifestPath(const char* pchActionManifestPath)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->SetActionManifestPath(pchActionManifestPath);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetActionSetHandle(const char* pchActionSetName, vr::VRActionSetHandle_t* pHandle)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetActionSetHandle(pchActionSetName, pHandle);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetActionHandle(const char* pchActionName, vr::VRActionHandle_t* pHandle)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetActionHandle(pchActionName, pHandle);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetInputSourceHandle(const char* pchInputSourcePath, vr::VRInputValueHandle_t* pHandle)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetInputSourceHandle(pchInputSourcePath, pHandle);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_UpdateActionState(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->UpdateActionState(pSets, unSizeOfVRSelectedActionSet_t, unSetCount);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetDigitalActionData(vr::VRActionHandle_t action, vr::InputDigitalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetDigitalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetAnalogActionData(vr::VRActionHandle_t action, vr::InputAnalogActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetAnalogActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetPoseActionData(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetPoseActionData(action, eOrigin, fPredictedSecondsFromNow, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetSkeletalActionData(vr::VRActionHandle_t action, vr::InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetSkeletalBoneData(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalBoneData(action, eTransformSpace, eMotionRange, pTransformArray, unTransformArrayCount, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetSkeletalBoneDataCompressed(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalBoneDataCompressed(action, eTransformSpace, eMotionRange, pvCompressedData, unCompressedSize, punRequiredCompressedSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_DecompressSkeletalBoneData(void* pvCompressedBuffer, uint32_t unCompressedBufferSize, vr::EVRSkeletalTransformSpace* peTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->DecompressSkeletalBoneData(pvCompressedBuffer, unCompressedBufferSize, peTransformSpace, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_TriggerHapticVibrationAction(vr::VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->TriggerHapticVibrationAction(action, fStartSecondsFromNow, fDurationSeconds, fFrequency, fAmplitude, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT(originOutCount)vr::VRInputValueHandle_t* originsOut, uint32_t originOutCount)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetActionOrigins(actionSetHandle, digitalActionHandle, originsOut, originOutCount);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetOriginLocalizedName(vr::VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetOriginLocalizedName(origin, pchNameArray, unNameArraySize);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_GetOriginTrackedDeviceInfo(vr::VRInputValueHandle_t origin, vr::InputOriginInfo_t* pOriginInfo, uint32_t unOriginInfoSize)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->GetOriginTrackedDeviceInfo(origin, pOriginInfo, unOriginInfoSize);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_ShowActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t ulActionHandle)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->ShowActionOrigins(actionSetHandle, ulActionHandle);
}

vr::EVRInputError __stdcall fntable_Input_004_impl_ShowBindingsForActionSet(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, vr::VRInputValueHandle_t originToHighlight)
{
	return static_cast<VirtualInput_004*>(VRClient::cInstance->vInput->steamInput)->ShowBindingsForActionSet(pSets, unSizeOfVRSelectedActionSet_t, unSetCount, originToHighlight);
}

static void* fnTable_VirtualInput_004[] = {
	fntable_Input_004_impl_SetActionManifestPath,
	fntable_Input_004_impl_GetActionSetHandle,
	fntable_Input_004_impl_GetActionHandle,
	fntable_Input_004_impl_GetInputSourceHandle,
	fntable_Input_004_impl_UpdateActionState,
	fntable_Input_004_impl_GetDigitalActionData,
	fntable_Input_004_impl_GetAnalogActionData,
	fntable_Input_004_impl_GetPoseActionData,
	fntable_Input_004_impl_GetSkeletalActionData,
	fntable_Input_004_impl_GetSkeletalBoneData,
	fntable_Input_004_impl_GetSkeletalBoneDataCompressed,
	fntable_Input_004_impl_DecompressSkeletalBoneData,
	fntable_Input_004_impl_TriggerHapticVibrationAction,
	fntable_Input_004_impl_GetActionOrigins,
	fntable_Input_004_impl_GetOriginLocalizedName,
	fntable_Input_004_impl_GetOriginTrackedDeviceInfo,
	fntable_Input_004_impl_ShowActionOrigins,
	fntable_Input_004_impl_ShowBindingsForActionSet,
};

void* VirtualInput_004::GetFnTable()
{
	return fnTable_VirtualInput_004;
}
