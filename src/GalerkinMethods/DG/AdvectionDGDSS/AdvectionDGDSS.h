#include <vector>
#include <functional>
#include <cstdio>
#include <algorithm>

#include "../../../Essentials/Zero/Zero.h"
#include "../../MassMatrix/MassMatrix.h"
#include "../../../Integration/LobattoNodes/LobattoNodes.h"
#include "../../AdvectionMatrix/AdvectionMatrix.h"
#ifndef AdvectionDGDSS_H
#define AdvectionDGDSS_H
#endif

using namespace std;

vector< vector<double> > massDGDSS(unsigned , unsigned , unsigned, double, double );///This would be the 2-D mass matrix, after so-called DSS. The two matrices at the end are the velocity vectors at each grid point.


