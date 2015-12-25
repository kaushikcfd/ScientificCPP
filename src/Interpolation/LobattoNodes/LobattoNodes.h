#include <vector>
#include <functional>
#include <algorithm>
#include "../../Polynomial/LegendrePoynomial/LegendrePoynomial.h"
#include "../../Polynomial/PolyEval/PolyEval.h"
#include "../../Polynomial/PolyDerivative/PolyDerivative.h"
#include "../../Polynomial/SyntheticDivision/SyntheticDivision.h"
#include "../../RootFinding/NewtonRaphson/NewtonRaphson.h"

#ifndef LobattoNodes_H
#define LobattoNodes_H
#endif

using namespace std;

vector<double> lobattoNodes( unsigned n );

