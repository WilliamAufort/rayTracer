#ifndef DEF_VECTOR
#define DEF_VECTOR

#include <iostream>

class Vector
{
	public:
		Vector();
		Vector(double x, double y, double z);
		Vector(Vector const& u);

		double getX() const __attribute__((pure));
		double getY() const __attribute__((pure));
		double getZ() const __attribute__((pure));

		Vector& operator+=(const Vector& v);
		Vector& operator-=(const Vector& v);
		Vector operator-() const;
		Vector& prodByScal(double lambda);
		void printVector(std::ostream& flux) const;

		Vector& convertIntoColor(bool gamma_correction);

	private:
		double m_x;
		double m_y;
		double m_z;
};

Vector operator+(Vector const& u, Vector const& v) __attribute__((pure));
Vector operator-(Vector const& u, Vector const& v) __attribute__((pure));
Vector operator*(double lambda, Vector const& u) __attribute__((pure));

Vector prodByCoord(Vector const& u, Vector const& v) __attribute__((pure));
double scalarProd(Vector const& u, Vector const& v)  __attribute__((pure));
Vector crossProd(Vector const& u, Vector const& v) __attribute__((pure));
double norm(Vector const& u) __attribute__((pure));
double squareNorm(Vector const& u) __attribute__((pure));
Vector normalize(Vector const& u) __attribute__((pure));

std::ostream& operator<<(std::ostream& flux, Vector const& u);

#endif
