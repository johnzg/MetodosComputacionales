#include <iostream>
#include <fstream>
using namespace std;
double funPrime(double, double);
double *euler(double, double,double,int);
double *rungeKutta(double, double, double inicial, int);
int main()
{
    int n =10000;
    double h=(2.0)/(n-1);
    double *e=euler(0.0,2.0,1.0,n);
    double *r=rungeKutta(0.0,2.0,1.0,n);
    ofstream outfile;
    outfile.open("datos.txt");
    for(int i=0;i<n;i++)
    {
        outfile<<h*i<<" "<<*e<<" "<<*r<<endl;
        e++;
        r++;
    }
    outfile.close();
}
double funPrime(double x, double y)
{
    return -y;
}
double *euler(double a, double b, double inicial, int N)
{
    double *yEuler=new double[N];
    double h=(b-a)/(N-1);
    double x[N];
    for(int i=0;i<N;i++)
    {
        x[i]=a+h*i;
    }
    yEuler[0]=inicial;
    for(int i=1;i<N;i++)
    {
        yEuler[i]=yEuler[i-1]+h*funPrime(x[i-1],yEuler[i-1]);
    }
    
    return yEuler;
}
double *rungeKutta(double a, double b, double inicial, int N)
{
    double x[N];
    double h=(b-a)/(N-1);
    for(int i=0;i<N;i++)
    {
        x[i]=a+h*i;
    }
    double *yRunge= new double[N];
    yRunge[0]=inicial;
    for (int i=1; i<N; i++ )
    {
        double k1=h*funPrime(x[i-1],yRunge[i-1]);
        double k2=h*funPrime(x[i-1]+0.5*h,yRunge[i-1]+0.5*k1);
        double k3=h*funPrime(x[i-1]+0.5*h,yRunge[i-1]+0.5*k2);
        double k4=h*funPrime(x[i-1]+h,yRunge[i-1]+k3);
        yRunge[i]=yRunge[i-1]+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
    }     
    return yRunge;
}