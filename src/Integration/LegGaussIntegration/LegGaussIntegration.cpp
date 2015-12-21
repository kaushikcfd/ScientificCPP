/**
 * @file	LegendreGaussGaussIntegration.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function double legendreGaussIntegration(double start , double end, unsigned n, funtion<double(double)> ). The function would return the lobatto integral of the function from start to end.
 */

#include "LegGaussIntegration.h"

/**
 * @name		legendreGaussIntegration
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned int n
 * This would denote the number of roots to be returned.
 *
 * Example usage
 * @code
 * 		double integral = legendreGaussIntegration(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */
double legendreGaussIntegration(double start, double end, unsigned n, function<double(double)> f)
{
	n++;///Since for an n-degree polynomial we would need n+1 nodes.
	if(start>=end)
	{
		printf("ERROR: Please look into it there is some error in the given inputs for legendreGaussIntegration()\n");
		return 0.0;
	}
		
	vector<double> Roots = legendreGaussNodes(n);///This would be in the compuational domain. But still mapping it in the normal domain would be neccesary.
	vector<double> Weights = legendreGaussWeights(n);
	Roots = (0.5*(start+end))*ones(n) +  (0.5*(start-end))*Roots;///Made a shift from the computational space to the physical space.	
	vector<double> Values;///Vector to store the value of the function at the given nodes.
	unsigned i;///For the counter requirements of the for loop ahead.
	for(i=0;i<n;i++)
		Values.push_back(f(Roots[i]));

	double integral=0.0;
	for(i=0;i<n;i++)
	{
		integral = integral + Values[i]*Weights[i];
	}
	
	return integral;
}
