#include "../include/material.hpp"

using namespace std;

/**
* A black material
**/

Material::Material() : m_color(Vector()), m_specular(false), m_transparent(false), m_refr_index(1) {} // Black color

/**
* A colored material
**/

Material::Material(Vector color) : m_color(color), m_specular(false), m_transparent(false), m_refr_index(1) {}

/**
* A specular material
**/

Material::Material(Vector color, bool specular) : m_color(color), m_specular(specular), m_transparent(false), m_refr_index(1) {}

/**
* A transparent material
**/

Material::Material(Vector color, bool transparent, double refr_index) : m_color(color), m_specular(false), m_transparent(transparent), m_refr_index(refr_index) {}

/**
* Return the color of the material
**/

Vector Material::getColor() const
{
	return m_color;
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
