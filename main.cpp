#include "ScientificCPP.h"

int main()
{
	vector<double> b(3,0),x;
		
	b[0] = 0;
	b[1] = 7;
	b[2] = 16;

	x=equiInterpolation(-1,1,3, b);
	display(x);
}
