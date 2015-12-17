/**
 * This GaussEimination.cpp would solve the system of linear equation.
 * This should take in an argument for an vector and make all the elements in it one.
 * */
/**
 * VARIABLES USED:
 * std::vector<double> GivenVector: This actually is used as a function argument and has no end use. It is the part of the function void zeroes(vector<double> & )
 * int CurrentElement: This denotes the CurrentElement we are dealing in the vector we are dealling with.
 * int VecorLength: This denotes the length of the vector being dealt over here.

 * FUNCTIONS USED/CREATED:
 * void ones(vector<double> & ): This is the main operating function of this file.
**/

#include <vector>
#include <cstdio>
#ifndef _SCIENTIFICCPP_H
#define _SCIENTIFICCPP_H
#endif

using namespace std;

vector<double> GaussElimination(vector< vector<double> > A, vector<double> b);
/**END OF THE FILE.**/
