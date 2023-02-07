//11. Write a program to implement Binary Search Tree which supports the following operations:
//(i) Insert an element x
//(ii) Delete an element x
//(iii) Search for an element x in the BST and change its value to y and then place the node with
//value y at its appropriate position in the BST
//(iv) Display the elements of the BST in preorder, inorder, and postorder traversal
//(v) Display the elements of the BST in level-by-level traversal
//(vi) Display the height of the BST

#include <iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

template <class T>
class Tree;

template <class B>
class BSTNode
{
	B val;
	BSTNode<B>* left;
	BSTNode<B>* right;
	public:
		BSTNode(B info,BSTNode<B>* ptr1=NULL,BSTNode<B>* ptr2=NULL)
		{
			val=info;
			left=ptr1;
			right=ptr2;
		}
		friend class Tree<B>;
};

template <class T>
class Tree
{
	BSTNode<T>* root;
	BSTNode<T>*& recur_insert(BSTNode<T>*& temp,const T& ele);
	const T& recur_search(BSTNode<T>* temp,const T& ele);
	void recur_breadthFirst(Queue_LinkedList<BSTNode<T>*>& q);
	void recur_inorder(BSTNode<T>* temp);
	void recur_postorder(BSTNode<T>* temp);
	void recur_preorder(BSTNode<T>* temp);
	void dlt_by_merging(BSTNode<T>*& curr);
	void dlt_by_copying(BSTNode<T>*& curr);
	int recur_height(BSTNode<T>*& temp);
	int recur_countNodes(BSTNode<T>*& temp);
	int recur_countLeafNodes(BSTNode<T>*& temp);
	int recur_countInternalNodes(BSTNode<T>*& temp);
	public:
		Tree()
		{
			root=NULL;
		}
		void insert(const T& ele);
		void r_insert(const T& ele);
		const T& search(const T& ele);
		void r_search(const T& ele);
		void breadthFirst();
		void r_breadthFirst();	
		void r_inorder();
		void r_postorder();
		void r_preorder();
		void postorder();
		void preorder();
		void inorder();
		void find_and_dlt(const T& ele);
		void height();
		void r_height();
		void r_countNodes();
		void r_countLeafNodes();
		void r_countInternalNodes();
		void replace(const T& x, const T& y);
};

template <class T> void Tree<T>::insert(const T& ele)
{
	if(root==NULL)
	{
		root=new BSTNode<T>(ele);
		cout<<"\nNODE INSERTED SUCCESSFULLY!!!"<<endl;
		return;
	}
	BSTNode<T>* curr=root;
	BSTNode<T>* prev=NULL;
	while(curr!=NULL)
	{
		prev=curr;
		if(ele==curr->val)
		{
			cout<<"\nDuplicate element!!";
			return;
		}
		if(ele<curr->val)
			curr=curr->left;
		else
			curr=curr->right;
	}
	if(ele<prev->val)
	{
		prev->left=new BSTNode<T>(ele);
		cout<<"\nNODE INSERTED SUCCESSFULLY!!!"<<endl;
	}
	else
	{
		prev->right=new BSTNode<T>(ele);
		cout<<"\nNODE INSERTED SUCCESSFULLY!!!"<<endl;
	}
}

template <class T> BSTNode<T>*& Tree<T>::recur_insert(BSTNode<T>*& temp,const T& ele)
{
	if(ele==temp->val)
	{
		cout<<"\nDuplicate element!!";
		return temp;
	}
	if(temp==NULL)
	{
		BSTNode<T>* curr=new BSTNode<T>(ele);
		return curr;
	}
	if(ele<temp->val)
	{
		temp->left=recur_insert(temp->left,ele);
	}
	else if(ele>temp->val)
	{
		temp->right=recur_insert(temp->right,ele);
	}
	return temp;
}

template <class T> void Tree<T>::r_insert(const T& ele)
{
	root=recur_insert(root,ele);
}

template <class T> const T& Tree<T>::search(const T& ele)
{
	BSTNode<T>* temp=root;
	while(temp!=NULL)
	{
		if(ele==temp->val)
			return temp->val;
		else if(ele<temp->val)
			temp=temp->left;
		else
			temp=temp->right;
	}
	return NULL;
}

