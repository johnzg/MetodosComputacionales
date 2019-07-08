#include <iostream>
#include <fstream>
using namespace std;
double funPrime(double, double, double);
double *leapFrog2Ord(double, double, double, double, int);
int main()
{
    int n =10000;
    double h=(5.0)/(n-1);
    double *l=leapFrog2Ord(0.0,5.0,0.1,0.0,n);
    for(int i=0;i<n;i++)
    {
        cout<<h*i<<" "<<*l<<endl;
        l++;
    }
}
double fun1(double t, double x, double v)
{
    double m = 2;
    double k = 300;
    return -(k/m)*x;
}

double *leapFrog2Ord(double Ti, double Tf, double X0, double V0, int N)
{
    double deltat=(Tf-Ti)/(N-1);
    double Vi=-fun1(Ti, X0, V0)*deltat*0.5+V0;
    double *x= new double[N];
    double v[N];
    double t[N];
    v[0]=Vi;
    x[0]=X0;
    t[0]=Ti;
    
    for(int i=0;i<N;i++)
    {   
        t[i+1]=t[i]+deltat;
        v[i+1]=fun1(t[i], x[i], v[i])*deltat +v[i];
        x[i+1]=v[i+1]*deltat + x[i];
       
    }
        
    return x; 
}