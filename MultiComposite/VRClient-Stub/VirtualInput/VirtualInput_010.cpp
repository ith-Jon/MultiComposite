#include "VirtualInput_010.h"
#include "VRClient.h"

EVRInputError VirtualInput_010::SetActionManifestPath(const char* pchActionManifestPath)
{
	return VRClient::cInstance->vInput->SetActionManifestPath(pchActionManifestPath);
}

EVRInputError VirtualInput_010::GetActionSetHandle(const char* pchActionSetName, VRActionSetHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetActionSetHandle(pchActionSetName, pHandle);
}

EVRInputError VirtualInput_010::GetActionHandle(const char* pchActionName, VRActionHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetActionHandle(pchActionName, pHandle);
}

EVRInputError VirtualInput_010::GetInputSourceHandle(const char* pchInputSourcePath, VRInputValueHandle_t* pHandle)
{
	return VRClient::cInstance->vInput->GetInputSourceHandle(pchInputSourcePath, pHandle);
}

EVRInputError VirtualInput_010::UpdateActionState(VR_ARRAY_COUNT(unSetCount)VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount)
{
	return VRClient::cInstance->vInput->UpdateActionState(pSets, unSizeOfVRSelectedActionSet_t, unSetCount);
}

EVRInputError VirtualInput_010::GetDigitalActionData(VRActionHandle_t action, InputDigitalActionData_t* pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetDigitalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

EVRInputError VirtualInput_010::GetAnalogActionData(VRActionHandle_t action, InputAnalogActionData_t* pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetAnalogActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

EVRInputError VirtualInput_010::GetPoseActionDataRelativeToNow(VRActionHandle_t action, ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, InputPoseActionData_t* pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetPoseActionDataRelativeToNow(action, eOrigin, fPredictedSecondsFromNow, pActionData, unActionDataSize, ulRestrictToDevice);
}

EVRInputError VirtualInput_010::GetPoseActionDataForNextFrame(VRActionHandle_t action, ETrackingUniverseOrigin eOrigin, InputPoseActionData_t* pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->GetPoseActionDataForNextFrame(action, eOrigin, pActionData, unActionDataSize, ulRestrictToDevice);
}

EVRInputError VirtualInput_010::GetSkeletalActionData(VRActionHandle_t action, InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize)
{
	return VRClient::cInstance->vInput->GetSkeletalActionData(action, pActionData, unActionDataSize);
}

EVRInputError VirtualInput_010::GetDominantHand(ETrackedControllerRole* peDominantHand)
{
	return VRClient::cInstance->vInput->GetDominantHand(peDominantHand);
}

EVRInputError VirtualInput_010::SetDominantHand(ETrackedControllerRole eDominantHand)
{
	return VRClient::cInstance->vInput->SetDominantHand(eDominantHand);
}

EVRInputError VirtualInput_010::GetBoneCount(VRActionHandle_t action, uint32_t* pBoneCount)
{
	return VRClient::cInstance->vInput->GetBoneCount(action, pBoneCount);
}

EVRInputError VirtualInput_010::GetBoneHierarchy(VRActionHandle_t action, VR_ARRAY_COUNT(unIndexArayCount)BoneIndex_t* pParentIndices, uint32_t unIndexArayCount)
{
	return VRClient::cInstance->vInput->GetBoneHierarchy(action, pParentIndices, unIndexArayCount);
}

EVRInputError VirtualInput_010::GetBoneName(VRActionHandle_t action, BoneIndex_t nBoneIndex, VR_OUT_STRING() char* pchBoneName, uint32_t unNameBufferSize)
{
	return VRClient::cInstance->vInput->GetBoneName(action, nBoneIndex, pchBoneName, unNameBufferSize);
}

EVRInputError VirtualInput_010::GetSkeletalReferenceTransforms(VRActionHandle_t action, EVRSkeletalTransformSpace eTransformSpace, EVRSkeletalReferencePose eReferencePose, VR_ARRAY_COUNT(unTransformArrayCount)VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return VRClient::cInstance->vInput->GetSkeletalReferenceTransforms(action, eTransformSpace, eReferencePose, pTransformArray, unTransformArrayCount);
}

EVRInputError VirtualInput_010::GetSkeletalTrackingLevel(VRActionHandle_t action, EVRSkeletalTrackingLevel* pSkeletalTrackingLevel)
{
	return VRClient::cInstance->vInput->GetSkeletalTrackingLevel(action, pSkeletalTrackingLevel);
}

EVRInputError VirtualInput_010::GetSkeletalBoneData(VRActionHandle_t action, EVRSkeletalTransformSpace eTransformSpace, EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount)VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return VRClient::cInstance->vInput->GetSkeletalBoneData(action, eTransformSpace, eMotionRange, pTransformArray, unTransformArrayCount);
}

EVRInputError VirtualInput_010::GetSkeletalSummaryData(VRActionHandle_t action, EVRSummaryType eSummaryType, VRSkeletalSummaryData_t* pSkeletalSummaryData)
{
	return VRClient::cInstance->vInput->GetSkeletalSummaryData(action, eSummaryType, pSkeletalSummaryData);
}

EVRInputError VirtualInput_010::GetSkeletalBoneDataCompressed(VRActionHandle_t action, EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize)
{
	return VRClient::cInstance->vInput->GetSkeletalBoneDataCompressed(action, eMotionRange, pvCompressedData, unCompressedSize, punRequiredCompressedSize);
}

EVRInputError VirtualInput_010::DecompressSkeletalBoneData(const void* pvCompressedBuffer, uint32_t unCompressedBufferSize, EVRSkeletalTransformSpace eTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount)VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return VRClient::cInstance->vInput->DecompressSkeletalBoneData(pvCompressedBuffer, unCompressedBufferSize, eTransformSpace, pTransformArray, unTransformArrayCount);
}

