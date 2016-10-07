#ifndef DEF_IMAGE
#define DEF_IMAGE

#include <vector>
// See : http://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries

class Image
{
	public:
		Image();
		Image(unsigned int height, unsigned int width);

		bool isValidPixel(unsigned int i, unsigned int j) __attribute__((pure));
		unsigned int getHeight() const __attribute__((pure));
		unsigned int getWidth() const __attribute__((pure));
		void setColor(unsigned int i, unsigned int j, unsigned char red, unsigned char green, unsigned char blue);
		void save(const char* filename);

	private:
		unsigned int m_height;
		unsigned int m_width;
		std::vector<unsigned char> m_red;
		std::vector<unsigned char> m_green;
		std::vector<unsigned char> m_blue;
		
};

#endif
