/**
 * @file	DerivativeMatrix.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector< vector<double> > derivativeMatrix(vector<double> ). The function would return the derivative matrix (in the strong form) for the corresponding nodes.
 */

#include "DerivativeMatrix.h"

/**
 * @name		derivativeMatrix
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector<double> Points
 * This would denote the inteprolating points for which the Lagrange polynomials have to be written.
 *
 * Example usage
 * @code
 * 		double integral = lobattoIntegration(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */
vector< vector<double> > derivativeMatrix(vector<double> Points)
{
	unsigned n = Points.size();
	sort(Points.begin(),Points.end());
	double start = Points[0];///The first element.
	double end = Points[n-1];///The last element.
	vector< vector<double> > DerivativeMatrix;
	DerivativeMatrix=zeros(n,n);
	vector< vector<double> > LagrangePolynomials = lagrangePolynomials(Points);
	unsigned i,j;///Counters for the loop.
	function<double(double)> eval;
	for(i=0;i<n;i++)
	{

		for(j=0;j<n;j++)
		{
			eval = [&LagrangePolynomials,&i,&j](double x){  return ((polyEval(LagrangePolynomials[i],x)*polyEval(polyDeriv(LagrangePolynomials[j]),x)));};
			DerivativeMatrix[i][j] = lobattoIntegration(start,end,n,eval);
		}
	}
	return DerivativeMatrix;
}

vector< vector<double> > twoDDerivativeMatrixX(unsigned N)///Note the syntax is very much different from the 1-D one as taking the computational grid as an input would be a very hefty task.
{
    vector< vector< double > > DerivativeMatrix;
    vector <double> Nodes = lobattoNodes(N+1);///N+1 as the N+1 nodes will give me a polynomial of degree 'N'.
    vector < vector < double > > D = derivativeMatrix(Nodes);
	vector < vector < double > > M = massMatrix(Nodes);

	unsigned i1,i2,j1,j2;///These would be the counter for the loops.


    DerivativeMatrix = zeros((N+1)*(N+1),(N+1)*(N+1));

    for(i1=0;i1<=N;i1++)
        for(j1=0;j1<=N;j1++)
            for(i2=0;i2<=N;i2++)
                for(j2=0;j2<=N;j2++)
                    DerivativeMatrix[i1*(N+1)+j1][i2*(N+1)+j2] = M[i1][i2]*D[j1][j2];


    return DerivativeMatrix;
}

vector< vector<double> > twoDDerivativeMatrixY(unsigned N)///Note the syntax is very much different from the 1-D one as taking the computational grid as an input would be a very hefty task.
{
    vector< vector< double > > DerivativeMatrix;
    vector <double> Nodes = lobattoNodes(N+1);///N+1 as the N+1 nodes will give me a polynomial of degree 'N'.
    vector < vector < double > > D = derivativeMatrix(Nodes);
	vector < vector < double > > M = massMatrix(Nodes);

	unsigned i1,i2,j1,j2;///These would be the counter for the loops.


    DerivativeMatrix = zeros((N+1)*(N+1),(N+1)*(N+1));

    for(i1=0;i1<=N;i1++)
        for(j1=0;j1<=N;j1++)
            for(i2=0;i2<=N;i2++)
                for(j2=0;j2<=N;j2++)
                    DerivativeMatrix[i1*(N+1)+j1][i2*(N+1)+j2] = D[i1][i2]*M[j1][j2];


    return DerivativeMatrix;
}
