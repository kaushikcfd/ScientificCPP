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

#ifndef FluxMatrix_H
#define FluxMatrix_H
#endif

using namespace std;

vector< vector<double> > fluxMatrix(vector<double> );
vector< vector<double> > twoDFluxMatrix1(unsigned );
vector< vector<double> > twoDFluxMatrix2(unsigned );
vector< vector<double> > twoDFluxMatrix3(unsigned );
vector< vector<double> > twoDFluxMatrix4(unsigned );
