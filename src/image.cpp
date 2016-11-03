#include "../include/image.hpp"
#include <vector>
#include <stdexcept>
#include <fstream>
#include <string>

using namespace std;

/**
* A 255*255 image
**/

Image::Image() : m_height(256), m_width(256), m_red(vector<unsigned char>(256*256,0)), m_green(vector<unsigned char>(256*256,0)), m_blue(vector<unsigned char>(256*256,0)) {}

/**
* An image with given dimensions
**/

Image::Image(unsigned int height, unsigned int width) : m_height(height), m_width(width), m_red(vector<unsigned char>(height*width,0)), m_green(vector<unsigned char>(height*width,0)), m_blue(vector<unsigned char>(height*width,0)) {}

/**
* Is a pixel really inside the image ?
**/

bool Image::isValidPixel(unsigned int i, unsigned int j)
{
	return ((i < m_width) && (j < m_height));
}

/**
* Return the height of the image
**/

unsigned int Image::getHeight() const
{
	return m_height;
}

/**
* Return the width of the image
**/

unsigned int Image::getWidth() const
{
	return m_width;
}

/**
* Set a given color to a pixel
**/

void Image::setColor(unsigned int i, unsigned int j, unsigned char r, unsigned char g, unsigned char b)
{
	if (isValidPixel(i,j))
	{
		m_red[j*m_width + i] = r;
		m_green[j*m_width + i] = g;
		m_blue[j*m_width + i] = b;
	}
	else throw invalid_argument("Pixel out of range!");
}

/**
* Save the image in a file
* Note : This function is inspired from the stackoverflow link of the project notes
* http://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
**/


void Image::save(const char* filename)
{
	ofstream stream;
	stream.open(filename);

	unsigned char file[14] = {
		'B','M', // magic
		0,0,0,0, // size in bytes
		0,0, // app data
		0,0, // app data
		40+14,0,0,0 // start of data offset
		};
	unsigned char info[40] = {
		40,0,0,0, // info hd size
		0,0,0,0, // width
		0,0,0,0, // heigth
		1,0, // number color planes
		24,0, // bits per pixel
		0,0,0,0, // compression is none
		0,0,0,0, // image bits size
		0x13,0x0B,0,0, // horz resolution in pixel / m
		0x13,0x0B,0,0, // vert resolutions (0x03C3 = 96 dpi, 0x0B13 = 72 dpi)
		0,0,0,0, // #colors in pallete
		0,0,0,0, // #important colors
		};

	unsigned int padSize  = (4-(m_width*3)%4)%4;
	unsigned int sizeData = m_width*m_height*3 + m_height*padSize;
	size_t sizeAll  = sizeData + sizeof(file) + sizeof(info);

	file[ 2] = static_cast<unsigned char>(sizeAll    );
	file[ 3] = static_cast<unsigned char>(sizeAll>> 8);
	file[ 4] = static_cast<unsigned char>(sizeAll>>16);
	file[ 5] = static_cast<unsigned char>(sizeAll>>24);

	info[ 4] = static_cast<unsigned char>(m_width    );
	info[ 5] = static_cast<unsigned char>(m_width>> 8);
	info[ 6] = static_cast<unsigned char>(m_width>>16);
	info[ 7] = static_cast<unsigned char>(m_width>>24);

	info[ 8] = static_cast<unsigned char>(m_height    );
	info[ 9] = static_cast<unsigned char>(m_height>> 8);
	info[10] = static_cast<unsigned char>(m_height>>16);
	info[11] = static_cast<unsigned char>(m_height>>24);

	info[20] = static_cast<unsigned char>(sizeData    );
	info[21] = static_cast<unsigned char>(sizeData>> 8);
	info[22] = static_cast<unsigned char>(sizeData>>16);
	info[23] = static_cast<unsigned char>(sizeData>>24);

	stream.write(reinterpret_cast<char*>(file), sizeof(file));
	stream.write(reinterpret_cast<char*>(info), sizeof(info));

	unsigned char pad[3] = {0,0,0};

	for (unsigned int j = 0; j < m_height; j++)
	{
		for (unsigned int i = 0; i < m_width; i++)
		{
			unsigned char pixel[3];
			pixel[0] = m_blue[j*m_width + i];
			pixel[1] = m_green[j*m_width + i];
			pixel[2] = m_red[j*m_width + i];
			stream.write(reinterpret_cast<char*>(pixel), 3);
		}
		stream.write(reinterpret_cast<char*>(pad), padSize);
}	}
