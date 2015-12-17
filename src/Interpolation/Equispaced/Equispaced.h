/**
 * This zeroes.h would generate the zeroes array for the initialization.
 * This should take in an argument for an array and make all the elements in it zero.
 * */
/**
 * VARIABLES USED:
 * std::vector<double> GivenVector: This actually is used as a function argument and has no end use. It is the part of the function void zeroes(vector<double> & )
 * int CurrentElement: This denotes the CurrentElement we are dealing in the vector we are dealling with.
 * int VecorLength: This denotes the length of the vector being dealt over here.
 * int m, n : denote the number of rows and columns.

 * FUNCTIONS USED/CREATED:
 * void zeroes(vector<double> & ): This is the main operating function of this file.
 * void zeros(vector< vector<double> > & GivenVector,int m, int n): This would be used for the intialization of an mxn matrix with all zeros. 

 **/

#include <vector>
#include <cstdio>

#include "../../MatrixOperations/GaussElimination/GaussElimination.h"
#include "../../Essentials/Zero/Zero.h"
#include "../../Essentials/StepFill/StepFill.h"

#ifndef Equispaced_H
#define Equispaced_H
#endif

using namespace std;

vector<double> equiInterpolation(double start, double end, unsigned int N, const vector<double>& Y);

/**END OF THE FILE.**/
