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
//Tonemapping and bloom combiner
//////////////////////////////////////////////////////////////////////////////////////////
void tonemap(out float4 low, out float4 high, float3 rgb, float scale)
{
    rgb = rgb * scale;
	
    const float fWhiteIntensity = 1.7;
    const float fWhiteIntensitySQR = fWhiteIntensity * fWhiteIntensity;
	
    low = float4(((rgb * (1 + rgb / fWhiteIntensitySQR)) / (rgb + 1)).xyz,0.f);
    high = float4(rgb.xyz / def_hdr,0.f); // 8x dynamic range
}
half4 combine_bloom(half3  low, half4 high)	
{
        half4 result = half4(low + high.rgb*high.a, 1.h);
		return result;
}

#endif