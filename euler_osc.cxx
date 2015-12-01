#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void eulerf(double*,int,double);
void eulerb(double*,int,double);


int main()
{

	double x0 = 1.0;
	double dx0 = 0.0;
	double tmax = 20*M_PI;
	double dt = M_PI/10;
	int n = tmax/dt;
	double x_ana;	
	double dx_ana;

	double f1[2];
	double f2[2];
	

	f1[1]=x0;f1[2]=dx0;
	f2[1]=x0;f2[2]=dx0;
	

	eulerf(f1,n,dt);
	eulerb(f2,n,dt);

	ofstream outputosc("ana.txt");
	for(int i=0;i<n;i++)
	{
	 x_ana = sin(i*dt);
	 dx_ana = cos(i*dt);
	 outputosc << x_ana << "\t" << dx_ana << endl;
	}
	outputosc.close();
}

void eulerf(double* f1, int n, double dt)
{
	double a=f1[2];
	ofstream outputf("eulerf.txt");
	for(int i=1;i<n;i++)
	{
	 f1[2]=f1[2]+dt*(-1.0)*f1[1];
	 f1[1]=f1[1]+dt*a;
	 a=f1[2];
	 outputf << f1[1] << "\t" << f1[2] << endl;
	}
	outputf.close();

}

void eulerb(double* f2, int n, double dt)
{	
	double b = f2[1];
	ofstream outputb("eulerb.txt");
	for(int i=1;i<n;i++)
	{
	 
	 f2[1]=(f2[2]*dt + f2[1])/(1+pow(dt,2));
	 f2[2]=(f2[2] - dt*b)/(1+pow(dt,2));
	 b = f2[1];
	 outputb << f2[1] << "\t" << f2[2] << endl;
	}
	outputb.close();
}





