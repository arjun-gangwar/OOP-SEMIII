#include <iostream>
using namespace std;

class cppArray
{
     int *arr;
public:
     int n, maxSize;
     cppArray()  //default constructor
     {
          n = 0;
          maxSize = 4;
          arr = nullptr;
     }
     cppArray(const cppArray& c)  //copy constructor
     {
          n = c.n;
          arr = c.arr;
     }

     //overloaded functions
     friend istream& operator>>(istream&, cppArray&);
     friend ostream& operator<<(ostream&, cppArray&);
     int operator[](int);
     void operator=(cppArray&);

     //functions
     void range();

     //getters and setters
     inline int getSize()
     {
          return n;
     }
};

int main()
{
     cppArray c,c1;
     cin>>c;
     cout<<c;
     cout<<c[2]<<endl;
     // c1 = c;
     cout<<c1;
     return 0;
}

istream& operator>>(istream& din, cppArray& c)
{
     cout<<"enter the size of the array: ";
     din>>c.n;
     c.arr = new int[c.n];
     cout<<"enter the elements of the array: ";
     for(int i=0; i<c.n; i++)
     {
          din>>*(c.arr+i);
     }
     return din;
}

ostream& operator<<(ostream& dout, cppArray& c)
{
     dout<<"contents of the array: ";
     for(int i=0; i<c.n; i++)
     {
          dout<<*(c.arr+i)<<" ";
     }
     dout<<endl;
     return dout;
}

int cppArray::operator[](int index)
{
     return *(arr+index);
}

void cppArray::operator=(cppArray& c)
{
     c.n = this->n;
     for(int i=0; i<n; i++)
     {
          c.arr[i] = arr[i];
     }
}
