#include "Plotter.h"

void plot(vector<double> & LeftVector, vector<double> & RightVector,string GraphTitle="", string LegendTitle="")
{
	if(RightVector.size()==LeftVector.size())
	{
		freopen("temp.dat","w",stdout);
		printf("# X\tY\n");
		int CurrentElement,VectorLength=LeftVector.size();
		double xmax=LeftVector[0],xmin=LeftVector[0],ymax=RightVector[0],ymin=RightVector[0];
		for(CurrentElement = 0; CurrentElement < VectorLength; CurrentElement++)
		{
			printf("%.6f\t%.6f\n",LeftVector[CurrentElement],RightVector[CurrentElement]);
			if(LeftVector[CurrentElement]>xmax)
				xmax = LeftVector[CurrentElement];
			if(LeftVector[CurrentElement]<xmin)
				xmin = LeftVector[CurrentElement];
			if(RightVector[CurrentElement]>ymax)
				ymax = RightVector[CurrentElement];
			if(RightVector[CurrentElement]<ymin)
				ymin = RightVector[CurrentElement];
		}
		if(ymax>0)
			ymax*=1.05;
		else
			ymax*=0.95;
		if(ymin>0)
			ymin*=0.95;
		else
			ymin*=1.05;
		fclose(stdout);
		freopen("temp.gnu","w",stdout);
		printf("reset\n");
		printf("set terminal jpeg interlace enhanced size 1366,768\n");
		printf("set output \"output.jpg\"\n");
		printf("set key right box\n");
		printf("set grid\n");
		printf("set title '%s'\n",GraphTitle.c_str());
		printf("set xrange[%.6f:%.6f]\n",xmin,xmax);
		printf("set yrange[%.6f:%.6f]\n",ymin,ymax);	
		printf("set ylabel 'Y'\n");
		printf("set xlabel 'X'\n");
		printf("plot 'temp.dat' title '%s' w lines ls 1\n",LegendTitle.c_str());
		fclose(stdout);
		freopen ("/dev/tty", "a", stdout);
		system("gnuplot> load 'temp.gnu'");
		cerr<<"Success, Plotting of Vectors done. Check the working directory file with output.jpg is created!!\n";		
	}
	else
		printf("ERROR: The given vectors are of different lengths, hence aborting!!\n");
}




/**END OF THE FILE.**/
