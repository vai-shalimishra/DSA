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
	node<T>* header;
	node<T>* trailer;
	
	protected:
	void add(node<T>* ,const T&);
	void remove(node<T>*);


};

template<class T>
Dlink<T>::Dlink()
{
	header=new node<T>;
	trailer=new node<T>;
	header->next=trailer;
	trailer->prev=header;
}

template<class T>
const T& Dlink<T>::front() const
{
	return header->next->num;
}

template<class T>
node<T>* Dlink<T>:: getfront()
{
	return header->next;
}

template<class T>
node<T>* Dlink<T>:: getback()
{
	return trailer->prev;
}

template<class T>
const T& Dlink<T>::back() const
{
	return trailer->prev->num;
}

template<class T>
bool Dlink<T>::empty() const
{
	return(header->next==trailer);
}

template<class T>
void Dlink<T>::add(node<T>* v,const T& val)
{
	node<T>* u=new node<T>;
	u->num=val;
	u->next=v;
	u->prev=v->prev;
	v->prev->next=v->prev=u;
}
template<class T>
void Dlink<T>::addHead(const T& val)
{
	add(header->next,val);
}


template<class T>
void Dlink<T>::addTail(const T& val)
{
	add(trailer,val);
}

template<class T>
void Dlink<T>::remove(node<T>* v)
{
	node<T>* u =v->prev;
	node<T>* w =v->next;
	u->next=w;
	w->prev=u;
	delete v;
}

template<class T>
void Dlink<T>::removeHead()
{
	remove(header->next);
}

template<class T>
void Dlink<T>::removeTail()
{
	remove(trailer->prev);
}




template<class T>
node<T>* Dlink<T>::search(const T& val)
{
	node<T>* h=header;
	while(h!=trailer)
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
	node<T>* h=header->next;
	while(h!=trailer)
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
	cout<<"6. Display "<<endl;
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
			d.disp();
			e.disp();
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


