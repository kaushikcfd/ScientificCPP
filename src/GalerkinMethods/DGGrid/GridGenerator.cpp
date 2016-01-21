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
 * @endcode
 */


vector< vector<double> > xlobattoGrid(unsigned N)
{
    vector< vector<double> > CompGridx;///This would be used  for storing the y-coordinates of the computational grid.
    
    vector<double> Nodes = lobattoNodes(N+1);///Note we need N+1 nodes bcoz N+1 nodes would interpolate a polynomial of degree N.

    unsigned i,j;///These would be used as counter for the loops and hence for the purpose of traversing through the matrix.

    CompGridx = zeros(N+1,N+1);

    for(i=0;i<=N;i++)
    {
        for(j=0;j<=N;j++)
        {
            CompGridx[i][j] = Nodes[j];
        }
    }
    
    return CompGridx;
}


vector< vector<double> > ylobattoGrid(unsigned N)
{
    vector< vector<double> > CompGridy;///This would be used  for storing the y-coordinates of the computational grid.
    
    vector<double> Nodes = lobattoNodes(N+1);///Note we need N+1 nodes bcoz N+1 nodes would interpolate a polynomial of degree N.

    unsigned i,j;///These would be used as counter for the loops and hence for the purpose of traversing through the matrix.

    CompGridy = zeros(N+1,N+1);

    for(i=0;i<=N;i++)
    {
        for(j=0;j<=N;j++)
        {
            CompGridy[i][j] = Nodes[i];
        }
    }
    
    return CompGridy;
}


vector< vector<double> > xLimitsGrid(double X_start, double X_end, double Y_start, double Y_end,unsigned Ne_x, unsigned Ne_y, unsigned N)
{
    vector< vector<double> > Xlimits;
    vector<double> XFirst(Ne_x*Ne_y,0), XLast(Ne_x*Ne_y,0) ;
    double step = (X_end - X_start)/Ne_x;
    unsigned i,j ;///Counter for the loop ahead.
    for(i=0;i<Ne_y;i++)
    {
        XFirst[i*(Ne_x)] = X_start;
        XLast[i*(Ne_x)]  = X_start + step; 
        for(j=1;j<Ne_x;j++)
        {
            XFirst[i*(Ne_x) + j] = XFirst[i*(Ne_x) + j-1] + step;
             XLast[i*(Ne_x) + j] =  XLast[i*(Ne_x) + j-1] + step;
        }
    }

    Xlimits.push_back(XFirst);
    Xlimits.push_back(XLast);


    return Xlimits;
}

vector< vector<double> > yLimitsGrid(double X_start, double X_end, double Y_start, double Y_end,unsigned Ne_x, unsigned Ne_y, unsigned N)
{
    vector< vector<double> > Ylimits;
    vector<double> YFirst(Ne_x*Ne_y,0),  YLast(Ne_x*Ne_y,0) ;
    double step = (Y_end - Y_start)/Ne_y;
    unsigned i,j ;///Counter for the loop ahead.
    for(i=0;i<Ne_y;i++)
    {
        for(j=0;j<Ne_x;j++)
        {
            YFirst[i*(Ne_x) + j] = Y_start + i*step; 
             YLast[i*(Ne_x) + j] = Y_start + (i+1)*step;
        }
    }

    Ylimits.push_back(YFirst);
    Ylimits.push_back(YLast);


    return Ylimits;
}

vector< vector<double> > elementNeighbours(unsigned Ne_x, unsigned Ne_y)///Note: This would be an 4*(Ne_x*Ne*y) matrix since each of the element would have 4 neighbours this is the case for periodic boundary condition, the first row would represent the top element, the second one bottom, then right and finally left :)
{
    vector< vector<double> > Neighbours;
    vector<double> top(Ne_x*Ne_y,0),bottom(Ne_x*Ne_y,0),left(Ne_x*Ne_y,0),right(Ne_x*Ne_y,0);
    unsigned i,j;
    for(i=0;i<Ne_y;i++)
    {
        for(j=0;j<Ne_x;j++)
        {
            if(j!=(Ne_x-1))
                right[i*Ne_x + j] = i*Ne_x + j+1;
            else
                right[i*Ne_x + j] = i*(Ne_x);
            if(j!=0)
                left[i*Ne_x + j] = i*Ne_x +j- 1;
            else
                left[i*Ne_x + j] = i*Ne_x + Ne_x -1;
            if(i!=(Ne_y-1))
                top[i*Ne_x + j] = (i+1)*Ne_x + j;
            else
                top[i*Ne_x + j] = j;
            if(i!=0)
                bottom[i*Ne_x + j] = (i-1)*Ne_x + j;
            else
                bottom[i*Ne_x + j] = (Ne_y-1)*Ne_x + j;                    
        }
    }
    


    Neighbours.push_back(top);
    Neighbours.push_back(bottom);
    Neighbours.push_back(right);
    Neighbours.push_back(left);
    return Neighbours;
}
