#include "../include/ray.hpp"

Ray::Ray() : m_origin(Vector()), m_direction(Vector(1,1,0)) {}

/**
* A ray with a given origin and direction
**/

Ray::Ray(Vector origin, Vector direction) : m_origin(origin), m_direction(direction) {} 

/**
* Return the origin of the ray
**/

Vector Ray::getOrigin() const
{
	return m_origin;
}

/**
* Return the direction of the ray
**/

Vector Ray::getDirection() const
{
	return m_direction;
}

/**
* Given a scaling factor (computed by the intersection functions), return the corresponding point on the ray
**/

Vector Ray::getIntersect(double t) const
{
	return m_origin + t * m_direction;
}
