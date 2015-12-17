/**
 * This Increment.cpp would generate the series array for the initialization.
 * This should take in an argument for an vector and make all the elements in it one.
 * */
/**
 * VARIABLES USED:
 * std::vector<double> GivenVector: This actually is used as a function argument and has no end use. It is the part of the function void zeroes(vector<double> & )
 * int CurrentElement: This denotes the CurrentElement we are dealing in the vector we are dealling with.
 * int VectorLength: This denotes the length of the vector being dealt over here.

 * FUNCTIONS USED/CREATED:
 * void stepFill(vector<double> & , double , double  ): This is the main operating function of this file.
**/

#include <vector>
#include <cstdio>
#ifndef StepFill_H
#define StepFill_H
#endif

using namespace std;

vector<double> stepFill(double start, double stepSize, double end);
	
/**END OF THE FILE.**/
