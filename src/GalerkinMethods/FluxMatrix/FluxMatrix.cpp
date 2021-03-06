/**
 * @file	FluxMatrix.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector< vector<double> > fluxMatrix(vector<double> ). The function would return the flux matrix for the corresponding nodes.
 */

#include "FluxMatrix.h"

/**
 * @name		fluxMatrix
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector<double> Points
 * This would denote the inteprolating points for which the Lagrange polynomials have to be written.
 *
 * Example usage
 * @code
 * 		double integral = lobattoIntegration(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */
vector< vector<double> > fluxMatrix(vector<double> Points)
{
	unsigned n = Points.size();
	sort(Points.begin(),Points.end());
	double start = Points[0];///The first element.
	double end = Points[n-1];///The last element.
	vector< vector<double> > FluxMatrix;
	FluxMatrix=zeros(n,n);
	vector< vector<double> > LagrangePolynomials = lagrangePolynomials(Points);
	unsigned i,j;///Counters for the loop.
	function<double(double)> eval;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			eval = [&LagrangePolynomials,&i,&j](double x){  return ((polyEval(LagrangePolynomials[i],x)*polyEval(LagrangePolynomials[j],x)));};
			FluxMatrix[i][j] =( eval(end)-eval(start) );
		}
	}

	return FluxMatrix;
}

vector< vector<double> > twoDFluxMatrix1(unsigned N)///Note the syntax is very much different from the 1-D one as taking the computational grid as an input would be a very hefty task.
{
    vector< vector< double > > FluxMatrix;
    vector <double> Nodes = lobattoNodes(N+1);///N+1 as the N+1 nodes will give me a polynomial of degree 'N'.
    vector < vector < double > > F = fluxMatrix(Nodes);
	vector < vector < double > > M = massMatrix(Nodes);
    unsigned i1,i2,j1,j2;///These would be the counter for the loops.


    FluxMatrix = zeros((N+1)*(N+1),(N+1)*(N+1));

	i1=i2=0;
        for(j1=0;j1<=N;j1++)
                for(j2=0;j2<=N;j2++)
                    FluxMatrix[i1*(N+1)+j1][i2*(N+1)+j2] = F[i1][i2]*M[j1][j2];

    return FluxMatrix;
}

vector< vector<double> > twoDFluxMatrix2(unsigned N)///Note the syntax is very much different from the 1-D one as taking the computational grid as an input would be a very hefty task.
{
    vector< vector< double > > FluxMatrix;
    vector <double> Nodes = lobattoNodes(N+1);///N+1 as the N+1 nodes will give me a polynomial of degree 'N'.
    vector < vector < double > > F = fluxMatrix(Nodes);
	vector < vector < double > > M = massMatrix(Nodes);
    unsigned i1,i2,j1,j2;///These would be the counter for the loops.


    FluxMatrix = zeros((N+1)*(N+1),(N+1)*(N+1));

	j1=j2=N;
        for(i1=0;i1<=N;i1++)
                for(i2=0;i2<=N;i2++)
                    FluxMatrix[i1*(N+1)+j1][i2*(N+1)+j2] = M[i1][i2]*F[j1][j2];

    return FluxMatrix;
}


vector< vector<double> > twoDFluxMatrix3(unsigned N)///Note the syntax is very much different from the 1-D one as taking the computational grid as an input would be a very hefty task.
{
    vector< vector< double > > FluxMatrix;
    vector <double> Nodes = lobattoNodes(N+1);///N+1 as the N+1 nodes will give me a polynomial of degree 'N'.
    vector < vector < double > > F = fluxMatrix(Nodes);
	vector < vector < double > > M = massMatrix(Nodes);
    unsigned i1,i2,j1,j2;///These would be the counter for the loops.


    FluxMatrix = zeros((N+1)*(N+1),(N+1)*(N+1));

	i1=i2=N;
        for(j1=0;j1<=N;j1++)
                for(j2=0;j2<=N;j2++)
                    FluxMatrix[i1*(N+1)+j1][i2*(N+1)+j2] = F[i1][i2]*M[j1][j2];

    return FluxMatrix;
}

vector< vector<double> > twoDFluxMatrix4(unsigned N)///Note the syntax is very much different from the 1-D one as taking the computational grid as an input would be a very hefty task.
{
    vector< vector< double > > FluxMatrix;
    vector <double> Nodes = lobattoNodes(N+1);///N+1 as the N+1 nodes will give me a polynomial of degree 'N'.
    vector < vector < double > > F = fluxMatrix(Nodes);
	vector < vector < double > > M = massMatrix(Nodes);
    unsigned i1,i2,j1,j2;///These would be the counter for the loops.


    FluxMatrix = zeros((N+1)*(N+1),(N+1)*(N+1));

	j1=j2=0;
        for(i1=0;i1<=N;i1++)
                for(i2=0;i2<=N;i2++)
                    FluxMatrix[i1*(N+1)+j1][i2*(N+1)+j2] = M[i1][i2]*F[j1][j2];

    return FluxMatrix;
}
