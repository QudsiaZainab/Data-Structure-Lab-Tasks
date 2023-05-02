#include<iostream>
using namespace std;

class Node
{
    int element;
    Node* next_node;
    Node* previous_node;
public:
    Node(int e, Node* n, Node* p) :element(e), next_node(n), previous_node(p)
    {

    }
    Node()
    {

    }
    int retrieve()
    {
        return element;
    }
    Node* next()
    {
        return next_node;
    }
    Node* previous()
    {
        return previous_node;
    }
    friend class DoublyLinkedList;
};

class DoublyLinkedList
{
    Node* list_head;
    Node* list_tail;
public:
    DoublyLinkedList() :list_head(nullptr), list_tail(nullptr)
    {

    }

    bool empty() const
    {
        return(list_head == nullptr);
    }

    Node* head() const
    {
        return list_head;
    }

    Node* tail() const
    {
        return list_tail;
    }

    void displayList() const
    {
        Node* ptr = head();
        if (list_head == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            while (ptr != nullptr)
            {
                cout << "\t" << ptr->element;
                ptr = ptr->next();
            }
        }
    }

    void push_front(int n)
    {
        if (list_head == NULL)
        {
            list_head = new Node(n, nullptr, nullptr);
            list_tail = list_head;
        }
        else
        {
            list_head = new Node(n, head(), nullptr);
            list_head->next_node->previous_node = list_head;
        }
    }

    void pop_back()
    {
        if (list_head == NULL) //Means empty list
        {
            cout << "\nno element is to delete.\n";
        }
        else
        {
            Node* last = tail();
            if (list_head->next_node == nullptr && list_head->previous_node == nullptr) //Means only one element in list
            {
                list_tail=nullptr;
                list_head=nullptr;
            }
            else
            {
                Node* p = last->previous();
                p->next_node = NULL;
                list_tail = p;
            }
            delete last;
        }
    }

    //Example of backward traverse
    void pop_front()
    {
        if(list_tail==nullptr)
        {
            cout<<"\nlist is empty. So no element is to delete.\n";
        }
        else if(list_tail==list_head)
        {
            delete list_tail;
            list_tail=nullptr;
            list_head=nullptr;
        }
        else
        {
            Node* front=tail();
            while(front->previous_node->previous_node!=NULL)
            {
                front=front->previous_node;
            }
            delete front->previous_node;
            front->previous_node=NULL;
            list_head=front;
        }
    }

    Node* search(int x)
    {
        Node* currentptr = head();
        while (currentptr != NULL)
        {
            if (currentptr->retrieve() == x)
            {
                return currentptr;
            }
            else 
            {
                currentptr = currentptr->next();
            }
        }
        return NULL;
    }

};

int main()
{
    DoublyLinkedList ls;
    ls.displayList();

    int key, list_elements;

    cout << "Enter number of elements you want to insert: \n";
    cin >> list_elements;
    for (int i = 0; i < list_elements; i++)
    {
        cout << "Enter element \n";
        cin >> key;
        ls.push_front(key);
    }
    ls.displayList();

    cout << "\n########## Pop Back \n";
    ls.pop_back();
    ls.displayList();

    cout<<"\nEnter element to know its previous element: ";
    cin>>key;
    if(ls.search(key)==NULL)   //If entered element is not in list.
    {
        if(ls.head()==nullptr)   //and list is empty
        {
            cout<<"List is empty. So ";
        }
        cout<<key<<" is not in list.\n";
    }
    else if(ls.search(key)->previous()==nullptr)   //If entered element is head of list.
    {
        cout<<"There is no element before "<<key<<". \n";
    }
    else
    {
        cout<<ls.search(key)->previous()->retrieve()<<" is before "<<key<<". \n"; //Display the previous element of entered key.
    }
    cout<<endl;

    cout<<"\n########## Pop front\n";
    ls.pop_front();
    ls.displayList();

}
