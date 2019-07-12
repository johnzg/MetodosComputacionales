#include <iostream>
#include <fstream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
void difusionfijas(double, double, double);
void difusionLibres(double, double, double);
void difusionPeriodica(double, double, double);
void difusionCuadradoMantenidoFijas(double, double, double);

int main()
{
    double L=1.0; 
    double dx=0.01;
    double V = 1.0/(10.0*10.0*10.0*10.0);
    
    difusionfijas(L,dx,V);
    difusionLibres(L, dx, V);
    difusionPeriodica(L,dx,V);
    difusionCuadradoMantenidoFijas(L,dx,V);
    return 0;
}

void difusionfijas(double lon, double deltax, double v)
{   
    double deltat=(0.25*deltax*deltax)/v;
    double deltay=deltax;
    int n=(lon/deltax)+1;
    int l=(2600/deltat)+1;
    double tiempo=0.0;
    double tProm[l];
    double upas[n][n];
    double upres[n][n];
    double x[n];
    double y[n];
    double foto1[n][n];
    double foto2[n][n];
    double foto3[n][n];
    for(int i=0;i < n ; i++)
    {
        x[i]=i*deltax;
        y[i]=i*deltay;

    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(x[i]>=0.2 && x[i]<=0.4 && y[j]>=0.4 && y[j]<=0.6)
            {
                upas[i][j]=100.0;
            }else{
                upas[i][j]=50.0;
            }
            foto1[i][j]=upas[i][j];
      
        }
    }
    double aux=0.0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            aux+=upas[i][j];
        }
    }
    tProm[0]=aux/(n*n);
    double r1=(v*deltat)/(deltax*deltax);
    double r2=(v*deltat)/(deltay*deltay);
    for(int j=0; j<l ; j++)
    {

        for (int i=1;i<n-1;i++)
        {
            for (int k=1;k<n-1;k++)
            {
                upres[i][k]=r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
            }
        }
        tiempo=tiempo+deltat;

        for (int i=1;i<n-1;i++)
        {
            for (int k=1;k<n-1;k++)
            {
                upas[i][k]=upres[i][k];
            }
        }        
        aux=0.0;
        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                aux+=upas[i][k];
            }
        }
        tProm[j]=aux/(n*n);
        if (tiempo==100)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<n;k++)
                {
                    foto2[i][k]=upres[i][k];
                }
            }
        }
        if (tiempo==2500)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<n;k++)
                {
                    foto3[i][k]=upres[i][k];
                }
            }
        }
        
    }
    ofstream outfile;
    outfile.open("difusionfijas.dat");
    for (int i=0;i<n;i++)
    {
        outfile<<x[i]<<" "<<y[i];
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto1[i][j];
        }
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto2[i][j];
        }
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto3[i][j];
        }

        outfile<<endl;     
    }
    
    outfile.close();
    outfile.open("difusionfijastprom.dat");
    for(int i=0;i<l;i++)
    {
        outfile<<i*deltat<<" "<<tProm[i]<<endl;
    }
}
void difusionLibres(double lon, double deltax, double v)
{   
    double deltat=(0.25*deltax*deltax)/v;
    double deltay=deltax;
    int n=(lon/deltax)+1;
    int l=(2600/deltat)+1;
    double tiempo=0.0;
    double tProm[l];
    double upas[n][n];
    double upres[n][n];
    double x[n];
    double y[n];
    double foto1[n][n];
    double foto2[n][n];
    double foto3[n][n];
    for(int i=0;i < n ; i++)
    {
        x[i]=i*deltax;
        y[i]=i*deltay;

    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(x[i]>=0.2 && x[i]<=0.4 && y[j]>=0.4 && y[j]<=0.6)
            {
                upas[i][j]=100.0;
            }else{
                upas[i][j]=50.0;
            }
            foto1[i][j]=upas[i][j];
      
        }
    }
    double aux=0.0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            aux+=upas[i][j];
        }
    }
    tProm[0]=aux/(n*n);
    double r1=(v*deltat)/(deltax*deltax);
    double r2=(v*deltat)/(deltay*deltay);
    for(int j=0; j<l ; j++)
    {

        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                if (i ==0 && k==0)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[i][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k]- 2*upas[i][k])+upas[i][k];
                    
                }else if(i ==n-1 && k==n-1)
                {
                    upres[i][k]=r1*(upas[i][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                    
                }else if(i ==0 && k==n-1)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[i][k]- 2*upas[i][k]) + r2*(upas[i][k]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                    
                }else if(i ==n-1 && k==0)
                {
                    upres[i][k]=r1*(upas[i][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k]- 2*upas[i][k])+upas[i][k];
                    
                }else if(i==0)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[i][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                    
                }else if(k==0)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k]- 2*upas[i][k])+upas[i][k];
                }else if(i==n-1)
                {
                    upres[i][k]=r1*(upas[i][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                }else if(k==n-1)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                }else{
                    upres[i][k]=r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                    
                }
                
            }
        }
        tiempo=tiempo+deltat;

        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                upas[i][k]=upres[i][k];
            }
        }        
        aux=0.0;
        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                aux+=upas[i][k];
            }
        }
        tProm[j]=aux/(n*n);
        if (tiempo==100)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<n;k++)
                {
                    foto2[i][k]=upres[i][k];
                }
            }
        }
        if (tiempo==2500)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<n;k++)
                {
                    foto3[i][k]=upres[i][k];
                }
            }
        }
        
    }
    ofstream outfile;
    outfile.open("difusionlibres.dat");
    for (int i=0;i<n;i++)
    {
        outfile<<x[i]<<" "<<y[i];
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto1[i][j];
        }
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto2[i][j];
        }
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto3[i][j];
        }

        outfile<<endl;     
    }
    
    outfile.close();
    outfile.open("difusionlibrestprom.dat");
    for(int i=0;i<l;i++)
    {
        outfile<<i*deltat<<" "<<tProm[i]<<endl;
    }
}
void difusionPeriodica(double lon, double deltax, double v)
{   
    double deltat=(0.25*deltax*deltax)/v;
    double deltay=deltax;
    int n=int(lon/deltax)+1;
    int l=int(2600/deltat)+1;
    double tiempo=0.0;
    double tProm[l];
    double upas[n][n];
    double upres[n][n];
    double x[n];
    double y[n];
    double foto1[n][n];
    double foto2[n][n];
    double foto3[n][n];
    for(int i=0;i < n ; i++)
    {
        x[i]=i*deltax;
        y[i]=i*deltay;
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(x[i]>=0.2 && x[i]<=0.4 && y[j]>=0.4 && y[j]<=0.6)
            {
                upas[i][j]=100.0;
            }else{
                upas[i][j]=50.0;
            }
            foto1[i][j]=upas[i][j];
      
        }
    }
    double aux=0.0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            aux+=upas[i][j];
        }
    }
    tProm[0]=aux/(n*n);
    double r1=(v*deltat)/(deltax*deltax);
    double r2=(v*deltat)/(deltay*deltay);
    for(int j=0; j<l ; j++)
    {

        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                if (i ==0 && k==0)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[n-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][n-1]- 2*upas[i][k])+upas[i][k];
                    
                }else if(i ==n-1 && k==n-1)
                {
                    upres[i][k]=r1*(upas[0][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][0]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                    
                }else if(i ==0 && k==n-1)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[n-1][k]- 2*upas[i][k]) + r2*(upas[i][0]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                    
                }else if(i ==n-1 && k==0)
                {
                    upres[i][k]=r1*(upas[0][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][n-1]- 2*upas[i][k])+upas[i][k];
                    
                }else if(i==0)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[n-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                    
                }else if(k==0)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][n-1]- 2*upas[i][k])+upas[i][k];
                }else if(i==n-1)
                {
                    upres[i][k]=r1*(upas[0][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                }else if(k==n-1)
                {
                    upres[i][k]=r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][0]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                }else{
                    upres[i][k]=r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                    
                }
                
            }
        }
        tiempo=tiempo+deltat;

        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                upas[i][k]=upres[i][k];
            }
        }        
        aux=0.0;
        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                aux+=upas[i][k];
            }
        }
        tProm[j]=aux/(n*n);
        if (tiempo==100)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<n;k++)
                {
                    foto2[i][k]=upres[i][k];
                }
            }
        }
        if (tiempo==2500)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<n;k++)
                {
                    foto3[i][k]=upres[i][k];
                }
            }
        }
        
    }
    ofstream outfile;
    outfile.open("difusionperiodicas.dat");
    for (int i=0;i<n;i++)
    {
        outfile<<x[i]<<" "<<y[i];
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto1[i][j];
        }
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto2[i][j];
        }
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto3[i][j];
        }

        outfile<<endl;     
    }
    
    outfile.close();
    outfile.open("difusionperiodicastprom.dat");
    for(int i=0;i<l;i++)
    {
        outfile<<i*deltat<<" "<<tProm[i]<<endl;
    }
}

