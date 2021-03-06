/**
 * @file	DerivativeCGDSS.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is the file which contains the definition of the function equiDerivativeDSS(unsigned Ne, unsigned N). Here Ne denoted the number of elements and N denotes the order of polynomial in each of the element, hence telling us that the total number of grid points = N*Ne + 1. By default this function would try to solve a problem with periodic boundary condition but once the user has the `` D`` derivative matrix it should not at all be tough to change it according to the given boundary condition. By default the program uses Lobatto Nodes. but can easily be changed in the function to make it give different for different types of GridPoints.
 * */

#include "DerivativeCGDSS.h"

/**
 * @name		derivativeCGDSS
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned Ne
 * This would denote the number of elements in the given problem.
 *
 * @param[in]	unsigned N
 * This would denote the order of the polynomial used for interpolating in each element.
 *
 * Example usage
 * @code
 * 		double integral = lobattoIntegration(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */

vector< vector<double> > derivativeCGDSS(unsigned Ne, unsigned N)
{
	vector< vector<double> > D;///This would be the total summed up derivative matrix.
	vector< vector<double> > d;///This would denote the temporary derivative matrix involved in each element.
	vector<double> points;///This would denote the temporary points in each of the element.
	unsigned Np= Ne*N + 1;///This would denote the number of gridpoints present.
	unsigned i;///Counter for the loop.
	unsigned j,k;///Denotes which of the node is going to be affected 
	D = zeros(Np,Np);
	points  = lobattoNodes(N+1);///N+1 because Using N+1 nodes we can construct N degree polynomial.
	d = derivativeMatrix(points);
	for(i=0;i<Ne;i++)
	{
		for(j=0;j<=N;j++)
		{
			for(k=0;k<=N;k++)
				D[j+i*N][k+i*N] = D[j + i*N][k+i*N] + d[j][k];
		}
	}
	
	i = N*Ne-1;
	for(j=0;j<N;j++)
	{
		D[i][0]+=D[i][Ne*N];
		D[i][Ne*N]=0;
		D[0][i]+=D[Ne*N][i];
		D[Ne*N][i]=0;
		i--;
	}
	D[0][0]+=D[Ne*N][Ne*N];
	D[Ne*N][Ne*N]=0;


	return D;
}
