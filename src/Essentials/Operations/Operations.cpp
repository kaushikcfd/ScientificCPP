#include "Operations.h"

vector<double> operator*(vector<double> GivenVector, const double Factor)
{
	int VectorSize = GivenVector.size();
	vector<double> Result(GivenVector.begin(),GivenVector.end());
	for (unsigned CurrentElement = 0; CurrentElement < VectorSize; CurrentElement++)
	 	Result[CurrentElement] = GivenVector[CurrentElement] * Factor;
	printf("Success!! The matrix was multiplied by a factor\n");
	return Result;  
} 

vector<double> operator*(const double Factor, vector<double> GivenVector)
{
	vector<double> Result;
	Result = GivenVector*Factor;
	return Result;
}

vector<double> operator+(vector<double> LeftVector, vector <double> RightVector)
{
	unsigned VectorSize=LeftVector.size();
	if(RightVector.size()==VectorSize)
	{
		vector<double> Result(LeftVector.begin(),LeftVector.end());
		for (unsigned CurrentElement = 0; CurrentElement < VectorSize; CurrentElement++)
	 		Result[CurrentElement] += RightVector[CurrentElement] ;
		printf("Success the given matrices have been added!\n");
		return Result;	
	}
	else
	{
		printf("ERROR: The arrays sent in for addition are of different sizes.\n");
		return LeftVector;
	}
}

vector<double> operator-(vector<double> LeftVector, vector <double> RightVector)
{
	unsigned VectorSize=LeftVector.size();
	if(RightVector.size()==VectorSize)
	{
		vector<double> Result(LeftVector.begin(),LeftVector.end());
		for (unsigned CurrentElement = 0; CurrentElement < VectorSize; CurrentElement++)
	 		Result[CurrentElement] -= RightVector[CurrentElement] ;
		printf("Success the given matrices have been subtracted!\n");
		return Result;	
	}
	else
	{
		printf("ERROR: The arrays sent in for subtraction are of different sizes.\n");
		return LeftVector;
	}
}

vector<double> operator*(vector<double> LeftVector, vector <double> RightVector)
{
	unsigned VectorSize=LeftVector.size();
	if(RightVector.size()==VectorSize)
	{
		vector<double> Result(LeftVector.begin(),LeftVector.end());
		for (unsigned CurrentElement = 0; CurrentElement < VectorSize; CurrentElement++)
	 		Result[CurrentElement] =LeftVector[CurrentElement]* RightVector[CurrentElement] ;
		printf("Success!! The dot product of the given matrices has been evaluated.\n");
		return Result;	
	}
	else
	{
		printf("ERROR: The arrays sent in for dot product are of different sizes.\n");
		return LeftVector;
	}
}





vector< vector<double> > operator*( vector< vector<double> > LeftMatrix, vector< vector<double> > RightMatrix )
{
	unsigned p = LeftMatrix.size(), q = LeftMatrix[0].size(), r= RightMatrix.size(),s= RightMatrix[0].size();
	if(r!=q)
	{
		printf("ERROR: The matrices given to be multiplied do not have the property by which they can be multiplied.\n");
		return LeftMatrix;
	}
	
	unsigned i,j,k;///These all act as counters for the loop.
	
	vector< vector<double> > Result = zeros(p,s);
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<s;j++)
		{

			for(k=0;k<r;k++)
			{
				Result[i][j] = Result[i][j] + LeftMatrix[i][k]*RightMatrix[k][j];			
			}
		}
	}

	return Result;
}
