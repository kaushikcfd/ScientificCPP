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

#include "../../Interpolation/LobattoNodes/LobattoNodes.h"
#include "../../Integration/LobattoIntegration/LobattoIntegration.h"

#include "../../Polynomial/PolyEval/PolyEval.h"
#include "../../Polynomial/PolyDerivative/PolyDerivative.h"

#ifndef MassMatrix_H
#define MassMatrix_H
#endif

using namespace std;

vector < vector<double> > massMatrix( vector<double> );
vector < vector<double> > twoDMassMatrix( unsigned  );///Note: Right now the support is only for quad grids, but can be very easily extended for other grid types. 
