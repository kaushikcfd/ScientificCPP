#include "ScientificCPP.h"

int main()
{
	vector<double> a(200),b(200);
	ones(a);
	display(a);
	b=a*5.0;
	display(a);
	//display((1.0*a).begin());
}
