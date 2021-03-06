#ifndef DEF_SCENE
#define DEF_SCENE

#include "vector.hpp"
#include "sphere.hpp"
#include "ray.hpp"
#include "randomEngine.hpp"
#include <vector>
#include <utility>

/**
* The scene is the set of all objects we can see from the camera
**/

class Scene
{
	public:
		Scene();
		Scene(std::vector<Sphere> spheres, Vector light, double intensity);
		~Scene();

		Vector normal(unsigned int i, Vector point);
		Vector getColor(unsigned int i) const __attribute__((pure));

		bool isEmissive(unsigned int i) const __attribute__((pure));
		double getRho(unsigned int i) const __attribute__((pure));

		bool isSpecular(unsigned int i) const __attribute__((pure));
		Ray reflect(Ray r, Vector intersect, unsigned int i) const;

		bool isDiffuse(unsigned int i) const __attribute__((pure));
		double getDiffuseCoeff(unsigned int i) const __attribute__((pure));

		bool isTransparent(unsigned int i) const __attribute__((pure));
		std::pair<bool,Ray> refract(Ray r, Vector intersect, unsigned int i) const;

		std::pair<unsigned int,double> computeIntersect(Ray r) const;
		bool isShadowed(Vector point) const;

		Vector getColor(Ray r);
		Vector getColor(Ray r, unsigned int nb_rebounds);

	private:
		std::vector<Sphere> m_spheres;
		Vector m_light;
		double m_intensity;
		RandomEngine m_eng;
};

#endif
