#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdio>
#include "Essentials/zero.cpp"
#include "Essentials/one.cpp"
#include "Essentials/ArrayDisplay.cpp"
#include "Essentials/Operations.cpp"

using namespace std;


void zeroes(vector<double> & );
void ones(vector<double> & );
void display(vector<double> & );
template<class T, class U>
const vector<T>& operator*(vector<T>& , const U);
template<class T, class U>
const vector<T>& operator*(const U, vector<T>& );
