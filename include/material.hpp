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
		Material(bool specular);
		Material(bool transparent, double refr_index);
		~Material() {};

		void setSpecularity(bool specular);
		void setTransparency(bool specular, double index);

		bool isSpecular() const __attribute__((pure));
		bool isTransparent() const __attribute__((pure));
		double getRefrIndex() const __attribute__((pure));

	private:
		bool m_specular;
		bool m_transparent;
		double m_refr_index;
};

const Vector black = Vector();
const Vector red = Vector(1,0,0);
const Vector green = Vector(0,1,0);
const Vector blue = Vector(0,0,1);
const Vector yellow =Vector(1,1,0);
const Vector white = Vector(1,1,1);
const Vector pink = Vector(1,0.784,0.5765);

const Material mirror = Material(true);
const Material glass = Material(true, n_glass);

#endif
