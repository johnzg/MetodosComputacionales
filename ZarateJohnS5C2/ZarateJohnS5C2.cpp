#include <iostream>
using namespace std;
double funPrime(double, double);
int main()
{
    int n = 1000;
    double h=2.0/(n-1);
    
    double x[n];
    for(int i=0;i<n;i++)
    {
        x[i]=h*i;
    }
    double yEuler[n];
    yEuler[0]=1.0;
    for(int i=1;i<n;i++)
    {
        yEuler[i]=yEuler[i-1]+h*funPrime(x[i-1],yEuler[i-1]);
    }
    
    double yRunge[n];
    yRunge[0]=1;
    for (int i=1; i<n; i++ )
    {
        double k1=h*funPrime(x[i-1],yRunge[i-1]);
        double k2=h*funPrime(x[i-1]+0.5*h,yRunge[i-1]+0.5*k1);
        double k3=h*funPrime(x[i-1]+0.5*h,yRunge[i-1]+0.5*k2);
        double k4=h*funPrime(x[i-1]+h,yRunge[i-1]+k3);
        yRunge[i]=yRunge[i-1]+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
    }
        
        
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" "<<yEuler[i]<<" "<<yRunge[i]<<endl;
    }
    
    
}
double funPrime(double x, double y)
{
    return -y;
}