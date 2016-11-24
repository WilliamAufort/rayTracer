#include "../include/sphere.hpp"
#include "../include/utils.hpp"
#include <vector>
#include <cmath>

using namespace std;

/**
* An empty sphere
**/

Sphere::Sphere() : m_center(Vector()), m_r(0), m_color(Vector()), m_material(Material()) {}

/**
* A sphere with dimensions, color and material given
**/

Sphere::Sphere(Vector center, double r, Vector color, Material mat) : m_center(center), m_r(r), m_color(color), m_material(mat) {}

/**
* Return the color of the sphere
**/

Vector Sphere::getColor() const
{
	return m_color;
}

/**
* Compute the intersection between a given ray and the sphere
**/

double Sphere::computeIntersect(Ray ray) const
{
	Vector v = ray.getDirection();
	Vector u = ray.getOrigin() - m_center;
	double a = squareNorm(v);
	double b = 2 * scalarProd(v,u);
	double c = squareNorm(u) - m_r * m_r;
	vector<double> solutions = discriminant(a,b,c);
	double sol = -1; // The error case, when the solution is not relevant
	if ((solutions.size() == 1) and (isNonNegative(solutions[0])))
		sol = solutions[0];
	else if (solutions.size() == 2)
	{
		if (isNonNegative(solutions[0]))
			sol = solutions[0];
		else if (isNonNegative(solutions[1]))
			sol = solutions[1];
	}
	return sol;
}

/**
* Compute the normal vector on a given point of the sphere
**/

Vector Sphere::normal(Vector point) const
{
	return point - m_center;
}

/**
* Is the sphere emissive ?
**/

bool Sphere::isEmissive() const
{
	return m_material.isEmissive();
}

/**
* Return the emissivity coefficient of the sphere
**/

double Sphere::getRho() const
{
	return m_material.getRho();
}

/**
* Is the sphere specular?
**/

bool Sphere::isSpecular() const
{
	return m_material.isSpecular();
}

/**
* Reflect a ray on a sphere, given the intersection
**/

Ray Sphere::reflect(Ray r, Vector intersect) const
{
	Vector i = r.getDirection();
	Vector n = normal(intersect);
	return Ray(intersect, i - (2 * scalarProd(i,n) / squareNorm(n)) * n);
    // Note : no need to normalize i, but we divide by squareNorm to avoid normalization computations
}

/**
*  Is the sphere transparent?
**/

bool Sphere::isTransparent() const
{
	return m_material.isTransparent();
}

/**
* Is there a refraction on the sphere? If yes, return the refracted ray
**/

pair<bool,Ray> Sphere::refract(Ray r, Vector intersect) const
{
	Vector i = normalize(r.getDirection()); // TODO Try to avoid this
	Vector n = normalize(normal(intersect)); // TODO IDEM
	double n1 = n_air;
	double n2 = m_material.getRefrIndex();
	double prod = scalarProd(i,n);
	if (prod > 0)
	{
		swap(n1,n2);
		n = -n;
	}
	double ratio = n1/n2;
	double radicand =  1 - ratio * ratio * ( 1 - prod * prod);
	if (radicand < 0)
		return make_pair(false,r);
	else {
		Vector u = (ratio * i) - ((ratio * prod + sqrt(radicand)) * n);
		return make_pair(true,Ray(intersect,u));
}	}

/**
* Is the sphere diffuse ?
**/

bool Sphere::isDiffuse() const
{
	return m_material.isDiffuse();
}
