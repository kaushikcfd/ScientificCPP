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

vector<double> equiInterpolation(double start, double end, unsigned int N, const vector<double>& Y)
{
	if( (end>start) && (Y.size()==N) )
	{
		int i,j;/**Loop variables for creating the VanderMonde Matrix. **/
		vector<double> X(N,0),A(N,0),b(N,0);
		vector< vector<double> > V;
		zeros(V,N,N);
		double h = (end-start)/(N-1);
		stepFill(X,start,h,end);
		for(i=0;i<N;i++)
		{
			V[i][0] = 1;
			for(j=1;j<N;j++)
			{
				V[i][j] = V[i][j-1]*X[i];
			}
			b[i] = Y[i];
		}
		A = GaussElimination(V,b); 
		/**Now the VanderMonde matrix has been created..**/
		printf("The given function has been interpolated with a polynomial of degree %d and the coefficients have been returned.\n",(N-1));
		return A;
	}
	else
	{
		printf("There is some error in the given input please check them.\n");
		return Y;
	}


}



/**END OF THE FILE.**/
