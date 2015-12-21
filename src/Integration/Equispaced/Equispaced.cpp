#include "Equispaced.h"

vector<double> equiInterpolation(double start, double end, unsigned int N, function<double(double)> f)
{
	if( (end>start) )
	{
		vector<double> Y;///To the function f at the equispaced nodes.
		int i,j;/**Loop variables for creating the VanderMonde Matrix. **/
		vector<double> X(N,0),A(N,0),b(N,0);
		vector< vector<double> > V;
		V = zeros(N,N);
		double h = (end-start)/(N-1);
		X = stepFill(start,h,end);
		for(i=0;i<N;i++)
			Y.push_back(f(X[i]));
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
		return zeros(N);
	}
}



/**END OF THE FILE.**/
