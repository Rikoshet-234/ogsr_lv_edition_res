#include "common.h"

struct p_fv
{
	float4 hpos		:POSITION0;
	float4 pos		:TEXCOORD0;
};

p_fv main(float3 _pos:POSITION0)
{
	p_fv o;

	float4 P = float4(_pos, 1.0);
	o.hpos = mul(m_WVP, P);
	float3 Pe = mul(m_WV, P);
	o.pos = proj_to_screen(o.hpos);
	o.pos.z = Pe.z/180.f;
	return o;
};