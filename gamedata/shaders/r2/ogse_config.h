#ifndef OGSE_CONFIG_H
#define OGSE_CONFIG_H

// эффекты со включением через консоль
// Саншафты								r2_sunshafts [qt_off/qt_low/qt_medium/qt_high/qt_extreme]
// Объемные саншафты					r2_sunshafts_mode volumetric
// Плоские саншафты аля Crysis			r2_sunshafts_mode screen_space
// Мягкая вода							r2_soft_water [on/off]
// Мягкие партиклы						r2_soft_particles [on/off]
// Мягкие тени							r2_soft_shadows [qt_off/qt_low/qt_medium/qt_high/qt_extreme]
// SSDO									r2_ssao_mode ssdo
// HBAO									r2_ssao_mode hbao
// Steep Parallax						r2_steep_parallax [qt_off/qt_low/qt_medium/qt_high/qt_extreme]
// Dynamic Depth Of Field				r2_dof [qt_off/qt_low/qt_medium/qt_high/qt_extreme]
// Motion Blur							r2_mblur [on/off]
// Antialiasing							r2_aa [qt_off/qt_low/qt_medium/qt_high/qt_extreme]
// FXAA Antialiasing					r2_aa_mode fxaa
// SMAA Antialiasing					r2_aa_mode smaa
// Детальный бамп						r2_detail_bump [on/off]

// PARAMETERS 
// Используйте параметры для настройки соответствующего эффекта
/////////////////////////////////////////////////////////////
// Плоские саншафты
	#define SS_INTENSITY float(0.5)			// яркость лучей, работает совместно с настройками из конфига
	#define SS_BLEND_FACTOR float(0.8)		// фактор смешивания с рассеянным светом. Чем меньше значение, тем меньше "засветка" от эффекта, но теряется "объемность"
	#define SS_LENGTH float(1.0)			// длина лучей. Чем больше длина, тем меньше производительность

/////////////////////////////////////////////////////////////
// volumetric light
	#define USE_VOLUMETRIC_DUST
	#define SS_VOL_MAX_INTENSITY float(0.170)
	#define VOL_LIGHT_MAX_INTENSITY float(0.015)

/////////////////////////////////////////////////////////////
// Horizon-Based Ambient Occlusion	
	#define HBAO_NUM_STEPS int(3)			// Добавочное количество шагов при поиске горизонта. Улучшает качество, ухудшает производительность
	#define HBAO_RADIUS float(2.0)			// Радиус поиска окклюдера.
	#define HBAO_STEP_SIZE float(4)			// Шаг семплирования. Меньшие значения приводят к более четким теням
	#define HBAO_ANGLE_BIAS float(0.5)		// Угол в радианах для компенсации самозатенения плохо тесселированной геометрии. Увеличивать, если на  ребрах полигонов заметны тени.
	#define HBAO_THRESHOLD float(0.3)		// Порог срабатывания эффекта. Чем меньше, тем более мелкие детали затеняются.
	#define HBAO_GRASS_TUNING float(2.0)	// коррекция затенения травы. Чем больше, тем меньше затеняется.
	#define HBAO_BLEND_FACTOR float(0.700)
	#define AO_BLUR_FACTOR int(4)
	
/////////////////////////////////////////////////////////////
// improved parallax occlusion mapping
	#define POM_PARALLAX_OFFSET float(0.02)			// смещение. Чем больше, тем дальше будут выступать кирпичи.
	
/////////////////////////////////////////////////////////////
// Gaussian blur
	#define GAUSS_SIGMA float(2.5)
	
/////////////////////////////////////////////////////////////
// Motion blur
	#define MBLUR_CLAMP (0.0025)
	#define MBLUR_SEUS_NOISE_INT (0.75)

/////////////////////////////////////////////////////////////
// Raindrops
	#define DROPS_TURBSIZE 15.f
	#define DROPS_TURBSHIFT float4(0.35, 1, 0, 1)
	#define DROPS_TURBTIME sin(0.1/3.f)
	#define DROPS_TURBCOF 0.33

/////////////////////////////////////////////////////////////
// Ripples
	#define RIPPLES_DISTORTION 0.095f
	#define RIPPLES_FREQUENCY 0.4f
	#define RIPPLES_MAX_RADIUS 2	

/////////////////////////////////////////////////////////////
// Hashed alpha test
	#define H_AREF //enables hashed alpha test 
	#define H_AREF_SCALE float(0.5) //scale
	
