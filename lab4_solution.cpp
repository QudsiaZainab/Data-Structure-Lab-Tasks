#include <iostream>
using namespace std;
class Node {
private:
	int element;
	Node* next_node;
public:
	Node(int = 0, Node* = nullptr);
	int retrieve() const;
	Node* next() const;
	friend class List;
};
Node::Node(int e, Node* n) :element(e), next_node(n)
{
	// empty constructor
}
int Node::retrieve() const 
{
	return element;
}
Node* Node::next() const 
{
	return next_node;
}
/* ########## List Class ############ */
class List {
private:
	Node* list_head;
	Node* list_tail;
public:
	// Constructors and destructors 
	List();
	
	// Accessors
	bool empty() const;
	// int size() const;
	int front() const;
	Node* head() const;
	Node* getLastNode() const;
	int count(int) const;
	void display() const;
	
	// Mutators
	void push_front(int);
	int pop_front();
	Node* search(int);
	void push_back(int);
	// int erase(int);
};
List::List() :list_head(nullptr),list_tail(nullptr) {
	// empty constructor
}

bool List::empty() const
{
	return (list_head == nullptr);
}

Node* List::head() const 
{
	return list_head;
}
Node* List::getLastNode() const 
{
	Node* ptr = head();
	while (ptr->next() != NULL) 
    {
		ptr = ptr->next();
	}
	return ptr;
}
int List::front() const 
{
	if (list_head == nullptr) 
    {
		return 0;
	}
	return head()->retrieve();
}

/*
void List::push_front(int n) {
	if (empty()) {
		list_head = new Node(n, nullptr);
	}
	else {
		list_head = new Node(n, head());
	}
}
*/
void List::push_front(int n) 
{
	list_head = new Node(n, head());
}
// ********************* Lab Task -02
void List::push_back(int n) 
{
	if (empty()) 
    {
		list_head = new Node(n, nullptr);
		list_tail = list_head;
	}
	else 
    {
		// Traverse till last node then added the new node
		getLastNode()->next_node = new Node(n, NULL);
	}
}
//Lab Task-01(b) logic
int List::pop_front() {
	if (empty()) {
		return 0;
	}
	int e = front();
	Node* ptr = list_head;
	list_head = list_head->next();
	delete ptr;
	return e;
}
int List::count(int n) const 
{
	int node_count = 0;
	for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) 
    {
		if (ptr->retrieve() == n) 
        {
			++node_count;
		}
	}
	return node_count;
}
// Lab Task - 01(c & d)logic
Node* List::search(int x)
{
	cout << "In search function" << endl;
	Node* currentPtr = head();
	while (currentPtr != NULL) 
    {
		if (currentPtr->retrieve() == x)
			return currentPtr;
		else
			currentPtr = currentPtr->next();
	}
	return NULL; // Now x is not, so return NULL
};

void List::display() const {
	Node* ptr = head();
	if (head()==NULL) 
    {
		cout << "List is empty" << endl;
	}
	else 
    {
		while (ptr != NULL) 
        {
			cout << "\t" << ptr->element;
			ptr = ptr->next();
		}
	}
}

int main()
{
	List ls;
	ls.display();


	int list_elements;
	int key;
	int num_to_search;
	cout << "Enter number of elements you want to insert " << endl;
	cin >> list_elements;

	// Push at the front of the linked list
	for (int i = 0; i < list_elements; i++) 
    {
		cout << "Enter element " << endl;
		cin >> key;
		// ************************* Lab Task-01(a) logic
		while (key % 2 != 0) 
        {
			cout << "Enter key again as the previous one was not even" << endl;
			cin >> key;
		}
		ls.push_front(key);
	}
	// Complete list
	ls.display();
	cout << " " << endl;


	// Push Back
	ls.push_back(3);
	ls.display();
	cout << " " << endl;

	// Pop element at the front of the linked list
	//for (int i = 0; i < list_elements; i++) {
	//	cout<<ls.pop_front()<<"\t";
	//}

	//Again calling the display function
	//ls.display();

	// Search in the list
	cout << "Enter number you want to search " << endl;
	cin >> num_to_search;
	Node* temp = ls.search(num_to_search);
	cout << "Value you were looking for: " << temp->retrieve() << endl;
	cout << " " << endl;
	ls.display();
	cout << " " << endl;

	cout << "Total existance of "<<num_to_search<<" in list: " << ls.count(num_to_search);
	return 0;
}