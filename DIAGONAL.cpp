#include<iostream>
using namespace std;
template<class D>
class Diagonal
{
	public:
		int size;
		D*arr;  // declaring an array 
		bool flag=1; 
		Diagonal();   //default constructor
		void set(const int& i,const int& j,const D&val);//const int &->a reference to an int object which happens to be const 
		void get(const int& i,const int& j);           // which means we can't modify its value
		void input();
		void display();
		
};

template<class D>Diagonal<D>::Diagonal()
{
	cout<<"Enter the size of diagonal matrix";//it should be square matrix (rows==columns)
	cin>>size;
	arr=new D[size];// total number of values of D datatype  and assigning it to pointer variable *arr.
}
template <class D> void Diagonal<D>::set(const int& i,const int& j,const D& val)
{
	if(i==j)     //i=row,j=column
	{
		arr[i-1]=val;
	}
	else
	{
		if(val!=0)
		{
			cout<<"Wrong input YOU entered at non-diagonal place";
			flag=0;
		}
	}
}
template<class D>void Diagonal<D>::input()
{
  int value;
  cout<<"Enter the elements of diagonal matrix\n";
  for(int i=0;i<size;i++)
  {
  	cout<<"\t\t";
  	for(int j=0;j<size;j++)
  	{
  		cin>>value;
  		set(i,j,value);
  		if(flag==0)
  		return;
    }
  }
}

template<class D>void Diagonal<D>::get(const int& i,const int& j)
{
	if(i==j)
  {
  	cout<<arr[i-1]<<" ";//Here we can also use j instead of i
  	                  //Dispaly the matrix on console
  }
  else
  {
  	cout<<"0"<<" ";
  }
}

template<class D>void Diagonal<D>::display()
{
  if(flag==1)
  {
  	cout<<"The matrix is diagonal matrix\n\t";
  	for(int i=0;i<size;i++)
  	{cout<<endl;
  	for(int j=0;j<size;j++)
  	{
  		get(i,j);
    }
    cout<<"\n\t";
  }
}
}
int main()
{
	Diagonal<int>D;
	D.input();
	D.display();
	return 0;
	
}

