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

#ifndef AdvectionMatrix_H
#define AdvectionMatrix_H
#endif

using namespace std;

vector< vector<double> > advectionMatrix(unsigned , vector< vector < double > > , vector < vector <double> >);


