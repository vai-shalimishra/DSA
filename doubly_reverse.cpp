
#include <iostream>
using namespace std;

template <class D>
class Doubly_List;

template <class N> 
class Node
{
	N info;
	Node<N>* next;
	Node<N>* prev;
	public:
		Node(N data,Node<N>* ptr1=NULL,Node<N>* ptr2=NULL)
		{
			info=data;
			next=ptr1;
			prev=ptr2;
		}
		friend class Doubly_List <N>;
};

template <class D>
class Doubly_List
{
	Node<D>* head;
	Node<D>* tail;
	public:
		Doubly_List()
		{
			head=tail=NULL;
		}
		void add_to_Head(D data);
		void add_to_Tail(D data);
		void display();
		void reverse();
};

template <class D> void Doubly_List<D>::add_to_Head(D data)
{
	if(head==NULL)
	{
		head=tail=new Node<D>(data);
		return;
	}
	head->prev=new Node<D>(data,head);
	head->prev->next=head;
	head=head->prev;
	
}

template <class D> void Doubly_List<D>::add_to_Tail(D data)
{
	if(tail==NULL)
	{
		tail=head=new Node<D>(data);
		return;
	}
	tail->next=new Node<D>(data,NULL);
	tail->next->prev=tail;
	tail=tail->next;
}


template <class D> void Doubly_List<D>::display()
{
	Node<D>* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->info<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

template <class D> void Doubly_List<D>::reverse()
{
	Node<D>* temp=tail;
	Node<D>* temp3=head;
	Node<D>* current=tail->prev;
	while(current!=NULL)
	{
		temp->next=current;
		Node<D>* temp2=current->prev;
		current->prev=temp;
		temp=current;
		current=temp2;
	}
	head=tail;
	tail=temp3;
	head->prev=NULL;
	tail->next=NULL;
	cout<<"list is reversed"<<endl;
}

int main()
{
	Doubly_List<int> L1;
	char repeat;
	int c;
	do
	{
		cout << "1. Insert an element in beginning\n";
		cout << "2. Insert element in the last\n";
		cout << "3. Displaying the link list\n";
		cout << "4. Reversing the link list\n";
		cout << "\nEnter your choice - ";
		cin >> c;
		switch (c)
		{
			case 1 : {	int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						L1.add_to_Head(ele);
						break;
					 }
			case 2 : {	int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						L1.add_to_Tail(ele);
						break;
					 }	
		   case 3 : {	L1.display();
						break;
					 }
			
			case 4 : { L1.reverse();
						break;
					 }
			default : cout << "Wrong choice"<<endl;
					  break;
		}
	

	cout<<"Do you want to continue(Y/N)?"<<endl;
		cin>>repeat;
	}
	while(repeat=='y'||repeat=='Y');

	
	return 0;

}
