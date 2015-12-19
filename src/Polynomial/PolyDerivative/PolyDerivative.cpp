/**
 * @file	PolyDerivative.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector<double> polyDeriv( vector<double> ), and would return a vector cotaining the coefficients of the differentiated polynomial.
 */

#include "PolyDerivative.h"

/**
 * @name		polyDeriv
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector<double> Poly
 *
 * Example usage
 * @code
 * 		vector<double> derivedpoly = polyDeriv(GivenPoly);//Storing the coefficients of the nth degree Legendre Polynomial in the variable polyn
 * 	@endcode
 */
vector<double> polyDeriv(vector<double> GivenPoly)
{
	vector<double> DerivedPoly;
	for(int i = 1;i<GivenPoly.size();i++)
		DerivedPoly.push_back( i*GivenPoly[i] );
	return DerivedPoly;
}
