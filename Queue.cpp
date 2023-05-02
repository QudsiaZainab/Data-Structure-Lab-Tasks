#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* next;
    public:
    Node()
    {

    }
    Node(int value,Node*ptr)
    {
        data=value;
        next=ptr;
    }
    void setData(int value)
    {
        data=value;
    }
    int getData()
    {
        return data;
    }
    void setNext(Node* ptr)
    {
        next=ptr;
    }
    Node* getNext()
    {
        return next;
    }
    friend class Queue;
};

class Queue
{
    Node *front;
    Node *rear;
    public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    ~Queue()
    {

    }
    void enqueue(int value)
    {
        if(isEmpty())
        {
            rear = new Node(value,nullptr);
            front=rear;
        }
        else
        {
            Node *newNode = new Node;
            newNode->next=nullptr;
            newNode->data=value;
            rear->next=newNode;
            rear=newNode;
        }
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"underflow error!"<<endl;
        }
        else
        {
            Node* current = front;
            front = front->getNext();
            delete current;
        }
    }
    Node* getfront()
    {
        return front;
    }
    bool isEmpty()
    {
        return(front==NULL);
    }
    void display()
    {
        Node* ptr = getfront();
	    if (front==NULL) 
        {
		    cout << "Queue is empty" << endl;
	    }
	    else 
        {
		    while (ptr != nullptr) 
            {
			    cout << "\t" << ptr->data;
			    ptr = ptr->getNext();
		    }
	    }
    }
};

int main()
{
    Queue q;
    int key,total_elments;
    q.display();
    cout<<"enter total number of elements you want in queue: ";
    cin>>total_elments;
    for(int i=0;i<total_elments;i++)
    {
        cout<<"Enter element: ";
        cin>>key;
        q.enqueue(key);
    }
    q.display();
    q.dequeue();
    cout<<"\nDequeue.....\n";
    q.display();
}