#include <iostream>
using namespace std;

class complex
{
     int real;
     int img;
public:
     friend complex operator+(complex&, complex&);
     friend complex operator-(complex&, complex&);
     friend complex operator*(complex&, complex&);
     friend complex operator/(complex&, complex&);
     friend istream& operator>>(istream&, complex&);
     friend ostream& operator<<(ostream&, complex&);
};

int main()
{
     complex c, c1, c2;
     cin>>c1;
     cout<<c1<<endl;
     cin>>c2;
     cout<<c2<<endl;
     c = c1 - c2;
     cout<<c;
     return 0;
}

istream& operator>>(istream& din, complex& c)
{
     cout<<"enter real part: ";
     din>>c.real;
     cout<<"enter imaginary part: ";
     din>>c.img;
     cout<<"the complex number you have entered: "<<c.real<<" + i("<<c.img<<")"<<endl;
     return din;
}

ostream& operator<<(ostream& dout, complex& c)
{
     dout<<"real part: "<<c.real<<endl;
     dout<<"imaginary part: "<<c.img<<endl;
     dout<<"complex number: "<<c.real<<" + i("<<c.img<<")"<<endl;
     return dout;
}

complex operator+(complex& c1, complex& c2)
{
     complex ans;
     ans.real = c1.real + c2.real;
     ans.img = c1.img + c2.img;
     return ans;
}

complex operator-(complex& c1, complex& c2)
{
     complex ans;
     ans.real = c1.real - c2.real;
     ans.img = c1.img - c2.img;
     return ans;
}

complex operator*(complex& c1, complex& c2)
{
     
}

complex operator/(complex& c1, complex& c2)
{

}
