#ifndef        COMMON_FUNCTIONS_H
#define        COMMON_FUNCTIONS_H

//////////////////////////////////////////////////////////////////////////////////////////
//Correction functions
//////////////////////////////////////////////////////////////////////////////////////////

float Contrast(float Input, float ContrastPower)
{
     //piecewise contrast function
     bool IsAbovefloat = Input > 0.5 ;
     float ToRaise = saturate(2*(IsAbovefloat ? 1-Input : Input));
     float Output = 0.5*pow(ToRaise, ContrastPower);
     Output = IsAbovefloat ? 1-Output : Output;
     return Output;
}

//////////////////////////////////////////////////////////////////////////////////////////
//Tonemapping
//////////////////////////////////////////////////////////////////////////////////////////
void tonemap(out float4 low, out float4 high, float3 rgb, float scale)
{
    rgb = rgb * scale;
	
    const float fWhiteIntensity = 1.7;
    const float fWhiteIntensitySQR = fWhiteIntensity * fWhiteIntensity;
	
    low = float4(((rgb * (1 + rgb / fWhiteIntensitySQR)) / (rgb + 1)).xyz,0.f);
    high = float4(rgb.xyz / def_hdr,0.f); // 8x dynamic range
}

//////////////////////////////////////////////////////////////////////////////////////////
//Noise functions
//////////////////////////////////////////////////////////////////////////////////////////

float hash(float2 tc)
{
return frac(1.0e4 * sin(17.0*tc.x + 0.1*tc.y) * (0.1 + abs(sin(13.0*tc.y + tc.x))));
}

float hash3D(float3 tc)
{
return hash(float2(hash(tc.xy),tc.z));
}

float2 hash22(float2 p)
{
	float3 p3 = frac(float3(p.xyx) * float3(.1031, .1030, .0973));
    p3 += dot(p3, p3.yzx+19.19);
    return frac((p3.xx+p3.yz)*p3.zy);
}

float2 mod289(float2 x)
{ 
	return x - floor(x * (1.0 / 289.0)) * 289.0;
}

float3 mod289(float3 x)
{
	return x - floor(x * (1.0 / 289.0)) * 289.0; 
}

float4 mod289(float4 x)
{
	return x - floor(x * (1.0 / 289.0)) * 289.0;
}

float3 permute(float3 x)
{
	return mod289(((x*34.0)+1.0)*x);
}

float4 permute(float4 x)
{
	return mod289(((x*34.0)+1.0)*x);
}


/// 2D Noise by Ian McEwan, Ashima Arts.
float snoise_2D (float2 v)
{
    const float4 C = float4(0.211324865405187,  // (3.0-sqrt(3.0))/6.0
                        0.366025403784439,  // 0.5*(sqrt(3.0)-1.0)
                        -0.577350269189626, // -1.0 + 2.0 * C.x
                        0.024390243902439); // 1.0 / 41.0

    // First corner
    float2 i  = floor(v + dot(v, C.yy) );
    float2 x0 = v -   i + dot(i, C.xx);

    // Other corners
    float2 i1;
    i1 = (x0.x > x0.y) ? float2(1.0, 0.0) : float2(0.0, 1.0);
    float4 x12 = x0.xyxy + C.xxzz;
    x12.xy -= i1;

    // Permutations
    i = mod289(i); // Avoid truncation effects in permutation
    float3 p = permute( permute( i.y + float3(0.0, i1.y, 1.0 ))
        + i.x + float3(0.0, i1.x, 1.0 ));

    float3 m = max(0.5 - float3(dot(x0,x0), dot(x12.xy,x12.xy), dot(x12.zw,x12.zw)), 0.0);
    m = m*m ;
    m = m*m ;

    // Gradients: 41 points uniformly over a line, mapped onto a diamond.
    // The ring size 17*17 = 289 is close to a multiple of 41 (41*7 = 287)

    float3 x = 2.0 * frac(p * C.www) - 1.0;
    float3 h = abs(x) - 0.5;
    float3 ox = floor(x + 0.5);
    float3 a0 = x - ox;

    // Normalise gradients implicitly by scaling m
    // Approximation of: m *= inversesqrt( a0*a0 + h*h );
    m *= 1.79284291400159 - 0.85373472095314 * ( a0*a0 + h*h );

    // Compute final noise value at P
    float3 g;
    g.x  = a0.x  * x0.x  + h.x  * x0.y;
    g.yz = a0.yz * x12.xz + h.yz * x12.yw;
    return 130.0 * dot(m, g);
}


#endif