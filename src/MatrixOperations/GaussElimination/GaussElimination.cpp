#include "GaussElimination.h"

vector<double> GaussElimination(vector< vector<double> > A, vector<double> b)
{
	if(A.size()!=b.size())
	{
		printf("The equation cannot be solved as the order of the marices are not matched.\n");
		return b;
	}
	else
	{
		unsigned int n = b.size();/**The number of rows.**/
		vector<double> x(n,0),temp(n,0);/**Initializing the solution vector with zeroes.**/
		int i,j,k,M;/**'M' denotes the row having max value**/
		double m,sum=0.0;
		for(i=0;i<n-1;i++)
    	{
			M = i;
			for(k=i+1;k<n;k++)
			{
			    if(A[k][i] > A[M][i] )
				M =k;
			}
			temp[0] = b[M];
			b[M] = b[i];
			b[i] = temp[0];
			for(k=0;k<n;k++)
			{
			    temp[k] = A[M][k];
			    A[M][k] = A[i][k];
			    A[i][k] = temp[k];
			}

			/**Done Swapping the ith row and the row containing pivot**/
			for(j=n-1;j>=i+1;j--)
			{
			    m = A[j][i]/A[i][i];
			    /**Now beginning to update A matrix and the b vector**/
			    A[j][i] = 0;
			    b[j] = b[j] - m*b[i];
			    for(k=i+1;k<n;k++)
			    {
				A[j][k] =  A[j][k] - m*A[i][k];
			    }
			}
		}
		/**Now A is an Upper triangular matrix.**/
		x[n-1] = b[n-1]/A[n-1][n-1];
		for(i=n-2;i>=0;i--)
		{
		sum = 0.0;
		for(j=i+1;j<n;j++)
		{
		    sum = sum + A[i][j]*x[j];
		}
		x[i] = (b[i] - sum)/A[i][i];
		}
		return x;
	}
}
/**END OF THE FILE.**/
