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

		void setEmissivity(double rho);
		void setSpecularity();
		void setTransparency(double index);
		void setDiffuse(double coeff);

		bool isEmissive() const __attribute__((pure));
		double getRho() const __attribute__((pure));

		bool isSpecular() const __attribute__((pure));

		bool isTransparent() const __attribute__((pure));
		double getRefrIndex() const __attribute__((pure));

		bool isDiffuse() const __attribute__((pure));
		double getDiffuseCoeff() const __attribute__((pure));

	private:
		bool m_emissive;
		double m_rho;
		bool m_specular;
		bool m_transparent;
		double m_refr_index;
		bool m_diffuse;
		double m_diffuse_coeff;
};

#endif
