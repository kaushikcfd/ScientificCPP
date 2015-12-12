/**
 * This zeroes.h would generate the zeroes array for the initialization.
 * This should take in an argument for an array and make all the elements in it zero.
 * */
/**
 * VARIABLES USED:
 * std::vector<double> GivenVector: This actually is used as a function argument and has no end use. It is the part of the function void zeroes(vector<double> & )
 * int CurrentElement: This denotes the CurrentElement we are dealing in the vector we are dealling with.
 * int VecorLength: This denotes the length of the vector being dealt over here.
 * int m, n : denote the number of rows and columns.

 * FUNCTIONS USED/CREATED:
 * void zeroes(vector<double> & ): This is the main operating function of this file.
 * void zeros(vector< vector<double> > & GivenVector,int m, int n): This would be used for the intialization of an mxn matrix with all zeros. 

 **/

#include <vector>
#include <cstdio>
#ifndef _SCIENTIFICCPP_H
#define _SCIENTIFICCPP_H
#endif

using namespace std;

void zeros(vector<double> & GivenVector)
{
	int CurrentElement,VectorLength=GivenVector.size();
	for(CurrentElement = 0; CurrentElement < VectorLength; CurrentElement++)
		GivenVector[CurrentElement] = 0.0;
	printf("Success, VECTOR of size %d created with zeroes.\n",VectorLength);	
}

void zeros(vector<double> & GivenVector, unsigned int n)
{
	GivenVector.resize(n);
	printf("Success, VECTOR of size %d created with zeroes.\n",n);	
}

void zeros(vector< vector<double> > & GivenVector, unsigned int m, unsigned int n)
{
	int CurrentElement;
	GivenVector.resize(m);
	for(CurrentElement = 0; CurrentElement < m; CurrentElement++)
		GivenVector[CurrentElement].resize(n);
	printf("Success, MATRIX of size %d x %d  created with zeroes.\n",m,n);	
}



/**END OF THE FILE.**/
