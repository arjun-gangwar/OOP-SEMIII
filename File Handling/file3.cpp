#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
     float arr[] = {175.5, 153.0, 167.25, 160.70};
     ofstream fout;
     fout.open("file3.dat", ios::binary| ios::out);
     cout<<"tellp: "<<fout.tellp()<<endl;
     fout.write((char*)&arr, sizeof(arr));
     cout<<"tellp: "<<fout.tellp()<<endl;
     fout.close();
     for(int i=0; i<4; i++)
     {
          arr[i] = 0;
     }
     ifstream fin;
     fin.open("file3.dat", ios::binary| ios::in);
     cout<<"tellg: "<<fin.tellg()<<endl;
     fin.read((char*)&arr, sizeof(arr));
     cout<<"tellg: "<<fin.tellg()<<endl;
     fin.close();
     for(int i=0; i<4; i++)
     {
          cout.setf(ios::showpoint);
          cout<<setprecision(2)<<arr[i]<<" ";
     }
     cout<<endl;
     return 0;
}
