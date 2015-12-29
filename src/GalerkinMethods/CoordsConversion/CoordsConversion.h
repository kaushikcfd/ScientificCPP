#include <vector>
#include <functional>
#include <cstdio>
#include <algorithm>



#include "../../Essentials/Operations/Operations.h"
#include "../../Essentials/One/One.h"
#include "../../Essentials/ArrayDisplay/ArrayDisplay.h"
#include "../../Essentials/Zero/Zero.h"

#include "../../MatrixOperations/GaussElimination/GaussElimination.h"

#include "../../Interpolation/LagrangePolynomials/LagrangePolynomials.h"

#include "../../Integration/LobattoIntegration/LobattoIntegration.h"

#include "../../Polynomial/PolyEval/PolyEval.h"
#include "../../Polynomial/PolyDerivative/PolyDerivative.h"

#ifndef MassMatrix_H
#define MassMatrix_H
#endif

using namespace std;

vector<double> CGToDG(vector<double> , unsigned , unsigned );

vector<double> DGToCG(vector<double> , unsigned , unsigned );
