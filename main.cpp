#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	
	//vector< vector<double> > A = derivativeDGDSS(4,4) - fluxDGDSS(4,4)*rusanovFluxDGDSS(4,4);
	vector< vector<double> > A;
	vector<double> b;
	vector<string> k;
	b = stepFill(-1,0.01,1);
	k.push_back("cosx");
	vector<double> c;
	unsigned i;
	for(i=0;i<b.size();i++)
		c.push_back(cos(b[i]));
	A.push_back(c);
	c.clear();
	for(i=0;i<b.size();i++)
		c.push_back(sin(b[i]));
	A.push_back(c);
	k.push_back("sinx");
	plot(b,A,"Try",k);
	
	
	return 0;
}
