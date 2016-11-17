#ifndef DEF_MATERIAL
#define DEF_MATERIAL

#include "utils.hpp"
#include "vector.hpp"

/**
* Implementation of the materials
**/

class Material
{
	public:
		Material();
		~Material() {};

		void setSpecularity(bool specular);
		void setTransparency(bool transparent, double index);

		bool isSpecular() const __attribute__((pure));
		bool isTransparent() const __attribute__((pure));
		double getRefrIndex() const __attribute__((pure));

	private:
		bool m_specular;
		bool m_transparent;
		double m_refr_index;
};

#endif
