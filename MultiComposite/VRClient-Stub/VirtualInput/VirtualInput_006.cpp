#include "VirtualInput_006.h"
#include "VRClient.h"

vr::EVRInputError VirtualInput_006::SetActionManifestPath(const char* pchActionManifestPath)
{
	return VRClient::cInstance->vInput->SetActionManifestPath(pchActionManifestPath);
}

vr::EVRInputError VirtualInput_006::GetActionSetHandle(const char* pchActionSetName, vr::VRActionSetHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetActionSetHandle(pchActionSetName, pHandle);
}

vr::EVRInputError VirtualInput_006::GetActionHandle(const char* pchActionName, vr::VRActionHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetActionHandle(pchActionName, pHandle);
}

vr::EVRInputError VirtualInput_006::GetInputSourceHandle(const char* pchInputSourcePath, vr::VRInputValueHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetInputSourceHandle(pchInputSourcePath, pHandle);
}

vr::EVRInputError VirtualInput_006::UpdateActionState(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount)
{
	return VRClient::cInstance->vInput->UpdateActionState(pSets, unSizeOfVRSelectedActionSet_t, unSetCount);
}

vr::EVRInputError VirtualInput_006::GetDigitalActionData(vr::VRActionHandle_t action, vr::InputDigitalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetDigitalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_006::GetAnalogActionData(vr::VRActionHandle_t action, vr::InputAnalogActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetAnalogActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_006::GetPoseActionDataRelativeToNow(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetPoseActionDataRelativeToNow(action, eOrigin, fPredictedSecondsFromNow, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_006::GetPoseActionDataForNextFrame(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetPoseActionDataForNextFrame(action, eOrigin, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_006::GetSkeletalActionData(vr::VRActionHandle_t action, vr::InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize)
{
	return VRClient::cInstance->vInput->GetSkeletalActionData(action, pActionData, unActionDataSize);
}

vr::EVRInputError VirtualInput_006::GetBoneCount(vr::VRActionHandle_t action, uint32_t* pBoneCount)
{
	return VRClient::cInstance->vInput->GetBoneCount(action, pBoneCount);
}

vr::EVRInputError VirtualInput_006::GetBoneHierarchy(vr::VRActionHandle_t action, VR_ARRAY_COUNT(unIndexArayCount)vr::BoneIndex_t* pParentIndices, uint32_t unIndexArayCount)
{
	return VRClient::cInstance->vInput->GetBoneHierarchy(action, pParentIndices, unIndexArayCount);
}

vr::EVRInputError VirtualInput_006::GetBoneName(vr::VRActionHandle_t action, vr::BoneIndex_t nBoneIndex, VR_OUT_STRING() char* pchBoneName, uint32_t unNameBufferSize)
{
	return VRClient::cInstance->vInput->GetBoneName(action, nBoneIndex, pchBoneName, unNameBufferSize);
}

vr::EVRInputError VirtualInput_006::GetSkeletalReferenceTransforms(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalReferencePose eReferencePose, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return VRClient::cInstance->vInput->GetSkeletalReferenceTransforms(action, eTransformSpace, eReferencePose, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput_006::GetSkeletalTrackingLevel(vr::VRActionHandle_t action, vr::EVRSkeletalTrackingLevel* pSkeletalTrackingLevel)
{
	return VRClient::cInstance->vInput->GetSkeletalTrackingLevel(action, pSkeletalTrackingLevel);
}

vr::EVRInputError VirtualInput_006::GetSkeletalBoneData(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return VRClient::cInstance->vInput->GetSkeletalBoneData(action, eTransformSpace, eMotionRange, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput_006::GetSkeletalSummaryData(vr::VRActionHandle_t action, vr::EVRSummaryType eSummaryType, vr::VRSkeletalSummaryData_t* pSkeletalSummaryData)
{
	return VRClient::cInstance->vInput->GetSkeletalSummaryData(action, eSummaryType, pSkeletalSummaryData);
}

vr::EVRInputError VirtualInput_006::GetSkeletalBoneDataCompressed(vr::VRActionHandle_t action, vr::EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize)
{
	return VRClient::cInstance->vInput->GetSkeletalBoneDataCompressed(action, eMotionRange, pvCompressedData, unCompressedSize, punRequiredCompressedSize);
}

vr::EVRInputError VirtualInput_006::DecompressSkeletalBoneData(const void* pvCompressedBuffer, uint32_t unCompressedBufferSize, vr::EVRSkeletalTransformSpace eTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return VRClient::cInstance->vInput->DecompressSkeletalBoneData(pvCompressedBuffer, unCompressedBufferSize, eTransformSpace, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput_006::TriggerHapticVibrationAction(vr::VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->TriggerHapticVibrationAction(action, fStartSecondsFromNow, fDurationSeconds, fFrequency, fAmplitude, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput_006::GetActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT(originOutCount)vr::VRInputValueHandle_t* originsOut, uint32_t originOutCount)
{
	return VRClient::cInstance->vInput->GetActionOrigins(actionSetHandle, digitalActionHandle, originsOut, originOutCount);
}

vr::EVRInputError VirtualInput_006::GetOriginLocalizedName(vr::VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize, int32_t unStringSectionsToInclude)
{
	return VRClient::cInstance->vInput->GetOriginLocalizedName(origin, pchNameArray, unNameArraySize, unStringSectionsToInclude);
}

vr::EVRInputError VirtualInput_006::GetOriginTrackedDeviceInfo(vr::VRInputValueHandle_t origin, vr::InputOriginInfo_t* pOriginInfo, uint32_t unOriginInfoSize)
{
	return VRClient::cInstance->vInput->GetOriginTrackedDeviceInfo(origin, pOriginInfo, unOriginInfoSize);
}

vr::EVRInputError VirtualInput_006::ShowActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t ulActionHandle)
{
	return VRClient::cInstance->vInput->ShowActionOrigins(actionSetHandle, ulActionHandle);
}

vr::EVRInputError VirtualInput_006::ShowBindingsForActionSet(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, vr::VRInputValueHandle_t originToHighlight)
{
	return VRClient::cInstance->vInput->ShowBindingsForActionSet(pSets, unSizeOfVRSelectedActionSet_t, unSetCount, originToHighlight);
}

bool VirtualInput_006::IsUsingLegacyInput()
{
	return VRClient::cInstance->vInput->IsUsingLegacyInput();
}

/**			Fn Table			*/


vr::EVRInputError __stdcall fntable_Input_006_impl_SetActionManifestPath(const char* pchActionManifestPath)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->SetActionManifestPath(pchActionManifestPath);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetActionSetHandle(const char* pchActionSetName, vr::VRActionSetHandle_t* pHandle)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetActionSetHandle(pchActionSetName, pHandle);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetActionHandle(const char* pchActionName, vr::VRActionHandle_t* pHandle)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetActionHandle(pchActionName, pHandle);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetInputSourceHandle(const char* pchInputSourcePath, vr::VRInputValueHandle_t* pHandle)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetInputSourceHandle(pchInputSourcePath, pHandle);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_UpdateActionState(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->UpdateActionState(pSets, unSizeOfVRSelectedActionSet_t, unSetCount);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetDigitalActionData(vr::VRActionHandle_t action, vr::InputDigitalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetDigitalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetAnalogActionData(vr::VRActionHandle_t action, vr::InputAnalogActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetAnalogActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetPoseActionDataRelativeToNow(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetPoseActionDataRelativeToNow(action, eOrigin, fPredictedSecondsFromNow, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetPoseActionDataForNextFrame(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetPoseActionDataForNextFrame(action, eOrigin, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetSkeletalActionData(vr::VRActionHandle_t action, vr::InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalActionData(action, pActionData, unActionDataSize);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetBoneCount(vr::VRActionHandle_t action, uint32_t* pBoneCount)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetBoneCount(action, pBoneCount);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetBoneHierarchy(vr::VRActionHandle_t action, VR_ARRAY_COUNT(unIndexArayCount)vr::BoneIndex_t* pParentIndices, uint32_t unIndexArayCount)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetBoneHierarchy(action, pParentIndices, unIndexArayCount);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetBoneName(vr::VRActionHandle_t action, vr::BoneIndex_t nBoneIndex, VR_OUT_STRING() char* pchBoneName, uint32_t unNameBufferSize)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetBoneName(action, nBoneIndex, pchBoneName, unNameBufferSize);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetSkeletalReferenceTransforms(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalReferencePose eReferencePose, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalReferenceTransforms(action, eTransformSpace, eReferencePose, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetSkeletalTrackingLevel(vr::VRActionHandle_t action, vr::EVRSkeletalTrackingLevel* pSkeletalTrackingLevel)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalTrackingLevel(action, pSkeletalTrackingLevel);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetSkeletalBoneData(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalBoneData(action, eTransformSpace, eMotionRange, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetSkeletalSummaryData(vr::VRActionHandle_t action, vr::EVRSummaryType eSummaryType, vr::VRSkeletalSummaryData_t* pSkeletalSummaryData)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalSummaryData(action, eSummaryType, pSkeletalSummaryData);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetSkeletalBoneDataCompressed(vr::VRActionHandle_t action, vr::EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetSkeletalBoneDataCompressed(action, eMotionRange, pvCompressedData, unCompressedSize, punRequiredCompressedSize);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_DecompressSkeletalBoneData(const void* pvCompressedBuffer, uint32_t unCompressedBufferSize, vr::EVRSkeletalTransformSpace eTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->DecompressSkeletalBoneData(pvCompressedBuffer, unCompressedBufferSize, eTransformSpace, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_TriggerHapticVibrationAction(vr::VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->TriggerHapticVibrationAction(action, fStartSecondsFromNow, fDurationSeconds, fFrequency, fAmplitude, ulRestrictToDevice);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT(originOutCount)vr::VRInputValueHandle_t* originsOut, uint32_t originOutCount)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetActionOrigins(actionSetHandle, digitalActionHandle, originsOut, originOutCount);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetOriginLocalizedName(vr::VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize, int32_t unStringSectionsToInclude)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetOriginLocalizedName(origin, pchNameArray, unNameArraySize, unStringSectionsToInclude);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_GetOriginTrackedDeviceInfo(vr::VRInputValueHandle_t origin, vr::InputOriginInfo_t* pOriginInfo, uint32_t unOriginInfoSize)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->GetOriginTrackedDeviceInfo(origin, pOriginInfo, unOriginInfoSize);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_ShowActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t ulActionHandle)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->ShowActionOrigins(actionSetHandle, ulActionHandle);
}

vr::EVRInputError __stdcall fntable_Input_006_impl_ShowBindingsForActionSet(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, vr::VRInputValueHandle_t originToHighlight)
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->ShowBindingsForActionSet(pSets, unSizeOfVRSelectedActionSet_t, unSetCount, originToHighlight);
}

bool __stdcall fntable_Input_006_impl_IsUsingLegacyInput()
{
	return static_cast<VirtualInput_006*>(VRClient::cInstance->vInput->steamInput)->IsUsingLegacyInput();
}

static void* fnTable_VirtualInput_006[] = {
	fntable_Input_006_impl_SetActionManifestPath,
	fntable_Input_006_impl_GetActionSetHandle,
	fntable_Input_006_impl_GetActionHandle,
	fntable_Input_006_impl_GetInputSourceHandle,
	fntable_Input_006_impl_UpdateActionState,
	fntable_Input_006_impl_GetDigitalActionData,
	fntable_Input_006_impl_GetAnalogActionData,
	fntable_Input_006_impl_GetPoseActionDataRelativeToNow,
	fntable_Input_006_impl_GetPoseActionDataForNextFrame,
	fntable_Input_006_impl_GetSkeletalActionData,
	fntable_Input_006_impl_GetBoneCount,
	fntable_Input_006_impl_GetBoneHierarchy,
	fntable_Input_006_impl_GetBoneName,
	fntable_Input_006_impl_GetSkeletalReferenceTransforms,
	fntable_Input_006_impl_GetSkeletalTrackingLevel,
	fntable_Input_006_impl_GetSkeletalBoneData,
	fntable_Input_006_impl_GetSkeletalSummaryData,
	fntable_Input_006_impl_GetSkeletalBoneDataCompressed,
	fntable_Input_006_impl_DecompressSkeletalBoneData,
	fntable_Input_006_impl_TriggerHapticVibrationAction,
	fntable_Input_006_impl_GetActionOrigins,
	fntable_Input_006_impl_GetOriginLocalizedName,
	fntable_Input_006_impl_GetOriginTrackedDeviceInfo,
	fntable_Input_006_impl_ShowActionOrigins,
	fntable_Input_006_impl_ShowBindingsForActionSet,
	fntable_Input_006_impl_IsUsingLegacyInput,
};

void* VirtualInput_006::GetFnTable()
{
	return fnTable_VirtualInput_006;
}
