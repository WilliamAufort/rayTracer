#include "../include/material.hpp"

using namespace std;

Material::Material() : m_color(Vector()), m_specular(false) {} // Black color

Material::Material(Vector color) : m_color(color), m_specular(false) {}

Material::Material(Vector color, bool specular) : m_color(color), m_specular(specular) {}

Vector Material::getColor() const
{
	return m_color;
}

bool Material::isSpecular() const
{
	return m_specular;
}
