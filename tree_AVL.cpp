#include <iostream>
#include "queue.h"
using namespace std;

template <class A>
class AVLTree;

template <class N>
class AVLNode
{
	AVLNode<N>* left;
	AVLNode<N>* right;
	AVLNode<N>* parent;
	int height;
	N info;
	public:
		AVLNode(N ele)
		{
			left=right=parent=NULL;
			height=1;
			info=ele;
		}
		friend class AVLTree<N>;
};

template <class A>
class AVLTree
{
	AVLNode<A>* root;
	int height(AVLNode<A>*&);
	AVLNode<A>*& rightRotate(AVLNode<A>*& temp);
	AVLNode<A>*& leftRotate(AVLNode<A>*& temp);
	AVLNode<A>*& insertion(AVLNode<A>*& temp,const A& ele);
	AVLNode<A>*& dlt_node(AVLNode<A>*& curr,const A& ele);
	AVLNode<A>*& balance_tree(AVLNode<A>*& temp,int balance);
	public:
		AVLTree()
		{
			root=NULL;
		}
		void insert(const A&);
		void dlt(const A&);
		void breadthFirst();
};

template <class A> int AVLTree<A>::height(AVLNode<A>*& temp)
{
	if(temp==NULL)
		return 0;	
	return temp->height;
}

template <class A> AVLNode<A>*& AVLTree<A>::leftRotate(AVLNode<A>*& temp)
{
	AVLNode<A>* node=temp->right;
	AVLNode<A>* curr=temp;
	if(curr->right!=NULL)
	{
		curr->right=node->left;
		if(node->left!=NULL)
		{
			node->left->parent=curr;
		}
		node->parent=curr->parent;
		if(curr->parent==NULL)
			root=node;
		else if(curr==curr->parent->left)
			curr->parent->left=node;
		else
			curr->parent->right=node;
	
		node->left=curr;
		curr->parent=node;
		
		curr->height=1+max(height(curr->left),height(curr->right));
		node->height=1+max(height(node->left),height(node->right));
	}
	return node;
}

template <class A> AVLNode<A>*& AVLTree<A>::rightRotate(AVLNode<A>*& temp)
{
	AVLNode<A>* node=temp->left;
	AVLNode<A>* curr=temp;
	if(curr->left!=NULL)
	{
		curr->left=node->right;
		if(node->right!=NULL)
		{
			node->right->parent=curr;
		}
		node->parent=curr->parent;
		if(curr->parent==NULL)
			root=node;
		else if(curr==curr->parent->right)
			curr->parent->right=node;
		else
			curr->parent->left=node;
	
		node->right=curr;
		curr->parent=node;
		
		curr->height=1+max(height(curr->left),height(curr->right));
		node->height=1+max(height(node->left),height(node->right));
	}
	return node;
}

template <class A> AVLNode<A>*& AVLTree<A>::balance_tree(AVLNode<A>*& temp,int balance_factor)
{
	//right sub-tree is causing the imbalance
	if(balance_factor==2)
	{
		//case 1: right sub-tree of right-subtree (right->right)
		if(height(temp->right->left)<=height(temp->right->right))
		{
			return leftRotate(temp);
		}
		//case 2: left sub-tree of right-subtree (right->left)
		else
		{
			temp->right=rightRotate(temp->right);
			return leftRotate(temp);
		}
	}
	
	//left sub-tree is causing the imbalance
	if(balance_factor==-2)
	{
		//case 3: left sub-tree of left-subtree (left->left)
		if(height(temp->left->right)<=height(temp->left->left))
		{
			return rightRotate(temp);
		}
		//case 4: right sub-tree of left-subtree (left->right)
		else
		{
			temp->left=leftRotate(temp->left);
			return rightRotate(temp);
		}
	}
}

