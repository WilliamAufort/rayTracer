#include "../include/randomEngine.hpp"
#include "../include/utils.hpp"
#include <cmath>

using namespace std;

RandomEngine::RandomEngine() : m_engine(default_random_engine()), m_distrib(uniform_real_distribution<double>(0,1)) {}

/**
* Sample a vector in the unit hemisphere directed by the input vector
**/

Vector RandomEngine::sampleHemisphere(Vector n)
{
	Vector i = someOrthogonal(n);
	Vector j = crossProd(n,i);
	// (i,j,n) is thus an orthonormal set oriented along n
	double r1 = m_distrib(m_engine);
	double r2 = m_distrib(m_engine);
	double s = sqrt(1-r2);
	double x = cos(2*pi*r1) * s;
	double y = sin(2*pi*r1) * s;
	double z = sqrt(r2);
	return (x * i + y * j + z * n);
}
