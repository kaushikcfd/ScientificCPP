/**
 * This is a demo file for checking the computational grid co-ordinats.
 * The code has been checked and verified.
 * Since the co-ordinates of x and y are known.
 */



#include "../src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector< vector<double> > gridx,gridy;
    gridx = xlobattoGrid(4);
    display(gridx);
    printf("\n");
    gridy = ylobattoGrid(3);
    display(gridy);
    
    return 0;
}
