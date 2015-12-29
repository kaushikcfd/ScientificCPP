/**
 * @file	RusanovFluxDGDSS.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is the file which contains the definition of the function rusanovFluxDGDSS(unsigned Ne, unsigned N,  double Lmax). Here Ne denoted the number of elements and N denotes the order of polynomial in each of the element, hence telling us that the total number of grid points = N*Ne + 1. By default this function would try to solve a problem with periodic boundary condition but once the user has the `` M`` matrix it should not at all be tough to change it according to the given boundary condition. By default the program uses Lobatto Nodes. but can easily be changed in the function to make it give different for different types of GridPoints.
 * */

#include "RusanovFluxDGDSS.h"

/**
 * @name		rusanovFluxDGDSS
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned Ne
 * This would denote the number of elements in the given problem.
 *
 * @param[in]	unsigned N
 * This would denote the order of the polynomial used for interpolating in each element.
 *
 * @param[in]	unsigned Ne
 * This would denote the number of elements in which the domain is divided into.
 *
 * Example usage
 * @code
 * 		double integral = lobattoIntegration(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */

vector< vector<double> > rusanovFluxDGDSS(unsigned Ne, unsigned N) 
{

	vector< vector<double> > f;///This would denote the temporary mass matrix involved in each element.

	unsigned Np= Ne*N + Ne;///This would denote the number of gridpoints present.
	unsigned i;///Counter for the loop.
	unsigned j,k;///Denotes which of the node is going to be affected 
	f = zeros(Np,Np);

	f[0][Np-1]=1;
	f[N][N] = 1;
	for(i=1;i<Ne;i++)
	{
		j = (N+1)*i + 0;
		k = (N+1)*i + N;
		f[j][j-1] = 1;
		f[k][k]   = 1;
	}

	return f;
}