template <class T> const T& Tree<T>::recur_search(BSTNode<T>* temp,const T& ele)
{
	if(temp==NULL)
		return NULL;
	if(ele==temp->val)
		return temp->val;
	else if(ele<temp->val)
		recur_search(temp->left,ele);
	else
		recur_search(temp->right,ele);
}

template <class T> void Tree<T>::r_search(const T& ele)
{
	if(root==NULL)
	{
		cout<<"\nTree is empty!!";
		return;
	}
	T res=recur_search(root,ele);
	if(res==NULL)
		cout<<"\nElement not found";
	else
		cout<<"\nElement found -- "<<res;
}

template <class T> void Tree<T>::breadthFirst()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	cout<<"\nBREADTH FIRST TRAVERSAL : ";
	Queue_LinkedList<BSTNode<T>*> q;
	BSTNode<T>* temp=root;
	q.enqueue(temp);
	while(!q.empty())
	{
		temp=q.dequeue();
		cout<<temp->val<<" ";
		if (temp->left!=NULL)
			q.enqueue(temp->left);
		if(temp->right!=NULL)
			q.enqueue(temp->right);
	}
}

template <class T> void Tree<T>::recur_breadthFirst(Queue_LinkedList<BSTNode<T>*>& q)
{
	if(!q.empty())
	{
		BSTNode<T>* temp=q.dequeue();
		cout<<temp->val<<" ";
		if (temp->left!=NULL)
			q.enqueue(temp->left);
		if(temp->right!=NULL)
			q.enqueue(temp->right);
		recur_breadthFirst(q);
	}
}

template <class T> void Tree<T>::r_breadthFirst()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	cout<<"\nBREADTH FIRST TRAVERSAL : ";
	Queue_LinkedList<BSTNode<T>*> q;
	q.enqueue(root);
	recur_breadthFirst(q);
}

template <class T> void Tree<T>::recur_inorder(BSTNode<T>* temp)
{
	if(temp==NULL)
		return;
	recur_inorder(temp->left);
	cout<<temp->val<<" ";
	recur_inorder(temp->right);
}

template <class T> void Tree<T>::recur_postorder(BSTNode<T>* temp)
{
	if(temp==NULL)
		return;
	recur_postorder(temp->left);
	recur_postorder(temp->right);
	cout<<temp->val<<" ";
}

template <class T> void Tree<T>::recur_preorder(BSTNode<T>* temp)
{
	if(temp==NULL)
		return;
	cout<<temp->val<<" ";
	recur_preorder(temp->left);
	recur_preorder(temp->right);
}

template <class T> void Tree<T>::r_inorder()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	cout<<"\nINORDER TRAVERSAL : ";
	recur_inorder(root);
}

template <class T> void Tree<T>::r_postorder()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	cout<<"\nPOSTORDER TRAVERSAL : ";
	recur_postorder(root);
}

template <class T> void Tree<T>::r_preorder()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	cout<<"\nPREORDER TRAVERSAL : ";
	recur_preorder(root);
}

template <class T> void Tree<T>::postorder()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	
	cout<<"\nPOSTORDER TRAVERSAL : ";
	BSTNode<T>* p=root;
	Stack_LinkedList<BSTNode<T>*> s;
	do
	{
		while(p!=NULL)
		{
			if(p->right!=NULL)
				s.push(p->right);
			s.push(p);
			p=p->left;
		}
		p=s.pop();
		if(p->right!=NULL && s.top_ele()==p->right)
		{
			BSTNode<T>* q=s.pop();
			s.push(p);
			p=q;
		}
		else
		{
			cout<<p->val<<" ";
			p=NULL;
		}
	} while(!s.empty());
}

template <class T> void Tree<T>::preorder()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	
	cout<<"\nPREORDER TRAVERSAL : ";
	Stack_LinkedList<BSTNode<T>*> s;
	BSTNode<T>* p=root;
	s.push(p);
	while(!s.empty())
	{
		p=s.pop();
		cout<<p->val<<" ";
		if(p->right!=NULL)
			s.push(p->right);
		if(p->left!=NULL)
			s.push(p->left);
	}
}

