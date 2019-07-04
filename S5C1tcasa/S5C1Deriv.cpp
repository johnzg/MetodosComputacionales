#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include<math.h> 
float * derivada (float *dom, float *f,int N){

    float *der= new float[N-2];
    float h=dom[1]- dom[0];
    for(int i=0;i<N-2;i++)
    {
        der[i]=(f[i+1]-f[i])/h;
    }
    return der;
}
int main(){
    float a;
    float b;
    int n;
    //cout<<"introduzca el extremo inicial del intervalo"<<endl;
    cin>>a;
    //cout<<"introduzca el extremo final del intervalo"<<endl;
    cin>>b;
    //cout<<"introduzca el numero de puntos"<<endl;
    cin>>n;
    
    float x[n];
    float h=(b-a)/(n-1);
    for(int i=0;i<n;i++)
    {
        x[i]=a+h*i;
    }
    float funcion[n];
        
    for(int i=0;i<n;i++)
    {
        funcion[i]=cos(x[i]);
    }
    float *p;
    p=derivada(x,funcion,n);
    for(int i=0; i<n-1;i++){
     cout<< x[i]<<" "<<funcion[i] <<" " <<*p<<endl;
     p++;
    }
    
    return 0;
}
