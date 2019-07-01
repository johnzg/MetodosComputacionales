#include <iostream>
using namespace std;
bool esPrimo(int);
int main()
{
   int a;
   int b;
   cout<<"inserte los numeros entre los cuales se calcularan los numeros primos"<<endl;
   cin>>a;
   cin>>b;
   cout<<"Listado de primos:"<<endl;
   while(a<=b)
   {
       if(esPrimo(a))
       {
            cout<<a<<endl;
       }
       a=a+1;
   }
   return 0;
}
bool esPrimo(int n)
{
   bool aux = true;
   if(n<2)
   {
       aux=false;
   }
   for(int i = 2; i<=n/2 ;i++)
   {
       if(n%i==0)
       {
           aux=false;
       }
   }
   return aux;
}