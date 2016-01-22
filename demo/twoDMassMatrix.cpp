/**
 * This  is a tester file for the two D mass matrix.
 * The code has been checked from the manuscript of FX Giraldo. 
 */


#include "../src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector < vector<double> > M = twoDMassMatrix(1);
    display(M);
}