void difusionCuadradoMantenidoFijas(double lon, double deltax, double v)
{   
    double deltat=(0.25*deltax*deltax)/v;
    double deltay=deltax;
    int n=(lon/deltax)+1;
    int l=(2600/deltat)+1;
    double tiempo=0.0;
    double tProm[l];
    double upas[n][n];
    double upres[n][n];
    double x[n];
    double y[n];
    double foto1[n][n];
    double foto2[n][n];
    double foto3[n][n];
    for(int i=0;i < n ; i++)
    {
        x[i]=i*deltax;
        y[i]=i*deltay;
        
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(x[i]>=0.2 && x[i]<=0.4 && y[j]>=0.4 && y[j]<=0.6)
            {
                upas[i][j]=100.0;
            }else{
                upas[i][j]=50.0;
            }
            foto1[i][j]=upas[i][j];
      
        }
    }
    double aux=0.0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            aux+=upas[i][j];
        }
    }
    tProm[0]=aux/(n*n);
    double r1=(v*deltat)/(deltax*deltax);
    double r2=(v*deltat)/(deltay*deltay);
    for(int j=0; j<l ; j++)
    {

        for (int i=1;i<n-1;i++)
        {
            for (int k=1;k<n-1;k++)
            {
                bool auxiliar=(x[i]>=0.2 && x[i]<=0.4 && y[k]>=0.4 && y[k]<=0.6);
                if(x[i]>=0.2 && x[i]<=0.4 && y[k]>=0.4 && y[k]<=0.6)
                {
                    upres[i][k]=100;
                }else{
                    upres[i][k]=r1*(upas[i+1][k]+upas[i-1][k]- 2*upas[i][k]) + r2*(upas[i][k+1]+upas[i][k-1]- 2*upas[i][k])+upas[i][k];
                }
            }
            
        }
        tiempo=tiempo+deltat;

        for (int i=1;i<n-1;i++)
        {
            for (int k=1;k<n-1;k++)
            {
                    upas[i][k]=upres[i][k];
                    
            }
        }        
        aux=0.0;
        for (int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                aux+=upas[i][k];
            }
        }
        tProm[j]=aux/(n*n);
        if (tiempo==100)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<n;k++)
                {
                    foto2[i][k]=upres[i][k];
                }
            }
        }
        if (tiempo==2500)
        {
            for (int i=0;i<n;i++)
            {
                for (int k=0;k<n;k++)
                {
                    foto3[i][k]=upres[i][k];
                }
            }
        }
        
    }
    ofstream outfile;
    outfile.open("difusionCuadradoMantenidoFijas.dat");
    for (int i=0;i<n;i++)
    {
        outfile<<x[i]<<" "<<y[i];
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto1[i][j];
        }
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto2[i][j];
        }
        for (int j=0;j<n;j++)
        {
            outfile<<" "<<foto3[i][j];
        }

        outfile<<endl;     
    }
    
    outfile.close();
    outfile.open("difusionCuadradoMantenidoFijastprom.dat");
    for(int i=0;i<l;i++)
    {
        outfile<<i*deltat<<" "<<tProm[i]<<endl;
    }
}