#include<iostream>
using namespace std;
template<class L>
class LT
{
	public:
		int size;
		L*arr; // declaring an array
		char flag;
		LT(); //default constructor
		void set(const int& i,const int& j,const L&val); //const int &->a reference to an int object which happens to be const 
		void get(const int& i,const int& j);           //which means we can't modify its value
		void input();
		void display();
		
};

template<class L>LT<L>::LT()
{
	cout<<"Enter the size of lower triangular matrix";//it should be square matrix (rows==columns)
	cin>>size;
	arr=new L[(size*(size+1))/2];//1+2+3+4----+n=n(n+1)/2
	                             //// total number of values of L datatype  and assigning it to pointer variable *arr.
	cout<<"Enter R for row major form "<<"or enter C for column major form";
	cin>>flag;
}

template <class L> void LT<L>::set(const int& i,const int& j,const L& val)
{
	if(i>=j)
	{
		if(flag=='R')
		{
			//arr[((i*(i+1))/2)+j]=val;//this is the formula if user use value of i and j from 0 to size
			 arr[(i*(i-1))/2+j-1]=val;
		}
		else
		{
			
			//arr[((j*size)-(((j-1)*(j))/2))+(i-j)]=val;//this is formula if user use value of i and j from 0 to size
			arr[((size*(j-1))-(((j-2)*(j-1))/2))+(i-j)]=val;
			
			
		}
	}
	else
	{
		if(val!=0)
		{
			cout<<"Value entered at wrong place";
			
		}
	}
	return;
}

template<class L>void LT<L>::input()
{
  int value;
  cout<<"Enter the elements of lower triangualar matrix\n";
  for(int i=1;i<=size;i++)
  {
  	cout<<"\t\t";
  	for(int j=1;j<=size;j++)
  	{
  		cin>>value;
  	set(i,j,value);
   }
  }
}

template<class L>void LT<L>::get(const int& i,const int& j)
{
	if(i>=j)
  {
  	if(flag=='R')
  	{
			//cout<<arr[((i*(i+1))/2)+j]<<" ";//this is the formula if user use value of i from 0 to size
			cout<<arr[(i*(i-1))/2+j-1]<<" ";
	}
	else
	{
			//cout<<arr[((j*size)-(((j-1)*(j))/2))+(i-j)]<<" ";//another formula for column major
		  cout<<arr[((size*(j-1))-(((j-2)*(j-1))/2))+(i-j)]<<" ";
	}
	

  }
  else
  {
  	cout<<"0"<<" ";
  }
}

template<class L>void LT<L>::display()
{
  
  	cout<<"The matrix is lower triangular matrix\n\t";
  	for(int i=1;i<=size;i++)
  	{
  	for(int j=1;j<=size;j++)
  	{
  		get(i,j);
    }
    cout<<"\n\t";
  }
}

int main()
{
	LT<int>Lt;
	Lt.input();
	Lt.display();
	return 0;
	
}