EVRInputError VirtualInput_010::TriggerHapticVibrationAction(VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, VRInputValueHandle_t ulRestrictToDevice)
{
	return VRClient::cInstance->vInput->TriggerHapticVibrationAction(action, fStartSecondsFromNow, fDurationSeconds, fFrequency, fAmplitude, ulRestrictToDevice);
}

EVRInputError VirtualInput_010::GetActionOrigins(VRActionSetHandle_t actionSetHandle, VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT(originOutCount)VRInputValueHandle_t* originsOut, uint32_t originOutCount)
{
	return VRClient::cInstance->vInput->GetActionOrigins(actionSetHandle, digitalActionHandle, originsOut, originOutCount);
}

EVRInputError VirtualInput_010::GetOriginLocalizedName(VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize, int32_t unStringSectionsToInclude)
{
	return VRClient::cInstance->vInput->GetOriginLocalizedName(origin, pchNameArray, unNameArraySize, unStringSectionsToInclude);
}

EVRInputError VirtualInput_010::GetOriginTrackedDeviceInfo(VRInputValueHandle_t origin, InputOriginInfo_t* pOriginInfo, uint32_t unOriginInfoSize)
{
	return VRClient::cInstance->vInput->GetOriginTrackedDeviceInfo(origin, pOriginInfo, unOriginInfoSize);
}

EVRInputError VirtualInput_010::GetActionBindingInfo(VRActionHandle_t action, InputBindingInfo_t* pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount, uint32_t* punReturnedBindingInfoCount)
{
	return VRClient::cInstance->vInput->GetActionBindingInfo(action, pOriginInfo, unBindingInfoCount, unBindingInfoCount, punReturnedBindingInfoCount);
}

EVRInputError VirtualInput_010::ShowActionOrigins(VRActionSetHandle_t actionSetHandle, VRActionHandle_t ulActionHandle)
{
	return VRClient::cInstance->vInput->ShowActionOrigins(actionSetHandle, ulActionHandle);
}

EVRInputError VirtualInput_010::ShowBindingsForActionSet(VR_ARRAY_COUNT(unSetCount)VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, VRInputValueHandle_t originToHighlight)
{
	return VRClient::cInstance->vInput->ShowBindingsForActionSet(pSets, unSizeOfVRSelectedActionSet_t, unSetCount, originToHighlight);
}

