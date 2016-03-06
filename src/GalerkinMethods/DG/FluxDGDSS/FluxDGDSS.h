#include <vector>
#include <functional>
#include <cstdio>
#include <algorithm>

#include "../../../Essentials/Zero/Zero.h"
#include "../../FluxMatrix/FluxMatrix.h"
#include "../../../Integration/LobattoNodes/LobattoNodes.h"

#ifndef FluxDGDSS_H
#define FluxDGDSS_H
#endif

using namespace std;

vector< vector<double> > fluxDGDSS(unsigned , unsigned );
vector< vector<double> > fluxDGDSS1(unsigned , unsigned , unsigned );
vector< vector<double> > fluxDGDSS2(unsigned , unsigned , unsigned );
vector< vector<double> > fluxDGDSS3(unsigned , unsigned , unsigned );
vector< vector<double> > fluxDGDSS4(unsigned , unsigned , unsigned );
