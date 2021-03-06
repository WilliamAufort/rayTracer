#include "../include/camera.hpp"
#include "../include/parserArguments.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <sys/time.h>

using namespace std;

int main(int argc, char* argv[])
{
	// Time initialization
	struct timeval start, end;
	gettimeofday(&start, NULL);

	parserArguments arguments(parserArguments::getOptionsNames(), parserArguments::getParametersNames());
	arguments.parse(argc,argv);
	if (arguments.askHelp())
	{
		cout << endl << "Use the following syntax :" << endl;
		cout << "./rayTracer file.sc" << endl;
		cout << "--output=file.bmp    Save the image in bmp file" << endl;
		cout << "--gamma              Use gamma correction" << endl;
		cout << "--omp                Use OpenMP in a naive way" << endl;
		cout << "--rays=nb            Use nb rays per pixel (default 1)" << endl;
		cout << "-h / --help          You're currently in the help mode" << endl;
		return EXIT_FAILURE;
	}

	// If no entry file, exit
	if(arguments.nbArguments()<1)
	{
		cout << endl << "Syntax :" << endl;
		cout << "./raytracer file"<< endl;
		cout << "Use `./raytracer --help' or `./raytracer -h' for help." << endl;
		return EXIT_FAILURE;
	}

	// Parse
	Camera cam = parseFile(arguments.getArgument(0));

	// Set the options
	cam.setGamma(arguments.getOption("-gamma"));
	cam.setParallel(arguments.getOption("-omp"));
	cam.setNbRays(static_cast<unsigned int>(stoi(arguments.getParameter("-rays","1"))));

	// And run !
	cam.plotScene();
	cam.save(arguments.getParameter("-output","test.bmp"));

	// Time measurement
	gettimeofday(&end, NULL);
	double time = (static_cast<double>((end.tv_sec  - start.tv_sec) * 1000000u) + static_cast<double>(end.tv_usec - start.tv_usec)) / 1.e6;
	cout << "Executution time : " << time << endl;

	return EXIT_SUCCESS;
}
