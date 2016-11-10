#include "../include/material.hpp"

using namespace std;

/**
* A only diffuse material
**/

Material::Material() : m_specular(false), m_transparent(false), m_refr_index(1) {}

/**
* A specular material
**/

Material::Material(bool specular) : m_specular(specular), m_transparent(false), m_refr_index(1) {}

/**
* A transparent material
**/

Material::Material(bool transparent, double refr_index) : m_specular(false), m_transparent(transparent), m_refr_index(refr_index) {}

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

void Material::setTransparency(bool specular, double index)
{
	m_specular = specular;
	m_refr_index = index;
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
