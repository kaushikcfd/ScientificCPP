/**
 * @file	AdvectionMatrix.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector< vector<double> > fluxMatrix(vector<double> ). The function would return the flux matrix for the corresponding nodes.
 */

#include "AdvectionMatrix.h"

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


vector< vector < vector <double> > > XadvectionMatrix(unsigned N)
{
    unsigned i1,j1,i2,j2,i3,j3;
    unsigned n = (N+1)*(N+1);
    vector < vector< vector <double> > > A;vector< vector<double> > Z = zeros(n,n);
    for(i1=0;i1<n;i1++)
        A.push_back(Z);
    

    function<double(double)> eval1,eval2;
    vector<double> Nodes = lobattoNodes(N+1);///Again N+1 nodes as N+1 nodes would give us a polynomial of degree N.
    vector < vector<double> > LagrangePolynomials = lagrangePolynomials(Nodes);
    for(i1=0;i1<=N;i1++)
        for(j1=0;j1<=N;j1++)
            for(i2=0;i2<=N;i2++)
                for(j2=0;j2<=N;j2++)
                    for(i3=0;i3<=N;i3++)
                        for(j3=0;j3<=N;j3++)
                        {
                            eval1 = [&LagrangePolynomials,&i1,&i2,&i3](double x){return (polyEval(LagrangePolynomials[i1],x)*polyEval(LagrangePolynomials[i3],x)*polyEval(polyDeriv(LagrangePolynomials[i2]),x));};
                            eval2 = [&LagrangePolynomials,&j1,&j2,&j3](double y){return (polyEval(LagrangePolynomials[j1],y)*polyEval(LagrangePolynomials[j2],y)*polyEval(LagrangePolynomials[j3],y));};

                            A[i1*(N+1)+j1][i2*(N+1)+j2][i3*(N+1)+j3]=lobattoIntegration(-1,+1,2*N,eval1)*lobattoIntegration(-1,+1,2*N,eval2);
                        }

    return A;
}



vector< vector < vector <double> > > YadvectionMatrix(unsigned N)
{
    unsigned i1,j1,i2,j2,i3,j3;
    unsigned n = (N+1)*(N+1);
    vector < vector< vector <double> > > A;vector< vector<double> > Z = zeros(n,n);
    for(i1=0;i1<n;i1++)
        A.push_back(Z);
    

    function<double(double)> eval1,eval2;
    vector<double> Nodes = lobattoNodes(N+1);///Again N+1 nodes as N+1 nodes would give us a polynomial of degree N.
    vector < vector<double> > LagrangePolynomials = lagrangePolynomials(Nodes);
    for(i1=0;i1<=N;i1++)
        for(j1=0;j1<=N;j1++)
            for(i2=0;i2<=N;i2++)
                for(j2=0;j2<=N;j2++)
                    for(i3=0;i3<=N;i3++)
                        for(j3=0;j3<=N;j3++)
                        {
                            eval1 = [&LagrangePolynomials,&i1,&i2,&i3](double x){return (polyEval(LagrangePolynomials[i1],x)*polyEval(LagrangePolynomials[i3],x)*polyEval(LagrangePolynomials[i2],x));};
                            eval2 = [&LagrangePolynomials,&j1,&j2,&j3](double y){return (polyEval(LagrangePolynomials[j1],y)*polyEval(LagrangePolynomials[j3],y)*polyEval(polyDeriv(LagrangePolynomials[j2]),y));};

                            A[i1*(N+1)+j1][i2*(N+1)+j2][i3*(N+1)+j3]=lobattoIntegration(-1,+1,2*N,eval1)*lobattoIntegration(-1,+1,2*N,eval2);
                        }

    return A;
}


vector< vector<double> > advectionMatrix(unsigned N, vector < vector < double > > U, vector < vector <double> > V)///This U would be the the value of the velocity at the lobatto nodes in the compuational grid. And similrly we have the V matrix which would again give us the y-component of the velocity at the lobatto grid.
{
    vector <double> Nodes = lobattoNodes(N+1);///N+1, as for getting a polynomial of degree N we need N+1 points.
    unsigned n = (N+1)*(N+1);///This would be the order of the advection square matix, since it is a matrix of order (N+1)*(N+1).
    vector< vector < double > > A = zeros(n,n);
    unsigned i1,i2,j1,j2,k;
    
    vector < vector< vector<double> > > XAdvMatrix = XadvectionMatrix(N),YAdvMatrix = YadvectionMatrix(N); 
    for(i1=0;i1<=N;i1++)
        for(j1=0;j1<=N;j1++)
            for(i2=0;i2<=N;i2++)
                for(j2=0;j2<=N;j2++)
                {
                    for(k=0;k<n;k++)
                        A[i1*(N+1)+j1][i2*(N+1)+j2] += (V[k/(N+1)][k%(N+1)]*XAdvMatrix[i1*(N+1)+j1][i2*(N+1)+j2][k]+U[k/(N+1)][k%(N+1)]*YAdvMatrix[i1*(N+1)+j1][i2*(N+1)+j2][k]);
                }
    return A;   
}
/**

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
}*/
