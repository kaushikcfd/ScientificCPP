#include "ScientificCPP.h"

int main()
{
	vector<double> a(20),b(20);
	ones(a);
	display(a);
	b=a*5.0;
	//display(10.0*a);
	display(b*(10*a));
}
