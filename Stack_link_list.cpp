#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* next;
    public:
    Node(int x,Node* ptr):data(x),next(ptr)
    {
    }
    Node()
    {
    }
    int getData()
    {
        return data;
    }
    Node* getNext()
    {
        return next;
    }
    void setData(int x)
    {
        data = x;
    }
    void setNext(Node *ptr)
    {
        next = ptr;
    }
};

class Stack
{
    Node *top;
    public:
    Stack()
    {
        top=nullptr;
    }
    Node *getTop()
    {
        return top;
    }
    void Push(int x)
    {
        Node *topptr = new Node(x,top);
        top=topptr;
    }
    int Pop()
    {
        if(isEmpty())
        {
            cout<<"\nstack is empty.\n";
            return 1;
        }
        else
        {
            Node* current = getTop();
            top = top->getNext();
            int x = current->getData();
            delete current;
            return x;
        }
    }
    bool isEmpty()
    {
        return (getTop() == NULL);
    }
    int Top()
    {
        return top->getData();
    }
};

int main()
{
    Stack S;
    cout<<"\nPopping the value: \n";S.Pop();
    S.Push(5);
    cout<<"\nTop of the stack is: "<<S.Top();
    S.Push(6);
    cout<<"\nTop of the stack is: "<<S.Top();
    S.Push(9);
    cout<<"\nTop of the stack is: "<<S.Top();
    S.Push(1);
    cout<<"\nTop of the stack is: "<<S.Top();
    cout<<"\nPopping the value: \n"<<S.Pop();
    cout<<"\nPopping the value: \n"<<S.Pop();
    cout<<"\nTop of the stack is: "<<S.Pop();
}