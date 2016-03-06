/**
 * This is a demo file for generating the 2-D mass matrix which isobtained after the DSS.
 * The values have not been verified just the sparsity has been intuitively checked.
 * **/

#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector< vector<double> > A = rusanovFluxDGDSS1(2, 2 , 1 );
    display(A);
    printf("\n");
    A = rusanovFluxDGDSS2(2, 2 , 1 );
    display(A);
    printf("\n");
    A = rusanovFluxDGDSS3(2, 2 , 1 );
    display(A);
    printf("\n");
    A = rusanovFluxDGDSS4(2, 2 , 1 );
    display(A);
}
