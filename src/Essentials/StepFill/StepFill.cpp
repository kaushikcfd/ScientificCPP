#include "StepFill.h"

vector<double> stepFill(double start, double stepSize, double end)
{
	if(((end-start)*stepSize) > 0)
	{
		vector<double> ResultVector;
		ResultVector.push_back(start);
        double lastElement=start;
		while(((lastElement+stepSize)-end) <= 1e-10)
		{
			ResultVector.push_back(lastElement+stepSize);
            lastElement+=stepSize;
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
