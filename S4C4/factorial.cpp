#include <iostream>
using namespace std;
int factorial(int);
int main()
{
   int a;
   a=7;
   cout<<factorial(a)<<endl;
   return 0;
}
int factorial(int n)
{
   if(n==0)
   {
       return 1;
   }else{
       int aux=n*factorial(n-1);
       return aux;
   }
    
}
