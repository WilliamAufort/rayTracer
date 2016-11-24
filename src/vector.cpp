#include <iostream>
#include <cmath>
#include <stdexcept>
#include "../include/utils.hpp"
#include "../include/vector.hpp"

using namespace std;

/**
* The zero vector
**/

Vector::Vector() : m_x(0), m_y(0), m_z(0) {}

/**
* Any vector
**/

Vector::Vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

/**
* Copy
**/

Vector::Vector(Vector const& u) : m_x(u.m_x), m_y(u.m_y), m_z(u.m_z) {}

/**
* Return the first coordinate
**/

double Vector::getX() const
{
	return m_x;
}

/**
* Return the second coordinate
**/

double Vector::getY() const
{
	return m_y;
}

/**
* Return the third coordinate
**/

double Vector::getZ() const
{
	return m_z;
}

/**
* Add a vector
**/

Vector& Vector::operator+=(const Vector& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
	return *this;
}

/**
* Substract a vector
**/

Vector& Vector::operator-=(const Vector& v)
{
	m_x -= v.m_x;
	m_y -= v.m_y;
	m_z -= v.m_z;
	return *this;
}

/**
* Opposite of a vector
**/

Vector Vector::operator-() const
{
	Vector v;
	v.m_x = -m_x;
	v.m_y = -m_y;
	v.m_z = -m_z;
	return v;
}

/**
* Product scalar * vector
**/

Vector& Vector::prodByScal(double lambda)
{
	m_x = lambda * m_x;
	m_y = lambda * m_y;
	m_z = lambda * m_z;
	return *this;
}

/**
* Print a vector
**/

void Vector::printVector(ostream& flux) const
{
	flux <<	"(" << m_x << "," << m_y << "," << m_z << ")";
}

/**
* Convert a vector into a vector of colors
**/

Vector& Vector::convertIntoColor(bool gamma_correction)
{
	m_x = convertColor(m_x,gamma_correction);
	m_y = convertColor(m_y,gamma_correction);
	m_z = convertColor(m_z,gamma_correction);
	return *this;
}

/**
* Add two vectors
**/

Vector operator+(Vector const& u, Vector const& v)
{
	Vector copie(u);
	copie += v;
	return copie;
}

/**
* Substract two vectors
**/

Vector operator-(Vector const& u, Vector const& v)
{
	Vector copie(u);
	copie -= v;
	return copie;
}

/**
* Multiply a vector by a scalar
**/

Vector operator*(double lambda, Vector const& u)
{
	Vector copie(u);
	copie.prodByScal(lambda);
	return copie;
}

/**
* Product coordinate by coordinate
* TODO useful ?
**/

Vector prodByCoord(Vector const& u, Vector const& v)
{
	double x = u.getX() * v.getX();
	double y = u.getY() * v.getY();
	double z = u.getZ() * v.getZ();
	Vector res(x,y,z);
	return res;
}

/**
* Scalar product of two vectors
**/

double scalarProd(Vector const& u, Vector const& v)
{
	return u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ();
}

/**
* Cross product of two vectors
**/

Vector crossProd(Vector const& u, Vector const& v)
{
	double x = u.getY() * v.getZ() - u.getZ() * v.getY();
	double y = u.getZ() * v.getX() - u.getX() * v.getZ();
	double z = u.getX() * v.getY() - u.getY() * v.getX();
	Vector res(x,y,z);
	return res;
}

/**
* Compute the norm of vector
**/

double norm(Vector const& u)
{
	return sqrt(squareNorm(u));
}

/**
* Compute the squared norm of a vector
* Square root free, we use it as often as possible
**/

double squareNorm(Vector const& u)
{
	return u.getX() * u.getX() + u.getY() * u.getY() + u.getZ() * u.getZ();
}

/**
* Normalize a non-zero vector
**/

Vector normalize(Vector const& u)
{
	double n = norm(u);
	if (closeEnough(n,0))
		throw overflow_error("Division by zero!");
	else return (1/n)*u ;
}

/**
* Compute a vector orthogonal to the input vector
**/

Vector someOrthogonal(Vector const& u)
{
	if (not closeEnough(u.getX(),0))
	{
		Vector v(u.getY(), -u.getX(),0);
		return normalize(v);
	}
	else return Vector(1,0,0);
}

/**
* Print a vector
**/

ostream& operator<<(ostream& flux, Vector const& u)
{
	u.printVector(flux);
	return flux;
}
