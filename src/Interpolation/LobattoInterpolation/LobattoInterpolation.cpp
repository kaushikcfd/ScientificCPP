/**
 * @file	LobattoGaussInterpolation.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector<double> lobattoInterpolation(double start , double end, unsigned n, funtion<double(double)> ). The function would return the coefficients to the polynomial of the interpolating polynomial.
 */

#include "LobattoInterpolation.h"

/**
 * @name		lobattoInterpolation
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned int n
 * This would denote the number of roots to be returned.
 *
 * Example usage
 * @code
 * 		vector<double> coeffs = lobattoInterpolation(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */
vector<double> lobattoInterpolation(double start, double end, unsigned n, function<double(double)> f)
{
	n++;///Since for an n-degree polynomial we would need n+1 nodes.
	if(start>=end)
	{
		printf("ERROR: Please look into it there is some error in the given inputs for legendreGaussInterpolation()\n");
		return ones(n);
	}
		
	vector<double> Roots = lobattoNodes(n);///This would be in the compuational domain. But still mapping it in the normal domain would be neccesary.
	Roots = (0.5*(start+end))*ones(n) +  (0.5*(start-end))*Roots;///Made a shift from the computational space to the physical space.	
	vector<double> Values;///Vector to store the value of the function at the given nodes.
	unsigned i,j;///For the counter requirements of the for loop ahead.
	for(i=0;i<n;i++)
		Values.push_back(f(Roots[i]));

	vector<double> Coeffs;///For storing the coefficients of the polynomial.
	vector<vector<double> >V;///For creating the VanderMonde Matrix. 
	V=zeros(n,n);
	for(i=0;i<n;i++)
	{
	
		V[i][0] = 1;
		for(j=1;j<n;j++)
		{
			V[i][j] = V[i][j-1]*Roots[i];
		}
	}
	Coeffs = GaussElimination(V,Values);
	return Coeffs;
}
