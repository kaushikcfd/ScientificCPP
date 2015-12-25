#include "ArrayDisplay.h"

void display(vector<double>  GivenVector)
{
	int CurrentElement, VectorLength = GivenVector.size();
	for(CurrentElement=0; CurrentElement< VectorLength; CurrentElement++)
		printf("%.6f\n",GivenVector[CurrentElement]);
}

void display(vector< vector<double> > GivenMatrix)
{
	unsigned i,j;
	unsigned m = GivenMatrix.size(),n;
	for(i=0;i<m;i++)
	{
		n= GivenMatrix[i].size();
		for(j=0;j<n;j++)
			printf("%.6f  ",GivenMatrix[i][j]);
		printf("\n");
	}
}


void sparseDisplay(vector< vector<double> > GivenMatrix)
{
	unsigned i,j;
	unsigned m = GivenMatrix.size(),n;
	for(i=0;i<m;i++)
	{
		n= GivenMatrix[i].size();
		for(j=0;j<n;j++)
		{
			if(abs(GivenMatrix[i][j])<=1e-4)
				printf("   ");
			else
				printf("*  ");
		}
		printf("\n");
	}
}


/**END OF FILE.**/
