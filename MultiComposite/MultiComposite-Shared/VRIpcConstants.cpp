#include "VRIpcConstants.h"

bool SharedState::Init(ISharedMem::Role role)
{
	m_pSharedStateMem = CreateSharedMem("SharedState", sizeof(VRSharedState_t), role);
	return true;
}

const VRSharedState_t* SharedState::GetSharedState()
{
	return (VRSharedState_t*)m_pSharedStateMem->Pointer();
}

VRSharedState_t* SharedState::GetWritableSharedState()
{
	return (VRSharedState_t*)m_pSharedStateMem->Pointer();
}
