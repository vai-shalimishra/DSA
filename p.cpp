#include <iostream>
using namespace std;

template <class TD>
class Tri_Diagonal
{
	public:
		int size;
		TD *arr; // declaring an array
		bool flag=1;
		Tri_Diagonal(); //default constructor
		void set(const int& i,const int& j, const TD& val); //const int &->a reference to an int object which happens to be const
		void get(const int& i,const int& j);              //which means we can't modify its value
		void input();
		void display();
};

template <class TD> Tri_Diagonal<TD>::Tri_Diagonal()
{
	cout<<"Enter the size of tridiagonal matrix - ";//it should be square matrix (rows==columns)
	cin>>size;
	arr=new TD[3*size-2];/*element in left diagonal,right diagonal and main diagonal is n-1 so total non-zeroelements are 
	                         n-1+n-1+n-1=3n-2               : (n=size)
	                        -> total number of values of TD datatype  and assigning it to pointer variable *arr */
}

template <class TD> void Tri_Diagonal<TD>::set(const int& i,const int& j, const TD& val)
{
	switch(i-j)
	{
		case 1 : arr[i-2]=val;  //For left diagonal; we can also take j-1  in instead of i-2
				 break;
		case 0 : arr[size-1+i]=val; //For main diagonal
				 break;
		case -1 : arr[2*size-1+i]=val; //For right diagonal
				  break;
		default : {
					if(val!=0)
					{
						cout<<"\n\nError!!! Entered non-zero value at non-tridiagonal place!!!!";
						flag=0;
					}
					break;
				}
	}
}

template <class TD> void Tri_Diagonal<TD>::input()
{
	int value;
	cout<<"Enter the elements of tridiagonal matrix---- \n";
	for(int i=1;i<=size;i++)
	{
		cout<<"\t\t";
		for (int j=1;j<=size;j++)
		{
			cin>>value;
			set(i,j,value);
			if(flag==0)
				return;
		}
	}
}

template <class TD> void Tri_Diagonal<TD>::get(const int &i,const int &j)
{
	
	switch(i-j)
	{
		case 1 : cout<<arr[i-2]<<" ";//if(i==(j+1))
				 break;
		case 0 : cout<<arr[size-1+i]<<" ";//else if(i==j)
				 break;
		case -1 : cout<<arr[2*size-1+i]<<" ";//else if(i==(j-1))
				  break;
		default : cout<<"0 ";//else "0"
				  break;
	}
}

template <class TD> void Tri_Diagonal<TD>::display()
{
	if(flag==1)
	{
		cout<<"\n\nThe tridiagonal matrix is- \n\t";
		for(int i=1;i<=size;i++)
		{
			for (int j=1;j<=size;j++)
			{
				get(i,j);
			}
			cout<<"\n\t";
		}
	}

}

int main()
{
	Tri_Diagonal <int>Td;
	Td.input();
	Td.display();
}
