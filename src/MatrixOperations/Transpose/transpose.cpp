#include "transpose.h"

vector < vector<double> > transpose(vector< vector<double> > GivenMatrix)
{
	vector< vector<double> > ResultMatrix;
	unsigned i,j,m=GivenMatrix.size(),n=GivenMatrix[0].size();
	ResultMatrix = zeros(n,m);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			ResultMatrix[j][i] = GivenMatrix[i][j];
	}
	return ResultMatrix;
}
