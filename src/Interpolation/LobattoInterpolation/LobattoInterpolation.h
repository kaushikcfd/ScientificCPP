#include <vector>
#include <functional>
#include <cstdio>

#include "../LobattoNodes/LobattoNodes.h"
#include "../../Essentials/Operations/Operations.h"
#include "../../Essentials/One/One.h"
#include "../../Essentials/ArrayDisplay/ArrayDisplay.h"
#include "../../MatrixOperations/GaussElimination/GaussElimination.h"
#include "../../Essentials/Zero/Zero.h"

#ifndef LobattoInterpolation_H
#define LobattoInterpolation_H
#endif

using namespace std;

vector<double> lobattoInterpolation(double , double , unsigned , function<double(double)> );

