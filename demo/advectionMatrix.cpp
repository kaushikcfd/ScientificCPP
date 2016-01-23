/**
 * This is a demo for the advecction matrix when it is given the inputs for the velocity on each point of the
 * computational grid.
 * The code has been verified and tested by the values given in the manuscript of FX Giraldo. But a small discrepancy in
 * terms of the values of the velocity being used. But will be cleared soon. :D
 */

#include "../src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector< vector <double> > U = 6*ones(2,2),V=zeros(2,2);
    vector < vector<double> > M = advectionMatrix(1,U,U);
    display(M);
}
