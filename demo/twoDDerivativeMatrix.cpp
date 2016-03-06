/**
 * This is a demo file for generating the 2-D mass matrix which isobtained after the DSS.
 * The values have not been verified just the sparsity has been intuitively checked.
 * **/

#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector< vector<double> > A = twoDDerivativeMatrixX(1);
    A   =   6*transpose(A);
    display(A);
    printf("\n");

    A = twoDDerivativeMatrixY(1);
    A   =   6*transpose(A);
    display(A);
}
