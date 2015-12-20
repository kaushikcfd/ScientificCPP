#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<double> x;
	x = legendreGaussInterpolation(-1,1,5,f);
	//x = legendreGaussNodes(5);
	display(x);
	return 0;
}
