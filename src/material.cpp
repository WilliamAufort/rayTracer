#include "../include/material.hpp"

using namespace std;

/**
* A only diffuse material
**/

Material::Material() : m_emissive(false), m_rho(0), m_specular(false), m_transparent(false), m_refr_index(1) {}

/**
* Set the emissivity coefficient
**/

void Material::setEmissivity(double rho)
{
	m_emissive = true;
	// Sanity checks : rho \in [0,1]
	if (rho < 0)
	{
		cout << "Warning: emissivity coefficient set to the value: " << rho;
		cout << " < 0, changed to the value 0" << endl;
		m_rho = 0;
	}
	else if (rho > 1)
	{
		cout << "Warning: emissivity coefficient set to the value: " << rho;
		cout << " > 1, changed to the value 1" << endl;
		m_rho = 1;
	}
	else m_rho = rho;
}

/**
* Return the emissivity coefficient
**/

double Material::getRho() const
{
	return m_rho;
}

/**
* Set the specularity
**/

void Material::setSpecularity()
{
	m_specular = true;
}

/**
* Set the transparency
**/

void Material::setTransparency(double index)
{
	m_transparent = true;
	m_refr_index = index;
}

/**
* Is the material emissive ?
**/

bool Material::isEmissive() const
{
	return m_emissive;
}

/**
* Is the material specular ?
**/

bool Material::isSpecular() const
{
	return m_specular;
}

/**
* Is the material transparent ?
**/

bool Material::isTransparent() const
{
	return m_transparent;
}

/**
* Return the refraction index, if the material is transparent
**/

double Material::getRefrIndex() const
{
	return m_refr_index;
}
