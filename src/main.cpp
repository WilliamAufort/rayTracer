#include "../include/camera.hpp"
#include "../include/parserArguments.hpp"
#include "../include/utils.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	speedTest__("Execution time : ")
	{
		parserArguments arguments(parserArguments::getOptionsNames(), parserArguments::getParametersNames());
		arguments.parse(argc,argv);
		if (arguments.askHelp())
		{
			cout << endl << "Use the following syntax :" << endl;
			cout << "./rayTracer file.sc" << endl;
			cout << "--output=file      Save the image in file" << endl;
			cout << "--gamma            Use gamma correction" << endl;
			cout << "--omp              Use OpenMP in a naive way" << endl;
			cout << "--rays=nb          Use nb rays per pixel (default 1)" << endl;
			cout << "-h / --help        You're currently in the help mode" << endl;
			return EXIT_FAILURE;
		}

		// If no entry file, exit
		if(arguments.nbArguments()<1)
		{
			cout << endl << "Syntax :" << endl;
			cout << "./raytracer file"<< endl;
			cout << "Use `./raytracer --help' or `./rapidex -h' for help." << endl;
			return EXIT_FAILURE;
		}
		Camera cam = parseFile(arguments.getArgument(0));
		// Set the options
		cam.setGamma(arguments.getOption("-gamma"));
		cam.setParallel(arguments.getOption("-omp"));
		cam.setNbRays(static_cast<unsigned int>(stoi(arguments.getParameter("-rays","1"))));
		cam.plotScene();
		cam.save(arguments.getParameter("-output","test.bmp"));
	}
	return EXIT_SUCCESS;
}
