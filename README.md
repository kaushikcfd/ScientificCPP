# ScientificCPP


## Functions 

* ### Essentials-
    * `vector<double> zeros(unsigned )`: This would return a column vector with all zeros.
    * `vector<double> ones(unsigned )`: This would return a column vector with all ones.
    * `vector<double> display(vector<double> )`: Given a vector<double> as an input, it would display its contents.
    * `void plot(vector<double> , vector<double> )`: Given two vector it would make a plot `x` vs `y`.
    * `vector<double> stepFill(double start, double step, double end )`: This would return a column vector from `start` to end `end`with a step size `step`
* ### Matrix Operations-
    * `vector<double> GaussElimination(vector< vector<double> > A, vector<double> b)`: Given the inputs it would output `x` column vector as the solution of the equation `Ax=b`
    * `vector< vector<double> > transpose(vector< vector<double> >)`: This would return the transpoe of a given matrix.
	* `vector< vector<double> >`inverse(vector< vector<double> > )` : This would return the inverse of the given matrix.
* ### Interpolation 
    * `vector<double> equiInterpolation(double start, double end, unsigned , function<double(double)>)`: Given a function and the start and end points it would interpolate equisapced points from start to end. And it would return the coefficients of the polynomials where the value of the _i th_ power of x.
    * `vector<double> legendreGaussInterpolation(double start, double end, unsigned n, function<double(double)>)`: Given a function and the start and end points it would interpolate using n+1 Legendre Gauss points from start to end. And it would return the coefficients of the polynomials where the value of the _i th_ power of x.
    * `vector<double> loabattoInterpolation(double start, double end, unsigned n, function<double(double)>)`: Given a function and the start and end points it would interpolate using the n+1 Lobatto nodes from start to end.
    * `vector<double> lobattoNodes(unsigned n)`: This would return the Lobatto Nodes is the computational space.
    * `vector<double> legendreGaussNodes(unsigned n)`: This would return the Legendre Gauss Nodes is the computational space.
    *  `vector<double> legendreGaussWeights(unsigned n)`: This would return the weights corresponding to the Legendre Gauss Nodes.
    *  `vector<double> lobattoWeights(unsigned n)`: This would return the weights corresponding to the Lobatto Nodes.
    
* ### Integration
    * `double legendreGaussIntegration(double start, double end, unsigned n, function<double(double)>)`: Given a function and the start and end points it would integrate it using n+1 Legendre Gauss points from start to end.
    * `double loabattoIntegration(double start, double end, unsigned n, function<double(double)>)`: Given a function and the start and end points it would integrate it using the n+1 Lobatto nodes from start to end.

* ### Polynomials
    * `double polyEval(vector<double> Poly, double x)` :This would return the value of the polynomial at the point `x` . This uses the Horner's scheme for evaluating the values of the polynomial. 
    * `vector<double> polyDeriv(vector<double> Poly)` :This would return the derivative of the polynomial in the polynomial form. 
    * `vector<double> synthDiv(vector<double> Poly, double root)` :This would return the coefficients of the polynomial after dividing the given polynomial using its root .
    * `vector<double> legendrePolynomial(unsigned n)` :This would return the coefficients of the Legendre polynomial of degree n .

* ### Root Finding.
    * `double newtonRaphson(function<double(double)> f, double x0)` :This would return the result of the Newton Raphson method of finding the root given an intial guess x0.

* ### Galerkin Methods:
    * `vector< vector<double> > massMatrix(vector<double> Points)` : Given the points as a vector<double> form, it would give us the **Mass Matrix** corresponding to the Lagrange Polynomials made usgin the given points.
    * `vector< vector<double> > derivativeMatrix(vector<double> Points)` : Given the points as a vector<double> form, it would give us the **Derivative Matrix**  in the strong form corresponding to the Lagrange Polynomials made usgin the given points. **Note:** The derivative matrix in weak form can be made simply using the transpose function described earlier.
    * `vector< vector<double> > fluxMatrix(vector<double> Points)`: Given the points as a vector<double> form, it would give us the **Flux Matrix** corresponding to the Lagrange Polynomials made usgin the given points. 
    * #### Continuous Galerkin Methods:
		* `vector< vector<double> > massCGDSS(unsigned Ne, unsigned N)`: This function would return the total mass matrix after doing the DSS for the given domain consisting of `Ne` elements and in each element, trying to interpolate the solution in each of the element with a polynomial of degree `N`. By default, it is tried to interpolate using Lobatto nodes. And the integration is kept exact. But each of these restrictions can be easily changed.
		* `vector< vector<double> > derivativeCGDSS(unsigned Ne, unsigned N)`: This function would return the total derivative matrix after doing the DSS for the given domain consisting of `Ne` elements and in each element, trying to interpolate the solution in each of the element of degree `N`. By default, it is tried to interpolate using Lobatto nodes. And the integration is kept exact. But each of these restrictions can be easily changed. 
