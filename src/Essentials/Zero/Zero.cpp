#include "Zero.h"


vector<double> zeros( unsigned int n )
{
	vector<double> ResultVector(n,0);
	//printf("Success, VECTOR of size %d created with zeroes.\n",n);	
	return ResultVector;
}

vector< vector<double> > zeros( unsigned int m, unsigned int n)
{
	int CurrentElement;
	vector< vector<double> > ResultVector;
	ResultVector.resize(m);
	for(CurrentElement = 0; CurrentElement < m; CurrentElement++)
		ResultVector[CurrentElement].resize(n);
	//printf("Success, MATRIX of size %d x %d  created with zeroes.\n",m,n);	
	return ResultVector;
}



/**END OF THE FILE.**/