/////////////////////////////////////////////////////////////
// depth of field

	//common
	#define DDOF_SKY_DIST float(10000)		// расстояние до неба. Менять, только если есть артефакты при направлении фокуса на небо.
	#define DDOF_FOCUS_CIRCLE float(10)		// диаметр области расчета усредненного фокуса, в пикселях. Увеличение до некоторого предела дает более плавный переход при смене фокуса.
	//far
	#define DDOF_FAR_PLANE float(40)		// дистанция от фокуса до границы сплошного блюра.
	#define DDOF_FAR_INTENSITY float(1.0)	// интенсивность эффекта. [0..1]
	//near
	#define DDOF_NEAR_PLANE float(10)		// дистанция, с которой блюр будет начинать уменьшаться. Больше поставите - дальше от актора будет распространяться ближний блюр
	#define DDOF_NEAR_MINDIST float (1.5)	// расстояние от камеры до плоскости начала заблюривания. Выставлять, чтобы не блюрилось оружие
	#define DDOF_NEAR_INTENSITY float(1.0)	// интенсивность эффекта. [0..1]
	//zoom depth of field
	#define ZDOF_MINDIST float(100)	        // минимальная дистанция от центра экрана, в пикселях. Ближе к фокусу блюра нет
	#define ZDOF_MAXDIST float(600)			// максимальная дистанция от центра экрана, в пикселях. Дальше - равномерный блюр.
	#define ZDOF_OFFSET float(2)			// предел глубины пикселя, меньшие значения не учитываютя при расчете среднего фокуса.
	#define ZDOF_INTENSITY float(1.0)
	#define ZDOF_MULT float(5)
	//reload depth of field
	#define RDOF_DIST float (1)				// расстояние, на котором начинается блюр. Выставлять так, чтобы не блюрилось оружие (0,7-1,2)
	#define RDOF_SPEED float (5)			// скорость нарастания эффекта. Хорошие значения - 5-1
	#define RDOF_INTENSITY float(1.0)
	#define RDOF_MULT float(5)

/////////////////////////////////////////////////////////////
// тепловизор
	#define IKV_DIST float(0.1)					// расстояние различимой геометрии
	#define IKV_HEATING_SPEED float(0.1)		// скорость нагрева/охлаждения оружия
	// пресеты
	#define IKV_PRESET_1_MIN float(0.274)		// пресеты подсвечиваемых материалов. Менять только в том случае, если знаете, что делаете.
	#define IKV_PRESET_1_MAX float(0.300)		// PRESET_1 - пресет для брони, костюмов, морд
	#define IKV_PRESET_2_MIN float(0.837)		// PRESET_2 - пресет для оружия
	#define IKV_PRESET_2_MAX float(0.862)		
	// цвета
	#define IKV_DEAD_COLOR float4(0.0,0.07,0.49,1.0)			// цветовая настройка тепловизора:
	#define IKV_MID3_COLOR float4(0.203,0.567,0.266,1.0)		// DEAD - цвет холодной геометрии
	#define IKV_MID2_COLOR float4(0.644,0.672,0.098,1.0)		// LIVE - цвет горячей геометрии
	#define IKV_MID1_COLOR float4(0.7,0.35,0.07,1.0)			// MID - промежуточные цвета
	#define IKV_LIVE_COLOR float4(0.7,0.16,0.08,1.0)	
	// помехи
	#define IKV_NOISE_INTENSITY float(1.0)		// интенсивность шума
	
/////////////////////////////////////////////////////////////
// Вода
	#define WATER_ENV_POWER float (0.7)				// интенсивность отражения скайкуба на воде
	#define PUDDLES_ENV_POWER float (0.3)			// интенсивность отражения скайкуба на лужах
	#define SW_USE_FOAM								// включить "пену" прибоя
	#define SW_FOAM_THICKNESS float (0.035)			// толщина "пены"
	#define SW_FOAM_INTENSITY float (3)				// интенсивность цвета "пены"
	#define SW_WATER_INTENSITY float (1.0)			// глубина цвета воды
	#define SW_REFL_INTENSITY float(2.0)			// интенсивность "честных" отражений
	#define SW_PUDDLES_REFL_INTENSITY float(3.0)	// интенсивность "честных" отражений в лужах
	#define MOON_ROAD_INTENSITY float(1.5)			// интенсивность "лунной дорожки"
	#define WATER_GLOSS float(0.5)					// интенсивность спекуляра на воде
	#define PUDDLES_GROW_SPEED float(0.200)
	#define USE_MOON_ROAD	
	
/////////////////////////////////////////////////////////////
// Флары от ламп
	#define FL_POWER float(1.0)					// общая интенсивность фларов
	#define FL_GLOW_RADIUS float(0.2)			// радиус короны источника света
	#define FL_DIRT_INTENSITY float(1.0)		// интенсивность эффекта Lens Dirt
	#define FL_USE_LONG_FLARE	
	
	#define MODEL_SELFLIGHT_POWER float(6.0)	// яркость свечения моделей
	#define MODEL_LOW_SELFLIGHT_POWER 2.f
	#define MODEL_RED_SELFLIGHT_POWER 2.f
	
