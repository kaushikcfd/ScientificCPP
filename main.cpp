#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<	vector<double> > MM = zeros(3,3);
	MM[0][0]=1.0/3.0;
	MM[0][1]=1.0/6;
	MM[0][2]=0.0;
	MM[1][0]=1.0/6;
	MM[1][1]=4.0/6;
	MM[1][2]=1.0/6;
	MM[2][0]=0.0;
	MM[2][1]=1.0/6;
	MM[2][2]=2.0/6;
	MM = inverse(MM);
	display(MM);
	return 0;
}
