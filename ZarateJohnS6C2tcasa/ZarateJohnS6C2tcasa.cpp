#include <iostream>
#include <fstream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
void caso1(double, double, double);
void caso2(double, double, double);
void caso3(double, double, double);
int main()
{
    double L=1.0; 
    double dx=0.005;
    double C = 300;
    
    caso1(L,dx,C);
    caso2(L,dx,C);
    caso3(L,dx,C);
 
    return 0;
}
void caso1(double lon, double deltax, double c)
{   
    double deltat=(0.25*deltax)/c;
    double A0=0.01;
    int n=(lon/deltax)+1;
    int m=0.1/deltat;
    double upas[n];
    double x[n];
    double foto1[n];
    double foto2[n];
    double foto3[n];
    double foto4[n];
    double foto5[n];
    for(int i=0;i < n ; i++)
    {
        
        x[i]=i*deltax;
        if(x[i]<lon*0.5)
        {
            upas[i]=2*(A0/lon)*x[i];
        }else{
            upas[i]=(-2*A0*x[i]/lon)+2*A0;
        }
        foto1[i]=upas[i];
    }
    double upres[n];
    double ufut[n];
    upres[0]=0;
    upres[n-1]=0;
    ufut[0]=0;
    ufut[n-1]=0;
    for (int i=1;i<n-1;i++)
    {
        upres[i]=(((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upas[i+1]+upas[i-1]-2*upas[i])+2*upas[i])*0.5;
    }
    

    for(int i=0; i<m;i++)
    {

        for (int k=1;k<n-1;k++)
        {
            ufut[k]=((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upres[k+1]+upres[k-1]-2*upres[k])-upas[k]+2*upres[k];
        }
        for (int k=1;k<n-1;k++)
        {
            upas[k]=upres[k];
            upres[k]=ufut[k];
        }
        

        if (i==600)
        {
            for(int j=0; j < n;j++)
            {
               foto2[j]=upres[j];
            }
        }
        if (i==1200)
        {
            for(int j=0; j < n;j++)
            {
              foto3[j]=upres[j];
            }
        }
         if (i==1800)
        {
            for(int j=0; j < n;j++)
            {
               foto4[j]=upres[j];
            }
        }
        if (i==2400)
        {
            for(int j=0; j < n;j++)
            {
               foto5[j]=upres[j];
            }
        }
        
    }
    ofstream outfile;
    outfile.open("datos1.dat");
    for (int i=0;i<n;i++)
    {
        outfile<<x[i]<<" "<<foto1[i]<<" "<<foto2[i]<<" "<<foto3[i]<<" "<<foto4[i]<<" "<<foto5[i]<<endl;
    }
    outfile.close();
}
void caso2(double lon, double deltax, double c)
{   
    double deltat=(0.25*deltax)/c;
    double A0=0.01;
    int n=(lon/deltax)+1;
    int m=0.1/deltat;
    double upas[n];
    double x[n];
    double foto1[n];
    double foto2[n];
    double foto3[n];
    double foto4[n];
    double foto5[n];
    for(int i=0;i < n ; i++)
    {
        
        x[i]=i*deltax;
        if(x[i]<lon*0.5)
        {
            upas[i]=2*(A0/lon)*x[i];
        }else{
            upas[i]=(-2*A0*x[i]/lon)+2*A0;
        }
        foto1[i]=upas[i];
    }
    double upres[n];
    double ufut[n];
    upres[0]=0;
    ufut[0]=0;
  
    for (int i=1;i<n;i++)
    {
        if(i != n-1)
        {
            upres[i]=(((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upas[i+1]+upas[i-1]-2*upas[i])+2*upas[i])*0.5;
        }else{
            upres[i]=(((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upas[i]+upas[i-1]-2*upas[i])+2*upas[i])*0.5;
        }
        
    }
    

    for(int i=0; i<m;i++)
    {

        for (int k=1;k<n;k++)
        {
            if(k != n-1)
            {
                ufut[k]=((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upres[k+1]+upres[k-1]-2*upres[k])-upas[k]+2*upres[k];
            }else
            {
                ufut[k]=((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upres[k]+upres[k-1]-2*upres[k])-upas[k]+2*upres[k];
            }
            
        }
        for (int k=1;k<n;k++)
        {
            upas[k]=upres[k];
            upres[k]=ufut[k];
        }
        

        if (i==600)
        {
            for(int j=0; j < n;j++)
            {
               foto2[j]=upres[j];
            }
        }
        if (i==1200)
        {
            for(int j=0; j < n;j++)
            {
              foto3[j]=upres[j];
            }
        }
         if (i==1800)
        {
            for(int j=0; j < n;j++)
            {
               foto4[j]=upres[j];
            }
        }
        if (i==2400)
        {
            for(int j=0; j < n;j++)
            {
               foto5[j]=upres[j];
            }
        }
        
    }
    ofstream outfile;
    outfile.open("datos2.dat");
    for (int i=0;i<n;i++)
    {
        outfile<<x[i]<<" "<<foto1[i]<<" "<<foto2[i]<<" "<<foto3[i]<<" "<<foto4[i]<<" "<<foto5[i]<<endl;
    }
    outfile.close();
}
void caso3(double lon, double deltax, double c)
{   
    double deltat=(0.25*deltax)/c;
    double A0=0.01;
    int n=(lon/deltax)+1;
    int m=0.1/deltat;
    double tiempo=0.0;
    double upas[n];
    double x[n];
    double foto1[n];
    double foto2[n];
    double foto3[n];
    double foto4[n];
    double foto5[n];
    for(int i=0;i < n ; i++)
    {
        
        x[i]=i*deltax;
        upas[i]=0;
        foto1[i]=upas[i];
    }
    double upres[n];
    double ufut[n];
    upres[0]=0;
    ufut[0]=0;
  
    for (int i=1;i<n;i++)
    {
        if(i != n-1)
        {
            upres[i]=(((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upas[i+1]+upas[i-1]-2*upas[i])+2*upas[i])*0.5;
        }else{
            upres[i]=(((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upas[i]+upas[i-1]-2*upas[i])+2*upas[i])*0.5;
        }
    }
    

    for(int i=0; i<m;i++)
    {

        for (int k=1;k<n;k++)
        {
            if(k != n-1)
            {
                ufut[k]=((c*deltat)/(deltax))*((c*deltat)/(deltax))*(upres[k+1]+upres[k-1]-2*upres[k])-upas[k]+2*upres[k];
            }else
            {
                ufut[k]=A0*sin(M_PI*3.9*tiempo*c/lon);
            }
            
        }
        tiempo=tiempo+deltat;
        for (int k=1;k<n;k++)
        {
            upas[k]=upres[k];
            upres[k]=ufut[k];
        }
        

        if (i==600)
        {
            for(int j=0; j < n;j++)
            {
               foto2[j]=upres[j];
            }
        }
        if (i==1200)
        {
            for(int j=0; j < n;j++)
            {
              foto3[j]=upres[j];
            }
        }
         if (i==1800)
        {
            for(int j=0; j < n;j++)
            {
               foto4[j]=upres[j];
            }
        }
        if (i==2400)
        {
            for(int j=0; j < n;j++)
            {
               foto5[j]=upres[j];
            }
        }
        
    }
    ofstream outfile;
    outfile.open("datos3.dat");
    for (int i=0;i<n;i++)
    {
        outfile<<x[i]<<" "<<foto1[i]<<" "<<foto2[i]<<" "<<foto3[i]<<" "<<foto4[i]<<" "<<foto5[i]<<endl;
    }
    outfile.close();
}