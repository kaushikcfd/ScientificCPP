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


void plot(vector< vector<double> > XVector, vector< vector<double> > YVector, vector< vector<double> > ZVector)
{
	if((XVector.size()==YVector.size())&&(YVector.size()==ZVector.size()))
	{
        unsigned m = XVector.size();///Number of rows.
        unsigned n = XVector[0].size();///Number of columns.
		unsigned i,j;
        
        freopen("X.dat","w",stdout);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n-1;j++)
                printf("%.3f\t",XVector[i][j]);
            printf("%.3f\n",XVector[i][j]);
        }
        fclose(stdout);
        
        
        freopen("Y.dat","w",stdout);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n-1;j++)
                printf("%.3f\t",YVector[i][j]);
            printf("%.3f\n",YVector[i][j]);
        }
        fclose(stdout);
        
        
        freopen("Z.dat","w",stdout);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n-1;j++)
                printf("%.3f\t",ZVector[i][j]);
            printf("%.3f\n",ZVector[i][j]);
        }
        fclose(stdout);
        
        freopen("temp.m","w",stdout);
        printf("load X.dat;\n");
        printf("load Y.dat;\n");
        printf("load Z.dat;\n");
        printf("surf(X,Y,Z);\n");
        printf("print -djpg output.jpg;\n");
        
        fclose(stdout);
        

        freopen ("/dev/tty", "a", stdout);
		system("octave temp.m");
		system("rm -rf temp* load");
		cerr<<"Success, Plotting of Vectors done. Check the working directory file with output.jpg is created!!\n";		
	}
	else
		printf("ERROR: The given vectors are of different lengths, hence aborting!!\n");
}




/**END OF THE FILE.**/