EVRInputError VirtualInput_010::GetComponentStateForBinding(const char* pchRenderModelName, const char* pchComponentName, const InputBindingInfo_t* pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount, RenderModel_ComponentState_t* pComponentState)
{
	return VRClient::cInstance->vInput->GetComponentStateForBinding(pchRenderModelName, pchComponentName, pOriginInfo, unBindingInfoSize, unBindingInfoCount, pComponentState);
}

bool VirtualInput_010::IsUsingLegacyInput()
{
	return VRClient::cInstance->vInput->IsUsingLegacyInput();
}

EVRInputError VirtualInput_010::OpenBindingUI(const char* pchAppKey, VRActionSetHandle_t ulActionSetHandle, VRInputValueHandle_t ulDeviceHandle, bool bShowOnDesktop)
{
	return VRClient::cInstance->vInput->OpenBindingUI(pchAppKey, ulActionSetHandle, ulDeviceHandle, bShowOnDesktop);
}

EVRInputError VirtualInput_010::GetBindingVariant(VRInputValueHandle_t ulDevicePath, VR_OUT_STRING() char* pchVariantArray, uint32_t unVariantArraySize)
{
	return VRClient::cInstance->vInput->GetBindingVariant(ulDevicePath, pchVariantArray, unVariantArraySize);
}

/**			Fn Table			*/


EVRInputError __stdcall fntable_Input_010_impl_SetActionManifestPath(const char* pchActionManifestPath)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->SetActionManifestPath(pchActionManifestPath);
}

EVRInputError __stdcall fntable_Input_010_impl_GetActionSetHandle(const char* pchActionSetName, VRActionSetHandle_t* pHandle)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetActionSetHandle(pchActionSetName, pHandle);
}

EVRInputError __stdcall fntable_Input_010_impl_GetActionHandle(const char* pchActionName, VRActionHandle_t* pHandle)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetActionHandle(pchActionName, pHandle);
}

EVRInputError __stdcall fntable_Input_010_impl_GetInputSourceHandle(const char* pchInputSourcePath, VRInputValueHandle_t* pHandle)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetInputSourceHandle(pchInputSourcePath, pHandle);
}

EVRInputError __stdcall fntable_Input_010_impl_UpdateActionState(VR_ARRAY_COUNT(unSetCount)VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->UpdateActionState(pSets, unSizeOfVRSelectedActionSet_t, unSetCount);
}

EVRInputError __stdcall fntable_Input_010_impl_GetDigitalActionData(VRActionHandle_t action, InputDigitalActionData_t* pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetDigitalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

EVRInputError __stdcall fntable_Input_010_impl_GetAnalogActionData(VRActionHandle_t action, InputAnalogActionData_t* pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetAnalogActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

EVRInputError __stdcall fntable_Input_010_impl_GetPoseActionDataRelativeToNow(VRActionHandle_t action, ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, InputPoseActionData_t* pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetPoseActionDataRelativeToNow(action, eOrigin, fPredictedSecondsFromNow, pActionData, unActionDataSize, ulRestrictToDevice);
}

EVRInputError __stdcall fntable_Input_010_impl_GetPoseActionDataForNextFrame(VRActionHandle_t action, ETrackingUniverseOrigin eOrigin, InputPoseActionData_t* pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetPoseActionDataForNextFrame(action, eOrigin, pActionData, unActionDataSize, ulRestrictToDevice);
}

EVRInputError __stdcall fntable_Input_010_impl_GetSkeletalActionData(VRActionHandle_t action, InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetSkeletalActionData(action, pActionData, unActionDataSize);
}

EVRInputError __stdcall fntable_Input_010_impl_GetDominantHand(ETrackedControllerRole* peDominantHand)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetDominantHand(peDominantHand);
}

EVRInputError __stdcall fntable_Input_010_impl_SetDominantHand(ETrackedControllerRole eDominantHand)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->SetDominantHand(eDominantHand);
}

EVRInputError __stdcall fntable_Input_010_impl_GetBoneCount(VRActionHandle_t action, uint32_t* pBoneCount)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetBoneCount(action, pBoneCount);
}

