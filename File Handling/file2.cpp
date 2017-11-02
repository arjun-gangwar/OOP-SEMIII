#include <iostream>
#include <fstream>
using namespace std;

int main()
{
     const int n=50;
     char line[50];
     string country;
     string capital;
     ifstream fin;
     ofstream fout;
     fout.open("country.txt");
     fout<<"United States of America"<<endl;
     fout<<"United Kingdom"<<endl;
     fout<<"South Korea"<<endl;
     fout.close();
     fout.open("capital.txt");
     fout<<"Washington"<<endl;
     fout<<"London"<<endl;
     fout<<"Seoul"<<endl;
     fout.close();
     fin.open("country.txt");
     cout<<"Contents of country file"<<endl;
     while(fin)
     {
          fin.getline(line, n);
          cout<<line<<endl;
     }
     fin.close();
     fin.open("capital.txt");
     cout<<"Contents of capital file"<<endl;
     while(fin)
     {
          fin.getline(line, n);
          cout<<line<<endl;
     }
     fin.close();
     return 0;
}
