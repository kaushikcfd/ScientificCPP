#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
	vector<double> x,y;
	x = stepFill(-1,0.01,1);
	for(int i=0;i<x.size();i++)
		y.push_back(sin(x[i]));
	display(x);
	plot(x,y);
}
