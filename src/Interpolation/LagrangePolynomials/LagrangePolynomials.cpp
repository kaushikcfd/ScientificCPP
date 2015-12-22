/**
 * @file	LagrangePolynomials.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector< vector<double> > lagrangePolynomial(vector<double> ). The function would return the coefficients to the polynomials of the interpolating polynomial in a matrix form where the fist vector would denote the coefficients of the L0 polynomial.. and so on.
 */

#include "LagrangePolynomials.h"

/**
 * @name		lagrangePolynomials
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector<double> Points
 * These would be the interpolating points of the function.
 *
 * Example usage
 * @code
 * 		vector<double> points;///These would be the points at which we need the polynomials to be interpolated.
 * 		vector<double> coeffs = lobattoInterpolation(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */
vector< vector<double> > lagrangePolynomials(vector<double> Points)
{
	vector< vector<double> > Result;
	vector<double> currentPolynomial;///For storing the current polynomial, which will be again pushed to the main result.
	vector<double> Values;///Values for the current polynomial.
	vector <vector<double> > V;///This would be the VanderMonde matrix.

	unsigned n = Points.size();///The number of points, hence the degree of the polynomials would be  would be n-1, and there would be n-polynomials.
	unsigned i,j;///Counters for the loop.
	V = zeros(n,n);
	for (i=0;i<n;i++)
	{
		V[i][0] = 1; 
		for(j=1;j<n;j++)
		{
			V[i][j] = Points[i]*V[i][j-1];
		}
	}
	for(i=0;i<n;i++)///Loop for repeating n-times, for each of the polynomial.
	{
		Values = zeros(n);
		Values[i] = 1;
		currentPolynomial = GaussElimination(V,Values);
		Result.push_back(currentPolynomial);	
	}
	return Result;
}
