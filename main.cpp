#include "ScientificCPP.h"

int main()
{
	vector<double> a,b;
	stepFill(a,-15,0.1,15);
	for(int i = 0; i < a.size();i++)
		b.push_back( a[i]*sin(a[i]));
	plot(a,b,"NewPloT","xsin(x)");
}
