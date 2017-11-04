#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class emp
{
     string name;
     int eCode;
public:
     emp() { } //default constructor
     emp(string n, int c)
     {
          name = n;
          eCode = c;
     }
};

int main()
{
     emp e[4];
     e[0] = emp("Amit", 1);
     e[1] = emp("Joy", 2);
     e[2] = emp("Rahul", 3);
     e[3] = emp("Vikas", 4);
     fstream file;
     file.open("file5.dat", ios::in| ios::out);
     for(int i=0; i<4; i++)
     {
          file.write((char*) &e[i], sizeof(e[i]));
     }
     file.seekg(0, ios::end);
     int end = file.tellg();
     cout<<"Number of objects stored in the file: "<<end<<endl;
     return 0;
}
