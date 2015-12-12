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
#ifndef _SCIENTIFICCPP_H
#define _SCIENTIFICCPP_H
#endif

using namespace std;

void stepFill(vector<double> & GivenVector, double start, double stepSize, double end)
{
	if(((end-start)*stepSize) > 0)
	{
		int CurrentElement;
		GivenVector.clear();
		GivenVector.push_back(start);
		for(CurrentElement = 0; GivenVector[CurrentElement] <= end; CurrentElement++)
		{
			if((GivenVector[CurrentElement]+stepSize)<=end)
				GivenVector.push_back(GivenVector[CurrentElement]+stepSize);
			else
				break;
		}
		printf("Success, VECTOR of size %ld created with stepSize %.6f.\n",GivenVector.size(),stepSize);	
	}
	else
		printf("Please check the given conditions the array will turn into an unending data structure!!!\n");
}
	/**END OF THE FILE.**/
