#ifndef        COMMON_STRUCTS_H
#define        COMMON_STRUCTS_H

//////////////////////////////////////////////////////////////////////////////////////////
struct         v_static                {
        float4      P                	: POSITION;                        // (float,float,float,1)
        float4      Nh                	: NORMAL;                // (nx,ny,nz,hemi occlusion)
        float4      T                 	: TANGENT;                // tangent
        float4      B                 	: BINORMAL;                // binormal
        float2      tc                	: TEXCOORD0;        // (u,v)
        float2      lmh                	: TEXCOORD1;        // (lmu,lmv)
        float4      color               : COLOR0;                        // (r,g,b,dir-occlusion)
};

struct         v_tree               	{
        float4      P                	: POSITION;                // (float,float,float,1)
        float4      Nh                	: NORMAL;                // (nx,ny,nz)
        float3      T                 	: TANGENT;                // tangent
        float3      B                 	: BINORMAL;                // binormal
        float4      tc                	: TEXCOORD0;        // (u,v,frac,???)
};

struct         v_model                 	{
        float4      P                   : POSITION;                // (float,float,float,1)
        float3      N                	: NORMAL;                // (nx,ny,nz)
        float3      T                	: TANGENT;                // (nx,ny,nz)
        float3      B                	: BINORMAL;                // (nx,ny,nz)
        float2      tc                	: TEXCOORD0;        // (u,v)
};

struct        v_detail                    {
        float4      pos                : POSITION;                // (float,float,float,1)
        int4        misc        : TEXCOORD0;        // (u(Q),v(Q),frac,matrix-id)
#ifdef USE_HWI
		float4		m0			: TEXCOORD1;
		float4		m1			: TEXCOORD2;
#endif
};

#if defined(USE_HWSMAP) && !defined(USE_PCSS)
struct         v_shadow_direct_aref
{
        float4      hpos:        POSITION;       // Clip-space position         (for rasterization)
        float2      tc0:        TEXCOORD1;       // Diffuse map for aref
};
struct         v_shadow_direct
{
        float4      hpos:        POSITION;       // Clip-space position         (for rasterization)
};
#else
struct         v_shadow_direct_aref
{
        float4      hpos:        POSITION;       // Clip-space position         (for rasterization)
        float       depth:         TEXCOORD0;     // Depth
        float2      tc0:        TEXCOORD1;       // Diffuse map for aref
};
struct         v_shadow_direct
{
        float4      hpos:        POSITION;       // Clip-space position         (for rasterization)
        float       depth:         TEXCOORD0;     // Depth
};
#endif

//////////////////////////////////////////////////////////////////////////////////////////
struct         p_bumped        {
        float4      hpos        : POSITION;
        float4      tcdh        : TEXCOORD0;        // Texture coordinates
        float4      position    : TEXCOORD1;        // position + hemi
        float3       M1         : TEXCOORD2;        // nmap 2 eye - 1
        float3       M2         : TEXCOORD3;        // nmap 2 eye - 2
        float3       M3         : TEXCOORD4;        // nmap 2 eye - 3
#ifdef USE_TDETAIL
        float2      tcdbump          : TEXCOORD5;        // d-bump
    #ifdef USE_LM_HEMI
        float2      lmh                    : TEXCOORD6;        // lm-hemi
    #endif
#else
    #ifdef USE_LM_HEMI
        float2      lmh                   : TEXCOORD5;        // lm-hemi
    #endif
#endif
};
//////////////////////////////////////////////////////////////////////////////////////////
struct         p_flat                  {
        float4                hpos        : POSITION;
		float4                tcdh        : TEXCOORD0;        // Texture coordinates
        float4                position    : TEXCOORD1;        // position + hemi
        float3                N           : TEXCOORD2;        // Eye-space normal        (for lighting)
  #ifdef USE_TDETAIL
        float2                tcdbump                : TEXCOORD3;        // d-bump
    #ifdef USE_LM_HEMI
        float2         lmh      : TEXCOORD4;        // lm-hemi
    #endif
  #else
    #ifdef USE_LM_HEMI
        float2         lmh      : TEXCOORD3;        // lm-hemi
    #endif
  #endif
};
//////////////////////////////////////////////////////////////////////////////////////////
struct                  f_deffer        		{
        float4 position:COLOR0;        // px,py,pz, m-id
        float4 Ne:COLOR1;        // nx,ny,nz, hemi
        float4 C:COLOR2;        // r, g, b,  gloss
};
//////////////////////////////////////////////////////////////////////////////////////////
struct  				p_screen                {
        float4 hpos:POSITION;
        float2 tc0:TEXCOORD0;        // Texture coordinates         (for sampling maps)
};
//////////////////////////////////////////////////////////////////////////////////////////

struct combine {
	float4 tc0:TEXCOORD0;
	float4 tc1:TEXCOORD1;
	float4 tc2:TEXCOORD2;
	float4 tc3:TEXCOORD3;
	float4 tc4:TEXCOORD4;
	float4 tc5:TEXCOORD5;
	float4 tc6:TEXCOORD6;
};

#endif