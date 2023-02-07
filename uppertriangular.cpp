#include<iostream>
using namespace std;
template<class U>
class UT
{
	public:
		int size;
		U*arr;// declaring an array
		char flag;
		UT();//default constructor
		void set(const int& i,const int& j,const U&val);//const int &->a reference to an int object which happens to be const
		void get(const int& i,const int& j);           // which means we can't modify its value
		void input();
		void display();
		
};

template<class U>UT<U>::UT()
{
	cout<<"Enter the size of square matrix";//it should be square matrix (rows==columns)
	cin>>size;
	arr=new U[(size*(size+1))/2];//1+2+3+4----+n=n(n+1)/2
	                             //// total number of values of U datatype  and assigning it to pointer variable *arr.
	cout<<"Enter R for row major form "<<"or enter C for column major form";
	cin>>flag;
}

template <class U> void UT<U>::set(const int& i,const int& j,const U& val)
{
	if(i<=j)
	{
		if(flag=='R')
		{
			//arr[((i*size)-(((i-1)*(i))/2))+(j-i)]=val; //this is formula if user use value of i and j from 0 to size
			arr[((size*(i-1))-(((i-2)*(i-1))/2))+(j-i)]=val;
			
		}
		else
		{
			//arr[((j*(j+1))/2)+i]=val; //this is the formula if user use value of i and j from 0 to size
			 arr[(j*(j-1))/2+i-1]=val;
			
			
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

template<class U>void UT<U>::input()
{
  int value;
  cout<<"ENTER THE ELEMENTS\n";
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

template<class U>void UT<U>::get(const int& i,const int& j)
{
	if(i<=j)
  {
  	if(flag=='R')
  	{
  		//cout<<arr[((i*size)-(((i-1)*(i))/2))+(j-i)]; //this is formula if user use value of i and j from 0 to size
		cout<<arr[((size*(i-1))-(((i-2)*(i-1))/2))+(j-i)]<<" ";
			
	}
		else
		{
			
		//cout<<arr[((j*(j+1))/2)+i]; //this is the formula if user use value of i and j from 0 to size
			 cout<<arr[(j*(j-1))/2+i-1]<<" ";
			
		}
		

  }
  else
  {
  	cout<<"0"<<" ";
  }
}

template<class U>void UT<U>::display()
{
  
  	cout<<"The matrix is upper triangular matrix\n\t";
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
	UT<int>Ut;
	Ut.input();
	Ut.display();
	return 0;
	
}

