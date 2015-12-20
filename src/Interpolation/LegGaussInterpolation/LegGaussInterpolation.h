#include <vector>
#include <functional>
#include <cstdio>

#include "../LegendreGaussNodes/LegendreGaussNodes.h"
#include "../../Essentials/Operations/Operations.h"
#include "../../Essentials/One/One.h"
#include "../../Essentials/ArrayDisplay/ArrayDisplay.h"
#include "../../MatrixOperations/GaussElimination/GaussElimination.h"
#include "../../Essentials/Zero/Zero.h"

#ifndef LegGaussInterpolation_H
#define LegGaussInterpolation_H
#endif

using namespace std;

vector<double> legendreGaussInterpolation(double , double , unsigned , function<double(double)> );

