/**
 * This file will contain the basic functions that define the operator overloading functions on vectors.
 * Defined multiplication on it.
 *
 * FUNCTIONS USED:
 * const vector<T>& operator*(vector<T>& GivenVector, const U Factor): This function basically multiplies the entire entries in the array by a factor of Factor.
 * const vector<T>& operator*(const U Factor, vector<T>& GivenVector): This also does the work of the above mentioned function, just the change is we have to make the multiplicative property associative, and there is no other to do it rather than defining an operator overloading function.
 *
 * VARIABLES USED:
 * U Factor: This basically takes in the factor given by the user, and also it is also for the template class, so basically this defines it for each type of class like int, double, float, etc.
 * vector<T> GivenVector: Again the same to take the vector any type given by the user.
 * unsigned CurrentElement: To traverse through the array while making computations in it.
 * **/

#include <vector>
#ifndef _SCIENTIFICCPP_H
#define _SCIENTIFICCPP_H
#endif


using namespace std;

template<class T, class U>
const vector<T>& operator*(vector<T>& GivenVector, const U Factor)
{
	for (unsigned CurrentElement = 0; CurrentElement < GivenVector.size(); CurrentElement++)
		GivenVector[CurrentElement] *= Factor; 
	return GivenVector;  
} 

template<class T, class U>
const vector<T>& operator*(const U Factor, vector<T>& GivenVector)
{
	return (GivenVector * Factor);
}
