#include <iostream>
#include <fstream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
void caso1(double, double, double);
void caso2(double, double, double);
void caso3(double, double, double);
double gauss(double, double, double, double);
void tambor(double, double, double, double);

int main()
{
    double L=1.0; 
    double dx=0.005;
    double dy=0.005;
    double C = 300;
    
    caso1(L,dx,C);
    caso2(L,dx,C);
    caso3(L,dx,C);
    tambor(L,dx,dy,C);
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
double gauss(double x, double y, double sigma, double amplitud)
{
    return (amplitud/(2*M_PI*sigma*sigma))*exp(-(x*x+y*y)/(2*sigma*sigma));
}
void tambor(double lon, double deltax, double deltay, double c)
{   
    double deltat=(0.25*deltax)/c;
    double A0=0.01;
    int n=(lon/deltax)+1;
    int m=(lon/deltay)+1;
    int l=0.1/deltat;
    double tiempo=0.0;
    double upas[n][m];
    double upres[n][m];
    double ufut[n][m];
    double x[n];
    double y[m];
    double foto1[n][m];
    double foto2[n][m];
    double foto3[n][m];
    double foto4[n][m];
    double foto5[n][m];
    for(int i=0;i < n ; i++)
    {
        x[i]=i*deltax;
        upres[i][m-1]=0;
        upres[i][0]=0;
        upas[i][m-1]=0;
        upas[i][0]=0;
        ufut[i][m-1]=0;
        ufut[i][0]=0;
    }
    for(int i=0;i < m ; i++)
    {
        y[i]=i*deltay;
        upres[n-1][i]=0;
        upres[0][i]=0;
        upas[n-1][i]=0;
        upas[0][i]=0;
        ufut[n-1][i]=0;
        ufut[0][i]=0;
    }

    for (int i=1;i<n-1;i++)
    {
        for (int j=1;j<m-1;j++)
        {
            upas[i][j]=gauss(x[i]-lon*0.5, y[j]-lon*0.5, 0.1, A0 );
            foto1[i][j]=upas[i][j];
        }
    }
    double r1=((c*deltat)/(deltax))*((c*deltat)/(deltax));
    double r2=((c*deltat)/(deltay))*((c*deltat)/(deltay));
    for (int i=1;i<n-1;i++)
    {
        for (int k=1;k<m-1;k++)
        {
            double aux = r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+2*upas[i][k];
            upres[i][k]=aux*0.5;
        }
    }

    for(int j=0; j<l;j++)
    {

        for (int i=1;i<n-1;i++)
        {
            for (int k=1;k<m-1;k++)
            {
                ufut[i][k]=r1*(upres[i+1][k]+upres[i-1][k]- 2*upres[i][k]) + r2*(upres[i][k+1]+upres[i][k-1]- 2*upres[i][k])+2*upres[i][k]-upas[i][k];
            }
        }
        
        for (int i=1;i<n-1;i++)
        {
            for (int k=1;k<m-1;k++)
            {
                upas[i][k]=upres[i][k];
                upres[i][k]=ufut[i][k];
            }
        }        

        if (j==1000)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<m;k++)
                {
                    foto2[i][k]=upres[i][k];
                }
            }
        }
        if (j==2000)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<m;k++)
                {
                    foto3[i][k]=upres[i][k];
                }
            }
        }
         if (j==3000)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<m;k++)
                {
                    foto4[i][k]=upres[i][k];
                }
            }
        }
        if (j==4000)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<m;k++)
                {
                    foto5[i][k]=upres[i][k];
                }
            }
        }
        
    }
    ofstream outfile;
    outfile.open("tambor.dat");
    for (int i=0;i<n;i++)
    {
        outfile<<x[i]<<" "<<y[i];
        for (int j=0;j<m;j++)
        {
            outfile<<" "<<foto1[i][j];
        }
        for (int j=0;j<m;j++)
        {
            outfile<<" "<<foto2[i][j];
        }
        for (int j=0;j<m;j++)
        {
            outfile<<" "<<foto3[i][j];
        }
        for (int j=0;j<m;j++)
        {
            outfile<<" "<<foto4[i][j];
        }
        for (int j=0;j<m;j++)
        {
            outfile<<" "<<foto5[i][j];
        }
        outfile<<endl;     
    }
    
    outfile.close();
}