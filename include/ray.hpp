#ifndef DEF_RAY
#define DEF_RAY

#include "vector.hpp"

/**
* Implementation of the rays used in the raytracer.
**/

class Ray
{
	public:
		Ray();
		Ray(Vector origin, Vector direction);

		Vector getOrigin() const;
		Vector getDirection() const;
		Vector getIntersect(double t) const;

	private:
		Vector m_origin;
		Vector m_direction;
};

#endif
