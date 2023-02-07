/*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the doubly linked list
(ii) Insert an element x at position in the doubly linked list
(iii)Remove an element from the beginning of the doubly linked list
(iv) Remove an element from position in the doubly linked list.
(vii) Search for an element x in the doubly linked list and return its pointer
(viii) Concatenate two doubly linked lists*/


#include<iostream>
using namespace std;

template<class T>
class list;

template<class T>
class node
{ 
	T info;
	node<T>*prev;
	node<T> *next;
	friend class list<T>;
	
	public:
	node(const T& val, node<T> *n=0,node<T>*p=0)
	{
		info=val;
		next = n;
		prev=p;
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
	void concatenate(list<T> &);

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
bool list<T>::empty() const
{
	return head==NULL;
}

template<typename T>
node<T>* list<T>::front()
{
	return head;
	return tail;
}


template<class T>
void list<T>::addTail(const T& val)

{   if(tail==0)
	{
		head=tail=new node<T>(val);
    }
    else
    {
    
	node<T>*temp=new node<T>(val);
	tail->next=temp;
    temp->prev=tail;
	tail=tail->next;
}
}

template<class T>
void list<T>::removeHead()
{   if(head==NULL)
   { tail=NULL;
    cout<<"Error"<<endl;
	return;	
   }
	node<T>*temp=head;
	head=temp->next;
   head->prev=NULL;
	delete temp;
}

template<class T>
void list<T>::removeTail()
{  node<T>*temp=tail;
   if(tail==NULL)
  {
  	head=NULL;
  	cout<<"LIST IS EMPTY"<<endl;
  	return;
  }
  
  else if(tail==head)
  {
  	delete temp;
  	tail=head=NULL;
  	return;
  }

    tail=temp->prev; 
   tail->next=NULL;
	delete temp;


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
	if(tail==n)
	{
	  n->next=new node<T>(val,NULL,n);
	   tail=n->next;
	  return;
    } 
	node <T>* m=n->next;
    node<T>*t=n->next->prev;
	n->next=new node<T>(val);
	n->next->next=m;
    n->next->prev=t;
    m->prev=n->next;
}


template<class T>
void list<T>::remove_from_position(int i)
{
	node<T>* n=head;
		
		if(i==1)
		{
			removeTail();
			return;
		}
		
		int counter=1;
		while(counter <i-1 && n!=0)
		{
			n=n->next;
			counter++;
		}
		
		if(n==0)
	    {
	    	cout<<"error : index out of bound \n";
	    	return;
		}
		
		if(n->next->next==0)
		{
			removeTail();
			return;
		}
		
		node<T>* t1=n->next;
		n->next=t1->next;
		t1->next->prev=n;
		t1=NULL;
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
template <class T>
void list<T>::concatenate(list<T> &y) {
	if(y.head==NULL || head==NULL)
	{
		cout<<"Either one of the list is empty !!! :(";
		return;
	}
	
	node<T>* temp = head; //creates Node pointer
	while (temp->next != NULL) {
		temp = temp->next; //traverse untill end of the list
	}
	temp->next = y.head; //set last's link to first of second list
	y.head->prev=tail;
	cout<<"Lists are concatenated !!"<<endl;
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
				cout<<"Deleted from "<<i<<endl;
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
			{   cout<<"Deleting from the last"<<endl;
				n.removeTail();				
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
				n.concatenate(m);
				cout<<"After Concatenating "<<endl;
				n.disp();	
				break;
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


