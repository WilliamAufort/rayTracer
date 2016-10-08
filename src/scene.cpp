#include "../include/scene.hpp"
#include "../include/utils.hpp"
#include "../include/material.hpp"

using namespace std;

Scene::Scene() : m_light(Vector(-10,20,40)), m_intensity(2000)
{
	Sphere s; //central sphere
	Sphere s_behind (Vector(0,0,1000),940,pink);
	Sphere s_front(Vector(0,0,-1000),940,green);
	Sphere s_above(Vector(0,1000,0),940,red);
	Sphere s_below(Vector(0,-1000,0),990,blue);
	Sphere s_left(Vector(1000,0,0),940,yellow);
	Sphere s_right(Vector(-1000,0,0),940,white);
	m_spheres.push_back(s);
	m_spheres.push_back(s_left);
	m_spheres.push_back(s_right);
	m_spheres.push_back(s_above);
	m_spheres.push_back(s_below);
	m_spheres.push_back(s_behind);
	m_spheres.push_back(s_front);
}
	
Scene::Scene(vector<Sphere> spheres, Vector light, double intensity) : m_spheres(spheres), m_light(light), m_intensity(intensity) {}

Vector Scene::normal(unsigned int i, Vector point)
{
	return (m_spheres[i]).normal(point);
}

Vector Scene::getColor(unsigned int i) const
{
	return (m_spheres[i]).getColor();
}

bool Scene::isSpecular(unsigned int i) const
{
	return (m_spheres[i]).isSpecular();
}

Ray Scene::reflect(Ray r, Vector intersect, unsigned int i) const
{
	return (m_spheres[i]).reflect(r,intersect);
}

bool Scene::isTransparent(unsigned int i) const
{
	return (m_spheres[i]).isTransparent();
}

pair<bool,Ray> Scene::refract(Ray r, Vector intersect, unsigned int i) const
{
	return (m_spheres[i]).refract(r,intersect);
}

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

Vector Scene::getColor(Ray r)
{
	return getColor(r,max_rebounds,true);
}

Vector Scene::getColor(Ray r, unsigned int nb_rebounds, bool allowShadows)
{
	Vector color; // black
	pair<unsigned int, double> t = computeIntersect(r);
	if (not closeEnough(t.second,-1))
	{
		Vector intersect_pt = r.getIntersect(t.second);
		if (not allowShadows or not isShadowed(intersect_pt))
		{
			if (isSpecular(t.first))
			{
				color += getColor(reflect(r,intersect_pt,t.first),nb_rebounds-1,false);
			}
			if (isTransparent(t.first))
			{
				pair<bool,Ray> refrac = refract(r,intersect_pt,t.first);
				if (refrac.first) {
					color += getColor(refrac.second,nb_rebounds-1,false);
			}	}
			double scal_prod = scalarProd(normalize(m_light - intersect_pt), normalize(normal(t.first,intersect_pt)));
			double factor = 255 * scal_prod * m_intensity / squareNorm(m_light - intersect_pt);
			color += factor * getColor(t.first);
		}
	}
	return color;
}
