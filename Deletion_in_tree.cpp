#include<iostream>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
#include<cmath>
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
{    public:
	BSTNode<T>* root;

    void dlt_by_merging(BSTNode<T>*& curr);
	void dlt_by_copying(BSTNode<T>*& curr);
	void find_and_dlt(const T& ele);
	public:
		Tree()
		{
			root=NULL;
		}
};
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
		prev=temp;
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


int main()
{
	Tree<int> t;
	int c,ch;
	
	int ele;
	cout<<"Enter the element - ";
	cin>>ele;
	t.find_and_dlt(ele);
						
	return 0;
	
}
					 				 
			
