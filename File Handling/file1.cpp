#include <iostream>
#include <fstream>
using namespace std;

int main()
{
     ofstream fout("file1.txt");  //opening file using constructor
     string item;
     int cost;
     cout<<"enter the name of the item: ";
     cin>>item;
     cout<<"enter the price of the item: ";
     cin>>cost;
     fout<<item<<" "<<cost;
     fout.close();
     ifstream fin("file1.txt");  //opening file using constructor
     fin>>item;
     fin>>cost;
     cout<<endl<<"item name: "<<item;
     cout<<endl<<"cost: "<<cost<<endl;
     fin.close();
     return 0;
}