template <class T> void Tree<T>::inorder()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	
	cout<<"\nINORDER TRAVERSAL : ";
	BSTNode<T>* p=root;
	Stack_LinkedList<BSTNode<T>*> s;
	do
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->left;
		}
		p=s.pop();
		cout<<p->val<<" ";
		p=p->right;
	} while(p!=NULL || !s.empty());
}

template <class T> void Tree<T>::dlt_by_merging(BSTNode<T>*& curr)
{
	BSTNode<T>* temp=curr;
	if(curr->left==NULL)
		curr=curr->right;
	else if(curr->right==NULL)
		curr=curr->left;
	else
	{
		temp=temp->left;
		while(temp->right!=NULL)
			temp=temp->right;
		temp->right=curr->right;
		temp=curr;
		curr=curr->left;
	}
	delete temp;
	cout<<"\nDELETION SUCCESSFUL !!!!";
}

template <class T> void Tree<T>::dlt_by_copying(BSTNode<T>*& curr)
{
	BSTNode<T>* temp=curr;
	BSTNode<T>* prev=NULL;
	if(curr->left==NULL)
		curr=curr->right;
	else if(curr->right==NULL)
		curr=curr->left;
	else
	{
		temp=temp->left;
		prev=curr;
		while(temp->right!=NULL)
		{
			prev=temp;
			temp=temp->right;
		}
		curr->val=temp->val;
		if(prev==curr)
			prev->left=temp->left;
		else
			prev->right=temp->left;
	}
	delete temp;
	cout<<"\nDELETION SUCCESSFUL !!!!";
}

template <class T> void Tree<T>::find_and_dlt(const T& ele)
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	int ch;
	cout<<"Delete by merging(0) or Delete by copying(1) ??? - ";
	cin>>ch;
	BSTNode<T>* temp=root;
	BSTNode<T>* prev=NULL;
	while(temp!=NULL)
	{
		if(ele==temp->val)
			break;
		prev=temp;
		if(ele<temp->val)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(temp!=NULL)
	{
		if(temp==root)
		{
			if(ch==0)
				dlt_by_merging(root);
			else
				dlt_by_copying(root);
		}
		else if(prev->left==temp)
		{
			if(ch==0)
				dlt_by_merging(prev->left);
			else
				dlt_by_copying(prev->left);
		}
		else
		{
			if(ch==0)
				dlt_by_merging(prev->right);
			else
				dlt_by_copying(prev->right);	
		}
	}
	else
		cout<<"\nDeletion unsuccessful..... Element not found in the tree!!";
}

template <class T> void Tree<T>::height()
{
	int height;
	
	if(root==NULL)
		height=0;
	
	else
	{
		Queue_LinkedList<BSTNode<T>*> q;
		q.enqueue(root);
		height=0;
		int nodeCount=1;
	
		while(nodeCount!=0)
		{
			height++;
		    while (nodeCount > 0)
		    {
		    	BSTNode<T>* temp=q.dequeue();
		    	if (temp->left!=NULL)
					q.enqueue(temp->left);
				if(temp->right!=NULL)
					q.enqueue(temp->right);
				nodeCount--;
			}
		    nodeCount=q.display_size(); 
		}
	}
	
	cout<<"\nHeight = "<<height;
}

template <class T> int Tree<T>::recur_height(BSTNode<T>*& temp)
{
	if(temp==NULL)
		return 0;
	int a=recur_height(temp->left);
	int b=recur_height(temp->right);
	return a>b?a+1:b+1;
}

template <class T> void Tree<T>::r_height()
{
	cout<<"\nHeight = "<<recur_height(root);
}

template <class T> int Tree<T>::recur_countNodes(BSTNode<T>*& temp)
{
	if(temp==NULL)
		return 0;
	return recur_countNodes(temp->left)+recur_countNodes(temp->right)+1;
}

template <class T> void Tree<T>::r_countNodes()
{
	cout<<"\nNo. of nodes = "<<recur_countNodes(root);
}

template <class T> int Tree<T>::recur_countLeafNodes(BSTNode<T>*& temp)
{
	if(temp->right==NULL && temp->left==NULL)
		return 1;
	return recur_countLeafNodes(temp->right)+recur_countLeafNodes(temp->left);
}

