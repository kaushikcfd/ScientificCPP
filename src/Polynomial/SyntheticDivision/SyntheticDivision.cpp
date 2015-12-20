/**
 * @file	SyntheticDivision.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector<double> synthDiv( vector<double> Poly, double x), and would return the quotient polynomial for the root 'x'.
 */

#include "SyntheticDivision.h"

/**
 * @name		synthDiv
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector<double> Poly
 * @param[in]	double x
 *
 * Example usage
 * @code
 * 		vector<double> quoPoly = polyEval(GivenPoly,x);///This would return the quotient polynomial for the root 'x'
 * @endcode
 */
vector<double> synthDiv(vector<double> GivenPoly, double root)
{
	int deg = GivenPoly.size()-1;///This variable stores the polynomial degree.
	vector<double> Result(deg,0);
	Result[deg-1] = GivenPoly[deg];
	for(int i = deg-2;i>=0;i--)
	{
		Result[i] = Result[i+1]*root + GivenPoly[i+1]; 		
	}
	return Result ;
}
