#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n=10000;
    double a=0.0;
    double b=2.0; 
    double deltax=(b-a)/(n-1);
    double v = 1.0;
    double tiempo=0.0;
    double deltat=(0.25*deltax)/v;
    double upas[n];
    double x[n];
    x[0]=a;
    //inicializando
    double foto1[n];
    double foto2[n];
    double foto3[n];
    double foto4[n];
    double foto5[n];
    for(int i=0; i < n ; i++)
    {
        x[i]=a+i*deltax;
        if(x[i]>=0.75 && x[i]<=1.25)
        {
            upas[i]=2.0;
        }else{
            upas[i]=1.0;
        }
        foto1[i]=upas[i];
    }
    double upres[n];

    for(tiempo=0; tiempo <= 40 ; tiempo += deltat)
    {
        tiempo=tiempo+deltat;
        for (int i=0;i<n;i++)
        {
            upres[i]=((v*deltat)/deltax)*(upas[i]-upas[i-1])+upas[i];
            upas[i]=upres[i];
            if (tiempo=10)
            {
               for(int i=0; i < n;i++)
               {
                   foto2[i]=upres[i];
               }
            }
            if (tiempo=20)
            {
               for(int i=0; i < n;i++)
               {
                   foto3[i]=upres[i];
               }
            }
            if (tiempo=30)
            {
               for(int i=0; i < n;i++)
               {
                   foto4[i]=upres[i];
               }
            }
            if (tiempo=40)
            {
               for(int i=0; i < n;i++)
               {
                   foto5[i]=upres[i];
               }
            }
        }
    }
   
    for (int i=0;i<n;i++)
    {
        cout<<x[i]<<" "<<foto1[i]<<" "<<foto2[i]<<" "<<foto3[i]<<" "<<foto4[i]<<endl;
    }
    return 0;
}