
#include <iostream>
using namespace std;

template <class L>
class Singly_List;

template <class N> 
class Node
{
	N info;
	Node<N>* next;
	public:
		Node(N data,Node<N>* ptr=NULL)
		{
			info=data;
			next=ptr;
		}
		friend class Singly_List <N>;
};

template <class L>
class Singly_List
{
	Node<L>* head;
	Node<L>* tail;
	public:
		Singly_List()
		{
			head=tail=NULL;
		}
		void add_to_Head(L data);
		void add_to_Tail(L data);
		void display();
		void reverse();
};

template <class L> void Singly_List<L>::add_to_Head(L data)
{
	if(head==NULL)
	{
		head=tail=new Node<L>(data);
		return;
	}
	Node<L>* temp=new Node<L>(data,head);
	head=temp;
}

template <class L> void Singly_List<L>::add_to_Tail(L data)
{
	if(tail==NULL)
	{
		tail=head=new Node<L>(data);
		return;
	}
	tail->next=new Node<L>(data,NULL);
	tail=tail->next;
}

template <class L> void Singly_List<L>::display()
{
	Node<L>* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->info<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


template <class L> void Singly_List<L>::reverse()
{
	Node<L>* current=head->next;
	Node<L>* temp=tail;
	tail->next=head;
	head->next=NULL;
	while(current!=tail)
	{
		Node<L>* temp2=current->next;
		current->next=temp->next;
		temp->next=current;
		current=temp2;
	}
	tail=head;
	head=temp;
	tail->next=NULL;
	cout<<"List is reversed"<<endl;
}

int main()
{
	Singly_List<int> L1;
	int c;
	char repeat;
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
			case 3: 
			{	L1.display();
						break;
					 }
			case 4 : {	L1.reverse();
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
