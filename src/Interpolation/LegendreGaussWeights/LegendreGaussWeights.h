#include <vector>
#include <functional>

#include "../LegendreGaussNodes/LegendreGaussNodes.h"
#include "../../Polynomial/LegendrePoynomial/LegendrePoynomial.h"
#include "../../Polynomial/PolyEval/PolyEval.h"
#include "../../Polynomial/SyntheticDivision/SyntheticDivision.h"
#include "../../Polynomial/PolyDerivative/PolyDerivative.h"
#include "../../RootFinding/NewtonRaphson/NewtonRaphson.h"

#ifndef LegendreGaussWeights_H
#define LegendreGaussWeights_H
#endif

using namespace std;

vector<double> legendreGaussWeights( unsigned n );

