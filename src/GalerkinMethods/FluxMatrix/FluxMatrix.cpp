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
