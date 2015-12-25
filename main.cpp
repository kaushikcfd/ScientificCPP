#include "src/ScientificCPP/ScientificCPP.cpp"

double f(double x)
{
	return sin(x);
}

int main()
{
	vector<	vector<double> > L = zeros(3,3),R = zeros(3,3),K;
	L[0][0]=1.0/3.0;
	L[0][1]=1.0/6;
	L[0][2]=0.0;
	L[1][0]=1.0/6;
	L[1][1]=4.0/6;
	L[1][2]=1.0/6;
	L[2][0]=0.0;
	L[2][1]=1.0/6;
	L[2][2]=2.0/6;
	L = inverse(L);
	L = 2*L;
	display(L);
	

	R[0][0]=-1.0;
	R[0][1]=1.0;
	R[0][2]=0.0;
	R[1][0]=-1.0;
	R[1][1]=0.0;
	R[1][2]=1.0;
	R[2][0]=0.0;
	R[2][1]=-1.0;
	R[2][2]=1.0;
	display(R);
	K = 0.25*L*R;
	printf("Displaying the result\n");
	display(K);

	return 0;
}