EVRInputError __stdcall fntable_Input_010_impl_GetBoneHierarchy(VRActionHandle_t action, VR_ARRAY_COUNT(unIndexArayCount)BoneIndex_t* pParentIndices, uint32_t unIndexArayCount)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetBoneHierarchy(action, pParentIndices, unIndexArayCount);
}

EVRInputError __stdcall fntable_Input_010_impl_GetBoneName(VRActionHandle_t action, BoneIndex_t nBoneIndex, VR_OUT_STRING() char* pchBoneName, uint32_t unNameBufferSize)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetBoneName(action, nBoneIndex, pchBoneName, unNameBufferSize);
}

EVRInputError __stdcall fntable_Input_010_impl_GetSkeletalReferenceTransforms(VRActionHandle_t action, EVRSkeletalTransformSpace eTransformSpace, EVRSkeletalReferencePose eReferencePose, VR_ARRAY_COUNT(unTransformArrayCount)VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetSkeletalReferenceTransforms(action, eTransformSpace, eReferencePose, pTransformArray, unTransformArrayCount);
}

EVRInputError __stdcall fntable_Input_010_impl_GetSkeletalTrackingLevel(VRActionHandle_t action, EVRSkeletalTrackingLevel* pSkeletalTrackingLevel)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetSkeletalTrackingLevel(action, pSkeletalTrackingLevel);
}

EVRInputError __stdcall fntable_Input_010_impl_GetSkeletalBoneData(VRActionHandle_t action, EVRSkeletalTransformSpace eTransformSpace, EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount)VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetSkeletalBoneData(action, eTransformSpace, eMotionRange, pTransformArray, unTransformArrayCount);
}

EVRInputError __stdcall fntable_Input_010_impl_GetSkeletalSummaryData(VRActionHandle_t action, EVRSummaryType eSummaryType, VRSkeletalSummaryData_t* pSkeletalSummaryData)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetSkeletalSummaryData(action, eSummaryType, pSkeletalSummaryData);
}

EVRInputError __stdcall fntable_Input_010_impl_GetSkeletalBoneDataCompressed(VRActionHandle_t action, EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetSkeletalBoneDataCompressed(action, eMotionRange, pvCompressedData, unCompressedSize, punRequiredCompressedSize);
}

EVRInputError __stdcall fntable_Input_010_impl_DecompressSkeletalBoneData(const void* pvCompressedBuffer, uint32_t unCompressedBufferSize, EVRSkeletalTransformSpace eTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount)VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->DecompressSkeletalBoneData(pvCompressedBuffer, unCompressedBufferSize, eTransformSpace, pTransformArray, unTransformArrayCount);
}

EVRInputError __stdcall fntable_Input_010_impl_TriggerHapticVibrationAction(VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->TriggerHapticVibrationAction(action, fStartSecondsFromNow, fDurationSeconds, fFrequency, fAmplitude, ulRestrictToDevice);
}

EVRInputError __stdcall fntable_Input_010_impl_GetActionOrigins(VRActionSetHandle_t actionSetHandle, VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT(originOutCount)VRInputValueHandle_t* originsOut, uint32_t originOutCount)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetActionOrigins(actionSetHandle, digitalActionHandle, originsOut, originOutCount);
}

EVRInputError __stdcall fntable_Input_010_impl_GetOriginLocalizedName(VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize, int32_t unStringSectionsToInclude)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetOriginLocalizedName(origin, pchNameArray, unNameArraySize, unStringSectionsToInclude);
}

EVRInputError __stdcall fntable_Input_010_impl_GetOriginTrackedDeviceInfo(VRInputValueHandle_t origin, InputOriginInfo_t* pOriginInfo, uint32_t unOriginInfoSize)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetOriginTrackedDeviceInfo(origin, pOriginInfo, unOriginInfoSize);
}

EVRInputError __stdcall fntable_Input_010_impl_GetActionBindingInfo(VRActionHandle_t action, InputBindingInfo_t* pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount, uint32_t* punReturnedBindingInfoCount)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetActionBindingInfo(action, pOriginInfo, unBindingInfoCount, unBindingInfoCount, punReturnedBindingInfoCount);
}

