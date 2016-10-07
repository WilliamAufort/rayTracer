#ifndef DEF_SCENE
#define DEF_SCENE

#include "vector.hpp"
#include "sphere.hpp"
#include "ray.hpp"
#include <vector>
#include <utility>

class Scene
{
	public:
		Scene();
		Scene(std::vector<Sphere> spheres, Vector light, double intensity);

		Vector normal(unsigned int i, Vector point);
		Vector getColor(unsigned int i) const __attribute__((pure));
		bool isSpecular(unsigned int i) const __attribute__((pure));
		Ray reflect(Ray r, Vector intersect, unsigned int i) const;

		std::pair<unsigned int,double> computeIntersect(Ray r) const;
		bool isShadowed(Vector point) const;

		Vector getColor(Ray r);
		Vector getColor(Ray r, unsigned int nb_rebounds);

	private:
		std::vector<Sphere> m_spheres;
		Vector m_light;
		double m_intensity;
};

#endif