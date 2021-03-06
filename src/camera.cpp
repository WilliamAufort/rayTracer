#include "../include/camera.hpp"
#include "../include/utils.hpp"
#include "../parser/driver.h"
#include "../include/parseError.hpp"
#include <cmath>
#include <omp.h>

using namespace std;

/**
* Setup camera
**/

Camera::Camera() : m_center(Vector()), m_fov(0), m_direction(Vector()), m_up(Vector()), m_image(Image()), m_scene(Scene()), m_gamma_correction(false), m_omp(false), m_nb_rays(1) {}

Camera::~Camera() {}

/**
* Get the position of the camera
**/

Vector Camera::getCenter() const
{
	return m_center;
}

/**
* Get the height of the image saved from the camera
**/

unsigned int Camera::getHeight() const
{
	return m_image.getHeight();
}

/**
* Get the width of the image saved from the camera
**/

unsigned int Camera::getWidth() const
{
	return m_image.getWidth();
}

/**
* Set the place of the camera
**/

void Camera::setLookat(Vector position, Vector direction, Vector up)
{
	m_center = position;
	m_direction = direction;
	m_up = up;
}

/**
* Set the fov (in degrees) of the camera
**/

void Camera::setFov(double fov)
{
	m_fov = (pi * fov)/180;
}

/**
* Setup the image
**/

void Camera::setImage(double height, double width)
{
	unsigned int h = static_cast<unsigned int>(height);
	unsigned int w = static_cast<unsigned int>(width);
	m_image = Image(h,w);
}

/**
* Set the scene the camera observes
**/

void Camera::setScene(Scene s)
{
	m_scene = s;
}

/**
* Set the gamma correction option
**/

void Camera::setGamma(bool gamma_correction)
{
	m_gamma_correction = gamma_correction;
}

/**
* Set the Omp parallel option
**/

void Camera::setParallel(bool omp)
{
	m_omp = omp;
}

/**
* Set the chosen number of rays per pixel
**/

void Camera::setNbRays(unsigned int nb_rays)
{
	m_nb_rays = nb_rays;
}

/**
* Build the ray from the camera used to print a particular pixel
**/

Ray Camera::startingRay(unsigned int i, unsigned int j)
{
	double x = i - static_cast<double>(m_image.getWidth())/2  + 0.5;
	double y = j - static_cast<double>(m_image.getHeight())/2 + 0.5;
	double z = - static_cast<double>(m_image.getHeight())/(2*tan(m_fov/2));
	Vector v = Vector(x,y,z);
	return Ray(m_center,v);
}

/**
* Set a pixel to a given color
**/

void Camera::setColor(unsigned int i, unsigned int j, Vector color)
{
	Vector true_colors = color.convertIntoColor(m_gamma_correction);
	unsigned char r = static_cast<unsigned char>(true_colors.getX());
	unsigned char g = static_cast<unsigned char>(true_colors.getY());
	unsigned char b = static_cast<unsigned char>(true_colors.getZ());
	m_image.setColor(i,j,r,g,b);
}

/**
* Build the image representing the scene 
**/

void Camera::plotScene()
{
	if (m_omp)
	{
		#pragma omp parallel for schedule(dynamic,1)
		for(unsigned int i = 0; i < m_image.getWidth(); i++)
			for(unsigned int j = 0; j < m_image.getHeight(); j++)
			{
				Ray r = startingRay(i,j);
				Vector color;
				for(unsigned int n = 0; n < m_nb_rays; n++)
					color += m_scene.getColor(r);
				setColor(i,j,(1/static_cast<double>(m_nb_rays))*color);
	}		}
	else
	{
		for(unsigned int i = 0; i < m_image.getWidth(); i++)
			for(unsigned int j = 0; j < m_image.getHeight(); j++)
			{
				Ray r = startingRay(i,j);
				Vector color;
				for(unsigned int n = 0; n < m_nb_rays; n++)
					color += m_scene.getColor(r);
				setColor(i,j,(1/static_cast<double>(m_nb_rays))*color);
}	}		}

/**
* Save the image in a file
**/

void Camera::save(string filename)
{
	m_image.save(filename.c_str());
}

/**
* Parse a camera from a .sc file
**/

Camera parseFile(string fileName)
{
	sceneParser::Driver parserDriver;
	try
	{
		return parserDriver.parse(fileName);
	}
	catch(ParseError& e)
	{
		cerr << "Parser error : " << e.getMessage() << endl << "Stop." << endl;
		exit(EXIT_FAILURE);
}	}
