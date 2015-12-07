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
	double dt = M_PI/200;
	int n = tmax/dt;
	double x_ana;	
	double dx_ana;

	double f1[2];
	double f2[2];
	

	f1[0]=x0;f1[1]=dx0;
	f2[0]=x0;f2[1]=dx0;
	

	eulerf(f1,n,dt);
	eulerb(f2,n,dt);

	ofstream outputosc("ana.txt");
	for(int i=0;i<n;i++)
	{
	 x_ana = cos(i*dt);
	 dx_ana =(-1.0)*sin(i*dt);
	 outputosc << (i+1)*dt << "\t" << x_ana << "\t" << dx_ana << endl;
	}
	outputosc.close();
}

void eulerf(double* f1, int n, double dt)
{
	double a=f1[1];
	ofstream outputf("eulerf.txt");
	for(int i=1;i<n;i++)
	{
	 f1[1]=f1[1]+dt*(-1.0)*f1[0];
	 f1[0]=f1[0]+dt*a;
	 a=f1[1];
	 outputf << i*dt  << "\t" << f1[0] << "\t" << f1[1] << endl;
	}
	outputf.close();

}

void eulerb(double* f2, int n, double dt)
{	
	double b = f2[0];
	ofstream outputb("eulerb.txt");
	for(int i=1;i<n;i++)
	{
	 
	 f2[0]=(f2[1]*dt + f2[0])/(1+pow(dt,2));
	 f2[1]=(f2[1] - dt*b)/(1+pow(dt,2));
	 b = f2[0];
	 outputb << i*dt << "\t" << f2[0] << "\t" << f2[1] << endl;
	}
	outputb.close();
}





