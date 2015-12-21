#include <vector>
#include <functional>

#include "../LobattoNodes/LobattoNodes.h"
#include "../../Polynomial/LegendrePoynomial/LegendrePoynomial.h"
#include "../../Polynomial/PolyEval/PolyEval.h"
#include "../../Polynomial/SyntheticDivision/SyntheticDivision.h"
#include "../../Polynomial/PolyDerivative/PolyDerivative.h"
#include "../../RootFinding/NewtonRaphson/NewtonRaphson.h"

#ifndef LobattoWeights_H
#define LobattoWeights_H
#endif

using namespace std;

vector<double> lobattoWeights( unsigned n );

