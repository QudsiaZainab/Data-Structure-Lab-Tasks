#include<iostream>
#define size 10
using namespace std;
class Stack
{
    int array[size];
    int top;
    public:
    Stack()
    {
        top=-1;
    }
    bool stack_empty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool stack_full()
    {
        if(top==size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(float x)
    {
        if(!stack_full())
        {
            top++;
            array[top]=x;
        }
        else
        {
            cout<<"\nStack is full.\n";
        }
    }
    int pop()
    {
        if(!stack_empty())
        {
            top--;
            return array[top+1];
        }
        else
        {
            cout<<"\nStack is empty.\n";
            return 1;
        }
    }
    int Top()
    {
        if(!stack_empty())
        {
            return array[top];
        }
        return -1;
    }
    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<array[i]<<" ";
        }
    }
};

int main()
{
    Stack S;
    int key;

    cout<<"Enter "<<size<<" values to be pushed on stack: ";
    for(int i=0;i<size;i++)
    {
        cin>>key;
        S.push(key);
    }
    S.display();

    cout<<"\nEnter number of elements you want to pop from stack (1-10): ";
    cin>>key;
    while(1)
    {
        if(key<1 || key>size)
        {
            cout<<"Invalid input! You can enter from 1-10: ";
            cin>>key;
        }
        else
        {
            break;
        }
    }

    int *popped_elements=new int[key];
    int sum = 0;
    for(int i=0;i<key;i++)
    {
        popped_elements[i]=S.pop();
        sum=sum + popped_elements[i];
    }
    cout<<"\nValues popped from stack are: \n";
    for(int i=0;i<key;i++)
    {
        cout<<popped_elements[i]<<" ";
    }
    cout<<"\nAverage of popped elements is: "<<sum/key;
}