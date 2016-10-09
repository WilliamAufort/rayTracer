#include <iostream>
#include <cmath>
#include <stdexcept>
#include "../include/utils.hpp"
#include "../include/vector.hpp"

using namespace std;

Vector::Vector() : m_x(0), m_y(0), m_z(0) {}

Vector::Vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

Vector::Vector(Vector const& u) : m_x(u.m_x), m_y(u.m_y), m_z(u.m_z) {}

double Vector::getX() const
{
	return m_x;
}

double Vector::getY() const
{
	return m_y;
}

double Vector::getZ() const
{
	return m_z;
}

Vector& Vector::operator+=(const Vector& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
	return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
	m_x -= v.m_x;
	m_y -= v.m_y;
	m_z -= v.m_z;
	return *this;
}

Vector Vector::operator-() const
{
	Vector v;
	v.m_x = -m_x;
	v.m_y = -m_y;
	v.m_z = -m_z;
	return v;
}

Vector& Vector::prodByScal(double lambda)
{
	m_x = lambda * m_x;
	m_y = lambda * m_y;
	m_z = lambda * m_z;
	return *this;
}

void Vector::printVector(ostream& flux) const
{
	flux <<	"(" << m_x << "," << m_y << "," << m_z << ")";
}

Vector& Vector::convertIntoColor(bool gamma_correction)
{
	m_x = convertColor(m_x,gamma_correction);
	m_y = convertColor(m_y,gamma_correction);
	m_z = convertColor(m_z,gamma_correction);
	return *this;
}

Vector operator+(Vector const& u, Vector const& v)
{
	Vector copie(u);
	copie += v;
	return copie;
}

Vector operator-(Vector const& u, Vector const& v)
{
	Vector copie(u);
	copie -= v;
	return copie;
}

Vector operator*(double lambda, Vector const& u)
{
	Vector copie(u);
	copie.prodByScal(lambda);
	return copie;
}

Vector prodByCoord(Vector const& u, Vector const& v)
{
	double x = u.getX() * v.getX();
	double y = u.getY() * v.getY();
	double z = u.getZ() * v.getZ();
	Vector res(x,y,z);
	return res;
}

double scalarProd(Vector const& u, Vector const& v)
{
	return u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ();
}

Vector crossProd(Vector const& u, Vector const& v)
{
	double x = u.getY() * v.getZ() - u.getZ() * v.getY();
	double y = u.getZ() * v.getX() - u.getX() * v.getZ();
	double z = u.getX() * v.getY() - u.getY() * v.getX();
	Vector res(x,y,z);
	return res;
}

double norm(Vector const& u)
{
	return sqrt(squareNorm(u));
}
double squareNorm(Vector const& u)
{
	return u.getX() * u.getX() + u.getY() * u.getY() + u.getZ() * u.getZ();
}
Vector normalize(Vector const& u)
{
	double n = norm(u);
	if (closeEnough(n,0)) // do (n == 0) is unsafe with FP
		throw overflow_error("Division by zero!");
	else return (1/n)*u ;
}

ostream& operator<<(ostream& flux, Vector const& u)
{
	u.printVector(flux);
	return flux;
}
