#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n=1000;
    double a=0.0;
    double b=2.0; 
    double deltax=(b-a)/(n-1);
    double v = 1.0;
    double tiempo=0.0;
    double deltat=(0.25*deltax)/v;
    double upas[n];
    double x[n];
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
    upres[0]=1;
    upres[n-1]=1;

    while(tiempo <= 16)
    {
        for (int i=1;i<n-1;i++)
        {
            upres[i]=((v*deltat)/(deltax))*(upas[i]-upas[i-1])+upas[i];
            upas[i]=upres[i];
        }
        tiempo=tiempo+deltat;

        if (16.0-deltat<=tiempo && tiempo<16.0)
        {
            for(int i=0; i < n;i++)
            {
               foto5[i]=upres[i];
            }
        }
        if (12.0-deltat*0.5<=tiempo && tiempo<=12.0+deltat*0.5)
        {
            for(int i=0; i < n;i++)
            {
              foto4[i]=upres[i];
            }
        }
         if (8.0-deltat*0.5<=tiempo && tiempo<=8.0+deltat*0.5)
        {
            for(int i=0; i < n;i++)
            {
               foto3[i]=upres[i];
            }
        }
        else if (4.0-deltat*0.5<=tiempo && tiempo<=4.0+deltat*0.5)
        {
            for(int i=0; i < n;i++)
            {
               foto2[i]=upres[i];
            }
        }
        
    }
   
    for (int i=0;i<n;i++)
    {
        cout<<x[i]<<" "<<foto1[i]<<" "<<foto2[i]<<" "<<foto3[i]<<" "<<foto4[i]<<" "<<foto5[i]<<endl;
    }
    return 0;
}