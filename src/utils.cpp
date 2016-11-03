#include "../include/utils.hpp"
#include <cmath>
#include <iostream>

using namespace std;

/**
* Are the two numbers close enough? (d1 == d2 is unsafe with doubles)
**/

bool closeEnough(double d1, double d2)
{
    return fabs(d1-d2) < epsilon; 
}

/**
* Is a double non-negative?
**/

bool isNonNegative(double d)
{
	return (d >= epsilon);
}

/**
* Is a double non-positive?
**/

bool isNonPositive(double d)
{
	return (d <= - epsilon);
}

/**
* Compute the (eventual) roots of a quadratic function
**/

vector<double> discriminant(double a, double b, double c)
{
	vector<double> solutions;
	double delta = b * b - 4 * a * c;
	if (closeEnough(delta,0))
		solutions.push_back(-b/(2*a));
	else if (isNonNegative(delta)) // TODO Check a = 0
	{
		double small_delta = sqrt(delta);
		solutions.push_back((- b - small_delta)/(2*a));
		solutions.push_back((- b + small_delta)/(2*a));
	}
	return solutions;
}

/**
* Correct a color
**/

double convertColor(double t, bool gamma_correction)
{
	if (gamma_correction) t = pow(t/255,1/2.2)*255;
	if (t > 255) return 255;
	else if (t < 0) return 0;
	else return t;
}

