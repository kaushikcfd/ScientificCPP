/**
 * @file	LobattoNodes.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector<double> lobattoNodes(unsigned ). Its function would be to return the roots of the nth Lobatto nodes which happen to be the roots of derivative of Legendre polynomial of n-1 degree , hence we would get n-2 points from here and the other two denote the end points precisely -1 and +1. I am going to use Newton Raphson method for finding the root.
 */

#include "LobattoNodes.h"

/**
 * @name		lobattoNodes
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned int n
 * This would denote the number of roots to be returned.
 *
 * Example usage
 * @code
 * 		vector<double> nodes = lobattoNodes(unsigned n);//Storing the roots of the nth degree Legendre roots.
 * 	@endcode
 */
vector<double> lobattoNodes(unsigned n)
{
	vector<double> Result;
	double root;///This would store a particular root of the Legendre Polynomial.
	double InitialGuess=1.0;
	unsigned deg;///To store the degree at each state of the polynomial. 
	vector<double> Poly = polyDeriv(legendrePoly(n-1));
	function<double(double)> eval;
	Result.push_back(1);
	for(int i=1;i<=n-2;i++)
	{
		deg = Poly.size()-1;	
		eval = [&Poly](double x){ return(polyEval(Poly,x));};
		root = newtonRaphson(eval,InitialGuess);
		Poly = synthDiv(Poly,root);
		Result.push_back(root);
	}
	Result.push_back(-1);
	sort(Result.begin(),Result.end());
	return Result;
}
