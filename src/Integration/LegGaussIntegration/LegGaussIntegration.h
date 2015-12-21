#include <vector>
#include <functional>
#include <cstdio>

#include "../LegendreGaussNodes/LegendreGaussNodes.h"
#include "../LegendreGaussWeights/LegendreGaussWeights.h"
#include "../../Essentials/Operations/Operations.h"
#include "../../Essentials/One/One.h"
#include "../../Essentials/ArrayDisplay/ArrayDisplay.h"
#include "../../MatrixOperations/GaussElimination/GaussElimination.h"
#include "../../Essentials/Zero/Zero.h"

#ifndef LegGaussIntegration_H
#define LegGaussIntegration_H
#endif

using namespace std;

double legendreGaussIntegration(double , double , unsigned , function<double(double)> );

