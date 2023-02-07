/*Write a program to implement doubly linked list which supports the following operations:
(i) Insert an element x at the beginning of the doubly linked list
(ii) Insert an element x at position in the doubly linked list
(iii)Insert an element x at the end of the doubly linked list
(iv) Remove an element from the beginning of the doubly linked list
(v) Remove an element from position in the doubly linked list.
(vi) Remove an element from the end of the doubly linked list
(vii) Search for an element x in the doubly linked list and return its pointer
(viii) Concatenate two doubly linked lists*/

#include<iostream>
using namespace std;

template<class T>
class Dlink;
template<class T>
class node
{
	T num;
	node* prev;
	node* next;
	friend class Dlink<T>;
	
	public:
		node(const T& val,node<T> *n=0,node<T>*p=0)
		{
			num=val;
			next=n;
			prev=p;
		}
};

template<class T>
class Dlink
{
public:
	Dlink();
	bool empty() const;
	const T& front() const;
	const T& back() const;
    node<T>* getfront();
	node<T>* getback();
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
	
	private:
	node<T>* head;
	node<T>* tail;
	
//	protected:
//	void add(node<T>* ,const T&);
//	void remove(node<T>*);
//

};

template<class T>
Dlink<T>::Dlink()
{
	//head->next=tail;
	//tail->prev=head;
	
	head=tail=NULL;
}

template<class T>
const T& Dlink<T>::front() const
{
	return head->num;
}

template<class T>
node<T>* Dlink<T>:: getfront()
{
	return head;
}

template<class T>
node<T>* Dlink<T>:: getback()
{
	return tail;
}

template<class T>
const T& Dlink<T>::back() const
{
	return tail->num;
}

template<class T>
bool Dlink<T>::empty() const
{
	return(head==tail);
}

//template<class T>
//void Dlink<T>::add(node<T>* v,const T& val)
//{
//	node<T>* u=new node<T>;
//	u->num=val;
//	u->next=v;
//	u->prev=v->prev;
//	v->prev->next=v->prev=u;
//}
template<class T>
void Dlink<T>::addHead(const T& val)
{    if(head==NULL)
   
   	  head=tail=new node<T>(val);
	else
	{
        head->prev=new node<T>(val,head);
        head->prev->next=head;
        head=head->prev;
     }   //add(head->next,val);
}


template<class T>
void Dlink<T>::addTail(const T& val)
{   node<T>*u=new node<T>(val,tail);
	tail=u;
	//add(tail,val);
}

//template<class T>
//void Dlink<T>::remove(node<T>* v)
//{
//	node<T>* u =v->prev;
//	node<T>* w =v->next;
//	u->next=w;
//	w->prev=u;
//	delete v;
//}

template<class T>
void Dlink<T>::removeHead()
{   node<T>*temp=head;
	head=temp->next;
	temp->prev=NULL;
	delete temp;
	//remove(head->next);
}

template<class T>
void Dlink<T>::removeTail()
{
	 if(tail=NULL)
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
	node<T>*temp=tail;
	tail=temp->prev;
	temp->next=NULL;
	delete temp;
	//remove(tail->prev);
}

template<class T>
void Dlink<T>::remove_from_position(int i)
{
//	node<T>* temp=head;
//	int counter=1;
//	if(i==1)
//	{
//		removeHead();
//		return;
//	}
//
//	while(temp!=NULL&& counter!=i)
//	{
//		temp=temp->next;
//		counter++;
//	}
//	
//	temp->prev->next=temp->next;
//	if(temp->next!=NULL)
//	{
//	temp->next->prev=temp->prev;
//}
//	delete temp;
if(i==1)
	{
		removeHead();
		return;
	}
	node<T> *temp=head;
	int counter=1;
	while(counter<i-1)
	{
		temp=temp->next;
		if(temp==0)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		counter++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
//	node <T>*m=n->next->next;
	delete temp;
//	n->next=m;


}


template<class T>
node<T>* Dlink<T>::search(const T& val)
{
	node<T>* h=head;
	while(h!=tail)
	{
		if(h->num==val)
		{
			cout<<"Value found "<<endl;
			return h->next;
		}
		h=h->next;
	}
	cout<<"Value not found!!"<<endl;
}

template<class T>
void Dlink<T>::disp()
{
	node<T>* h=head->next;
	while(h!=0)
	{
		cout<<h->num<<" ";
		h=h->next;
	}
	cout<<endl;
}


int main()
{
	Dlink<int> d;
	Dlink<int> e;
	int ch;char repeat;
	int val,i;
	do
	{
	cout<<"Menu"<<endl;
	cout<<"1.Insert an element x at the beginning of the doubly linked list"<<endl;
	cout<<"2.Insert an element x at the end of the doubly linked list"<<endl;
	cout<<"3.Remove an element from the beginning of the doubly linked list"<<endl;
	cout<<"4.Remove an element from the end of the doubly linked list"<<endl;
	cout<<"5.Search for an element x in the doubly linked list and return its pointer"<<endl;
	cout<<"6.Remove an element from position ith in the doubly linked list."<<endl;
	cout<<"7. Display "<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>ch;

	switch(ch)
	{
		case 1:
		{
			cout<<"Enter the value "<<endl;
			cin>>val;
			d.addHead(val);
			break;
		}
		
		case 2:
		{
			cout<<"Enter the value"<<endl;
			cin>>val;
			d.addTail(val);
			break;
		}
		case 3:
		{
			d.removeHead();
			cout<<"Deleted"<<endl;
			break;
		}
		
		case 4:
		{
			d.removeTail();
			cout<<"Deleted"<<endl;
			break;
		}
		case 5:
		{
			cout<<"Enter the value"<<endl;
			cin>>val;
			cout<<"Pointer : "<<d.search(val);
			break;
		}
		
		case 6:
		{
			cout<<"Enter the position"<<endl;
			cin>>i;
			d.remove_from_position(i);
			cout<<"Deleted"<<endl;
			break;
		}
		case 7:
		{
			d.disp();
			//e.disp();
			break;
		}
		default:
		{
			cout<<"Wrong choice "<<endl;
			break;
		}

	}
	cout<<"Do you want to continue(Y/N)?"<<endl;
	cin>>repeat;
	}
	while(repeat=='Y'||repeat=='y');
	return 0;
}


