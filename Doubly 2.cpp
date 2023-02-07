#include<iostream>
using namespace std;

template<class T>
class DLinkedList;

template<class T> // list element type
class DNode                // doubly linked list node
{  
	private:
		T elem; // node element value
		DNode<T>* prev; // previous node in list
	public:  
		DNode<T>* next; // next node in list
		friend class DLinkedList<T>; // allow DLinkedList access
};

template<class T>
class DLinkedList {                           // doubly linked list

    private: 
		DNode<T>* header;           
		DNode<T>* trailer;
	
	public:
		DLinkedList();    
		void empty() ;                    // is list empty?
		void front() ;                // get front element
		void back() ;                // get back element
		
		void addFront(T& a);                  	// add to front of list
		void addBack(T& a);                  	// add to back of list
		void removeFront();                   	// remove from front
		void removeBack();                      // remove from back
	
		void add(DNode<T>* v, T& a); 				// insert new node before v
		void remove(DNode<T>* v); 					// remove node v
		void print();
};

template<class T>
DLinkedList<T>::DLinkedList()                      // constructor
{ 
	header = new DNode<T>; 
	trailer = new DNode<T>;
	header->next = trailer;                    // have them point to each other
	trailer->prev = header;
}


template<class T>
void DLinkedList<T>::empty()  // is list empty?
{ 
	bool is= (header->next == trailer); 
	if(is == true)
	{
		cout<<"\nList is empty!!\n";
	}
	if(is == false)
	{
		cout<<"\nList is not empty!!\n";
	}
}

template<class T>
void DLinkedList<T> ::front()  // get front element
{ 
	cout<<"\nFront element of the list is: ";
	cout<< header->next->elem <<" "; 
}

template<class T>
void DLinkedList<T>::back()  // get back element
{ 
	cout<<"\nLast element of the list is: ";
	cout<< trailer->prev->elem; 
}

template<class T>
void DLinkedList<T>::add(DNode<T>* v, T& a) 
{
	DNode<T>* u = new DNode<T>;
	u->elem = a; 									// create a new node for a
	u->next = v; 									// link u in between v
	u->prev = v->prev; 
	v->prev->next = v->prev = u;
	cout<<"\nNew node is successfully added!!\n";
}

template<class T>
void DLinkedList<T>::addFront(T& a) 				// add to front of list
{ 
	add(header->next, a);
	cout<<"\nElement is added successfully at the front of the list!!\n";
}

template<class T>
void DLinkedList<T>::addBack(T& a) 			// add to back of list
{ 
	add(trailer, a);
	cout<<"\nElement is added successfully at the last of the list!!\n";
}

template<class T>
void DLinkedList<T>::remove(DNode<T>* v) 					// remove node v
{				 
	DNode<T>* u = v->prev; 
	DNode<T>* w = v->next; 
	u->next = w;                                    // unlink v from list
	w->prev = u;
	delete v;
}

template<class T>
void DLinkedList<T>::removeFront() // remove from front
{ 
	remove(header->next); 
	cout<<"\nElement is removed from the front successfully!!\n";
}

template<class T>
void DLinkedList<T>::removeBack() // remove from back
{ 
	remove(trailer->prev); 
	cout<<"\nElement is removed from the last successfully!!\n";
}

template<class T>
void DLinkedList<T> ::print()
{
	cout<<"\nDisplaying list !!\n";
	DNode<T>* h=header->next;
	while(h!=trailer)
	{
		cout<<h->elem<<" ";
		h=h->next;
	}
	cout<<endl;
}
int main()
{
	DLinkedList<int> l;
	DNode<int> *head = NULL;
	
	int ch,a;
	char con;
	
	cout<<"Choose from the following : \n"
	    <<"1- Add to front of the List\n"
	    <<"2- Add to the last of the list\n"
	    <<"3- Insert at position\n"
	    <<"4- Delete from first\n"
	    <<"5- Delete from last\n"
	    <<"6- Delete a node from position\n"
	    <<"7- Display the list\n"
	    <<"8- To check whether the list is empty or not\n"
	    <<"9- Display first element\n"
	    <<"10- Display last element\n\n";
		

	do
	{
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nEnter value to the front: ";
			        cin>>a;
			        l.addFront(a);
			        break;
			        
			case 2: cout<<"\nEnter value to the last: ";
			        cin>>a;
			        l.addBack(a);
			        break;
			        
			case 3: cout<<"\nEnter value to insert: ";
			        cin>>a;
			        l.add(head->next->next,a);
			        break;
			        
			case 4: l.removeFront();
			        break;
			        
			case 5: l.removeBack();
			        break;
			
			case 6: l.remove(head->next);
			        break;
			
			case 7: l.print();
			        break;
			        
			case 8: l.empty();
			        break;
			
			case 9: l.front();
			        break;
			        
			case 10: l.back();
			         break;
			         
			default: cout<<"\nInvalid choice !!\n";
		}
		
		cout<<"\n\nDo you want to continue(Y/N) ?? ";
		cin>>con;
	}while(con=='Y'or con=='y');
	
}

