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
	void disp();
	node<T>* orderlist(node<T>* start,int item);
	node<T>* front();
	
};


template<class T> 
list<T>::list()
{
	head=NULL;
	tail=NULL;
}
template<class T>
node<T>* list<T>::orderlist(node<T>* head,int item)
{   node<T> *p;
    node<T> *curr;
	node<T> *temp=new node<T>(item);
	if(head==NULL)
		return temp;
	
	if(item<head->info)
	{
		temp->next=head;
		return temp;
	}
	p=NULL;
	curr=head;
	while(curr!=NULL&&item>curr->info)
	{
		p=curr;
		curr=curr->next;
	}
	p->info=temp->info;
	temp->next=curr;
	return head;
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

//template<class T>
//void list<T>::addHead(const T& val)
// {	
//	node<T> *n=new node<T>(val,head);
//	//n->info=val;
//	//n->next=head;
//	if (head == 0)
//		head=tail=n;
//	else
//		head = n;
//	
//}

template<typename T>
node<T>* list<T>::front()
{
	return head;
	return tail;
}


int main()
{
	list<int> n;
	list<int> m;
	node<int> *head=NULL;
	int val;
	int i;
	int ch;
	char repeat;
	do
	{
		cout<<"Menu"<<endl;
		cout<<"1.Enter value in linked list"<<endl;
	    cout<<"9.Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				n.orderlist(head,val);
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
