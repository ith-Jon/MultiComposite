#pragma once
#include "openvr.h"
#include "VirtualCommon.h"

#include "VirtualInput/VirtualInput_004.h"
#include "VirtualInput/VirtualInput_005.h"
#include "VirtualInput/VirtualInput_006.h"
#include "VirtualInput/VirtualInput_007.h"
#include "VirtualInput/VirtualInput_010.h"

class VirtualInput
{
public:
	void* virtualInput;
	void* steamInput;

	VirtualInput()
	{
		virtualInput = nullptr;
		steamInput = nullptr;
	}

	~VirtualInput()
	{
		delete virtualInput;
		delete steamInput;
	}

	// ---------------  Handle management   --------------- //

	/** Sets the path to the action manifest JSON file that is used by this application. If this information
	* was set on the virtual partner site, calls to this function are ignored. If the virtual partner site
	* setting and the path provided by this call are different, VRInputError_MismatchedActionManifest is returned.
	* This call must be made before the first call to UpdateActionState or IVRSystem::PollNextEvent. */
	virtual vr::EVRInputError SetActionManifestPath(const char* pchActionManifestPath);

	/** Returns a handle for an action set. This handle is used for all performance-sensitive calls. */
	virtual vr::EVRInputError GetActionSetHandle(const char* pchActionSetName, vr::VRActionSetHandle_t* pHandle);

	/** Returns a handle for an action. This handle is used for all performance-sensitive calls. */
	virtual vr::EVRInputError GetActionHandle(const char* pchActionName, vr::VRActionHandle_t* pHandle);

	/** Returns a handle for any path in the input system. E.g. /user/hand/right */
	virtual vr::EVRInputError GetInputSourceHandle(const char* pchInputSourcePath, vr::VRInputValueHandle_t* pHandle);

	// --------------- Reading action state ------------------- //

	/** Reads the current state into all actions. After this call, the results of Get*Action calls
	* will be the same until the next call to UpdateActionState. */
	virtual vr::EVRInputError UpdateActionState(VR_ARRAY_COUNT(unSetCount) vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount);

	/** Reads the state of a digital action given its handle. This will return VRInputError_WrongType if the type of
	* action is something other than digital */
	virtual vr::EVRInputError GetDigitalActionData(vr::VRActionHandle_t action, vr::InputDigitalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice);

	/** Reads the state of an analog action given its handle. This will return VRInputError_WrongType if the type of
	* action is something other than analog */
	virtual vr::EVRInputError GetAnalogActionData(vr::VRActionHandle_t action, vr::InputAnalogActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice);

	/**
	 * Reads the state of a pose action given its handle.
	 *
	 * Renamed to GetPoseActionDataRelativeToNow as of IVRInput_006.
	 */
	virtual vr::EVRInputError GetPoseActionData(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice);

	/** Reads the state of a pose action given its handle for the number of seconds relative to now. This
	* will generally be called with negative times from the fUpdateTime fields in other actions. */
	virtual vr::EVRInputError GetPoseActionDataRelativeToNow(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice);

	/** Reads the state of a pose action given its handle. The returned values will match the values returned
	* by the last call to IVRCompositor::WaitGetPoses(). */
	virtual vr::EVRInputError GetPoseActionDataForNextFrame(vr::VRActionHandle_t action, vr::ETrackingUniverseOrigin eOrigin, vr::InputPoseActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice);


	/** Reads the state of a skeletal action given its handle. */
	virtual vr::EVRInputError GetSkeletalActionData(vr::VRActionHandle_t action, vr::InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize, vr::VRInputValueHandle_t ulRestrictToDevice);

	/** Reads the state of a skeletal action given its handle. */
	virtual vr::EVRInputError GetSkeletalActionData(vr::VRActionHandle_t action, vr::InputSkeletalActionData_t* pActionData, uint32_t unActionDataSize);

