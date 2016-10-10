#include "../include/camera.hpp"
#include "../include/utils.hpp"
#include <cmath>
#include <iostream> // TODO For debug only
#include <omp.h>

using namespace std;

Camera::Camera() : m_center(Vector(0,0,55)), m_fov(pi/3), m_direction(Vector(0,0,-1)), m_up(Vector(1,0,0)), m_image(Image()), m_gamma_correction(false), m_omp(false) {} // The configuration of the camera in the project

Camera::Camera(unsigned int height, unsigned int width, bool gamma_correction, bool omp) : m_center(Vector(0,0,55)), m_fov(pi/3), m_direction(Vector(0,0,-1)), m_up(Vector(1,0,0)), m_image(Image(height,width)), m_gamma_correction(gamma_correction), m_omp(omp) {}

Camera::Camera(Vector center, double fov, Vector direction, Vector up, unsigned int height, unsigned int width) : m_center(center), m_fov(fov), m_direction(direction), m_up(up), m_image(Image(height,width)), m_gamma_correction (false), m_omp(false) {}

Vector Camera::getCenter() const
{
	return m_center;
}

unsigned int Camera::getHeight() const
{
	return m_image.getHeight();
}

unsigned int Camera::getWidth() const
{
	return m_image.getWidth();
}

Ray Camera::startingRay(unsigned int i, unsigned int j)
{
	double x = i - static_cast<double>(m_image.getWidth())/2  + 0.5;
	double y = j - static_cast<double>(m_image.getHeight())/2 + 0.5;
	double z = - static_cast<double>(m_image.getHeight())/(2*tan(m_fov/2));
	Vector v = Vector(x,y,z);
	return Ray(m_center,v);
}

void Camera::setColor(unsigned int i, unsigned int j, Vector color)
{
	Vector true_colors = color.convertIntoColor(m_gamma_correction);
	unsigned char r = static_cast<unsigned char>(true_colors.getX());
	unsigned char g = static_cast<unsigned char>(true_colors.getY());
	unsigned char b = static_cast<unsigned char>(true_colors.getZ());
	m_image.setColor(i,j,r,g,b);
}

void Camera::plotScene(Scene s)
{
	if (m_omp)
	{
		#pragma omp parallel for schedule(dynamic,1)
		for(unsigned int i = 0; i < m_image.getWidth(); i++)
			for(unsigned int j = 0; j < m_image.getHeight(); j++)
			{
				Ray r = startingRay(i,j);
				Vector color = s.getColor(r);
				setColor(i,j,color);
	}		}
	else
	{
		for(unsigned int i = 0; i < m_image.getWidth(); i++)
			for(unsigned int j = 0; j < m_image.getHeight(); j++)
			{
				Ray r = startingRay(i,j);
				Vector color = s.getColor(r);
				setColor(i,j,color);
}	}		}

void Camera::save(string filename)
{
	m_image.save(filename.c_str());
}
