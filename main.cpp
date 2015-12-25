#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	
	vector< vector<double> > R = ones(3,3);

	display(R * ones(3));

	
	
	
	return 0;
}
