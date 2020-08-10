#include "VirtualInput.h"
#include "VRClient.h"

#include "Logger.h"

vr::EVRInputError VirtualInput::SetActionManifestPath(const char* pchActionManifestPath)
{
	dlog::Println("[VirtualInput::SetActionManifestPath] Called.");
	return static_cast<IVRInput_010*>(steamInput)->SetActionManifestPath(pchActionManifestPath);
}

vr::EVRInputError VirtualInput::GetActionSetHandle(const char* pchActionSetName, vr::VRActionSetHandle_t* pHandle)
{
	return static_cast<IVRInput_010*>(steamInput)->GetActionSetHandle(pchActionSetName, pHandle);
}

vr::EVRInputError VirtualInput::GetActionHandle(const char* pchActionName, vr::VRActionHandle_t* pHandle)
{
	return static_cast<IVRInput_010*>(steamInput)->GetActionHandle(pchActionName, pHandle);
}

vr::EVRInputError VirtualInput::GetInputSourceHandle(const char* pchInputSourcePath, vr::VRInputValueHandle_t* pHandle)
{
	return static_cast<IVRInput_010*>(steamInput)->GetInputSourceHandle(pchInputSourcePath, pHandle);
}

vr::EVRInputError VirtualInput::UpdateActionState(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
		return VRInputError_None;

	return static_cast<IVRInput_010*>(steamInput)->UpdateActionState(pSets, unSizeOfVRSelectedActionSet_t, unSetCount);
}

