#include<iostream>
using namespace std;
class stack
{
    int size;
    float *array;
    int top;
    public:
    stack()
    {
        size=3;
        array = new float[size];
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
    void push(int x)
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
    float Top()
    {
        if(!stack_empty())
        {
            return array[top];
        }
        return -1;
    }
};

int main()
{
    stack S;
    cout<<"\nPopping the value: \n";S.pop();
    S.push(5.7);
    cout<<"\nTop of the stack is: "<<S.Top();
    S.push(6.9);
    cout<<"\nTop of the stack is: "<<S.Top();
    S.push(9.9);
    cout<<"\nTop of the stack is: "<<S.Top();
    S.push(1.9);
    cout<<"\nTop of the stack is: "<<S.Top();
    cout<<"\nPopping the value: \n"<<S.pop();
    cout<<"\nPopping the value: \n"<<S.pop();
    cout<<"\nTop of the stack is: "<<S.Top();
}