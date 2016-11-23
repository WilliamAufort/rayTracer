#include "../include/material.hpp"

using namespace std;

/**
* A only diffuse material
**/

Material::Material() : m_emissive(false), m_rho(0), m_specular(false), m_transparent(false), m_refr_index(1) {}

/**
* Set the emissivity
**/

void Material::setEmissivity(bool emissive, double rho)
{
	m_emissive = emissive;
	m_rho = rho; // TODO Sanity check
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

void Material::setSpecularity(bool specular)
{
	m_specular = specular;
}

/**
* Set the transparency
**/

void Material::setTransparency(bool transparent, double index)
{
	m_transparent = transparent;
	m_refr_index = index;
}

/**
* Is the material emissive ?
**/

bool Material::isEmissive() const
{
	return m_emissive; // TODO Not implemented yet
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
