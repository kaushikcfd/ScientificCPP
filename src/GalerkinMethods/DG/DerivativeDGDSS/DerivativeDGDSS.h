#include <vector>
#include <functional>
#include <cstdio>
#include <algorithm>

#include "../../../Essentials/Zero/Zero.h"

#include "../../../MatrixOperations/Transpose/transpose.h"

#include "../../DerivativeMatrix/DerivativeMatrix.h"
#include "../../../Integration/LobattoNodes/LobattoNodes.h"

#ifndef DerivativeDGDSS_H
#define DerivativeDGDSS_H
#endif

using namespace std;

vector< vector<double> > derivativeDGDSS(unsigned , unsigned );
vector< vector<double> > derivativeDGDSSX(unsigned , unsigned , unsigned );
vector< vector<double> > derivativeDGDSSY(unsigned , unsigned , unsigned );
