#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "vector.hpp"
#include "image.hpp"
#include "ray.hpp"
#include "scene.hpp"

class Camera
{
	public:
		// TODO add Scene as a camera member
		Camera(); // The default camera in the project
		Camera(unsigned int height, unsigned int width, bool gamma_correction);
		Camera(Vector center, double fov, Vector direction, Vector up, unsigned int height, unsigned int width, bool gamma_correction);

		Vector getCenter() const __attribute__((pure));
		unsigned int getHeight() const __attribute__((pure));
		unsigned int getWidth() const __attribute__((pure));

		Ray startingRay(unsigned int i, unsigned int j);

		void setColor(unsigned int i, unsigned int j, unsigned char r, unsigned char g, unsigned char b);
		void setColor(unsigned int i, unsigned int j, double gray);
		void setColor(unsigned int i, unsigned int j, Vector color);
		void plotScene(Scene s);
		void save(std::string filename);

	private:
		Vector m_center;
		double m_fov;
		Vector m_direction;
		Vector m_up;
		Image m_image;
		bool m_gamma_correction;
};

#endif
