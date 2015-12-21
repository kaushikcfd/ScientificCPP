#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	double x;
	x = legendreGaussIntegration(0,3.14159,7,f);
	printf("**********************\n%.6f\n*******************\n",x);
	return 0;
}
