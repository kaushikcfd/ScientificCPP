#include "ScientificCPP.h"

int main()
{
	vector<double> b(4,0),x(4,0);
	vector<vector<double> > A(4);
	A[0].resize(4);
	A[1].resize(4);
	A[2].resize(4);
	A[3].resize(4);
	
	A[0][0] = 5;
	
	A[0][1] = 7;
	A[0][2] = 6;
	A[0][3] = 5;
	A[1][0] = 7;
	A[1][1] =10;
	A[1][2] = 8;
	A[1][3] = 7;
	A[2][0] = 6;
	A[2][1] = 8;
	A[2][2] =10;
	A[2][3] = 9;
	A[3][0] = 5;
	A[3][1] = 7;
	A[3][2] = 9;
	A[3][3] =10;
		
	b[0] =  1;
	b[1] = -1;
	b[2] = -1;
	b[3] =  1;

	x=GaussElimination(A, b);
	display(x);
}
