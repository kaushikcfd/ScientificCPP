#include "One.h"


vector<double> ones( unsigned int n )
{
	vector<double> ResultVector(n,1);
	printf("Success, VECTOR of size %d created with ones.\n",n);	
	return ResultVector;
}

vector< vector<double> > ones( unsigned int m, unsigned int n)
{
	int CurrentElement;
	vector< vector<double> > ResultVector;
	ResultVector.resize(m);
	for(CurrentElement = 0; CurrentElement < m; CurrentElement++)
		ResultVector[CurrentElement] = vector<double>(n,1);
	printf("Success, MATRIX of size %d x %d  created with ones.\n",m,n);	
	return ResultVector;
}



/**END OF THE FILE.**/
