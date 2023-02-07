#include <iostream>
using namespace std;

template <class T>
class Ordered_list;

template <class N>
class node
{
	N info;
	node<N>* next;
	public:
		node(N val,node<N>* ptr=NULL)
		{
			info=val;
			next=ptr;
		}
		friend class Ordered_list<N>;
};

template <class T>
class Ordered_list
{  	node<T>* head;
	node<T>* tail;
	public:
		Ordered_list()
		{
			head=tail=NULL;
		}
		
		void insert(T val);
		void dlt(T val);
        void display();
};
template <class T> void Ordered_list<T>::insert(T val)
{
	if(head==NULL)
	{
		head=tail=new node<T>(val);
		cout<<"Element inserted"<<endl;
		return; 
	}
	node<T>* temp=head;
	while(temp->next!=NULL && temp->next->info < val)
	{
		temp=temp->next;
	}
	if(temp==head)// to add before head
	{
		if(temp->info > val)
		{
			temp=new node<T>(val,head);
			head=temp;
			cout<<"Element inserted"<<endl;
			return;
		}
	}
	if(temp==tail)//to add after tail
	{
		tail->next=new node<T>(val,NULL);
		tail=tail->next;
		cout<<"Element inserted"<<endl;
		return;
	}
	temp->next=new node<T>(val,temp->next);
	cout<<"Element inserted"<<endl;
}

template <class T> void Ordered_list<T>::dlt(T val)
{
	if(head->info==val)
	{
		node<T>* temp=head;
		head=head->next;
		delete temp;
		cout<<"Element deleted"<<endl;
		return;
	}
	node<T>* current=head;
	while(current->next!=NULL)
	{
		if(current->next->info==val)
		{
			node<T>* temp=current->next;
			current->next=current->next->next;
			delete temp;
			cout<<"Element deleted"<<endl;
			return;
		}
		current=current->next;
	}
	cout<<"Element erased"<<endl;
}
template <class T> void Ordered_list<T>::display()
{
	cout<<"The Ordered Singly list-";
	node<T>* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->info<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	Ordered_list<int> O1;
   int c;
   char con;
	do
	{
	
		cout << "1.Insert an element"<<endl;
		cout << "2.Erase an element"<<endl;
	   	cout << "3.Display link list"<<endl;
    	cout << "Enter your choice - "<<endl;
		cin >> c;
		switch (c)
		{
			case 1 : {	int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						O1.insert(ele);
						break;
					 }
			case 2 : {	O1.display();
						int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						O1.dlt(ele);
						break;
					 }	
	        case 3 : {	O1.display();
						break;
					}
		    default: cout<<"\nInvalid choice !!\n";
		}
			
		cout<<"\n\nDo you want to continue(Y/N) ?? ";
		cin>>con;
      }while(con=='Y'or con=='y');
	return 0;
}

		
