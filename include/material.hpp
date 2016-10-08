#ifndef DEF_MATERIAL
#define DEF_MATERIAL

#include "utils.hpp"
#include "vector.hpp"

class Material
{
	public:
		Material();
		Material(Vector color);
		Material(Vector color, bool specular);
		Material(Vector color, bool transparent, double refr_index);

		Vector getColor() const __attribute__((pure));
		bool isSpecular() const __attribute__((pure));
		bool isTransparent() const __attribute__((pure));
		double getRefrIndex() const __attribute__((pure));

	private:
		Vector m_color;
		bool m_specular;
		bool m_transparent;
		double m_refr_index;
};

const Material black = Material();
const Material red = Material(Vector(1,0,0));
const Material green = Material(Vector(0,1,0));
const Material blue = Material(Vector(0,0,1));
const Material yellow = Material(Vector(1,1,0));
const Material white = Material(Vector(1,1,1));
const Material pink = Material(Vector(1,0.784,0.5765));

const Material mirror = Material(Vector(), true);
const Material glass = Material(Vector(), true, n_glass);

#endif
