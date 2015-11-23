#include "ScientificCPP.h"

int main()
{
	vector<double> a(200);
	ones(a);
	for(int i=0; i<a.size(); i++)
		printf("%f\n",a[i]);
}
