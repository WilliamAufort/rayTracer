#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

#include <vector>

/**
* Some useful constants
**/

const double epsilon = 0.0000001;
const double pi = 3.1415926535;
const double n_air = 1;
const unsigned int max_rebounds = 5;

/**
* Some useful functions
**/

bool closeEnough(double d1, double d2) __attribute__((const));
bool isNonNegative(double d) __attribute__((const));
bool isNonPositive(double d) __attribute__((const));

std::vector<double> discriminant(double a, double b, double c) __attribute__((const));

double convertColor(double t, bool gamma_correction) __attribute__((const));

#endif
