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
		node<T>*merge(Ordered_list<T> &L);
		void display();
};

template <class T> void Ordered_list<T>::insert(T val)
{
	if(head==NULL)
	{
		head=tail=new node<T>(val);
		cout<<"\nELEMENT INSERTED SUCCESSFULLY!!!"<<endl;
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
			cout<<"\nELEMENT INSERTED SUCCESSFULLY!!!"<<endl;
			return;
		}
	}
	if(temp==tail)//to add after tail
	{
		tail->next=new node<T>(val,NULL);
		tail=tail->next;
		cout<<"\nELEMENT INSERTED SUCCESSFULLY!!!"<<endl;
		return;
	}
	temp->next=new node<T>(val,temp->next);
	cout<<"\nELEMENT INSERTED SUCCESSFULLY!!!"<<endl;
}

template <class T> void Ordered_list<T>::dlt(T val)
{
	if(head->info==val)
	{
		node<T>* temp=head;
		head=head->next;
		delete temp;
		cout<<"\nELEMENT ERASED SUCCESSFULLY!!!"<<endl;
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
			cout<<"\nELEMENT ERASED SUCCESSFULLY!!!"<<endl;
			return;
		}
		current=current->next;
	}
	cout<<"\nELEMENT ERASED UNSUCCESSFUL!!!"<<endl;
}

template <class T> node<T>*Ordered_list<T>::merge(Ordered_list<T>& L)
{       node<T>* L1=NULL;
        node<T>*L2=NULL;
        node<T>*sorting;
	
   node<T>* newhead=NULL;
  if(L1==NULL)
  {
     return L2;
 }
  if(L2==NULL)
  {
    return L1;
}
  if(L1&&L2)
	{
	if(L1->info<=L2->info)
	{
	  sorting=L1;
	  L1=sorting->next;
}
else
{
	sorting=L2;
	L2=sorting->next;
	
}
}
newhead=sorting;

while(L1&&L2)
{
	if(L1->info<=L2->info)
	{
		sorting->next=L1;
		sorting=L1;
		L1=sorting->next;
	}
	
	else
	{
		sorting->next=L2;
		sorting=L2;
		L2=sorting->next;
	}
}
if(L1==NULL)
sorting->next=L2;
if(L2=NULL)
{
sorting->next=L1;
return newhead;
}
}

template <class T> void Ordered_list<T>::display()
{
	cout<<"\nTHE ORDERED SINGLY LINKED LIST - ";
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
	Ordered_list<int> O2;
	int c;
	do
	{
		cout << "\n\n******** CHOOSE ONE OF THE GIVEN OPTIONS ********\n";
		cout << "1. INSERT AN ELEMENT (L1)\n";
		cout << "2. ERASE AN ELEMENT (L1)\n";
		cout << "3. INSERT AN ELEMENT (L2)\n";
		cout << "4. ERASE AN ELEMENT (L2)\n";
		cout << "5. MERGE TWO ORDERED SINGLY LINKED LIST (L1+L2)\n";
		cout << "6. DISPLAY THE ORDERED SINGLY LINKED LIST (L1)\n";
		cout << "7. DISPLAY THE ORDERED SINGLY LINKED LIST (L2)\n";
		cout << "8. EXIT\n";
		cout << "\nEnter your choice - ";
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
			case 3 : {	int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						O2.insert(ele);
						break;
					 }
			case 4 : {	O2.display();
						int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						O2.dlt(ele);
						break;
					 }
			case 5 : {	O1.merge(O2);
			             //O1.display();
						break;
					 }
			case 6 : {	O1.display();
						break;
					 }	
			case 7 : {	O2.display();
						break;
					 }
			case 8 : {	cout<<"\n\n..... Exiting ....."<<endl;
						break;
					 }
			default : cout << "\n***** PLEASE ENTER A VALID OPTION *****";
					  break;
		}
	} while(c!=8);
	cout << "\n\n\n******************** THANKYOU ********************";
	return 0;
}
