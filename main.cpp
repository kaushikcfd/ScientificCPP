/**
 * This is a demo file for generating the 2-D mass matrix which isobtained after the DSS.
 * The values have not been verified just the sparsity has been intuitively checked.
 * **/

#include "src/ScientificCPP/ScientificCPP.cpp"


vector<double> GridX(double L_start, double L_end,unsigned Nex, unsigned Ney, unsigned N)
{
	unsigned Np= (N+1)*(N+1)*Nex*Ney;///This would denote the number of gridpoints present.
    vector<double> gridX = zeros(Np);
    unsigned i;///Counter for the loop.
	unsigned j,k;///Denotes which of the node is going to be affected

    vector<double> Nodes = lobattoNodes(N+1);

    double dx = (L_end-L_start)/Nex;

    double Xstart,Xend;

    for(i=0;i<Ney;i++)
	{

		for(j=0;j<Nex;j++)
		{
            Xstart  =   L_start + j*dx;
            Xend    =   Xstart + dx;
			for(k=0;k<((N+1)*(N+1));k++)
				gridX[(j+i*Nex)*(N+1)*(N+1)+k] = 0.5*(Xstart+Xend) + 0.5*dx*Nodes[(k%(N+1))];
		}
	}

	return gridX;
}


vector<double> GridY(double H_start, double H_end,unsigned Nex, unsigned Ney, unsigned N)
{
	unsigned Np= (N+1)*(N+1)*Nex*Ney;///This would denote the number of gridpoints present.
    vector<double> gridY = zeros(Np);
    unsigned i;///Counter for the loop.
	unsigned j,k;///Denotes which of the node is going to be affected

    vector<double> Nodes = lobattoNodes(N+1);

    double dy = (H_end-H_start)/Ney;

    double Ystart,Yend;

    for(i=0;i<Ney;i++)
	{
        Ystart  =   H_start + i*dy;
        Yend    =   Ystart + dy;
        for(j=0;j<Nex;j++)
		{
			for(k=0;k<((N+1)*(N+1));k++)
				gridY[(j+i*Nex)*(N+1)*(N+1)+k] = 0.5*(Ystart+Yend) + 0.5*dy*Nodes[(k/(N+1))];
		}
	}

	return gridY;
}

vector< vector<double> > oneDtoTwoD(vector<double> qDG, unsigned Nex, unsigned Ney, unsigned N)
{
	vector< vector<double> > qGrid	=	zeros((N+1)*Ney,(N+1)*Nex) ;

	unsigned i1,i2,j1,j2;

	for(i1=0;i1<Ney;i1++)
	{
		for(j1=0;j1<Nex;j1++)
		{
			for(i2=0;i2<=N;i2++)
			{
				for(j2=0;j2<=N;j2++)
				{
					qGrid[i2+i1*(N+1)][j2+j1*(N+1)]=qDG[(j1+i1*Nex)*(N+1)*(N+1)+i2*(N+1)+j2];
				}
			}
		}
	}

	return qGrid;
}




int main()
{
    vector<double> X = GridY(-1,1,2,2,1);
    vector< vector<double> > grX    =   oneDtoTwoD(X,2,2,1);

    grX = DGToCG(grX,2,2,1);

    display(grX);

    return 0;

}
