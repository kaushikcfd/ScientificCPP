#include "ArrayDisplay.h"

void display(vector<double>  GivenVector)
{
	int CurrentElement, VectorLength = GivenVector.size();
	for(CurrentElement=0; CurrentElement< VectorLength; CurrentElement++)
		printf("%.6f\n",GivenVector[CurrentElement]);
}

/**END OF FILE.**/
