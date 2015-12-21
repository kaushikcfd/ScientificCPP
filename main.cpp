#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<double> x;
	//x = legendreGaussInterpolation(-1,1,5,f);
	printf("Displaying the nodes\n");
	x = lobattoNodes(6);
	display(x);
	//printf("Displaying the Nodes\n");
	//x = legendreGaussNodes(7);
	//display(x);
	return 0;
}
