#include <iostream>
using namespace std;
int producto[5];
int * prod (int * a,int * b)
{
    
    for(int i=0; i<5;i++)
    {
        producto[i]=*a * *b;
        a++;
        b++;
    }
    return producto;
}
int prodPunto(int a[5], int b[5])
{
    int aux=0;
    for(int i=0; i<5;i++)
    {
        aux+=a[i]*b[i];
    }
    return aux;
}
int main(){
    int arr1[]={1,2,3,4,5};
    int arr2[]={10,20,30,40,50};
    int *p;
    p=prod(arr1,arr2);
    cout<<"producto de los arreglos por elementos"<<endl;
    for(int i=0; i<5;i++){
     cout<<*p<<endl;
     p++;
   }
    cout<<"producto punto de los dos arreglos"<<endl;
    cout<<prodPunto(arr1,arr2)<<endl;
    return 0;
}
