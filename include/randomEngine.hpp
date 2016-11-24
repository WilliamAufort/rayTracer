#ifndef DEF_RANDOM_ENGINE
#define DEF_RANDOM_ENGINE

#include <random>
#include "vector.hpp"

class RandomEngine
{
	public:
		RandomEngine();
		~RandomEngine() {};

		Vector sampleHemisphere(Vector n);

	private:
		std::default_random_engine m_engine;
		std::uniform_real_distribution<double> m_distrib;
};

#endif
