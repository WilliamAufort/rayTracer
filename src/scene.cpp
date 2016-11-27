#include "../include/scene.hpp"
#include "../include/utils.hpp"
#include "../include/material.hpp"

using namespace std;

/**
* Empty scene
**/

Scene::Scene() : m_spheres(vector<Sphere>()), m_light(Vector()), m_intensity(0), m_eng(RandomEngine()) {}

/**
* The scene with all the parameters given by the user
**/
	
Scene::Scene(vector<Sphere> spheres, Vector light, double intensity) : m_spheres(spheres), m_light(light), m_intensity(intensity), m_eng(RandomEngine()) {}

/**
* Destructor
**/

Scene::~Scene() {}

/**
* Return the normal vector to the i-th sphere of the scene
**/

Vector Scene::normal(unsigned int i, Vector point)
{
	return (m_spheres[i]).normal(point);
}

/**
* Return the color to the i-th sphere of the scene
**/

Vector Scene::getColor(unsigned int i) const
{
	return (m_spheres[i]).getColor();
}

/**
* Is the i-th sphere of the scene emissive ?
**/

bool Scene::isEmissive(unsigned int i) const
{
	return (m_spheres[i]).isEmissive();
}

/**
* Get the emissivity coefficient of the i-th sphere
**/

double Scene::getRho(unsigned int i) const
{
	return (m_spheres[i]).getRho();
}

/**
* Is the i-th sphere of the scene specular?
**/

bool Scene::isSpecular(unsigned int i) const
{
	return (m_spheres[i]).isSpecular();
}

/**
* Return the ray reflected on the i-th sphere of the scene
**/

Ray Scene::reflect(Ray r, Vector intersect, unsigned int i) const
{
	return (m_spheres[i]).reflect(r,intersect);
}

/**
* Is the i-th sphere of the scene transparent?
**/

bool Scene::isTransparent(unsigned int i) const
{
	return (m_spheres[i]).isTransparent();
}

/**
* Is there a refraction on the i-th sphere? If yes, return the refracted ray
**/

pair<bool,Ray> Scene::refract(Ray r, Vector intersect, unsigned int i) const
{
	return (m_spheres[i]).refract(r,intersect);
}

/**
* Is the i-th sphere diffuse ?
**/

bool Scene::isDiffuse(unsigned int i) const
{
	return (m_spheres[i]).isDiffuse();
}

/**
* Get the diffuse coefficient of the i-th sphere
**/

double Scene::getDiffuseCoeff(unsigned int i) const
{
	return (m_spheres[i]).getDiffuseCoeff();
}

/**
* Compute the intersection and the intersected primitive (if they exist) with a given ray
**/

pair<unsigned int,double> Scene::computeIntersect(Ray r) const
{
	double result = -1;
	unsigned int index = 0; 
	for (unsigned int i = 0; i < m_spheres.size(); i++)
	{
		double t = (m_spheres[i]).computeIntersect(r);
		if (not closeEnough(t,-1))
		{
			if (closeEnough(result,-1)) // First initialization
			{
				result = t;
				index = i;
			}
			else if (t < result)
			{
				result = t; // Find the min
				index = i;
	}	}	}
	return make_pair(index,result);
}

/**
* Is a point shadowed by the scene ?
**/

bool Scene::isShadowed(Vector point) const
{
	Ray r(point, m_light - point);
	pair<unsigned int,double> t = computeIntersect(r);
	if (closeEnough(t.second,-1)) return false;
	else
	{
		Vector intersect_pt = r.getIntersect(t.second);
		return (squareNorm(intersect_pt - point) < squareNorm(m_light - point));
}	}

/**
* Compute the color in the direction of a ray
**/

Vector Scene::getColor(Ray r)
{
	return getColor(r,max_rebounds);
}

Vector Scene::getColor(Ray r, unsigned int nb_rebounds)
{
	Vector color; // black
	pair<unsigned int, double> t = computeIntersect(r);
	if (not closeEnough(t.second,-1))
	{
		Vector intersect_pt = r.getIntersect(t.second);
		if (isSpecular(t.first) and (nb_rebounds != 0))
		{
			color += getColor(reflect(r,intersect_pt,t.first),nb_rebounds-1);
		}
		if (isTransparent(t.first) and (nb_rebounds != 0))
		{
			pair<bool,Ray> refrac = refract(r,intersect_pt,t.first);
			if (refrac.first) {
				color += getColor(refrac.second,nb_rebounds-1);
		}	}
		if (isDiffuse(t.first) and (nb_rebounds != 0))
		{
			Vector sample = m_eng.sampleHemisphere(normal(t.first,intersect_pt));
			Ray random_ray(intersect_pt,sample);
			color += getDiffuseCoeff(t.first) * getColor(random_ray,nb_rebounds-1);
		}
		if (isEmissive(t.first) and not isShadowed(intersect_pt))
		{
			double scal_prod = scalarProd(normalize(m_light - intersect_pt), normalize(normal(t.first,intersect_pt)));
			double factor = 255 * scal_prod * m_intensity / squareNorm(m_light - intersect_pt) * getRho(t.first) ;
			color += factor * getColor(t.first);
	}	}
	return color;
}
