/**
 * This One.h would generate the ones array for the initialization.
 * This should take in an argument for an array and make all the elements in it one.
 * */
/**
 * VARIABLES USED:
 * std::vector<double> GivenVector: This actually is used as a function argument and has no end use. It is the part of the function void ones(vector<double> & )
 * int CurrentElement: This denotes the CurrentElement we are dealing in the vector we are dealling with.
 * int VecorLength: This denotes the length of the vector being dealt over here.
 * int m, n : denote the number of rows and columns.

 * FUNCTIONS USED/CREATED:
 * void ones(vector<double> & ): This is the main operating function of this file.
 * void ones(vector< vector<double> > & GivenVector,int m, int n): This would be used for the intialization of an mxn matrix with all ones. 

 **/

#include <vector>
#include <cstdio>
#ifndef One_H
#define One_H
#endif

using namespace std;

vector<double> ones( unsigned int );

vector< vector<double> > ones(unsigned int m, unsigned int n);


/**END OF THE FILE.**/
