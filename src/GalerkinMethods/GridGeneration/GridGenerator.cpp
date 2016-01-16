/**
 * @file	GridGenerator.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	January, 2016
 * @brief	This is the file which contains a function which generates a 2-D grid points, given the number of elements in each direction would return the grid points that would be involved with each of the element subdivided using the lobatto quadrature points.
 * */

#include "GridGenerator.h"

/**
 * @name		gridGenerator
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

vector< vector<double> > lobattoGrid(unsigned N)
{
    vector< vector<double> > CompGrid;
    vector<double> CompGridX,CompGridY;///This computational grid has been formed using the lobatto Nodes and and in the space -1 to +1 cross -1 to +1.
    vector<double> Nodes = lobattoNodes(N+1);
    
    unsigned M = (N+1)*(N+1);///The total number of elements in a quad element.
    unsigned i,j;///Used as an counter for the loop ahead.
    /**Now creating the computational grid.**/
    CompGridX = CompGridY = zeros(M);
    for (i=0;i<=N;i++)
    {
          for(j=0;j<=N;j++)
          {
             CompGridX[i*(N+1) + j] = Nodes[j]; 
             CompGridY[i*(N+1) + j] = Nodes[i];
          }
    }
    CompGrid.push_back(CompGridX);
    CompGrid.push_back(CompGridY);
    return CompGrid;
}
