/**
 * This is a demo file for the function advectionDGDSS.
 * And again there is one slight limitation in the code that is it is assumed that the velocities U and V to be constant
 * throughout the domain, but one can easily change the function to get more of it.
 * Currently, the sparsity of the solution is checked intuitively, but not verified from anny trustworthy source.
 */

#include "../src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector< vector<double> > A = advectionDGDSS(2,2,1,6,0);
    sparseDisplay(A);
}
