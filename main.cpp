#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<double> x;
	x = lobattoInterpolation(-2,2,5,f);
	display(x);
	return 0;
}
