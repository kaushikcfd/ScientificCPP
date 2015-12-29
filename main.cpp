#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector< vector<double> > k;
	k= derivativeDGDSS(4,4);
	sparseDisplay(k);

	return 0;
}
