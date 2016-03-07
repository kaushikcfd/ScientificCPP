/**
 * @file	CoordsConversion.cpp
 * @Author	Kaushik Kulkarni (kaushikcfd@gmail.com)
 * @date	December, 2015
 * @brief	This is a small file containing a function which would contain two function vector< double > CGtoDG(vector<double> ) and vector<double> DGtoCG(vector<double>). The function would convert the solution from GGS to LES and vice-versa.
 */

#include "CoordsConversion.h"

/**
 * @name		CGToDG
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector<double> Points
 * This would denote the points which are to be converted.
 *
 * @param[in]	unsigned Ne
 * This would denote the number of elements which have been used to generate the solution.
 *
 * @param[in]	unsigned N
 * This would denote the order of polynomial which has been used to generate the solution.
 *
 * Example usage
 * @code
 * 		double integral = lobattoIntegration(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */
vector<double> CGToDG(vector<double> CG, unsigned Ne, unsigned N)
{
	vector<double> DG;
	unsigned i;///Counter for the loop.
	unsigned Np = Ne*N + 1;///This denotes the number of points that are present in the vector<double> CG.
	if(CG.size()!=Np)
	{
		printf("ERROR: The vector given for conversion is not of suitable size.\n");
		return CG;
	}
	DG.push_back(CG[0]);
	for(i=1;i<Np-1;i++)
	{
		if(i%N==0)
		{
			DG.push_back(CG[i]);
			DG.push_back(CG[i]);
		}
		else
		{
			DG.push_back(CG[i]);
		}
	}
	DG.push_back(CG[i]);

	return DG;
}




/**
 * @name		DGToCG
 * @brief		This is the main working function of the file. Every work of the file is done in this function.
 * @param[in]	vector<double> DG
 * This would denote the points which are to be converted.
 *
 * @param[in]	unsigned Ne
 * This would denote the number of elements which have been used to generate the solution.
 *
 * @param[in]	unsigned N
 * This would denote the order of polynomial which has been used to generate the solution.
 *
 * Example usage
 * @code
 * 		double integral = lobattoIntegration(unsigned n);//Storing the coefficient of the nth degree Legendre roots.
 * 	@endcode
 */
vector<double> DGToCG(vector<double> DG, unsigned Ne, unsigned N)
{
	vector<double> CG;
	unsigned Np = Ne*(N+1);///This denoted the total number of elements in the given vector.
	unsigned i;///Counter for the loop.

	if(DG.size()!=Np)
	{
		printf("ERROR: The vector given for conversion is not of suitable size.\n");
		return DG;
	}

	for(i=0;i<Np-1;i++)
	{
		if((i%(N+1)) == N )
		{
			CG.push_back(0.5*(DG[i]+DG[i+1]));
			i++;
		}
		else
		{
			CG.push_back(DG[i]);
		}
	}
	CG.push_back(DG[i]);

	return CG;
}

vector< vector<double> > DGToCG(vector< vector<double> > DG, unsigned Nex, unsigned Ney, unsigned N)
{
	unsigned i;///Counter for the loop.

	vector< vector<double> > CG	=	DG;

	/*First converting the vectors in the x-direction.*/

	for(i=0;i<((N+1)*Ney);i++)
	{
		CG[i]	=	DGToCG(CG[i],Nex,N);
	}

	CG 	=	transpose(CG);

	for(i=0;i<(N*Nex + 1);i++)
	{
		CG[i]	=	DGToCG(CG[i],Ney,N);
	}

	CG 	=	transpose(CG);

	return CG;
}
