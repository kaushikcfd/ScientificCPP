/**
 * @file	Inverse.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector< vector<double> > inverse(vector< vector<double> > ). The function would return the inverse of the given matrix.
 */

#include "Inverse.h"

/**
 * @name		inverse
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector< vector<double> > GivenMatrix
 *
 * Example usage
 * @code
 * 		vector< vector<double> > InversedMatrix = inverse(GivenMatrix);///Finding the inverse of the Given Matrix.
 * @endcode
 */
vector< vector<double> > inverse(vector< vector<double> > GivenMatrix )
{
	vector< vector<double> > Inverse = GivenMatrix;
	unsigned n = GivenMatrix.size(),i,j;
	vector<double> b;///This would store the temporary column vector of the 'I' matrix.
	vector<double> I;///This would be the temporary column vector of the inverses matrix.
	if(GivenMatrix[0].size()!=n)
	{
		printf("ERROR: The matrix given to be inversed is not a square matrix.\n");
		return Inverse;
	}

	for(i=0;i<n;i++)
	{

		b  = zeros(n);
		b[i] = 1;
		I = GaussElimination(GivenMatrix,b);
		for(j=0;j<n;j++)
			Inverse[j][i] = I[j];

	}

	return Inverse;
}
