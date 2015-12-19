/**
 * @file	LegendrePolynomial.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain a function vector<double> legendrePoly(unsigned int n), and would return a vector cotaining the coefficients of the Legendre Polynomial of degree n.
 */

#include "LegendrePoynomial.h"



/**
 * @name	legendrePoly
 * @brief	This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	unsigned int n
 *
 * Example usage
 * @code
 * 		vector<double> polyn = legendrePoly(n);//Storing the coefficients of the nth degree Legendre Polynomial in the variable polyn
 * 	@endcode
 */
vector<double> legendrePoly(unsigned int n)
{
	vector<double> LegPolyn,LegPolyn_1,LegPolyn_2,temp;///These are the main working data in the code. Legpolyn_1 denotes the n-1 Legendre Polynomial and the LegPolyn_2 denotes the n-2 Legendre Polynomial. The temp is for the switching of the polynomials.
	LegPolyn_1.push_back(0);
	LegPolyn_1.push_back(1);
	LegPolyn_2.push_back(1);
	if(n==0)
		return LegPolyn_2;
	else if(n==1)
		return LegPolyn_1;
	else
	{
		for(int i=2;i<=n;i++)
		{
			LegPolyn_1.insert(LegPolyn_1.begin(),0);
			LegPolyn_2.push_back(0);
			LegPolyn_2.push_back(0);
			LegPolyn = ((2*i-1.0)/(i))*LegPolyn_1 - ((i-1.0)/(i))*LegPolyn_2;
			LegPolyn_1.erase(LegPolyn_1.begin());
			LegPolyn_2 = LegPolyn_1;
			LegPolyn_1 = LegPolyn;			
		}
		return LegPolyn;
	}
}
