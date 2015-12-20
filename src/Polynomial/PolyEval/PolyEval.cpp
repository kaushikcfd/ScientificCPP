/**
 * @file	PolyEval.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function double polyEval( vector<double> Poly, double x), and would return the value of the given polynomial at the point 'x'. Note: This method is optimized as it uses the Horner's scheme of polynomial Evaluation, makin this method O(polydeg).
 */

#include "PolyEval.h"

/**
 * @name		polyEval
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector<double> Poly
 * @param[in]	double x
 *
 * Example usage
 * @code
 * 		f_x = polyEval(GivenPoly,x);///This would return the value of the polynomial at the point 'x'
 * @endcode
 */
double polyEval(vector<double> GivenPoly, double x)
{
	int deg = GivenPoly.size()-1;///This variable stores the polynomial degree
	double Result = GivenPoly[deg];
	for(int i = deg-1;i>=0;i--)
		Result = Result*x+GivenPoly[i];
	return Result ;
}