EVRInputError __stdcall fntable_Input_010_impl_ShowActionOrigins(VRActionSetHandle_t actionSetHandle, VRActionHandle_t ulActionHandle)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->ShowActionOrigins(actionSetHandle, ulActionHandle);
}

EVRInputError __stdcall fntable_Input_010_impl_ShowBindingsForActionSet(VR_ARRAY_COUNT(unSetCount)VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, VRInputValueHandle_t originToHighlight)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->ShowBindingsForActionSet(pSets, unSizeOfVRSelectedActionSet_t, unSetCount, originToHighlight);
}

EVRInputError __stdcall fntable_Input_010_impl_GetComponentStateForBinding(const char* pchRenderModelName, const char* pchComponentName, const InputBindingInfo_t* pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount, RenderModel_ComponentState_t* pComponentState)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetComponentStateForBinding(pchRenderModelName, pchComponentName, pOriginInfo, unBindingInfoSize, unBindingInfoCount, pComponentState);
}

bool __stdcall fntable_Input_010_impl_IsUsingLegacyInput()
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->IsUsingLegacyInput();
}

EVRInputError __stdcall fntable_Input_010_impl_OpenBindingUI(const char* pchAppKey, VRActionSetHandle_t ulActionSetHandle, VRInputValueHandle_t ulDeviceHandle, bool bShowOnDesktop)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->OpenBindingUI(pchAppKey, ulActionSetHandle, ulDeviceHandle, bShowOnDesktop);
}

EVRInputError __stdcall fntable_Input_010_impl_GetBindingVariant(VRInputValueHandle_t ulDevicePath, VR_OUT_STRING() char* pchVariantArray, uint32_t unVariantArraySize)
{
	return static_cast<VirtualInput_010*>(VRClient::cInstance->vInput->virtualInput)->GetBindingVariant(ulDevicePath, pchVariantArray, unVariantArraySize);
}

static void* fnTable_VirtualInput_010[] = {
	fntable_Input_010_impl_SetActionManifestPath,
	fntable_Input_010_impl_GetActionSetHandle,
	fntable_Input_010_impl_GetActionHandle,
	fntable_Input_010_impl_GetInputSourceHandle,
	fntable_Input_010_impl_UpdateActionState,
	fntable_Input_010_impl_GetDigitalActionData,
	fntable_Input_010_impl_GetAnalogActionData,
	fntable_Input_010_impl_GetPoseActionDataRelativeToNow,
	fntable_Input_010_impl_GetPoseActionDataForNextFrame,
	fntable_Input_010_impl_GetSkeletalActionData,
	fntable_Input_010_impl_GetDominantHand,
	fntable_Input_010_impl_SetDominantHand,
	fntable_Input_010_impl_GetBoneCount,
	fntable_Input_010_impl_GetBoneHierarchy,
	fntable_Input_010_impl_GetBoneName,
	fntable_Input_010_impl_GetSkeletalReferenceTransforms,
	fntable_Input_010_impl_GetSkeletalTrackingLevel,
	fntable_Input_010_impl_GetSkeletalBoneData,
	fntable_Input_010_impl_GetSkeletalSummaryData,
	fntable_Input_010_impl_GetSkeletalBoneDataCompressed,
	fntable_Input_010_impl_DecompressSkeletalBoneData,
	fntable_Input_010_impl_TriggerHapticVibrationAction,
	fntable_Input_010_impl_GetActionOrigins,
	fntable_Input_010_impl_GetOriginLocalizedName,
	fntable_Input_010_impl_GetOriginTrackedDeviceInfo,
	fntable_Input_010_impl_GetActionBindingInfo,
	fntable_Input_010_impl_ShowActionOrigins,
	fntable_Input_010_impl_ShowBindingsForActionSet,
	fntable_Input_010_impl_GetComponentStateForBinding,
	fntable_Input_010_impl_IsUsingLegacyInput,
	fntable_Input_010_impl_OpenBindingUI,
	fntable_Input_010_impl_GetBindingVariant,
};

void* VirtualInput_010::GetFnTable()
{
	return fnTable_VirtualInput_010;
}
