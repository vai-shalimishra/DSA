//implementation of extendable array
#include<iostream>
using namespace std;

template<class T>
class ArrayVector
{
	int s;//size(no. of elements)
	int c;//capacity(current size)
	T* arr;
	public:
		ArrayVector();
		int size()const;//this means user can't change anything in this function
		bool empty()const;
		T& operator[](int i);
		T& at(int i);
		void erase(int i);
		void insert(int i,const T& ele);
		void reserve(int p);
		void display();
};

template<class T>ArrayVector<T>::ArrayVector()
{
	c=0;
	s=0;//size start from 0
	arr=NULL;//we can't initialise 0 to an array that's why we store NULL 
	// Here NULL means that arr store nothing
}

template<class T>int ArrayVector<T>::size()const
{
	return s;
}

template<class T>bool ArrayVector<T>::empty()const
{
	return size()==0;
}

template<class T>T&ArrayVector<T>::operator[](int i)
{
	return arr[i];
}

template<class T>T&ArrayVector<T>::at(int i)
{
	if(i<0||i>s)
	{
		cout<<"Error";
		
	}
	return arr[i];
}
template<class T>void ArrayVector<T>::erase(int i)
{
	for(int j=i+1;j<s;j++)
	{
		arr[j-1]=arr[j];
	}
	s--;
}

template<class T>void ArrayVector<T>::reserve(int A)
{  if(c>=A)return;
	T*temp=new T[A];
	for(int j=0;j<s;j++)
	{
		temp[j]=arr[j];
	}
	if(arr!=NULL)
	{
		delete[] arr;
	}
	arr=temp;
	c=A;
}

template<class T>void ArrayVector<T>::insert(int i,const T& ele)
{
	if(s>=c)
	reserve(max(1,2*c));
	for(int j=s-1;j>=i;j--)
	arr[j+1]=arr[j];
	arr[i]=ele;
	s++;
}

template<class T>void ArrayVector<T>::display()
{
	for(int i=0;i<s;i++)
	cout<<arr[i]<<" ";
}

int main()
{
	ArrayVector<int>vector;
	cout<<"checking that the vector is empty or not\n";
	cout<<vector.empty()<<endl;
	cout<<"Insertion\n";
	vector.insert(0,4);
	vector.insert(1,6);
	vector.insert(2,5);
	vector.insert(3,7);
	
	vector.display();
	cout<<endl;
	
	cout<<"size is:";
	cout<<vector.size()<<endl;
	
	//cout<<vector.empty()<<endl;

	cout<<"Erase\n";
	vector.erase(1);
	vector.display();
	cout<<endl;
	
	cout<<"size is:";
	cout<<vector.size()<<endl;
	vector.display();
	cout<<endl;
	cout<<"Value at index\n";
	cout<<vector.at(0)<<endl;
	cout<<vector.at(1)<<endl;
	cout<<"Value at index 0: ";
	cout<<vector[0]<<endl;
	cout<<"The array is:";
	vector.display();
	//vector.display();
	return 0;
	
}
