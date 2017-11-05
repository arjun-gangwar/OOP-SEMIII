#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class inventory
{
     char name[10];
     int code;
     float cost;
public:
     void readData();
     void writeData();
};

int main()
{
     inventory item[3];
     fstream file;
     file.open("ARJUN.dat", ios::in| ios::out);
     cout<<"tellp: "<<file.tellp()<<endl;
     for(int i=0; i<3; i++)
     {
          item[i].readData();
          file.write((char*)&item[i], sizeof(item[i]));
          cout<<"tellp: "<<file.tellp()<<endl;
     }
     cout<<"tellp: "<<file.tellp()<<endl;
     file.seekg(0);
     cout<<"OUTPUT: "<<endl;
     for(int i=0; i<3; i++)
     {
          file.read((char*)&item[i], sizeof(item[i]));
          item[i].writeData();
     }
     file.close();
     return 0;
}

void inventory::readData()
{
     cout<<"Item name: ";
     cin>>name;
     cout<<"Item code: ";
     cin>>code;
     cout<<"Item cost: ";
     cin>>cost;
}

void inventory::writeData()
{
     cout << setiosflags(ios::left)
          << setw(10) << name
          << setiosflags(ios::right)
          << setw(10) << code
          << setprecision(2)
          << setw(10) <<cost
          << endl;
}
