/**
 * @file	EquiCoords.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is the file which contains the definition of the function equiCoords(double start, double end, unsigned Ne, unsigned N). Here Ne denoted the number of elements and N denotes the order of polynomial in each of the element, hence telling us that the total number of grid points = N*Ne + 1. By default this function would try to make the vector containing the points into which the total grid is divided. By default the program uses Lobatto Nodes. but can easily be changed in the function to make it give different for different types of GridPoints.
 * */

#include "EquiCoords.h"

/**
 * @name		equiCoords
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned Ne
 * This would denote the number of elements in the given problem.
 *
 * @param[in]	unsigned N
 * This would denote the order of the polynomial used for interpolating in each element.
 *
 * Example usage
 * @code
 * 		double integral = lobattoIntegration(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */

vector<double> equiCoords(double start, double end, unsigned Ne, unsigned N)
{
	if(start>=end)
	{
		printf("ERROR: The co-ordinated could not be set up as there is something wrong with the input.\n");
		return zeros(Ne*N+1);
	}
	double a,b;///Temporary end points for a given element;
	double step = (end-start)/Ne;	
	vector<double> points;///Temporary points within an element.
	vector<double> coords;///This is the final value which is to be returned.
	
	coords.push_back(start);
	for(unsigned i=0;i<Ne;i++)
	{
		a = start + i*step;
		b = a + step;
		points = lobattoNodes(N+1);///N+1 so as to construct a polynomial of degree `N'.
		points = (0.5*(b+a))*ones(N+1) + (0.5* (b-a))*points;///Mapping it from computational space to physical space.
		//display(points);
		for(unsigned j =1;j <=N ; j++)
			coords.push_back(points[j]);
	}

	return coords;
}
