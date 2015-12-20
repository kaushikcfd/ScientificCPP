#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
	vector<double> x;
	double y;
	x .push_back(6);
	x.push_back(-5);
	x.push_back(1);
	display(x);
	function<double(double)> eval = [&x](double a){ return (polyEval(x,a)); };
	function<double(double)> deriv = [&x](double a){return (polyEval((polyDeriv(x)),a));};

	y = eval(100);
	printf("%.6f\n",y);
	y = deriv(2.5);
	printf("%.6f\n",y);
	printf("Now trying with root-finding************\n\n\n\n\n");
	y = newtonRaphson(eval,44);
	printf("%.6f\n",y);
	return 0;

}
