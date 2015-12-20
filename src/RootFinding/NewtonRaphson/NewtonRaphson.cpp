/**
 * @file	PolyEval.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function double polyEval( vector<double> Poly, double x), and would return the value of the given polynomial at the point 'x'. Note: This method is optimized as it uses the Horner's scheme of polynomial Evaluation, makin this method O(polydeg).
 */

#include "NewtonRaphson.h"

/**
 * @name		newtonRaphson
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	function<double(double)> func
 * The passing of the the function func whose root is to be found out.
 * @param[in]	function<double(double)> deriv
 * This would be the passing of the derivative of the function, whose roots is to be found out.
 * @param[in]	double x///This is the initial guess for the root.
 *
 * Example usage
 * @code
 * 		vector<double> derivedpoly = polyDeriv(GivenPoly);//Storing the coefficients of the nth degree Legendre Polynomial in the variable polyn
 * 	@endcode
 */
double newtonRaphson(function<double(double)> func, function<double(double)> deriv ,double x)
{
	double x_curr;
	double x_pre = x;///This is the storage of the initial guess and for developing the nice iterative struacture of the root.
	do
	{
		x_curr = x_pre - (func(x_pre))/(deriv(x_pre));	
	}while(abs(x_curr - x_pre) >= 1e-6);
	return x_curr ;
}

