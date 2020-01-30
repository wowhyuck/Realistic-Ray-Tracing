#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Texture.h"
#include "rgb.h"
#include "SolidNoise.h"

class MarbleTexture : public Texture
{
public:
	MarbleTexture(float stripes_per_unit, float _scale = 5.0f, int _octaves = 8)
	{
		freq = M_PI * stripes_per_unit;
		scale = _scale;
		octaves = _octaves;
		c0 = rgb(0.8, 0.8, 0.8);
		c1 = rgb(0.4, 0.2, 0.1);
		c2 = rgb(0.06, 0.04, 0.02);
	}
	MarbleTexture(const rgb& _c0, const rgb& _c1, const rgb& _c2, float stripes_per_unit, float _scale = 3.0f, int _octaves = 8)
		: c0(_c0), c1(_c1), c2(_c2)
	{
		freq = M_PI * stripes_per_unit;
		scale = _scale;
		octaves = _octaves;
	}

	virtual rgb value(const Vector2& uv, const Vector3& p) const;

	float freq, scale;
	int octaves;
	rgb c0, c1, c2;
	SolidNoise noise;
};