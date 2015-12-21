/**
 * @file	LobattoWeights.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector<double> lobattoWeights(unsigned ). Its function would be to return the weights of the nth order Lobatto nodes.
 */

#include "LobattoWeights.h"

/**
 * @name		lobattoWeights
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned int n
 * This would denote the number of weights to be returned.
 *
 * Example usage
 * @code
 * 		vector<double> nodes = lobattoWeights(unsigned n);//Storing the roots of the nth degree Legendre roots.
 * 	@endcode
 */
vector<double> lobattoWeights(unsigned n)
{
	vector<double> Result;
	double weight;///This would store a particular weight corresponding to that particular root of the Legendre Polynomial.
	vector<double> Poly = legendrePoly(n-1);
	vector<double> Roots = lobattoNodes(n);
	function<double(double)> Eval; 
	Result.push_back(2.0/((n)*(n-1)));
	for(int i=1;i<n-1;i++)
	{	
		Eval = [&Poly](double x){ return(polyEval(Poly,x));};
		weight = 2/((n*(n-1))*(Eval(Roots[i]))*(Eval(Roots[i])));
		Result.push_back(weight);
	}
	Result.push_back(2.0/((n)*(n-1)));
	return Result;
}
