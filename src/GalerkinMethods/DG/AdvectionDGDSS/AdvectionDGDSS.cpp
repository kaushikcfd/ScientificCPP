/**
 * @file	massDGDSS.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is the file which contains the definition of the function massDGDSS(unsigned Ne, unsigned N). Here Ne denoted the number of elements and N denotes the order of polynomial in each of the element, hence telling us that the total number of grid points = N*Ne + 1. By default this function would try to solve a problem with periodic boundary condition but once the user has the `` M`` matrix it should not at all be tough to change it according to the given boundary condition. By default the program uses Lobatto Nodes. but can easily be changed in the function to make it give different for different types of GridPoints.
 * */

#include "AdvectionDGDSS.h"

/**
 * @name		massDGDSS
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


vector< vector<double> > advectionDGDSS(unsigned Nex, unsigned Ney, unsigned N, double  U, double V)/**This is a very trivial case that is the velocity is totally constant throughout the domain which may not be the case, but can be easily modified since the computational grid is capable of taking those changes.*/
{
	vector< vector<double> > A;///This would be the total summed up mass matrix.
	vector< vector<double> > m;///This would denote the temporary mass matrix involved in each element.
	unsigned Np= (N+1)*(N+1)*Nex*Ney;///This would denote the number of gridpoints present.
	unsigned i;///Counter for the loop.
	unsigned j,k,l=0;///Denotes which of the node is going to be affected 
	A = zeros(Np,Np);
	vector < vector<double> > u,v,a;///These would give me the local/ computational velocities, in the computational grid.
    u = U*ones(N+1,N+1);
    v = V*ones(N+1,N+1);
    a = advectionMatrix(N,u,v);
    for(i=0;i<Ney;i++)
	{
		for(j=0;j<Nex;j++)
		{
			for(k=0;k<((N+1)*(N+1));k++)
                for(l=0;l<((N+1)*(N+1));l++)
				    A[(j+i*Nex)*(N+1)*(N+1)+k][(j+i*Nex)*(N+1)*(N+1)+l] = a[k][l];
		}
	}

	return A;
}

