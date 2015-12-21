#include <vector>
#include <functional>
#include <cstdio>

#include "../LobattoNodes/LobattoNodes.h"
#include "../LobattoWeights/LobattoWeights.h"
#include "../../Essentials/Operations/Operations.h"
#include "../../Essentials/One/One.h"
#include "../../Essentials/ArrayDisplay/ArrayDisplay.h"
#include "../../MatrixOperations/GaussElimination/GaussElimination.h"
#include "../../Essentials/Zero/Zero.h"

#ifndef LobattoIntegration_H
#define LobattoIntegration_H
#endif

using namespace std;

double lobattoIntegration(double , double , unsigned , function<double(double)> );

