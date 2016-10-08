#include "../include/material.hpp"

using namespace std;

Material::Material() : m_color(Vector()), m_specular(false), m_transparent(false), m_refr_index(1) {} // Black color

Material::Material(Vector color) : m_color(color), m_specular(false), m_transparent(false), m_refr_index(1) {}

Material::Material(Vector color, bool specular) : m_color(color), m_specular(specular), m_transparent(false), m_refr_index(1) {}

Material::Material(Vector color, bool transparent, double refr_index) : m_color(color), m_specular(false), m_transparent(transparent), m_refr_index(refr_index) {}

Vector Material::getColor() const
{
	return m_color;
}

bool Material::isSpecular() const
{
	return m_specular;
}

bool Material::isTransparent() const
{
	return m_transparent;
}

double Material::getRefrIndex() const
{
	return m_refr_index;
}
