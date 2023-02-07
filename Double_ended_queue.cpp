// C++ implementation of Deque using doubly linked list
#include <iostream>
using namespace std;
template<class T>
class Deque;

template<class T>

// Node of a doubly linked list
class Node
{
	T data;
	Node *prev, *next;
	friend class Deque<T>;
	// Function to get a new node
	
	static Node* getnode(int data)
	{    
	    Node<T> *newNode=new Node<T>(data);
		newNode->data = data;
		newNode->prev = newNode->next = NULL;
		return newNode;
	}
	
	public:
		Node(const T& val,Node<T> *n=0,Node<T>*p=0)
		{
			data=val;
			next=n;
			prev=p;
		}
	
};


template<class T>
class Deque
{
	Node<T>* front;
	Node<T>* rear;
	int Size;

public:
	Deque()
	{
		front = rear = NULL;
		Size = 0;
	}

	// Operations on Deque
	void insertFront(int data);
	void insertRear(int data);
	void deleteFront();
	void deleteRear();
	int getFront();
	int getRear();
	int size();
	bool isEmpty();
	void erase();
	void disp();
	
};

// Function to check whether deque is empty or not
template<class T>
bool Deque<T>::isEmpty()
{   
	return (front == NULL);
}

// Function to return the number of elements in the deque
template<class T>
int Deque<T>::size()
{
	cout<< Size;
}

// Function to insert an element at the front end
template<class T>
void Deque<T>::insertFront(int data)
{
	Node<T>* newNode = Node<T>::getnode(data);
	
		// If deque is empty
		if (front == NULL)
			rear = front = newNode;

		// Insert node at the front end
		else
		{
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}

	
		Size++;
	}


// Function to insert an element at the rear end
template<class T>
void Deque<T>::insertRear(int data)
{
	Node<T>* newNode =Node<T>::getnode(data);
	
		// If deque is empty
		if (rear == NULL)
			front = rear = newNode;

		// Insert node at the rear end
		else
		{
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}

		Size++;
	}


// Function to delete the element from the front end
template<class T>
void Deque<T>::deleteFront()
{
	// If deque is empty then'Underflow' condition
	if (isEmpty())
		cout << "UnderFlow\n";


	else
	{
		Node<T>* temp = front;
		front = front->next;

		// If only one element was present
		if (front == NULL)
			rear = NULL;
		else
			front->prev = NULL;
        delete temp;
		Size--;
	}
}

template<class T>
void Deque<T>::disp()
{
	Node<T> *h=front;

	if(h==NULL)
	{
	
		cout<<"Deque is empty!"<<endl;
		return;
	}
	while(h!=0)
	{
		cout<<h->data<<" ";
		h=h->next;
	}
	cout<<endl;
}



// Function to delete the element from the rear end
template<class T>
void Deque<T>::deleteRear()
{
	// If deque is empty then 'Underflow' condition
	if (isEmpty())
		cout << "UnderFlow\n";

	else
	{
		Node<T>* temp = rear;
		rear = rear->prev;

		// If only one element was present
		if (rear == NULL)
			front = NULL;
		else
			rear->next = NULL;
		delete temp;

		Size--;
	}
}

// Function to return the element at the front end
template<class T>
int Deque<T>::getFront()
{

	if (isEmpty())
		return -1;
	cout<< front->data;
}

// Function to return the element at the rear end
template<class T>
int Deque<T>::getRear()
{
	
	if (isEmpty())
		return -1;
	cout<< rear->data;
}

// Function to delete all the elements from Deque
template<class T>
void Deque<T>::erase()
{
	rear = NULL;
	while (front != NULL)
	{
		Node<T>* temp = front;
		front = front->next;
	}
	Size = 0;
}


int main()
{
	
	
	Deque<int>dq;
	int val;
	int i;
	int ch;
	char repeat;
	do
	{
		cout<<"Menu"<<endl;
		cout <<"1.Insert element at rear end\n";
		cout <<"2.Rear end element:\n";
		cout <<"3.Front end element:\n";
       cout <<"4.To check empty or not:\n";
		cout<<"5.Insert at the front"<<endl;
		cout<<"6.Delete from the front "<<endl;
		cout<<"7.Delete from the rear "<<endl;
		cout<<"8.Size of dequeue "<<endl;
		cout<<"9.Erase "<<endl;
        cout<<"10.Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				dq.insertRear(val);
				break;
			}
			case 2:
			{
				cout << "Rear end element is:";
				dq.getRear();
				cout<<endl;
				break;
			}
			case 3:
			{
				cout<<"Front end element is:"<<endl;
				dq.getFront();
				cout<<endl;
				break;
			}
			case 4:
			{   if(dq.isEmpty())
				cout<<"Deque is empty\n";
				cout<<"Deque is not empty\n";
				break;
			}
			case 5:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
			    dq.insertFront(val);
				break;
			}
			case 6:
			{   cout<<"Deleting from the front end"<<endl;
				dq.deleteFront();				
				break;
			}
			case 7:
			{   cout<<"Deleting from the rear end"<<endl;
				dq.deleteRear();			
				break;
			}
			
			case 8:
			{   cout<<"Size of dequeue is:"<<endl;
				dq.size();
				cout<<endl;				
				break;
			}
			case 9:
			{   cout<<"Erasing all elements"<<endl;
				dq.erase();	
				cout<<endl;			
				break;
			}
			case 10:
			{
				cout<<"Displaying the list "<<endl;
				dq.disp();
				break;
			}
			default:
			{
				cout<<"Wrong choice"<<endl;
				break;
			}
		}
		cout<<"Do you want to continue(Y/N)?"<<endl;
		cin>>repeat;
	}
	while(repeat=='y'||repeat=='Y');
	return 0;
}

