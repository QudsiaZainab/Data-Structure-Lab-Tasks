#include<iostream>
#define size 5
using namespace std;

class CircularQueue
{
    private:
    int queueArray[size]; 
    int front;
    int rear;
    public:
    CircularQueue();
    bool IsFull ();
    bool IsEmpty();
    void enqueue(int num);
    int dequeue();
    void displayQueue();
};

bool CircularQueue::IsEmpty()
{
    if (front==-1)
        return true ; // we can check “ rear ” too
    else
        return false ;
}

bool CircularQueue::IsFull()
{
    if ( ( (rear+1)%size ) == front )
        return true ;
    else
        return false ;
}

void CircularQueue ::enqueue(int num)
{
    if(IsFull ( ) ) 
    {
        cout <<" Over flow\n" ;
        return;
    }
    if (IsEmpty())
    rear = front = 0;
    else
    rear=(rear+1) % size;
    queueArray[rear] = num;
}

int CircularQueue ::dequeue()
{
    if ( IsEmpty() ) 
    {
        cout <<" Under flow\n" ;
        return 0;
    }
    int ReturnValue = queueArray[front];
    if ( front == rear ) 
        front = rear = - 1 ;
    else
        front = (front+1) % size;
    return ReturnValue;
}

CircularQueue::CircularQueue() //constructor
{
    front = - 1 ;
    rear = - 1 ;
}

void CircularQueue::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",queueArray[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", queueArray[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", queueArray[i]);
    }
}

int main()
{
    CircularQueue cq1,cq2;
    int value;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter "<<i+1<<" value in first circular queue: ";
        cin>>value;
        cq1.enqueue(value);
    }
    cout<<"\nDisplay 1st queue\n";
    cq1.displayQueue();
    for(int i =0;i<size;i++)
    {
        int enq2=cq1.dequeue();
        cq2.enqueue(enq2);
    }
    cout<<"\nDisplay 2nd queue\n";
    cq2.displayQueue();
    cout<<"\nDisplay 1st queue\n";
    cq1.displayQueue();
}