#include "Plotter.h"

void plot(vector<double> LeftVector, vector<double> RightVector,string GraphTitle="", string LegendTitle="")
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
		system("rm -rf temp* load");
		cerr<<"Success, Plotting of Vectors done. Check the working directory file with output.jpg is created!!\n";		
	}
	else
		printf("ERROR: The given vectors are of different lengths, hence aborting!!\n");
}



void plot(vector<double> LeftVector, vector< vector<double> > RightVector,string GraphTitle, vector<string> LegendTitle)
{
	unsigned n = LeftVector.size();
	unsigned m = RightVector.size();
	unsigned i,j;///Counter for the loop
	string FileName ;
	freopen("temp0.dat","w",stdout);
	printf("# X\tY\n");
	
	for(i = 0; i < n; i++)
		printf("%.6f\t%.6f\n",LeftVector[i],RightVector[0][i]);
	fclose(stdout);
	freopen("temp.gnu","w",stdout);
	printf("reset\n");
	printf("set terminal jpeg interlace enhanced size 1366,768\n");
	printf("set output \"output.jpg\"\n");
	printf("set key right box\n");
	printf("set grid\n");
	printf("set title '%s'\n",GraphTitle.c_str());
	printf("set ylabel 'Y'\n");
	printf("set xlabel 'X'\n");
	printf("plot 'temp0.dat' title '%s' w lines ls 1",LegendTitle[0].c_str());
	
	for(i=1;i<m;i++)
	{
		if(RightVector[i].size()==n)
		{
			FileName = "temp" + to_string(i) + ".dat";
			freopen(FileName.c_str(),"w",stdout);
			printf("# X\tY\n");
			
			for(j = 0; j < n; j++)
				printf("%.6f\t%.6f\n",LeftVector[j],RightVector[i][j]);
			
			fclose(stdout);

			freopen("temp.gnu","a",stdout);
			
			printf(", 'temp%d.dat' title '%s' w lines ls %d",i,LegendTitle[i].c_str(),i+1);

			fclose(stdout);
		}
		else
			printf("ERROR: The given vectors are of different lengths, hence aborting!!\n");		
	}
	

	freopen ("/dev/tty", "a", stdout);
	system("gnuplot> load 'temp.gnu'");
	system("rm -rf temp* load");
	cerr<<"Success, Plotting of Vectors done. Check the working directory file with output.jpg is created!!\n";		
}


void plot(vector<double> XVector, vector<double> YVector, vector<double> ZVector)
{
	if((XVector.size()==YVector.size())&&(YVector.size()==ZVector.size()))
	{
		freopen("temp.dat","w",stdout);
		printf("# X\tY\tZ\n");
		int CurrentElement,VectorLength=ZVector.size();
		double zmax=ZVector[0],zmin=ZVector[0];
		for(CurrentElement = 0; CurrentElement < VectorLength; CurrentElement++)
		{
			printf("%.6f\t%.6f\t%.6f\n",XVector[CurrentElement],YVector[CurrentElement],ZVector[CurrentElement]);
			if(ZVector[CurrentElement]>zmax)
				zmax = ZVector[CurrentElement];
			if(ZVector[CurrentElement]<zmin)
				zmin = ZVector[CurrentElement];
		}
		if(zmax>0)
			zmax*=1.05;
		else
			zmax*=0.95;
		if(zmin>0)
			zmin*=0.95;
		else
			zmin*=1.05;
		fclose(stdout);
		freopen("temp.gnu","w",stdout);
		printf("reset\n");
		printf("set terminal pdf color solid interlace enhanced size 1366,768\n");
		printf("set output \"output.pdf\"\n");
		printf("set key right box\n");
		printf("set grid\n");
		printf("set zrange[%.6f:%.6f]\n",zmin,zmax);
		printf("set ylabel 'Y'\n");
		printf("set xlabel 'X'\n");
		printf("set zlabel 'Z'\n");
        printf("set isosamples 150, 150\n");
        printf("unset surface\n");
        printf("set pm3d implicit at s\n");
        printf("set pm3d scansbackward\n## Last datafile plotted: \"$PALETTE\" \n");
        
        printf("splot 'temp.dat' using 1\n");
		fclose(stdout);
		freopen ("/dev/tty", "a", stdout);
		system("gnuplot> load 'temp.gnu'");
		//system("rm -rf temp* load");
		cerr<<"Success, Plotting of Vectors done. Check the working directory file with output.jpg is created!!\n";		
	}
	else
		printf("ERROR: The given vectors are of different lengths, hence aborting!!\n");
}




/**END OF THE FILE.**/
