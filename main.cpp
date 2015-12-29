#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	
	//vector< vector<double> > A = derivativeDGDSS(4,4) - fluxDGDSS(4,4)*rusanovFluxDGDSS(4,4);
	vector<double> b;
	b.push_back(-1);
	b.push_back(1);
	vector< vector<double> > A = fluxMatrix(b);
	display(A);
	
	return 0;
}
