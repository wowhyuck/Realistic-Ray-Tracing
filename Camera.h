#pragma once
// Camera.h

#include "Ray.h"
#include "ONB.h"

class Camera
{
public:
	Camera() {}
	Camera(const Camera& orig)
	{
		center = orig.center;
		corner = orig.corner;
		across = orig.across;
		up = orig.up;
		uvw = orig.uvw;
		u0 = orig.u0;
		u1 = orig.u1;
		v0 = orig.v0;
		v1 = orig.v1;
		d = orig.d;
		lens_radius = orig.lens_radius;
	}

	Camera(Vector3 c, Vector3 gaze, Vector3 vup, float aperture, float left, float right, float bottom, float top, float distance)
		: center(c), d(distance), u0(left), u1(right), v0(bottom), v1(top)
	{
		lens_radius = aperture / 2.0F;
		uvw.initFromWV(-gaze, vup);
		corner = center + u0 * uvw.u() + v0 * uvw.v() - d * uvw.w();
		across = (u0 - u1) * uvw.u();
		up = (v0 - v1) * uvw.v();
	}

	// a and b are the pixel positions
	// xi1 and xi2 are the lens samples in the range (0, 1)^2
	Ray getRay(float a, float b, float xi1, float xi2)
	{
		Vector3 origin = center + 2.0F * (xi1 - 0.5F) * lens_radius * uvw.u() + 2.0F * (xi2 - 0.5F) * lens_radius * uvw.v();
		Vector3 target = corner + across * a + up * b;
		return Ray(origin, unitVector(target - origin));
	}

	Vector3 center, corner, across, up;
	ONB uvw;
	float lens_radius;
	float u0, u1, v0, v1;
	float d;
};