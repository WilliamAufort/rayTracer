#include "../include/ray.hpp"

Ray::Ray() : m_origin(Vector()), m_direction(Vector(1,1,0)) {}

Ray::Ray(Vector origin, Vector direction) : m_origin(origin), m_direction(direction) {} 

Vector Ray::getOrigin() const
{
	return m_origin;
}

Vector Ray::getDirection() const
{
	return m_direction;
}

Vector Ray::getIntersect(double t) const
{
	return m_origin + t * m_direction;
}