	/** Returns the current dominant hand for the user for this application. This function will only return success for applications
	* which include "supports_dominant_hand_setting": true in their action manifests. The dominant hand will only change after
	* a call to UpdateActionState, and the action data returned after that point will use the new dominant hand. */
	virtual vr::EVRInputError GetDominantHand(vr::ETrackedControllerRole* peDominantHand);

	/** Sets the dominant hand for the user for this application. */
	virtual vr::EVRInputError SetDominantHand(vr::ETrackedControllerRole eDominantHand);

	// ---------------  Static Skeletal Data ------------------- //

	/** Reads the number of bones in skeleton associated with the given action */
	virtual vr::EVRInputError GetBoneCount(vr::VRActionHandle_t action, uint32_t* pBoneCount);

	/** Fills the given array with the index of each bone's parent in the skeleton associated with the given action */
	virtual vr::EVRInputError GetBoneHierarchy(vr::VRActionHandle_t action, VR_ARRAY_COUNT(unIndexArayCount) vr::BoneIndex_t* pParentIndices, uint32_t unIndexArayCount);

	/** Fills the given buffer with the name of the bone at the given index in the skeleton associated with the given action */
	virtual vr::EVRInputError GetBoneName(vr::VRActionHandle_t action, vr::BoneIndex_t nBoneIndex, VR_OUT_STRING() char* pchBoneName, uint32_t unNameBufferSize);

	/** Fills the given buffer with the transforms for a specific static skeletal reference pose */
	virtual vr::EVRInputError GetSkeletalReferenceTransforms(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalReferencePose eReferencePose, VR_ARRAY_COUNT(unTransformArrayCount) vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount);

	/** Reads the level of accuracy to which the controller is able to track the user to recreate a skeletal pose */
	virtual vr::EVRInputError GetSkeletalTrackingLevel(vr::VRActionHandle_t action, vr::EVRSkeletalTrackingLevel* pSkeletalTrackingLevel);

	// ---------------  Dynamic Skeletal Data ------------------- //

