#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<double> x;
	//x = legendreGaussInterpolation(-1,1,6,f);
	printf("Displaying the nodes\n");
	x = lobattoNodes(6);
	display(x);
	printf("Displaying the weights\n");
	x = lobattoWeights(6);
	display(x);
	return 0;
}
