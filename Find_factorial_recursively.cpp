#include<iostream>
using namespace std;

int fac(int n) 
{
    if (n <= 1) 
    {
        return 1;
    }
    else 
    {
        return n * fac(n - 1 ) ;
    }
}

int main()
{
    cout<<"Enter number to find factorial: ";
    int num;
    cin>>num;
    cout<<"Factorial of a number: "<<fac(num);
}