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
		cout << "./rayTracer" << endl;
		cout << "--output file		Save the image in file" << endl;
		cout << "--gamma			Use gamma correction" << endl;
		cout << "--omp				Use OpenMP" << endl;
		cout << "-h / --help		You're actually in the help mode" << endl;
		return EXIT_FAILURE;
	}
	Camera test(500,500,arguments.getOption("-gamma"),arguments.getOption("-omp"));
	Scene s;
	test.plotScene(s);
	test.save(arguments.getParameter("-output","test.bmp"));
	}
	return 0;
}
