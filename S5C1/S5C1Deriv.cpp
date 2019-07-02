#include <iostream>
using namespace std;
#include<math.h> 
float f(float x)
{
    return x*x;
}
float * derCentral (float ini, float fin, int N){
    float x[N];
    float h=(fin-ini)/N;
    for(int i=0;i<N;i++)
    {
        x[i]=ini+h*i
    }
    float der[N-2];
    for(int i=0;i<N-2;i++)
    {
        der[i]=(f(x[i+2])-f(x[i]))/2*h
    }
    return *der;
}
int main(){
    float a;
    float b;
    int n;
    cin>>a;
    cin>>b;
    cin>>n;
    return 0;
}
