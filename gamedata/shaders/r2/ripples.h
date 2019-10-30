#ifndef RIPPLES_H
#define	RIPPLES_H


#include "common.h"
#include "ogse_config.h"

float ripples(float2 tc, float factor)
{
	float2 uv = tc * factor;
    float2 p0 = floor(uv);

    float2 circles;
    for (int j = -RIPPLES_MAX_RADIUS; j <= RIPPLES_MAX_RADIUS; ++j)
    {
        for (int i = -RIPPLES_MAX_RADIUS; i <= RIPPLES_MAX_RADIUS; ++i)
        {
			float2 pi = p0 + float2(i, j);
            float2 hsh = pi;
            float2 p = pi + hash22(hsh);

            float t = frac(RIPPLES_FREQUENCY*timers.x + hash22(hsh));
            float2 v = p - uv;
            float d = length(v) - (float(RIPPLES_MAX_RADIUS) + 1.)*t;

            float h = 1e-3;

			//1st pass
            float d1 = d - h;
            float p1 = sin(31.*d1) * smoothstep(-0.6, -0.3, d1) * smoothstep(0., -0.3, d1);
			//sec pass
            float d2 = d + h;
            float p2 = sin(31.*d2) * smoothstep(-0.6, -0.3, d2) * smoothstep(0., -0.3, d2);
            circles += 0.5 * normalize(v) * ((p2 - p1) / (2. * h) * (1. - t) * (1. - t));
        }
    }
    circles /= float((2*3+1)*(2*2+1));

    float intensity = lerp(RIPPLES_DISTORTION, 0.15, smoothstep(0.1, 0.6, frac(0.05 + 0.05)*2.-1.));
    float3 n = float3(circles, sqrt(1. - dot(circles, circles)));
	float final = 3.0*pow(clamp(dot(n, normalize(float3(1., 0.7, 0.5))), 0., 1.), 6.);

	return final;
}

#endif