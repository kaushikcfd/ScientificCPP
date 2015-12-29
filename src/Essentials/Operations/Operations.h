/**
 * This file will contain the basic functions that define the operator overloading functions on vectors.
 * Defined multiplication on it.
 * Defined addition operation of two vectors of same size.
 * Defined subtraction operation of two vectors of same size.
 * Defined dot product of two vectors of same size, but the syntax is same as for a factor multiplying, the program itself identifies what input it has been given and then applies the formula to it.
 * FUNCTIONS USED:
 * const vector<T>& operator*(vector<T>& GivenVector, const U Factor);: This function basically multiplies the entire entries in the array by a factor of Factor.
 * const vector<T>& operator*(const U Factor, vector<T>& GivenVector);: This also does the work of the above mentioned function, just the change is we have to make the multiplicative property associative, and there is no other to do it rather than defining an operator overloading function.
 *
 * VARIABLES USED:
 * U Factor: This basically takes in the factor given by the user, and also it is also for the template class, so basically this defines it for each type of class like int, double, float, etc.
 * vector<T> GivenVector: Again the same to take the vector any type given by the user.
 * unsigned CurrentElement: To traverse through the array while making computations in it.
 * **/

#include <vector>
#include <cstdio>

#include "../Zero/Zero.h"

#ifndef Operations_H
#define Operations_H
#endif


using namespace std;

vector<double> operator*(vector<double> GivenVector, const double Factor);

vector<double> operator*(const double Factor, vector<double> GivenVector);

vector<double> operator+(vector<double> LeftVector, vector <double> RightVector);

vector<double> operator-(vector<double> LeftVector, vector <double> RightVector);

vector<double> operator*(vector<double> LeftVector, vector <double> RightVector);

vector< vector<double> > operator*(  vector< vector<double> > ,  vector< vector<double> > );

vector< vector<double> > operator*( vector< vector<double> > , const double  );

vector< vector<double> > operator*( const double , vector< vector<double> > );

vector<double> operator*(vector< vector<double> > , vector<double> );

vector< vector<double> >  operator+(vector< vector<double> > LeftVector, vector< vector <double> > RightVector);


vector< vector<double> >  operator-(vector< vector<double> > LeftVector, vector< vector <double> > RightVector);


