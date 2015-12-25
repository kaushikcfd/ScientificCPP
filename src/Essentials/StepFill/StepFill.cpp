#include "StepFill.h"

vector<double> stepFill(double start, double stepSize, double end)
{
	if(((end-start)*stepSize) > 0)
	{
		int CurrentElement;
		vector<double> ResultVector;
		ResultVector.push_back(start);
		for(CurrentElement = 0; ResultVector[CurrentElement] <= end; CurrentElement++)
		{
			if((ResultVector[CurrentElement]+stepSize)<=end)
				ResultVector.push_back(ResultVector[CurrentElement]+stepSize);
			else
				break;
		}
		//printf("Success, VECTOR of size %ld created with stepSize %.6f.\n",ResultVector.size(),stepSize);	
		return ResultVector;
	}
	else
	{
		printf("Please check the given conditions the array will turn into an unending data structure!!!\n");
		vector<double> ResultVector;
		return ResultVector;
	}
}
	/**END OF THE FILE.**/
