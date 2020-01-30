#pragma once
// Shape.h

#include "Ray.h"
#include "Vector3.h"
#include "rgb.h"

class Ray;
class rgb;

struct HitRecord
{
	float t;
	Vector3 normal;
	Vector2 uv;				// we will use this for 2D textures
	Vector3 hit_p;			// the point of intersection
	Texture* hit_tex;		// the nearest intersected object's texture
	rgb color;
};

class Shape
{
public:
	virtual bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const = 0;
	virtual bool shadowHit(const Ray& r, float tmin, float tmax, float time) const = 0;
};