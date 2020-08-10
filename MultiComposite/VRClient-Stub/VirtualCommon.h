#pragma once
#include "openvr.h"

using namespace vr;

struct Compositor_StageRenderSettings
{
	/** Primary color is applied as a tint to (i.e. multiplied with) the model's texture */
	HmdColor_t m_PrimaryColor;
	HmdColor_t m_SecondaryColor;

	/** Vignette radius is in meters and is used to fade to the specified secondary solid color over
	* that 3D distance from the origin of the playspace. */
	float m_flVignetteInnerRadius;
	float m_flVignetteOuterRadius;

	/** Fades to the secondary color based on view incidence.  This variable controls the linearity
	* of the effect.  It is mutually exclusive with vignette.  Additionally, it treats the mesh as faceted. */
	float m_flFresnelStrength;

	/** Controls backface culling. */
	bool m_bBackfaceCulling;

	/** Converts the render model's texture to luma and applies to rgb equally.  This is useful to
	* combat compression artifacts that can occur on desaturated source material. */
	bool m_bGreyscale;

	/** Renders mesh as a wireframe. */
	bool m_bWireframe;
};

struct Compositor_BenchmarkResults
{
	float m_flMegaPixelsPerSecond; // Measurement of GPU MP/s performed by compositor benchmark
	float m_flHmdRecommendedMegaPixelsPerSecond; // Recommended default MP/s given the HMD resolution, refresh, and panel mask.
};

class VirtualCommon
{
public:
	virtual void* GetFnTable() = 0;
};

class _InheritVirtualLayout { virtual void _ignore() = 0; };
class VirtualCorrectLayout : public _InheritVirtualLayout, public VirtualCommon {};

enum EGraphicsAPIConvention
{
	API_DirectX = 0, // Normalized Z goes from 0 at the viewer to 1 at the far clip plane
	API_OpenGL = 1,  // Normalized Z goes from 1 at the viewer to -1 at the far clip plane
};

class Frame
{
public:
	const Texture_t* texture;
	const VRTextureBounds_t* bounds;
	EVRSubmitFlags flags;

	Frame(const Texture_t* t, const VRTextureBounds_t* b, EVRSubmitFlags f)
	{
		texture = t;
		bounds = b;
		flags = f;
	}
};

struct InputSkeletonActionData_t
{
	// Whether or not this action is currently available to be bound in the active action set
	bool bActive;

	// The origin that caused this action's current state
	VRInputValueHandle_t activeOrigin;
};
