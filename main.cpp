#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<	vector<double> > MM;
	vector<double> x;
	x.push_back(-1);
	x.push_back(1);
	MM = massMatrix(x);
	display(MM);
	return 0;
}
