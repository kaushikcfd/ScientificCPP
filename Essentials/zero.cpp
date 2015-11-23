/**
 * This zeroes.h would generate the zeroes array for the initialization.
 * This should take in an argument for an array and make all the elements in it zero.
 * */
/**
 * VARIABLES USED:
 * std::vector<double> GivenVector: This actually is used as a function argument and has no end use. It is the part of the function void zeroes(vector<double> & )
 * int CurrentElement: This denotes the CurrentElement we are dealing in the vector we are dealling with.
 * int VecorLength: This denotes the length of the vector being dealt over here.

 * FUNCTIONS USED/CREATED:
 * void zeroes(vector<double> & ): This is the main operating function of this file.
**/

#include <vector>
#include <cstdio>
#ifndef _SCIENTIFICCPP_H
#define _SCIENTIFICCPP_H
#endif

using namespace std;

void zeroes(vector<double> & GivenVector)
{
	int CurrentElement,VectorLength=GivenVector.size();
	for(CurrentElement = 0; CurrentElement < VectorLength; CurrentElement++)
		GivenVector[CurrentElement] = 0.0;
	printf("Success, VECTOR of size %d created with zeroes.\n",VectorLength);	
}




/**END OF THE FILE.**/
