// NoiseTexture.cc

#include "NoiseTexture.h"

rgb NoiseTexture::value(const Vector2& uv, const Vector3& p) const
{
	float t = (1.0f + solid_noise.noise(p * scale)) / 2.0f;
	return t * c0 + (1.0f - t) * c1;
}