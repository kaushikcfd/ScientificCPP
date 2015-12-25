#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	
	vector< vector<double> > M;
	M = derivativeMatrix(lobattoNodes(5));
	display(M);
	
	return 0;
}
