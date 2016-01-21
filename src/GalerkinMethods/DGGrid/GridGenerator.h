#include <vector>
#include <cstdio>
#include <functional>
#include "../../Interpolation/LobattoNodes/LobattoNodes.h"
#include "../../Essentials/Zero/Zero.h"
#include "../../Essentials/StepFill/StepFill.h"

using namespace std;

#ifndef GridGeneration_H
#define GridGeneration_H

vector < vector<double> > xlobattoGrid(unsigned );

vector < vector<double> > ylobattoGrid(unsigned );

vector< vector<double> > gridGenerator(double , double , double , double , unsigned , unsigned );

vector< vector <double> >  xLimitsGrid(double , double, double, double,unsigned , unsigned ,unsigned );

vector< vector <double> >  yLimitsGrid(double , double, double, double,unsigned , unsigned ,unsigned );

vector< vector < double > > elementNeighbours(unsigned , unsigned);

#endif

