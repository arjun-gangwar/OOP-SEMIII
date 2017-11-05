//<1. old_word> <2. new_word> <3. file_name>

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc,char *argv[])
{
     if(argc < 4)
     {
          cout<<"!!! improper number of arguments !!!"<<endl;
          return 0;
     }
     string a, b, c;
     a = argv[1];
     b = argv[2];
     fstream finout1;
     fstream finout2;
     finout1.open(argv[3], ios::in);
     finout2.open("temp.txt", ios::out| ios::trunc);
     while(getline(finout1,c,' '))
     {
          if(c == a)
          {
               c = b + " ";
               finout2<<c;
          }
          else
          {
               c = c + " ";
               finout2<<c;
          }
     }
     finout1.close();
     finout2.close();
     remove("file8.txt");
     rename("temp.txt", "file8.txt");
     return 0;
}
