//program to evaluate a prefix expression using stacks

#include <iostream>
#include <cmath>
using namespace std;

template <class S>
class Stack;

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
		friend class Stack <N>;
};

template <class S>
class Stack
{
	Node<S>* top;
	public:
		Stack()
		{
			top=NULL;
		}
		void push(S ele);
		S pop();
		void display();
};

template <class S> void Stack<S>::push(S ele)
{
	if(top==NULL)
	{
		top=new Node<S>(ele);
		return;
	}
	Node<S>* temp=new Node<S>(ele,top);
	top=temp;
}

template <class S> S Stack<S>::pop()
{
	if(top==NULL)
	{
		cout<<"Error";
		return NULL;
	}
	Node<S>* temp=top;
	S val=temp->info;
	top=top->next;
	delete temp;
	return val;
}

template <class S> void Stack<S>::display()
{
	Node<S>* temp=top;
	cout<<"\nResult -----> "<<pop();
}

int main()
{
	Stack<int> s;
	cout<<"Enter the prefix expression - ";
	string st;
	char ch;
	while((ch = getchar())!='\n')
	{
		st+=ch;
	}
	for(int i=(st.length()-1);i>=0;i--)
	{
		if(st[i]>=48 && st[i]<=57)
		{
			int a=st[i]-'0';
			s.push(a);
		}
		else
		{
			int num2=s.pop();
			int num1=s.pop();
			switch(st[i])
			{
				case '+': s.push(num2+num1);
						  break;
				case '-': s.push(num2-num1);
						  break;
				case '*': s.push(num2*num1);
						  break;
				case '/': s.push(num2/num1);
						  break;
				case '#': s.push(pow(num2,num1));
						  break;
				default : cout<<"Wrong operand entered !!";
						  break;
			}
		}
	}
	s.display();
	return 0;
}
