#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<double> k;
	k= equiCoords(0.0,2.0,4,4);
	display(k);

	return 0;
}
