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

#include "../MassMatrix/MassMatrix.h"

#ifndef DerivativeMatrix_H
#define DerivativeMatrix_H
#endif

using namespace std;

vector< vector<double> > derivativeMatrix(vector<double> );
vector< vector<double> > twoDDerivativeMatrixX(unsigned );
vector< vector<double> > twoDDerivativeMatrixY(unsigned );
