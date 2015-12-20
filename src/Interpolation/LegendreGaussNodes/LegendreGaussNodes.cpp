/**
 * @file	PolyEval.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector<double> legendreGauss(unsigned ). Its function would be to return the roots of the nth degree Legendree Polynomial. I am going to use Newton Raphson method for finding the root.
 */

#include "LegendreGaussNodes.h"

/**
 * @name		legendreGauss
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned int n
 * This would denote the number of roots to be returned.
 *
 * Example usage
 * @code
 * 		vector<double> nodes = legendreGauss(unsigned n);//Storing the roots of the nth degree Legendre roots.
 * 	@endcode
 */
vector<double> legendreGaussNodes(unsigned n)
{
	vector<double> Result;
	double root;///This would store a particular root of the Legendre Polynomial.
	double InitialGuess=1.0;
	unsigned deg;///To store the degree at each state of the polynomial. 
	vector<double> Poly = legendrePoly(n);
	function<double(double)> eval; 
	for(int i=1;i<=n;i++)
	{
		deg = Poly.size()-1;	
		eval = [&Poly](double x){ return(polyEval(Poly,x));};
		root = newtonRaphson(eval,InitialGuess);
		Poly = synthDiv(Poly,root);
		Result.push_back(root);
	}
	return Result;
}
