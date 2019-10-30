#ifndef        COMMON_CONSTANTS_H
#define        COMMON_CONSTANTS_H

//////////////////////////////////////////////////////////////////////////////////////////
//Common floats
//////////////////////////////////////////////////////////////////////////////////////////
	#define PI  3.14159265f
	#define float_PI 1.570796325f
	#define DOUBLE_PI  6.2831853f

	#define USE_SUNMASK                		// enable sun mask
	
	#ifndef SMAP_size
		#define SMAP_size 2048
	#endif

//////////////////////////////////////////////////////////////////////////////////////////
//Common floats
//////////////////////////////////////////////////////////////////////////////////////////	
	#define parallax		float2(0.02, -0.01)				// shift for default stalker parallax calculating
	#define lumcoeff		float3(0.2125, 0.7154, 0.0721)		// luminance vector fo bokeh blur and SMAA
	#define xmaterial		float(L_material.w)				// just shortcut for material
	#define def_gloss       float(2.f /255.f)				// default gloss value
	#define def_aref        float(128.f/255.f)				// default alpha-test value
	#define def_virtualh    float(.05f)						// virtual position shift for bump look-a-like
	#define def_distort     float(0.025f)					// distortion shift

//////////////////////////////////////////////////////////////////////////////////////////
//HDR 
//////////////////////////////////////////////////////////////////////////////////////////	
	#define def_hdr         float(8.h)						// hdr divider
	#define def_skyhdr         float(8.h)						// hdr divider
	#define def_hdr_clip	float(0.75)        		//

	#define	LUMINANCE_VECTOR	float3(0.3, 0.38, 0.22)  // luminance vector fo luminance estimating

#endif