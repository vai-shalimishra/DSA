#include<iostream>
using namespace std;
class Tuple
{
	public:
		int ri,ci,val;
};

int main()
{
	int nrows,ncolumn,nzero;
	cout<<"Enter the no of rows";
	cin>>nrows;
	cout<<"Enter the no of columns";
	cin>>ncolumn;
	cout<<"Enter the no of non zero elements";
	cin>>nzero;
	Tuple *T=new Tuple[nzero];//dynamic array allocation of 1-D array
	//total number of values(nzero) of Tuple datatype  and assigning it to pointer variable *T.
	for(int i=0;i<nzero;i++)
	{
		cout<<"Enter row then column then value";
		cin>>T[i].ri;
		cin>>T[i].ci;
		cin>>T[i].val;
	}
	int curr=0;
	//cout<<"The Sparse matrix is:"<<endl;
	for(int i=0;i<nrows;i++)
	{
		
		for(int j=0;j<ncolumn;j++)
		{
			if(i<T[curr].ri)
			cout<<"0 ";
			else if(i==T[curr].ri)
			{
				if(j==T[curr].ci)
				{
					cout<<T[curr].val<<" ";
					curr++;
				}
				else if(j<T[curr].ci)
				cout<<"0 ";
			}
			else 
			cout<<"0"<<" ";
		}
		cout<<endl;
	}
}
