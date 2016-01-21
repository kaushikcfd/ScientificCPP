#include "src/ScientificCPP/ScientificCPP.cpp"

int main()
{
    vector<double> x,y,z;
    y = x = stepFill(-1,0.1,1);
    unsigned N = x.size();
    unsigned i,j;
    vector< vector<double> > gridZ = zeros(N,N);
    vector< vector<double> > gridY = zeros(N,N);
    vector< vector<double> > gridX = zeros(N,N);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            gridX[i][j]=x[j];
            gridY[i][j]=y[i];
            gridZ[i][j] = pow(2.7183,-0.5*((gridX[i][j]*gridX[i][j]+gridY[i][j]*gridY[i][j])));
        }
    }
    plot(gridX,gridY,gridZ);


    return 0;
}
