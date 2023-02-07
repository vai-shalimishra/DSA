#include<iostream>
using namespace std;
template<class>class LinkList;
template <class T>
class node
{
	protected:
	T info;
	node<T>* next;
	friend class LinkList <T>;
};
template<class T>
class LinkList
{ public:
	LinkList();
	void addHead(const T& e);
	void removeHead();
	void addTail(const T& r);
	void removeTail();
	void display();
	bool empty()const;
	private:
	node<T>*head;
	node<T>*tail;
};
template<class T>
LinkList<T>::LinkList()
{
	head=NULL;
	tail=NULL;
}
template<class T>
bool LinkList<T>::empty()const
{
	return head==NULL;
}
template<class T>
void LinkList<T>::addHead(const T& e)
{
	node<T>*temp=new node<T>(e,head);
	
		head=temp;
	
}
template<class T>
void LinkList<T>::addTail(const T& r)
{
	node<T>*temp=new node<T>(r,tail);
	tail->next=temp;
	tail=temp;
}
template<class T>
void LinkList<T>::removeHead()
{
	node<T>*temp=head;
	head=temp->next;
	delete temp;
}
//template<class T>
//void LinkList<T>::removeTail()
//{
//	
//}

template<class T>
void LinkList<T>::display()
{
	node<T>* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main(){
	LinkList<int>l;
	//l.addHead(5);
	l.addTail(7);
	l.addTail(8);
	l.addTail(6);
	//l.addHead(4);
	l.removeHead();
	l.display();
	
	return 0;
}



