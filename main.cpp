#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
	vector<double> x;
	vector<double> y;
	x .push_back(-6);
	x.push_back(11);
	x.push_back(-6);
	x.push_back(1);
	display(x);
	//function<double(double)> eval = [&x](double a){ return (polyEval(x,a)); };
	//function<double(double)> deriv = [&x](double a){return (polyEval((polyDeriv(x)),a));};

	y = synthDiv(x,1);
	display(y);
	return 0;
}
