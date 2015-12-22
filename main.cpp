#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<	vector<double> > poly;
	vector<double> x;
	x.push_back(-1);
	x.push_back(1);
	poly = lagrangePolynomials(x);
	display(poly);
	return 0;
}
