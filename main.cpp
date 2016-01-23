#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector< vector <double> > U = 6*ones(2,2),V=zeros(2,2);
    vector < vector<double> > M = advectionMatrix(1,U,U);
    display(M);
}
