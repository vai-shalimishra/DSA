//program to evaluate a postfix expression using stacks

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
	cout<<"Enter the postfix expression - ";
	char ch;
	while((ch = getchar())!='\n')
	{
		if(ch>=48 && ch<=57)
		{
			int a=ch-'0';
			s.push(a);
		}
		else
		{
			int num1=s.pop();
			int num2=s.pop();
			switch(ch)
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
