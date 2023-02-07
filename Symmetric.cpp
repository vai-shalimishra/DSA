#include<iostream>
using namespace std;
template<class S>
class ST
{
	    public:
		int size;
		S*arr; // declaring an array
		ST(); //default constructor
		int set(const int& i,const int& j,const S&val); //const int &->a reference to an int object which happens to be const 
		void get(const int& i,const int& j);          // which means we can't modify its value
		void input();
		void display();
		 
};

template<class S>ST<S>::ST()
{
	cout<<"Enter the size of square matrix";
	cin>>size;
	arr=new S[(size*(size+1))/2];//1+2+3+4----+n=n(n+1)/2
}

template <class S> int ST<S>::set(const int& i,const int& j,const S& val)
{
	if(i<1||j<1||i>size||j>size)
	{
	cout<<"Matrix Index out of bounds";
    }
	else if(i<=j)
	{
		arr[j*(j-1)/2+i-1]=val;   //column major of UT
	//arr[((size*(i-1))-(((i-2)*(i-1))/2))+(j-i)]=val;  //Row major of UT
    }
	else 
	{
	   //if(arr[((size*(j-1))-(((j-2)*(j-1))/2))+(i-j)]!=val)  //Column major of LT
       if(arr[(i*(i-1))/2+j-1]!=val)    //Row major of LT
       {
       	cout<<"\n  Not a Symmetric Matrix!!!\n";
       	return -1;
	   }
   }
}

    

template<class S>void ST<S>::input()
{
  int value;
  cout<<"Enter the elements of Symmetic elements \n";
  for(int i=1;i<=size;i++)
  {
  	cout<<"\t\t";
  	for(int j=1;j<=size;j++)
  	{
  		cin>>value;
  	int flag=set(i,j,value);
  	if(flag==-1)
  	  return;
   }
  }

}

template<class S>void ST<S>::get(const int& i,const int& j)
{
	
   if(i<0||j<0||i>size||j>size)
   {
	cout<<"Matrix Index out of bounds";
   }
	if(i<=j)
	{
		cout<<arr[j*(j-1)/2+i-1]<<" ";//column major of UT
		//cout<<arr[((size*(i-1))-(((i-2)*(i-1))/2))+(j-i)]<<" ";//row major of UT
   }  
	else 
	{  
	 	cout<<arr[(i*(i-1))/2+j-1]<<" ";//Row major of LT

	   //cout<<arr[((size*(j-1))-(((j-2)*(j-1))/2))+(i-j)]<<" ";//Column major of LT
    }
}

template<class S>void ST<S>::display()
{
  
  	cout<<"The matrix is Symmetric  matrix\n\t";
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
	ST<int>St;
	St.input();
	St.display();
	return 0;
	
}

