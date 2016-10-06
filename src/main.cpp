#include "../include/camera.hpp"
#include <iostream>

using namespace std;

int main()
{
	Camera test(500,500);
	Scene s;
	test.plotScene(s);
	test.save("test.bmp");
	return 0;
}
