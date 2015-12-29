#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <functional>
////////////////////////////////////////////
#include "../Essentials/Zero/Zero.cpp"
#include "../Essentials/One/One.cpp"
#include "../Essentials/ArrayDisplay/ArrayDisplay.cpp"
#include "../Essentials/Operations/Operations.cpp"
#include "../Essentials/Plotter/Plotter.cpp"
#include "../Essentials/StepFill/StepFill.cpp"
//////////////////////////////////////////////
#include "../MatrixOperations/GaussElimination/GaussElimination.cpp"
#include "../MatrixOperations/Transpose/transpose.cpp"
#include "../MatrixOperations/Inverse/Inverse.cpp"
//////////////////////////////////////////////
#include "../Interpolation/Equispaced/Equispaced.cpp"
#include "../Interpolation/LegendreGaussNodes/LegendreGaussNodes.cpp"
#include "../Interpolation/LegendreGaussWeights/LegendreGaussWeights.cpp"
#include "../Interpolation/LegGaussInterpolation/LegGaussInterpolation.cpp"
#include "../Interpolation/LobattoNodes/LobattoNodes.cpp"
#include "../Interpolation/LobattoWeights/LobattoWeights.cpp"
#include "../Interpolation/LobattoInterpolation/LobattoInterpolation.cpp"
#include "../Interpolation/LagrangePolynomials/LagrangePolynomials.cpp"
//////////////////////////////////////////////
#include "../Integration/LegGaussIntegration/LegGaussIntegration.cpp"
#include "../Integration/LobattoIntegration/LobattoIntegration.cpp"
//////////////////////////////////////////////
#include "../Polynomial/LegendrePoynomial/LegendrePoynomial.cpp"
#include "../Polynomial/PolyDerivative/PolyDerivative.cpp"
#include "../Polynomial/PolyEval/PolyEval.cpp"
#include "../Polynomial/SyntheticDivision/SyntheticDivision.cpp"
//////////////////////////////////////////////
#include "../RootFinding/NewtonRaphson/NewtonRaphson.cpp"
//////////////////////////////////////////////
#include "../GalerkinMethods/MassMatrix/MassMatrix.cpp"
#include "../GalerkinMethods/FluxMatrix/FluxMatrix.cpp"
#include "../GalerkinMethods/DerivativeMatrix/DerivativeMatrix.cpp"
#include "../GalerkinMethods/EquiCoords/EquiCoords.cpp"
#include "../GalerkinMethods/CG/MassCGDSS/MassCGDSS.cpp"
#include "../GalerkinMethods/CG/DerivativeCGDSS/DerivativeCGDSS.cpp"
#include "../GalerkinMethods/DG/MassDGDSS/MassDGDSS.cpp"
#include "../GalerkinMethods/DG/DerivativeDGDSS/DerivativeDGDSS.cpp"
//////////////////////////////////////////////
#ifndef ScientificCPP_H
#define ScientificCPP_H
#endif
using namespace std;
