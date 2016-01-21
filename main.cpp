#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector<double> x,y,z;
    y = x = stepFill(-1,0.02,1);
    display(x);
    unsigned N = x.size();
    unsigned i,j;
    vector<double> gridZ = zeros(N*N);
    vector<double> gridY = zeros(N*N);
    vector<double> gridX = zeros(N*N);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            gridX[i*N + j]=x[j];
            gridY[i*N + j]=y[i];
            gridZ[i*N + j] = pow(2.7183,-0.5*((gridX[i*N+j]*gridX[i*N+j]+gridY[i*N+j]*gridY[i*N+j])));
        }
    }
    plot(gridX,gridY,gridZ);


    return 0;
}
