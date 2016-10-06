#include "../include/sphere.hpp"
#include "../include/utils.hpp"
#include <vector>

using namespace std;

Sphere::Sphere() : m_center(Vector()), m_r(10), m_material(mirror) {} // Example of the project

Sphere::Sphere(Vector center, double r) : m_center(center), m_r(r), m_material(white) {}

Sphere::Sphere(Vector center, double r, Material mat) : m_center(center), m_r(r), m_material(mat) {}

Vector Sphere::getColor() const
{
	return m_material.getColor();
}

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

Vector Sphere::normal(Vector point) const
{
	return point - m_center;
}

bool Sphere::isSpecular() const
{
	return m_material.isSpecular();
}

Ray Sphere::reflect(Ray r, Vector intersect) const
{
	Vector i = r.getDirection();
	Vector n = normal(intersect);
	return Ray(intersect, i - (2 * scalarProd(i,n) / squareNorm(n)) * n); // No need to normalize i, but we divide by squareNorm to avoid normalization computations
}