vr::EVRInputError VirtualInput::GetDigitalActionData(vr::VRActionHandle_t action, vr::InputDigitalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
		return VRInputError_None;

	return static_cast<IVRInput_010*>(steamInput)->GetDigitalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput::GetAnalogActionData(vr::VRActionHandle_t action, vr::InputAnalogActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesInputs) != ApplicationPermissions_ReceivesInputs)
		return VRInputError_None;

	return static_cast<IVRInput_010*>(steamInput)->GetAnalogActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput::GetPoseActionData(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
		return VRInputError_None;

	return static_cast<IVRInput_005*>(steamInput)->GetPoseActionData(action, eOrigin, fPredictedSecondsFromNow, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput::GetPoseActionDataRelativeToNow(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
		return VRInputError_None;

	return static_cast<IVRInput_010*>(steamInput)->GetPoseActionDataRelativeToNow(action, eOrigin, fPredictedSecondsFromNow, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput::GetPoseActionDataForNextFrame(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
		return VRInputError_None;

	return static_cast<IVRInput_010*>(steamInput)->GetPoseActionDataForNextFrame(action, eOrigin, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput::GetSkeletalActionData(vr::VRActionHandle_t action, vr::InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
		return VRInputError_None;

	return static_cast<IVRInput_004*>(steamInput)->GetSkeletalActionData(action, pActionData, unActionDataSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput::GetSkeletalActionData(vr::VRActionHandle_t action, vr::InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
		return VRInputError_None;

	return static_cast<IVRInput_010*>(steamInput)->GetSkeletalActionData(action, pActionData, unActionDataSize);
}

vr::EVRInputError VirtualInput::GetDominantHand(vr::ETrackedControllerRole* peDominantHand)
{
	return static_cast<IVRInput_010*>(steamInput)->GetDominantHand(peDominantHand);
}

vr::EVRInputError VirtualInput::SetDominantHand(vr::ETrackedControllerRole eDominantHand)
{
	return static_cast<IVRInput_010*>(steamInput)->SetDominantHand(eDominantHand);
}

vr::EVRInputError VirtualInput::GetBoneCount(vr::VRActionHandle_t action, uint32_t* pBoneCount)
{
	return static_cast<IVRInput_010*>(steamInput)->GetBoneCount(action, pBoneCount);
}

vr::EVRInputError VirtualInput::GetBoneHierarchy(vr::VRActionHandle_t action, VR_ARRAY_COUNT(unIndexArayCount)vr::BoneIndex_t* pParentIndices, uint32_t unIndexArayCount)
{
	return static_cast<IVRInput_010*>(steamInput)->GetBoneHierarchy(action, pParentIndices, unIndexArayCount);
}

vr::EVRInputError VirtualInput::GetBoneName(vr::VRActionHandle_t action, vr::BoneIndex_t nBoneIndex, VR_OUT_STRING() char* pchBoneName, uint32_t unNameBufferSize)
{
	return static_cast<IVRInput_010*>(steamInput)->GetBoneName(action, nBoneIndex, pchBoneName, unNameBufferSize);
}

vr::EVRInputError VirtualInput::GetSkeletalReferenceTransforms(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalReferencePose eReferencePose, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<IVRInput_010*>(steamInput)->GetSkeletalReferenceTransforms(action, eTransformSpace, eReferencePose, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput::GetSkeletalTrackingLevel(vr::VRActionHandle_t action, vr::EVRSkeletalTrackingLevel* pSkeletalTrackingLevel)
{
	return static_cast<IVRInput_010*>(steamInput)->GetSkeletalTrackingLevel(action, pSkeletalTrackingLevel);
}

vr::EVRInputError VirtualInput::GetSkeletalBoneData(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
		return VRInputError_None;

	return static_cast<IVRInput_010*>(steamInput)->GetSkeletalBoneData(action, eTransformSpace, eMotionRange, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput::GetSkeletalBoneData(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	// Check Perms
	if ((VRClient::cInstance->pRuntime->permissions & ApplicationPermissions_ReceivesPoses) != ApplicationPermissions_ReceivesPoses)
		return VRInputError_None;

	return static_cast<IVRInput_010*>(steamInput)->GetSkeletalBoneData(action, eTransformSpace, eMotionRange, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput::GetSkeletalSummaryData(vr::VRActionHandle_t action, vr::EVRSummaryType eSummaryType, vr::VRSkeletalSummaryData_t* pSkeletalSummaryData)
{
	return static_cast<IVRInput_010*>(steamInput)->GetSkeletalSummaryData(action, eSummaryType, pSkeletalSummaryData);
}

vr::EVRInputError VirtualInput::GetSkeletalSummaryData(vr::VRActionHandle_t action, vr::VRSkeletalSummaryData_t* pSkeletalSummaryData)
{
	return static_cast<IVRInput_005*>(steamInput)->GetSkeletalSummaryData(action, pSkeletalSummaryData);
}

vr::EVRInputError VirtualInput::GetSkeletalBoneDataCompressed(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<IVRInput_004*>(steamInput)->GetSkeletalBoneDataCompressed(action, eTransformSpace, eMotionRange, pvCompressedData, unCompressedSize, punRequiredCompressedSize, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput::GetSkeletalBoneDataCompressed(vr::VRActionHandle_t action, vr::EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize)
{
	return static_cast<IVRInput_010*>(steamInput)->GetSkeletalBoneDataCompressed(action, eMotionRange, pvCompressedData, unCompressedSize, punRequiredCompressedSize);
}

vr::EVRInputError VirtualInput::DecompressSkeletalBoneData(void* pvCompressedBuffer, uint32_t unCompressedBufferSize, vr::EVRSkeletalTransformSpace* peTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<IVRInput_004*>(steamInput)->DecompressSkeletalBoneData(pvCompressedBuffer, unCompressedBufferSize, peTransformSpace, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput::DecompressSkeletalBoneData(const void* pvCompressedBuffer, uint32_t unCompressedBufferSize, vr::EVRSkeletalTransformSpace eTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount)vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount)
{
	return static_cast<IVRInput_010*>(steamInput)->DecompressSkeletalBoneData(pvCompressedBuffer, unCompressedBufferSize, eTransformSpace, pTransformArray, unTransformArrayCount);
}

vr::EVRInputError VirtualInput::TriggerHapticVibrationAction(vr::VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, vr::VRInputValueHandle_t ulRestrictToDevice)
{
	return static_cast<IVRInput_010*>(steamInput)->TriggerHapticVibrationAction(action, fStartSecondsFromNow, fDurationSeconds, fFrequency, fAmplitude, ulRestrictToDevice);
}

vr::EVRInputError VirtualInput::GetActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT(originOutCount)vr::VRInputValueHandle_t* originsOut, uint32_t originOutCount)
{
	return static_cast<IVRInput_010*>(steamInput)->GetActionOrigins(actionSetHandle, digitalActionHandle, originsOut, originOutCount);
}

vr::EVRInputError VirtualInput::GetOriginLocalizedName(vr::VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize)
{
	return static_cast<IVRInput_004*>(steamInput)->GetOriginLocalizedName(origin, pchNameArray, unNameArraySize);
}

vr::EVRInputError VirtualInput::GetOriginLocalizedName(vr::VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize, int32_t unStringSectionsToInclude)
{
	return static_cast<IVRInput_010*>(steamInput)->GetOriginLocalizedName(origin, pchNameArray, unNameArraySize, unStringSectionsToInclude);
}

vr::EVRInputError VirtualInput::GetOriginTrackedDeviceInfo(vr::VRInputValueHandle_t origin, vr::InputOriginInfo_t* pOriginInfo, uint32_t unOriginInfoSize)
{
	return static_cast<IVRInput_010*>(steamInput)->GetOriginTrackedDeviceInfo(origin, pOriginInfo, unOriginInfoSize);
}

vr::EVRInputError VirtualInput::GetActionBindingInfo(vr::VRActionHandle_t action, vr::InputBindingInfo_t* pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount, uint32_t* punReturnedBindingInfoCount)
{
	return static_cast<IVRInput_010*>(steamInput)->GetActionBindingInfo(action, pOriginInfo, unBindingInfoSize, unBindingInfoCount, punReturnedBindingInfoCount);
}

vr::EVRInputError VirtualInput::ShowActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t ulActionHandle)
{
	return static_cast<IVRInput_010*>(steamInput)->ShowActionOrigins(actionSetHandle, ulActionHandle);
}

vr::EVRInputError VirtualInput::ShowBindingsForActionSet(VR_ARRAY_COUNT(unSetCount)vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, vr::VRInputValueHandle_t originToHighlight)
{
	return static_cast<IVRInput_010*>(steamInput)->ShowBindingsForActionSet(pSets, unSizeOfVRSelectedActionSet_t, unSetCount, originToHighlight);
}

vr::EVRInputError VirtualInput::GetComponentStateForBinding(const char* pchRenderModelName, const char* pchComponentName, const vr::InputBindingInfo_t* pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount, vr::RenderModel_ComponentState_t* pComponentState)
{
	return static_cast<IVRInput_010*>(steamInput)->GetComponentStateForBinding(pchRenderModelName, pchComponentName, pOriginInfo, unBindingInfoSize, unBindingInfoCount, pComponentState);
}

bool VirtualInput::IsUsingLegacyInput()
{
	return static_cast<IVRInput_010*>(steamInput)->IsUsingLegacyInput();
}

vr::EVRInputError VirtualInput::OpenBindingUI(const char* pchAppKey, vr::VRActionSetHandle_t ulActionSetHandle, vr::VRInputValueHandle_t ulDeviceHandle, bool bShowOnDesktop)
{
	return static_cast<IVRInput_010*>(steamInput)->OpenBindingUI(pchAppKey, ulActionSetHandle, ulDeviceHandle, bShowOnDesktop);
}

vr::EVRInputError VirtualInput::GetBindingVariant(vr::VRInputValueHandle_t ulDevicePath, char* pchVariantArray, uint32_t unVariantArraySize)
{
	return static_cast<IVRInput_010*>(steamInput)->GetBindingVariant(ulDevicePath, pchVariantArray, unVariantArraySize);
}