template <class A> AVLNode<A>*& AVLTree<A>::insertion(AVLNode<A>*& temp,const A& ele)
{
	//inserting new node
	if(temp==NULL)
	{
		AVLNode<A>* curr=new AVLNode<A>(ele);
		return curr;
	}
	if(ele<temp->info)
	{
		temp->left=insertion(temp->left,ele);
		temp->left->parent=temp;
	}
	else if(ele>temp->info)
	{
		temp->right=insertion(temp->right,ele);
		temp->right->parent=temp;
	}
	
	//updating height of node
	temp->height=1+max(height(temp->right),height(temp->left));
	
	//checking for imbalance of balance factors
	int balance_factor=height(temp->right)-height(temp->left);
	
	if(balance_factor==2 || balance_factor==-2)
		temp=balance_tree(temp,balance_factor);
	return temp;
}

template <class A> AVLNode<A>*& AVLTree<A>::dlt_node(AVLNode<A>*& curr, const A& ele)
{
	if(curr!=NULL)
	{
		if(curr->info==ele)
		{
			//delete by merging
			AVLNode<A>* tmp=curr;
			if(curr->left==NULL)
			{
				curr=curr->right;
				tmp->right->parent=tmp->parent;
			}
			else if(curr->right==NULL)
			{
				curr=curr->left;
				tmp->left->parent=tmp->parent;
			}
			else
			{
				tmp=tmp->left;
				while(tmp->right!=NULL)
					tmp=tmp->right;
				tmp->right=curr->right;
				tmp=curr;
				curr=curr->left;
			}
			delete tmp;
			cout<<"\nDELETION SUCCESSFUL!!!"<<endl;
			return curr;
		}
		else if(ele<curr->info)
			curr->left=dlt_node(curr->left,ele);
		else if(ele>curr->info)
			curr->right=dlt_node(curr->right,ele);
	}
	else
	{
		cout<<"\nDELETION UNSUCCESSFUL!!!"<<endl;
		return curr;
	}
	
	//updating height of node
	curr->height=1+max(height(curr->right),height(curr->left));
	
	//checkig for imbalance of balance factors
	int balance_factor=height(curr->right)-height(curr->left);
	
	if(balance_factor==2 || balance_factor==-2)
		curr=balance_tree(curr,balance_factor);
	return curr;
}

template <class A> void AVLTree<A>::dlt(const A& ele)
{
	if(root==NULL)
	{
		cout<<"Tree is empty !!!";
		return;
	}
	dlt_node(root,ele);
}

template <class A> void AVLTree<A>::insert(const A& ele)
{
	root=insertion(root,ele);
	cout<<"\nINSRETION SUCCESFULL !!!"<<endl;
}

template <class A> void AVLTree<A>::breadthFirst()
{
	if(root==NULL)
	{
		cout<<"Tree is empty !!";
		return;
	}
	cout<<"\nBREADTH FIRST TRAVERSAL : ";
	Queue_LinkedList<AVLNode<A>*> q;
	AVLNode<A>* temp=root;
	q.enqueue(temp);
	while(!q.empty())
	{
		temp=q.dequeue();
		cout<<temp->info<<" ";
		if (temp->left!=NULL)
			q.enqueue(temp->left);
		if(temp->right!=NULL)
			q.enqueue(temp->right);
	}
}

int main()
{
	AVLTree<int> t;
	int c,ch;
	do
	{
		cout << "\n\n******** CHOOSE ONE OF THE GIVEN OPTIONS ********\n";
		cout << "1. INSERT A NODE\n";
		cout << "2. DELETE A NODE\n";
		cout << "3. BREADTH FIRST TRAVERSAL\n";
		cout << "4. EXIT\n";
		cout << "\nEnter your choice - ";
		cin >> c;
		switch (c)
		{
			case 1 : {	int ele;
						cout<<"Enter the element - ";
						cin>>ele;
						t.insert(ele);
						break;
					 }
			case 2 : {	int ele;
						cout<<"Enter the element - ";
						t.dlt(ele);
						break;
					 }	
			case 3 : {	t.breadthFirst();
						break;
					 }
			case 4: {	cout<<"\n\n..... Exiting ....."<<endl;
						break;
					 }
			default : cout << "\n***** PLEASE ENTER A VALID OPTION *****";
					  break;
		}
	} while(c!=4);
	cout << "\n\n\n******************** THANKYOU ********************";
	return 0;
}
