#include <vector>
#include <functional>
#include <cstdio>
#include <algorithm>

#include "../../../Essentials/Zero/Zero.h"
#include "../../MassMatrix/MassMatrix.h"
#include "../../../Integration/LobattoNodes/LobattoNodes.h"

#ifndef RusanovFluxDGDSS_H
#define RusanovFluxDGDSS_H
#endif

using namespace std;

vector< vector<double> > rusanovFluxDGDSS(unsigned , unsigned  );
vector< vector<double> > rusanovFluxDGDSS1(unsigned, unsigned , unsigned  );
vector< vector<double> > rusanovFluxDGDSS2(unsigned, unsigned , unsigned  );
vector< vector<double> > rusanovFluxDGDSS3(unsigned, unsigned , unsigned  );
vector< vector<double> > rusanovFluxDGDSS4(unsigned, unsigned , unsigned  );
