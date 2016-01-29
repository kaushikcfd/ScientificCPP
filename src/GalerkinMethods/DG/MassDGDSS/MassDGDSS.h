#include <vector>
#include <functional>
#include <cstdio>
#include <algorithm>

#include "../../../Essentials/Zero/Zero.h"
#include "../../MassMatrix/MassMatrix.h"
#include "../../../Integration/LobattoNodes/LobattoNodes.h"

#ifndef MassDGDSS_H
#define MassDGDSS_H
#endif

using namespace std;

vector< vector<double> > massDGDSS(unsigned , unsigned );///This is the 1-D mass matrix which is obtained after so-called DSS.
vector< vector<double> > massDGDSS(unsigned , unsigned , unsigned);///This would be the 2-D mass matrix, after so-called DSS.



