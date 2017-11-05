#include <iostream>
#include <fstream>
using namespace std;

class directory
{
     string name;
     int number;
public:
     directory()
     {
          name = "no name";
          number = 0;
     }
     void readData();
     void writeData();

     //accessors and mutators
     string getName()
     {
          return name;
     }
     int getNumber()
     {
          return number;
     }
     void setName(string n)
     {
          name = n;
     }
     void setNumber(int n)
     {
          number = n;
     }
};

int main()
{
     int position;
     string key1; //search parameter
     int key2; //search parameter
     string cName;
     int cNumber;
     fstream finout1, finout2;
     directory entry;  //read and write parameter
     int x1=1, choice1;  //menu parameters
     int choice2;  //sub menu parameters
     while(x1)
     {
          cout<<"##### MENU #####"<<endl;
          cout<<"1. add contact"<<endl;
          cout<<"2. search contact"<<endl;
          cout<<"3. update contact"<<endl;
          cout<<"4. delete contact"<<endl;
          cout<<"5. display contacts"<<endl;
          cout<<"6. exit"<<endl;
          cout<<"enter choice: ";
          cin>>choice1;

          switch(choice1)
          {
               case 1:
               finout1.open("file7.dat",ios::out| ios::app| ios::binary);
               // cout<<"tellg: "<<finout1.tellg()<<endl;
               entry.readData();
               finout1.write((char*) &entry, sizeof(entry));
               // cout<<"tellg: "<<finout1.tellg()<<endl;
               finout1.close();
               break;

               case 2:
               cout<<"enter the name to be searched: ";
               cin>>key1;
               finout1.open("file7.dat", ios::in| ios::binary);
               cout<<"tellg: "<<finout1.tellg()<<endl;
               while(finout1.read((char*) &entry, sizeof(entry)))
               {
                    if(entry.getName() == key1)
                    {
                         cout<<"!!! phone record found !!!"<<endl;
                         entry.writeData();
                    }
               }
               finout1.clear();
               finout1.close();
               break;

               case 3:
               cout<<"enter the number to be modify: ";
               cin>>key2;
               finout1.open("file7.dat", ios::in| ios::out| ios::ate| ios::binary);
               finout1.seekg(0, ios::beg);
               cout<<"tellg: "<<finout1.tellg()<<endl;
               while(finout1.read((char*) &entry, sizeof(entry)))
               {
                    if(entry.getNumber() == key2)
                    {
                         position = finout1.tellg() - (streampos) sizeof(entry);
                         break;
                    }
               }
               cout<<"!!! what do you want to modify !!!"<<endl;
               cout<<"1. name"<<endl;
               cout<<"2. number"<<endl;
               cout<<"3. both"<<endl;
               cout<<"enter choice: ";
               cin>>choice2;
               switch(choice2)
               {
                    case 1:
                    cout<<"enter new name: ";
                    cin>>cName;
                    entry.setName(cName);
                    break;

                    case 2:
                    cout<<"enter new number: ";
                    cin>>cNumber;
                    entry.setNumber(cNumber);
                    break;

                    case 3:
                    cout<<"enter new name: ";
                    cin>>cName;
                    entry.setName(cName);
                    cout<<"enter new number: ";
                    cin>>cNumber;
                    entry.setNumber(cNumber);
                    break;

                    default:
                    cout<<"!!! invalid choice !!!"<<endl;
               }
               finout1.seekg(position);
               finout1.write((char*) &entry, sizeof(entry));
               finout1.close();
               break;

               case 4:
               cout<<"enter the number to be deleted: ";
               cin>>cNumber;
               finout1.open("file7.dat", ios::in| ios::out| ios::binary);
               cout<<"tellg1: "<<finout1.tellg()<<endl;
               finout2.open("temp.dat", ios::in| ios::out| ios::binary| ios::trunc);
               cout<<"tellg2: "<<finout2.tellg()<<endl;
               while(finout1.read((char*) &entry, sizeof(entry)))
               {
                    if(entry.getNumber() == cNumber)
                    {
                         continue;
                    }
                    else
                    {
                         finout2.write((char*) &entry, sizeof(entry));
                    }
               }
               finout1.close();
               finout2.close();
               remove("file7.dat");
               rename("temp.dat", "file7.dat");
               break;

               case 5:
               finout1.open("file7.dat", ios::in| ios::binary);
               while(finout1.read((char*) &entry, sizeof(entry)))
               {
                    entry.writeData();
               }
               finout1.clear();
               finout1.close();
               break;

               case 6:
               x1=0;
               break;

               default:
               cout<<"!!! invalid choice !!!"<<endl;
          }
     }
     return 0;
}

void directory::readData()
{
     cout<<"enter name: ";
     cin>>name;
     cout<<"enter mobile number: ";
     cin>>number;
}

void directory::writeData()
{
     cout<<"name: "<<name<<endl;
     cout<<"number: "<<number<<endl;
}