/////////////////////////////////////////////////////////////
// Эффекты, связанные с дождем

	#define RAIN_MAX_DIFFUSE_SCALING float(0.7)				// максимальный коэффициент затемнения геометрии
	#define RAIN_MAX_DIFFUSE_DETAILS_MULT float(0.9)		// коэффициент затемнения травы относительно террейна
	#define RAIN_MAX_SPECULAR_SCALING float (3.0)			// максимальный уровень повышения блика
	#define RAIN_MAX_REFLECTION_POWER float(0.1)			// максимальная сила отражений
	#define RAIN_WETTING_SPEED float(0.5)					// скорость намокания поверхностей
	#define RAIN_GAIN_REFLECTIONS float(3.0)				// усиление честных отражений на намокших поверхностях

	// test params, not used now
	#define RMAP_KERNEL float(1.0)
	#define RMAP_size float(2048)
	#define RMAP_MAX_ENV_MAP_COEFF float(0.1)

/////////////////////////////////////////////////////////////
// Волны по траве
//	#define USE_GRASS_WAVE							// включить "волны" от ветра по траве
	#define GRASS_WAVE_POWER float(2.0)				// "яркость", заметность волн
	#define GRASS_WAVE_FREQ float(0.7)				// частота появления волн

/////////////////////////////////////////////////////////////
// Освещение полупрозрачной геометрии
	#define TRANSLUCENT_GLOSS float(1.0)						// спекуляр
	#define TRANSLUCENT_TORCH_ATT_FACTOR float(0.001231148)		// calculated as 1/(torch_range*torch_range*0.95*0.95)
	#define TRANSLUCENT_TORCH_COLOR float4(0.6,0.64,0.60,0.8)	// color of torch light
	#define TRANSLUCENT_TORCH_POSITION float3(0.00,0.0,0)		// position of torch light in view space
	#define TRANSLUCENT_TORCH_ANGLE_COS float(0.8434)			// cosinus of a half of a torch cone angle

/////////////////////////////////////////////////////////////
// Интерактивные детекторы
							// ДЕТЕКТОР "ОТКЛИК"
	#define ID_DETECTOR_1_DETECT_RADIUS float(20.0)			// радиус детектирования артефактов. Менять одновременно вместе со значением в конфиге
	#define ID_DETECTOR_1_COLOR float4(1.0,1.0,1.0,1.0)		// цвет индикации
	#define ID_DETECTOR_1_POWER float(6.0)					// яркость индикации

							// ДЕТЕКТОР "МЕДВЕДЬ"
	#define ID_DETECTOR_2_DETECT_RADIUS float(20.0)			// радиус детектирования артефактов. Менять одновременно вместе со значением в конфиге
	#define ID_DETECTOR_2_COLOR float4(0.1,1.0,0.0,1.0)		// цвет индикации
	#define ID_DETECTOR_2_POWER float(5.0)					// яркость индикации
	#define ID_DETECTOR_2_CENTER float2(0.2559, 0.2305)		// текстурные координаты центра экрана детектора. Менять при смене текстуры
	#define ID_DETECTOR_2_SECTOR float(0.7)					// сектор индикации на экране. Чем больше значение, тем меньше сектор. Ровно 1.0 не ставить!

							// ДЕТЕКТОР "ВЕЛЕС"
	#define ID_DETECTOR_3_DETECT_RADIUS float(35.0)			// радиус детектирования артефактов. Менять одновременно вместе со значением в конфиге
	#define ID_DETECTOR_3_COLOR float4(0.1,1.0,0.0,1.0)		// цвет индикации
	#define ID_DETECTOR_3_POWER float(6.0)					// яркость индикации
	#define ID_DETECTOR_3_DOT_RADIUS float(0.01)			// радиус точки артефакта на экране
	#define ID_DETECTOR_3_SCREEN_CORNERS float4(0.4668, 0.8398, 0.1035, 0.2891)		// текстурные координаты углов экрана в формате (max u,max v,min u,min v). Менять при смене текстуры
	#define USE_ANOMALY_DETECTION							// включение режима индикации аномалий
	#define ID_DETECTOR_3_AN_COLOR float4(1.0,0.0,0.0,1.0)	// цвет индикации аномалий
	#define ID_DETECTOR_3_AN_DOT_RADIUS float(0.02)			// радиус точки аномалии на экране
	#define ID_DETECTOR_3_NUM_COLOR float4(1.0,0.0,0.0,1.0)	// цвет индикации цифр на экране

/////////////////////////////////////////////////////////////
// Разное
	#define DETAIL_TEXTURE_MULTIPLIER float(1.5)			// множитель яркости детальной текстуры
	
// Фильтр контраста
	#define CONTRAST_FILTER_COEF float(0.4)					// уровень контраста

// Цветокоррекция
	#define COLOR_GRADING_LUMINANCE float3(0.213, 0.715, 0.072)		// цвет для расчета относительной светимости. Лучше не менять.


// Setting local light
#define ECB_LL_DIST 1.2f                            // дальность освещения ламп и костров
#define ECB_LL_BRIGHTNESS 1.5f                      // яркость освещения ламп и костров

#endif