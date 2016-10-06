#ifndef DEF_SPHERE
#define DEF_SPHERE

#include "vector.hpp"
#include "ray.hpp"
#include "material.hpp"

class Sphere
{
	public:
		Sphere();
		Sphere(Vector center, double r);
		Sphere(Vector center, double r, Material mat);

		Vector getColor() const;
		double computeIntersect(Ray ray) const;
		Vector normal(Vector point) const;
		bool isSpecular() const;
		Ray reflect(Ray r, Vector intersect) const;

	private:
		Vector m_center;
		double m_r;
		Material m_material;
};

#endif
