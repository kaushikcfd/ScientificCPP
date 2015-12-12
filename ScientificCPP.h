#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include "Essentials/Zero.cpp"
#include "Essentials/One.cpp"
#include "Essentials/ArrayDisplay.cpp"
#include "Essentials/Operations.cpp"
#include "Essentials/Plotter.cpp"
#include "Essentials/StepFill.cpp"
#include "MatrixOperations/GaussElimination.cpp"
#include "Interpolation/Equispaced.cpp"

using namespace std;


void zeros(vector<double> & );
void zeros(vector<double> &, unsigned int);
void zeros(vector<double> &, unsigned int , unsigned int);
void ones(vector<double> & );
void display(vector<double>  );
void plot(vector<double>& ,vector<double>&, string , string );
void stepFill(vector<double>& , double , double, double );
vector<double> GaussElimination(vector<vector<double> > , vector<double> );
vector<double> equiInterpolation(double, double , unsigned int , const vector<double> & );
vector<double> operator*(vector<double>& , const double);
vector<double> operator*(const double, vector<double>& );

