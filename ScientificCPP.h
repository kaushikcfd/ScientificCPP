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


using namespace std;


void zeros(vector<double> & );
void ones(vector<double> & );
void display(vector<double>  );
void plot(vector<double>& ,vector<double>&);
void stepFill(vector<double>& , double , double, double );
vector<double> operator*(vector<double>& , const double);
vector<double> operator*(const double, vector<double>& );

