#include "ScientificCPP.h"
#include <cmath>
int main()
{
	vector<double> a(500),b(500);
	zeroes(a);
	zeroes(b);
	for(int i = 1; i < a.size();i++)
	{
		a[i] = a[i-1] + 0.01;
		b[i] = sin(a[i]);
	}
	plot(a,b,"SimplePlot","SineCurve");
//	system("gnuplot> load 'temp.gnu'");
}
