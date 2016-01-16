#include <vector>
#include <cstdio>
#include <functional>
#include "../../Interpolation/LobattoNodes/LobattoNodes.h"
#include "../../Essentials/Zero/Zero.h"

using namespace std;

#ifndef GridGeneration_H
#define GridGeneration_H
#endif

vector < vector<double> > lobattoGrid(unsigned );

vector< vector<double> > gridGenerator(double , double , double , double , unsigned , unsigned );

