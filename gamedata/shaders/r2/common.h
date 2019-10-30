#ifndef        COMMON_H
#define        COMMON_H

#include "common_samplers.h"
#include "common_uniforms.h"
#include "common_constants.h"
#include "common_structs.h"
#include "common_functions.h"

#include "ogse_functions.h"
#include "ogse_config.h"

uniform float4x4 mVPTexgen;

///////////////////////////////////// SWM /////////////////////////////////////
uniform	float4 m_blender_mode; // x = [0 - default, 1 - night vision, 2 - thermal vision]; y = [0.0f / 1.0f - происходит ли в данный момент рендеринг картинки для прицела]; z = [0.0f / 1.0f - выключен или включён двойной рендер]; w - зарезервировано на будущее.

// Активен-ли двойной рендер
inline bool isSecondVPActive()
{
	return (m_blender_mode.z == 1.f);
}

inline bool IsSVPFrame()
{
	return (m_blender_mode.y == 1.f);
}
///////////////////////////////////////////////////////////////////////////////

float3 	unpack_normal(float3 v)
{
	return 2*v-1;
}

float3 unpack_bx2(float3 v)
{
	return 2*v-1;
}

float3 unpack_bx4(float3 v)
{
	return 4*v-2;
}

float2 unpack_tc_base(float2 tc, float du, float dv)
{
	return (tc.xy + float2	(du,dv))*(32.f/32768.f);
}

float2 unpack_tc_lmap(float2 tc)
{
	return tc*(1.f/32768.f); // [-1  .. +1 ]
}

//////////////////////////////////////////////////////////////////////////////////////////

float calc_cyclic(float x)
{
	float 	phase 	= 1/(2*3.141592653589f);
	float 	sqrt2	= 1.4142136f;
	float 	sqrt2m2	= 2.8284271f;
	float 	f 	= sqrt2m2*frac(x)-sqrt2;	// [-sqrt2 .. +sqrt2]
	return 	f*f - 1.f;				// [-1     .. +1]
}

float2 calc_xz_wave(float2 dir2D, float frac)
{
	// Beizer
	float2  ctrl_A	= float2(0.f,		0.f	);
	float2 	ctrl_B	= float2(dir2D.x,	dir2D.y	);
	return  lerp	(ctrl_A, ctrl_B, frac);
}

//////////////////////////////////////////////////////////////////////////////////////////

float calc_fogging(float4 w_pos)
{
	return dot(w_pos,fog_plane);
}

float3 calc_reflection(float3 pos_w, float3 norm_w)
{
    return reflect(normalize(pos_w-eye_position), norm_w);
}

///fog calculation for forwards
float3 calc_fog(float3 pos, float3 color, float2 tc, sampler2D s_sky)
{

	float         	dist			= length		(pos);
	float         	fog				= saturate		(dist*fog_params.w + fog_params.x); //
	float3			final			= lerp     		(color,fog_color.xyz,fog);        			//
	float        	skyblend		= saturate		(fog*fog);
	float3			sky				= tex2D			(s_sky,tc).xyz;
					final			= lerp     		(final,sky,skyblend);        			//
	return			final;
}

//////////////////////////////////////////////////////////////////////////////////////////

float3 calc_sun_r1(float3 norm_w)
{
	return L_sun_color*saturate(dot((norm_w),-L_sun_dir_w));
}

float3 calc_model_hemi_r1(float3 norm_w)
{
	return max(0,norm_w.y)*L_hemi_color;
}

float3 calc_model_lq_lighting(float3 norm_w)
{
	return L_material.x*calc_model_hemi_r1(norm_w) + L_ambient + L_material.y*calc_sun_r1(norm_w);
}

//////////////////////////////////////////////////////////////////////////////////////////

float3	v_hemi(float3 n)
{
	return L_hemi_color.xyz*(.5f + .5f*n.y);
}

float3	v_sun(float3 n)
{
	return L_sun_color*dot(n,-L_sun_dir_w);
}

float3   p_hemi(float2 tc)
{
	float3 t_lmh = tex2D(s_hemi, tc).xyz;
	return dot(t_lmh,1.h/3.h);
}

#define FXPS technique _render{pass _code{PixelShader=compile ps_3_0 main();}}
#define FXVS technique _render{pass _code{VertexShader=compile vs_3_0 main();}}

#include "ogse_gbuffer.h"
#endif