template <class T> void Tree<T>::r_countLeafNodes()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	cout<<"\nNo. of leaf nodes = "<<recur_countLeafNodes(root);
}

template <class T> int Tree<T>::recur_countInternalNodes(BSTNode<T>*& temp)
{
	if(temp->right!=NULL || temp->left!=NULL)
		return 1;
	return recur_countInternalNodes(temp->right)+recur_countInternalNodes(temp->left);
}

template <class T> void Tree<T>::r_countInternalNodes()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty !!";
		return;
	}
	cout<<"\nNo. of internal nodes = "<<recur_countInternalNodes(root);
}

template <class T> void Tree<T>::replace(const T& x, const T& y)
{
	find_and_dlt(x);
	insert(y);
}

int main()
{
	Tree<int> t;
	int c,ch;
	do
	{
		cout << "\n\n******** CHOOSE ONE OF THE GIVEN OPTIONS ********\n";
		cout << "1. INSERT A NODE\n";
		cout << "2. SEARCH A NODE\n";
		cout << "3. BREADTH FIRST TRAVERSAL\n";
		cout << "4. INORDER TRAVERSAL\n";
		cout << "5. POSTORDER TRAVERSAL\n";
		cout << "6. PREORDER TRAVERSAL\n";
		cout << "7. DELETE A NODE\n";
		cout << "8. DISPLAY HEIGHT\n";
		cout << "9. DISPLAY TOTAL NO OF NODES\n";
		cout << "10. DISPLAY TOTAL NO OF LEAF NODES\n";
		cout << "11. DISPLAY TOTAL NO OF INTERNAL NODES\n";
		cout << "12. REPLACE NODE X WIH NODE Y\n";
		cout << "13. EXIT\n";
		cout << "\nEnter your choice - ";
		cin >> c;
		switch (c)
		{
			case 1 : {	int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						cout<<"Iterative (0) or Recursive(1) ??? - ";
						cin>>ch;
						if(ch==0)
							t.insert(ele);
						else
							t.r_insert(ele);
						break;
					 }
			case 2 : {	int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						cout<<"Iterative (0) or Recursive(1) ??? - ";
						cin>>ch;
						if(ch==0)
							t.search(ele);
						else
							t.r_search(ele);
						break;
					 }	
			case 3 : {	cout<<"Iterative (0) or Recursive(1) ??? - ";
						cin>>ch;
						if(ch==0)
							t.breadthFirst();
						else
							t.r_breadthFirst();
						break;
					 }
			case 4 : {	cout<<"Iterative (0) or Recursive(1) ??? - ";
						cin>>ch;
						if(ch==0)
							t.inorder();
						else
							t.r_inorder();
						break;
					 }
			case 5 : {	cout<<"Iterative (0) or Recursive(1) ??? - ";
						cin>>ch;
						if(ch==0)
							t.postorder();
						else
							t.r_postorder();
						break;
					 }
			case 6 : {	cout<<"Iterative (0) or Recursive(1) ??? - ";
						cin>>ch;
						if(ch==0)
							t.preorder();
						else
							t.r_preorder();
						break;
					 }	
			case 7 : {	int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						t.find_and_dlt(ele);
						break;
					 }
			case 8 : {	cout<<"Iterative (0) or Recursive(1) ??? - ";
						cin>>ch;
						if(ch==0)
							t.height();
						else
							t.r_height();
						break;
					 }
			case 9 : {	t.r_countNodes();
						break;
					 }
			case 10 : {	t.r_countLeafNodes();
						break;
					 }
			case 11 : {	t.r_countInternalNodes();
						break;
					 }
			case 12 : {	int ele1;
						cout<<"Enter the element (x) - ";
						cin>>ele1;
						int ele2;
						cout<<"Enter the element (y) - ";
						cin>>ele2;
						t.replace(ele1,ele2);
						break;
					 }
			case 13: {	cout<<"\n\n..... Exiting ....."<<endl;
						break;
					 }
			default : cout << "\n***** PLEASE ENTER A VALID OPTION *****";
					  break;
		}
	} while(c!=13);
	cout << "\n\n\n******************** THANKYOU ********************";
	return 0;
}
