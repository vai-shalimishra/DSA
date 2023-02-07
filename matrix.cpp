#include <iostream>
using namespace std;
template<class T>
class matrix
{
public:
	matrix(int theRows=0,int theColumns=0);
    matrix<T> operator+(const matrix<T>&)const;
    matrix<T> operator*(const matrix<T>&)const;
    void input(); //taking input
    void display(); //displaying final matrix
    void set(int i,int j, int val);
    T get(int i, int j);
    

	int theRows;//no. of rows in matrix
	int theColumns; //no. of columns in matrix
	T *element; //element array
};

	
template <class T>
void matrix<T> :: set(int i, int j, int val)
{
	element[i*theColumns+j] = val;
}
		
template <class T>
T matrix<T> :: get (int i, int j)
{
	return element[i*theColumns+j];
}

template <class T>
void matrix<T> :: input()
{
	for(int i=0; i<theRows; i++)
	{
		T val;
		for(int j=0; j<theColumns; j++)
		{
	     	cin>>val;
			//set(i,j,val);
	    }
	}
}		
	
template <class T>
void matrix<T> :: display()
{
	for(int i=0; i<theRows; i++)
	{
		for(int j=0; j<theColumns; j++)
		{
			cout<<get(i,j)<<"  ";
		}
		cout<<endl;
    }
}




template<class T>
matrix<T>::matrix(int theRows,int theColumns)
{  //matrix constructor 
// validate theRows and theColumns
	if(theRows<0||theColumns<0)
		cout<<"Rows and Columns must be >0"<<endl;
		
	if((theRows==0||theColumns==0)&&(theRows!=0||theColumns!=0))
		cout<<"Either both or neither rows and columns should be zero"<<endl;
		//create the matrix
	this->theRows=theRows;
	this->theColumns=theColumns;
	element=new T[theRows*theColumns];
}



// matrix addition
template<class T>
matrix<T> matrix<T> ::operator+(const matrix<T>&m) const
{ //Return w=(*this)+m
	if(theRows!=m.theRows||theColumns!=m.theColumns)
		cout<<"Matix size mismatch";
		
	else
	{
	
	//create result matrix w
	matrix<T>m(theRows,theColumns);
	
	for (int i = 0; i < theColumns*theRows; ++i)
	{
	cin>>element[i];
    }
	matrix<T>w(theRows,theColumns);
	for (int i = 0;i<theColumns*theRows; ++i)
	{
	w.element[i]=element[i]+m.element[i];
	return w;
    }
}
}

int main()
{   
     matrix<int>m1;
      m1.input();
	 cout<<"No of rows in m1"<<m1.theRows<<endl;
    cout<<"No of columns in m1"<<m1.theColumns<<endl;
   
	
   
    cout<<"Matrix m1"<<endl;
    m1.display();
    
    matrix<int>m;
    m.display();
    
    
    matrix<int>w;
    cout<<"w=";
    //w.display();
    
    w=m1+m;
    cout<<"Addition of matrices";
    w.display();


//    matrix<int>m2;
//    m1.operator+(m2);
//    int theRows;
//	int theColumns;
//	cout<<"Enter the rows and columns";
//	cin>>theRows>>theColumns;
//	int *element=new int[theRows*theColumns];
//	cout<<"Enter the matrix"<<endl;
//	for (int i = 0; i < theColumns*theRows; ++i)
//	{
//	cin>>element[i];	
//	}


//m1.input();
//m2.input();

return 0;
}

