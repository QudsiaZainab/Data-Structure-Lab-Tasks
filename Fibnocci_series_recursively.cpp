#include<iostream>
 
using namespace std;
 
int Fib(int n)
{
    if((n==1)||(n==0))
    {
        return(n);
    }
    else
    {
        return(Fib(n-1)+Fib(n-2));
    }
}
 
int main()
{
    int n,i=0;
    cout<<"Input the number of terms for Fibonacci Series:";
    cin>>n;
    cout<<"\nFibonacci Series is as follows\n";
 
    while(i<n)
    {
        cout<<" "<<Fib(i);
        i++;
    }
 
    return 0;
}
 


