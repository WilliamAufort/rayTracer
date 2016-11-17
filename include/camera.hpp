#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "vector.hpp"
#include "image.hpp"
#include "ray.hpp"
#include "scene.hpp"

/**
* The camera used by the raytracer
**/

class Camera
{
	public:
		Camera();
		~Camera();

		Vector getCenter() const __attribute__((pure));
		unsigned int getHeight() const __attribute__((pure));
		unsigned int getWidth() const __attribute__((pure));

		void setLookat(Vector position, Vector direction, Vector up);
		void setFov(double fov);
		void setImage(double height, double width);
		void setScene(Scene s);
		void setGamma(bool gamma_correction);
		void setParallel(bool omp);

		Ray startingRay(unsigned int i, unsigned int j);

		void setColor(unsigned int i, unsigned int j, unsigned char r, unsigned char g, unsigned char b);
		void setColor(unsigned int i, unsigned int j, double gray);
		void setColor(unsigned int i, unsigned int j, Vector color);
		void plotScene();
		void save(std::string filename);

	private:
		Vector m_center;
		double m_fov;
		Vector m_direction;
		Vector m_up;
		Image m_image;
		Scene m_scene;
		bool m_gamma_correction;
		bool m_omp;
};

Camera parseFile(std::string fileName);

#endif
