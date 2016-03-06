/**
 * This is a demo file for generating the 2-D mass matrix which isobtained after the DSS.
 * The values have not been verified just the sparsity has been intuitively checked.
 * **/

#include "../src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector< vector<double> > A = twoDFluxMatrix1(1);
    display(A);
    printf("\n");
    A = twoDFluxMatrix2(1);
    display(A);
    printf("\n");
    A = twoDFluxMatrix3(1);
    display(A);
    printf("\n");
    A = twoDFluxMatrix4(1);
    display(A);
}
