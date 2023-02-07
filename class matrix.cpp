//#include "matrix.h"
#include <iostream>
using namespace std;
template<class T>
class matrix
{
	//friend ostream& operator<<(ostream&,const matrix<T>&);
public:
	matrix(int theRows=0,int theColumns=0);
	int rows() const{return theRows;}
	int columns() const{return theColumns;}
	matrix<T> operator+(const matrix<T>&)const;
	matrix<T> operator*(const matrix<T>&)const;
	void get(const int& i,const int& j);
	void input();
	void display();
	
public:
	int theRows;//no. of rows in matrix
	int theColumns; //no. of columns in matrix
	int *element; //element array
};
template<class T> void matrix<T>::input()
{
	int theRows,theColumns;
	cout<<"Enter the rows and columns";
	cin>>theRows>>theColumns;
	int *element=new int[theRows*theColumns];
	//cout<<"Enter the matrix"<<endl;
	for (int i = 0; i < theColumns*theRows; ++i)
	{
	cin>>element[i];
		
	}
  }
  
  template<class T>void matrix<T>::display()
{
  
  	//cout<<"The matrix is :\n\t";
  	for (int i = 0; i < theRows; i++)
	{
		for(int j=0;j<theColumns;j++)
      cout<<m1[i][j];
    }
    cout<<"\n\t";
  }
  
//template<class T>void matrix<T>::get(const int& i,const int& j)
//{
//if(i<1||i>theRows||j<1||j>theColumns){
//
//		cout<<"Out of bounds";
//	}
//else
//	cout<<element[(i-1)*theColumns+j-1];
//
//
//}

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
matrix<T> matrix<T>::operator+(const matrix<T>&m) const
{ //Return w=(*this)+m
	if(theRows!=m.theRows||theColumns!=m.theColumns)
		cout<<"Matix size mismatch";
	//create result matrix w
	//matrix<T>m1(theRows,theColumns);
	else
	{	
	matrix<T>w(theRows,theColumns);
	for(int i=0;i<theRows*theColumns;i++){

	w.element[i]=element[i]+m1.element[i];
}

	return w;
}
}
for (int i = 0; i < theColumns*theRows; ++i)
	{
	cout<<w.element[i];
}
int main()
{
//	int theRows,theColumns;
//	cout<<"Enter the rows and columns";
//	cin>>theRows>>theColumns;
//	int *element=new int[theRows*theColumns];
//	cout<<"Enter the matrix"<<endl;
//	for (int i = 0; i < theColumns*theRows; ++i)
//	{
//	cin>>element[i];	
//	}
	matrix<int> m1;
	//matrix<int>m2();
	cout<<"M1"<<endl;
	m1.input();
	
	m1.display();
	//cout<<"no of rows in m1"<<m1.rows()<<endl;
	//cout<<"no of columns in m1"<<m1.columns()<<endl;
	
	
	matrix<int>m2;
	cout<<"M2"<<endl;
	m2.input();
	m2.display();
	//cout<<"no of rows in m1"<<m2.rows()<<endl;
	//out<<"no of columns in m1"<<m2.columns()<<endl;
	cout<<"Addition of two matrices ";
	//	m1.operator+(m2);
	m1+m2;
//	matrix<int>w;
//	w=m1+m2;
//	w.display();

	
	

}
