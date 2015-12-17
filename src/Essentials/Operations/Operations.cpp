#include "Operations.h"

vector<double> operator*(vector<double>& GivenVector, const double Factor)
{
	int VectorSize = GivenVector.size();
	vector<double> Result(GivenVector.begin(),GivenVector.end());
	for (unsigned CurrentElement = 0; CurrentElement < VectorSize; CurrentElement++)
	 	Result[CurrentElement] = GivenVector[CurrentElement] * Factor;
	printf("Success!! The matrix was multiplied by a factor\n");
	return Result;  
} 

vector<double> operator*(const double Factor, vector<double>& GivenVector)
{
	return (GivenVector * Factor);
}

vector<double> operator+(vector<double>& LeftVector, vector <double> RightVector)
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

vector<double> operator-(vector<double>& LeftVector, vector <double> RightVector)
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

vector<double> operator*(vector<double>& LeftVector, vector <double> RightVector)
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