	/** Reads the state of the skeletal bone data associated with this action and copies it into the given buffer. */
	virtual vr::EVRInputError GetSkeletalBoneData(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount) vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount, vr::VRInputValueHandle_t ulRestrictToDevice);

	/** Reads the state of the skeletal bone data associated with this action and copies it into the given buffer. */
	virtual vr::EVRInputError GetSkeletalBoneData(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT(unTransformArrayCount) vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount);

	/** Reads summary information about the current pose of the skeleton associated with the given action.   */
	virtual vr::EVRInputError GetSkeletalSummaryData(vr::VRActionHandle_t action, vr::EVRSummaryType eSummaryType, vr::VRSkeletalSummaryData_t* pSkeletalSummaryData);

	// Same as above, but default to VRSummaryType_FromDevice (TODO check if this matches virtualVR). This was used in IVRInput_005
	virtual vr::EVRInputError GetSkeletalSummaryData(vr::VRActionHandle_t action, vr::VRSkeletalSummaryData_t* pSkeletalSummaryData);

	/** Reads the state of the skeletal bone data in a compressed form that is suitable for
		* sending over the network. The required buffer size will never exceed ( sizeof(VR_BoneTransform_t)*boneCount + 2).
		* Usually the size will be much smaller. */
	virtual vr::EVRInputError GetSkeletalBoneDataCompressed(vr::VRActionHandle_t action, vr::EVRSkeletalTransformSpace eTransformSpace, vr::EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize, vr::VRInputValueHandle_t ulRestrictToDevice);

	/** Reads the state of the skeletal bone data in a compressed form that is suitable for
	* sending over the network. The required buffer size will never exceed ( sizeof(VR_BoneTransform_t)*boneCount + 2).
	* Usually the size will be much smaller. */
	virtual vr::EVRInputError GetSkeletalBoneDataCompressed(vr::VRActionHandle_t action, vr::EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT(unCompressedSize) void* pvCompressedData, uint32_t unCompressedSize, uint32_t* punRequiredCompressedSize);

	/** Turns a compressed buffer from GetSkeletalBoneDataCompressed and turns it back into a bone transform array. */
	virtual vr::EVRInputError DecompressSkeletalBoneData(void* pvCompressedBuffer, uint32_t unCompressedBufferSize, vr::EVRSkeletalTransformSpace* peTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount) vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount);


	/** Turns a compressed buffer from GetSkeletalBoneDataCompressed and turns it back into a bone transform array. */
	virtual vr::EVRInputError DecompressSkeletalBoneData(const void* pvCompressedBuffer, uint32_t unCompressedBufferSize, vr::EVRSkeletalTransformSpace eTransformSpace, VR_ARRAY_COUNT(unTransformArrayCount) vr::VRBoneTransform_t* pTransformArray, uint32_t unTransformArrayCount);

	// --------------- Haptics ------------------- //

	/** Triggers a haptic event as described by the specified action */
	virtual vr::EVRInputError TriggerHapticVibrationAction(vr::VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, vr::VRInputValueHandle_t ulRestrictToDevice);

	// --------------- Action Origins ---------------- //

	/** Retrieve origin handles for an action */
	virtual vr::EVRInputError GetActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT(originOutCount) vr::VRInputValueHandle_t* originsOut, uint32_t originOutCount);

	/** Retrieves the name of the origin in the current language */
	virtual vr::EVRInputError GetOriginLocalizedName(vr::VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize);

	/** Retrieves the name of the origin in the current language. unStringSectionsToInclude is a bitfield of values in EVRInputStringBits that allows the
			application to specify which parts of the origin's information it wants a string for. */
	virtual vr::EVRInputError GetOriginLocalizedName(vr::VRInputValueHandle_t origin, VR_OUT_STRING() char* pchNameArray, uint32_t unNameArraySize, int32_t unStringSectionsToInclude);

	/** Retrieves useful information for the origin of this action */
	virtual vr::EVRInputError GetOriginTrackedDeviceInfo(vr::VRInputValueHandle_t origin, vr::InputOriginInfo_t* pOriginInfo, uint32_t unOriginInfoSize);

	/** Retrieves useful information about the bindings for an action */
	virtual vr::EVRInputError GetActionBindingInfo(vr::VRActionHandle_t action, vr::InputBindingInfo_t* pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount, uint32_t* punReturnedBindingInfoCount);

	/** Shows the current binding for the action in-headset */
	virtual vr::EVRInputError ShowActionOrigins(vr::VRActionSetHandle_t actionSetHandle, vr::VRActionHandle_t ulActionHandle);

	/** Shows the current binding all the actions in the specified action sets */
	virtual vr::EVRInputError ShowBindingsForActionSet(VR_ARRAY_COUNT(unSetCount) vr::VRActiveActionSet_t* pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, vr::VRInputValueHandle_t originToHighlight);

	/** Use this to query what action on the component returned by GetOriginTrackedDeviceInfo would trigger this binding. */
	virtual vr::EVRInputError GetComponentStateForBinding(const char* pchRenderModelName, const char* pchComponentName,
		const vr::InputBindingInfo_t* pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount,
		vr::RenderModel_ComponentState_t* pComponentState);

	// --------------- Legacy Input ------------------- //
	virtual bool IsUsingLegacyInput();

	// --------------- Utilities ------------------- //

	/** Opens the binding user interface. If no app key is provided it will use the key from the calling process.
	* If no set is provided it will open to the root of the app binding page. */
	virtual vr::EVRInputError OpenBindingUI(const char* pchAppKey, vr::VRActionSetHandle_t ulActionSetHandle, vr::VRInputValueHandle_t ulDeviceHandle, bool bShowOnDesktop);

	/**
	 * Returns the variant set in the current bindings. If the binding doesn't include a variant setting, this function
	 * will return an empty string
	 */
	virtual vr::EVRInputError GetBindingVariant(vr::VRInputValueHandle_t ulDevicePath, char* pchVariantArray, uint32_t unVariantArraySize);
};
