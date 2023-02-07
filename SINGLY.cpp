  /*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the singly linked list
(ii) Insert an element x at position in the singly linked list
(iii)Remove an element from the beginning of the singly linked list
(iv) Remove an element from position in the singly linked list.
(vii) Search for an element x in the singly linked list and return its pointer
(viii) Concatenate two singly linked lists*/


#include<iostream>
using namespace std;

template<class T>
class list;

template<class T>
class node
{ 
	T info;
	node<T> *next;
	friend class list<T>;
	
	public:
	node(const T& val, node<T> *n=0)
	{
		info=val;
		next = n;
	}
};

template<class T>
class list
{

	node<T>* head;
	node<T>*tail;
public:
	list();
	
	bool empty() const;
	void addHead(const T&);
	void removeHead();
	void addTail(const T&);
	void removeTail();
	void disp();
	node<T>* front();
	void add_at_position(const T&,int i);
	void remove_from_position(int i);
	node<T>* search(const T&);
	void concatenate(node<T> *);

};


template<class T> 
list<T>::list()
{
	head=NULL;
	tail=NULL;
}

template<class T>
void list<T>::disp()
{
	node<T> *h=head;

	if(h==NULL)
	{
	
		cout<<"list is empty!"<<endl;
		return;
	}
	while(h!=0)
	{
		cout<<h->info<<" ";
		h=h->next;
	}
	cout<<endl;
}

template<class T>
void list<T>::addHead(const T& val)
 {	
	node<T> *n=new node<T>(val,head);
	//n->info=val;
	//n->next=head;
	if (head == 0)
		head=tail=n;
	else
		head = n;
	
}

template<class T>
void list<T>::addTail(const T& val)

{   if(tail==0)
	{
		head=tail=new node<T>(val);
    }
	
	tail->next=new node<T>(val);
	tail=tail->next;                                                                                                       
		 	 	
}

template<class T>
void list<T>::removeTail()
{   if(tail=NULL)
  {
  	head=NULL;
  	cout<<"LIST IS EMPTY";
  }
  
  if(head==tail)
  {
  	delete head;
  	head=tail=NULL;
  	return;
  }
	node<T>*temp=head;
	while(temp->next->next!=0)
	{
	temp=temp->next; 
   }
	node<T>*t=temp->next;
	temp->next=0;
	delete t;
	tail=temp;
}

template<typename T>
node<T>* list<T>::front()
{
	return head;
	return tail;
}

template<class T>
void list<T>::removeHead()
{
	node<T>*temp=head;
	head=temp->next;
	delete temp;
}

template<class T>
bool list<T>::empty() const
{
	return head==NULL;
}

template<class T>
void list<T>::add_at_position(const T& val, int i)
{
	if(i==1)
	{
		addHead(val);
		return;
	}
	node<T> *n=head;
	int counter=1;
	while(counter<i-1)
	{
		n=n->next;
		if(n==0)
		{
			cout<<"Invalid position"<<endl;
			return;
			
		}
		counter++;
	}
	node <T>* m=n->next;
	n->next=new node<T>(val);
	n->next->next=m;
}

template<class T>
void list<T>::remove_from_position(int i)
{
	if(i==1)
	{
		removeHead();
		return;
	}
	node<T> *n=head;
	int counter=1;
	while(counter<i-1)
	{
		n=n->next;
		if(n==0)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		counter++;
	}
	node <T>*m=n->next->next;
	delete n->next;
	n->next=m;
}
template<class T>
node<T>* list<T>::search(const T& x)
{
	node<T> *n=head;
	while(n!=0)
	{
		if(n->info==x)
		{
			cout<<"Value "<<n->info<<" found !!"<<endl;
			return n->next;
		}
		n=n->next;
	}
	cout<<"Value not found"<<endl;
}
template <typename O>
void list<O>::concatenate(node<O>* y) {
	node<O>* temp = head; //creates Node pointer
	while (temp->next != NULL) {
		temp = temp->next; //traverse untill end of the list
	}
	temp->next = y; //set last's link to first of second list
}


int main()
{
	list<int> n;
	list<int> m;
	int val;
	int i;
	int ch;
	char repeat;
	do
	{
		cout<<"Menu"<<endl;
		cout<<"1.Add in the beginning"<<endl;
		cout<<"2.Add at a position"<<endl;
		cout<<"3.Delete from the beginning"<<endl;
		cout<<"4.Delete from a position"<<endl;
		cout<<"5.Add in the last"<<endl;
		cout<<"6.Delete from last "<<endl;
		cout<<"7.Search for an element x in the singly linked list and return its pointer "<<endl;
		cout<<"8.Concatenate two singly linked lists "<<endl;
        cout<<"9.Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				n.addHead(val);
				break;
			}
			case 2:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				cout<<"Enter the position "<<endl;
				cin>>i;
				n.add_at_position(val,i);
				break;
			}
			case 3:
			{
				n.removeHead();
				cout<<"Deleted from the beginning"<<endl;
				break;
			}
			case 4:
			{
				cout<<"Enter the position"<<endl;
				cin>>i;
				n.remove_from_position(i);
				//cout<<"Deleted from "<<i<<endl;
				break;
			}
			case 5:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				n.addTail(val);
				break;
			}
			case 6:
			{
				n.removeTail();
				cout<<"Deleted from the last"<<endl;
				
				break;
			}
			
			case 7:
			{
				cout<<"Enter the value to be searched"<<endl;
				cin>>val;
				cout<<"Address : "<<n.search(val)<<endl;
				break;
			}
			
			case 8:
			{
				cout<<"Enter another list "<<endl;
				cout<<"Enter the size of the list"<<endl;
				cin>>i;
				for(int j=1;j<=i;j++)
				{
					cout<<"Enter values "<<endl;
					cin>>val;
					m.add_at_position(val,j);
				}
				n.concatenate(m.front());
				cout<<"After Concatenating "<<endl;	
			}

			case 9:
			{
				cout<<"Displaying the list "<<endl;
				n.disp();
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

