/**
 * This function basically deals with the display function realted to the vectors.
 * Usage: display(_NAME_OF_THE_ARRAY)
 * VARIABLES USED:
 * 1.) vector<double> GivenVector: This is the variable used to take the vector argument provided by the user.
 * 2.) int CurrentElement: This is the variable which acts as an counter to traverse from the start to the end of the vector.
 *
 * FUNCTIONS USED:
 * 1.)void display(vector<double> & GivenVector): This is the main functional part of the code.
 **/

#include <vector>
#include <cstdio>

using namespace std;

void display(vector<double> & GivenVector)
{
	int CurrentElement, VectorLength = GivenVector.size();
	for(CurrentElement=0; CurrentElement< VectorLength; CurrentElement++)
		printf("%.6f\n",GivenVector[CurrentElement]);
}

/**END OF FILE.**/
