#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
	vector<double> x;
	double y;
	x = legendrePoly(4);
	display(x);
	y = polyEval(x,0);
	printf("%.6f",y);

}
