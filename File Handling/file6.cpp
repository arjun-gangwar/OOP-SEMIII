#include <iostream>
#include <fstream>
using namespace std;

int main()
{
     const int s = 80;
     char str[s];
     int lines = 0, alines = 0;
     ofstream fout("file6.txt", ios::out);
     cout<<"Enter the number of lines you want to enter: ";
     cin>>lines;
     for(int i = 0; i < lines; i++)
     {
          ws(cin);
          cin.getline(str, 80);
          fout<<str<<endl;
     }
     fout.close();
     ifstream fin("file6.txt", ios::in);
     while(!fin.eof())
     {
          fin.getline(str, 80);
          if(str[0] == 'a' || str[0] == 'A')
          {
               alines++;
          }
     }
     cout<<"The number of lines starting with a: "<<lines - alines<<endl;
     fin.close();
     return 0;
}
