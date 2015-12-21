/**
 * @file	LegendreGaussWeights.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector<double> legendreGauss(unsigned ). Its function would be to return the weights of the nth degree Legendree Polynomial.
 */

#include "LegendreGaussWeights.h"

/**
 * @name		legendreGaussWeights
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned int n
 * This would denote the number of roots to be returned.
 *
 * Example usage
 * @code
 * 		vector<double> nodes = legendreGauss(unsigned n);//Storing the roots of the nth degree Legendre roots.
 * 	@endcode
 */
vector<double> legendreGaussWeights(unsigned n)
{
	vector<double> Result;
	double weight;///This would store a particular weight corresponding to that particular root of the Legendre Polynomial.
	vector<double> Poly = legendrePoly(n);
	vector<double> Roots = legendreGaussNodes(n);
	function<double(double)> derivEval; 
	for(int i=0;i<n;i++)
	{	
		derivEval = [&Poly](double x){ return(polyEval(polyDeriv(Poly),x));};
		weight = 2/((1-Roots[i]*Roots[i])*(derivEval(Roots[i]))*(derivEval(Roots[i])));
		Result.push_back(weight);
	}
	return Result;
}
