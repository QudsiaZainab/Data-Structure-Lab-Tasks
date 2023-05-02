//Buy and sell shares of a stock and check profit

#include<iostream>
using namespace std;

class Node
{
    int no_of_shares;
    float price_per_share;
    Node* next;
    public:
    Node()
    {

    }
    Node(int shares,float price,Node*ptr)
    {
        no_of_shares=shares;
        price_per_share=price;
        next=ptr;
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
    int count_shares;
    public:
    Queue()
    {
        count_shares=0;
        front = nullptr;
        rear = nullptr;
    }
    ~Queue()
    {

    }
    void enqueue(int shares,float price)
    {
        if(isEmpty())
        {
            rear = new Node(shares,price,nullptr);
            front=rear;
        }
        else
        {
            Node *newNode = new Node;
            newNode->next=nullptr;
            newNode->no_of_shares=shares;
            newNode->price_per_share=price;
            rear->next=newNode;
            rear=newNode;
        }
        count_shares=count_shares+shares;
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
		    while (ptr != NULL) 
            {
			    cout << "\t" << ptr->no_of_shares<<","<<ptr->price_per_share;
			    ptr = ptr->getNext();
		    }
	    }
    }
    void buyshare()
    {
        int shares;
        float price;
        cout<<"\nBuy shares of a stock----------\n";
        cout<<"Enter shares to buy: ";
        cin>>shares;
        cout<<"Enter price of per share in PKR: ";
        cin>>price;
        enqueue(shares,price);
    }
    void sellShare()
    { 
        if(isEmpty())
        {
            cout<<"Error! You can't sell before buy share. So to sell 1st buy.\n";
        }
        else
        {
            int shares;
            float price;
            cout<<"\nSell shares of a stock----------\n";
            cout<<"Enter shares to sell: ";
            cin>>shares;
            cout<<"Enter price of per share in PKR: ";
            cin>>price;
            if(shares>count_shares)
            {
                cout<<"Error! Shares you want to sell are greater than the total shares in queue. So you can't sell.\n";
            }
            else
            {
                Node* ptr = front;
                float profit = 0;
                while(shares!=0)
                {
                    if(shares>=ptr->no_of_shares)
                    {
                        profit=profit+ptr->no_of_shares*(price-ptr->price_per_share);
                        shares=shares-ptr->no_of_shares;
                        ptr=ptr->next;
                        dequeue();
                    }
                    else if(shares<ptr->no_of_shares)
                    {
                        profit=profit+shares*(price-ptr->price_per_share);
                        ptr->no_of_shares=ptr->no_of_shares-shares;
                        shares=0;
                        ptr=ptr->next;
                    }
                }
                cout<<"Profit: "<<profit<<" PKR"<<endl;
            }
        }
    }
};

int main()
{
    Queue q;
    int choice;
    while(choice!=-1)
    {
        cout<<"\nPress 1 to buy shares\nPress 2 to sell shares\nPress -1 to end\nEnter your choice: \n";
        cin>>choice;
        if(choice==1)
        {
            q.buyshare();
        }
        else if(choice==2)
        {
            q.sellShare();
        }
        else if(choice==-1)
        {
            break;
        }
        else
        {
            cout<<"\nError! Your choice is not valid.\n";
        }
    }
}