#include<iostream>
using namespace std;
template<class A>//template class 
class matrix
{
   public:
	int nrows;
	int ncolumns;
	A*arr;//declaring an array
	bool flag;

    matrix()
	{
	    cout<<"enter no of rows";
		cin>>nrows;
		cout<<"Enter the no of columns";
		cin>>ncolumns;
		arr=new A[nrows*ncolumns];//nrows*ncolumns-> Total no of elements
		cout<<"Enter the value of flag";
		cin>>flag;
		if(flag==0)
		{
			cout<<"For row major form";
		}
		else
		{
			cout<<"For column major form";
		}
	}	


	void input()
	{
		for(int i=0;i<nrows;i++)
		{
			for(int j=0;j<ncolumns;j++)
			{
				if(flag==0)
				{
					cin>>arr[i*ncolumns+j];
		
				}
				else
				{
					cin>>arr[i+j*nrows];
				}
			}
		}
	}
	void display()
	{ 
	    for(int k=0;k<(nrows*ncolumns);k++)
		{
	      cout<<arr[k]<<" ";
		}
		cout<<endl<<endl;
		
//		int c=0;
//		for(int i=0;i<nrows;i++)
//		{
//			for(int j=0;j<ncolumns;j++)
//			{
//				if(flag==0)
//				{
//					//cout<<arr[c]<<" ";
//					//c++;
//					cout<<arr[i*ncolumns+j]<<" ";
//				
//				}
//				else
//				{
//					cout<<arr[i+j*nrows]<<" ";
//				}
//				
//			}
//			cout<<endl;
//		
//		
//	
//		}
	}
};
int main(){
	matrix <int>m;
	m.input();
	m.display();
	return 0;
}
	
