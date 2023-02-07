#include <iostream>
using namespace std;

template <class M>

class Matrix
{
	//friend void operator<<(ostream &, const Matrix<M>&);
	int theRows, theColumns;
	M *element;
	public:
		Matrix();//default constructor
		Matrix(int theRows,int theColumns);//parameterised constructor
        void input();
		void display();
		int rows() const {return theRows;}
		int columns() const {return theColumns;}
		Matrix <M> operator+(const Matrix<M>& m) const;
		Matrix<M> operator*(const Matrix<M>& m2) const;
};
template <class M> Matrix<M>::Matrix()
{
	//default constructor
	cout<<"Enter the no of rows - ";
	cin>>theRows;
	cout<<"Enter the no of columns - ";
	cin>>theColumns;
	if(theRows<=0 || theColumns<=0)
		cout<<"Matrix size mismatched";
	else
		element=new M[theRows*theColumns];
}

template <class M> Matrix<M>::Matrix(int theRows,int theColumns)
{
	//parameterized constructor
	if(theRows<=0 || theColumns<=0)
		cout<<"\nError!!!!!! Size should be>=0\n";
	else
	{
		this->theRows=theRows;
		this->theColumns=theColumns;
		element=new M[theRows*theColumns];
	}
}

template <class M> void Matrix<M>::input()
{ 
	cout<<"\nEnter the elements of matrix\n";
	for(int i=0;i<theRows;i++)
	{
		
		for(int j=0;j<theColumns;j++)
		{
			cin>>element[i*theColumns+j];
		}
	}
}

template <class M> void Matrix<M>::display()
{
	for(int i=0;i<theRows;i++)
	{
		for(int j=0;j<theColumns;j++)
		{
			cout<<element[i*theColumns+j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
}


template <class M> Matrix<M> Matrix<M>::operator+(const Matrix<M>& m) const
{
	//addition of  two matrices
	if(theRows!=m.theRows || theColumns!=m.theColumns)
		cout<<"\n Matrices mismatched";   //m.theRows wo matrix ki rows hain jo hum input kra chuke hai(M1)
		                                 //the Rows wo matix hai dubara humne enter krayi hai (M2)
	else
	{
		Matrix<M> w(theRows,theColumns);
		
		for(int i=0;i<(theRows*theColumns);i++)
			w.element[i]=element[i]+m.element[i];
		return w;
	}
}

template <class M> Matrix<M> Matrix<M>::operator*(const Matrix<M>& m2) const
{
	//multiplication of two matrices
	if(theColumns!=m2.theRows)   //yaha par m2.theRows uss matrix ki rows(M2-jisme dono matrix ka addition store hai) hai jisse hum nayi matix ka multipliacton
	                             //karenge aur theColumns nayi input matix ke column hai
	cout<<" Matrices size mismatched";
		
	else
	{
	
		Matrix<M> w(theRows,m2.theColumns);
		int ct=0,cm=0,cw=0;
		//compute w(i,j) for all i and j
	    for(int i=1;i<=theRows;i++)
	{
		
		for(int j=1;j<=m2.theColumns;j++)
		{//compute first term of w(i,j)
			M sum=element[ct]*m2.element[cm];
			
			// add in remaining terms
			for(int k=2;k<=theColumns;k++)
			{
				ct++;//next term in row 
				cm+=m2.theColumns;//next term in column j of m2
				sum+=element[ct]*m2.element[cm];
			}
			w.element[cw++]=sum; //save w(i,j)
			
			//reset to start of row and next column 
			ct-=theColumns-1;
			cm=j;
		}
		//reset to start of next row and first column
		ct +=theColumns;
		cm=0;
	}
return w;
	
}
}


int main()
{
	Matrix<int> M1;
	M1.input();
	cout<<"M1 = "<<endl;
	M1.display();
	
	cout<<"\nNo. of rows in M1 = "<<M1.rows()<<endl;
	cout<<"\nNo. of columns in M1 = "<<M1.columns()<<endl;
	
	

	Matrix<int> M2;	//creating a new object
	M2.input();
	cout<<"\nM2 = "<<endl;
	M2.display();
	
	//cout<<"\nNo.of rows in M2="<<M2.rows()<<endl;
	//cout<<"\nNo.of rows in M2="<<M2.columns()<<endl;
	
	
    M2=M1+M2;	//adding two matrices
	cout<<"M2 = M1+M2"<<endl;
	M2.display();	//resultant matrix
	
	Matrix<int> M3;
	M3.input();
	cout<<"\nM3 = "<<endl;
	M3.display();
	
	
    Matrix<int> M4=M3*M2; //multiplying two matrices
	cout<<"\nM4 = M3*M2"<<endl;
	cout<<"\nM4= "<<endl;
	M4.display();	//resultant matrix
	

	
return 0;
}

