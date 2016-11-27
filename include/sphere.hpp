#ifndef DEF_SPHERE
#define DEF_SPHERE

#include "vector.hpp"
#include "ray.hpp"
#include "material.hpp"
#include <utility>

/**
* The sphere is the simpler primitive to print in a scene
**/

class Sphere
{
	public:
		Sphere();
		Sphere(Vector center, double r, Vector color, Material mat);
		~Sphere() {};

		Vector getColor() const __attribute__((pure));
		double computeIntersect(Ray ray) const;
		Vector normal(Vector point) const;

		bool isEmissive() const __attribute__((pure));
		double getRho() const __attribute__((pure));

		bool isSpecular() const __attribute__((pure));
		Ray reflect(Ray r, Vector intersect) const;

		bool isTransparent() const __attribute__((pure));
		std::pair<bool,Ray> refract(Ray r, Vector intersect) const;

		bool isDiffuse() const __attribute__((pure));
		double getDiffuseCoeff() const  __attribute__((pure));

	private:
		Vector m_center;
		double m_r;
		Vector m_color;
		Material m_material;
};

#endif
