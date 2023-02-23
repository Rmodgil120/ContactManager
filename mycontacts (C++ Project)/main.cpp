#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#include "mycontacts.cpp"
mycontacts obj; //this is a global function now
void update_contact()
{
    int flag =0, flag2=1;
    char name[50];
    cout<<endl<<"Enter Name: ";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1; i<=size; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            cout<<endl<<"Record Matched";
            obj.accept();
            flag2 = 0;
        }
        wr.write((char *)&obj,sizeof(obj));
        flag = flag + 1;
    }
    if(flag==size && flag2 ==1)
    {
        cout<<"Record Not found";
    }
    rd.close();
    wr.close();
    remove("mydatafile.txt");
    rename("tempfile.txt", "mydatafile.txt");
}
void remove_contact()
{
    int flag = 0,flag2 = 1;
    char name[50];
    cout<<endl<<"Enter Name: ";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1; i<=size; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            cout<<endl<<"Record deleted";
            flag2 = 0;
        }
        else
        {
            wr.write((char *)&obj,sizeof(obj));
            flag = flag + 1;
        }
    }
    if(flag==size)
    {
        cout<<"Record Not found";
    }
    rd.close();
    wr.close();
    remove("mydatafile.txt");
    rename("tempfile.txt", "mydatafile.txt");
}
void read_data()
{
    fstream rd;
    rd.open("mydatafile.txt", ios::in);
    rd.seekg(0, ios::end);
    cout<<endl<<"Size of file is: "<<rd.tellg();
    cout<<endl<<"Number of objects is: "<<rd.tellg()/sizeof(obj)<<endl;
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0, ios::beg);
    cout<<endl;
    cout<<left;
    cout<<setw(30);
    cout<<"Name";
    cout<<setw(35);
    cout<<"Email ID";
    cout<<setw(15);
    cout<<"Mobile No.";
    cout<<setw(20);
    cout<<"Insta ID";
    cout<<setw(20);
    cout<<"Twitter ID";
    cout<<endl<<"----------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=1; i<=s ; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        obj.display();
    }
}
void add_mycontacts()
{
    int flag = 0;
    char name[50];
    cout<<endl<<"Enter Name: ";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1; i<=size; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<endl<<"Duplicate name is not allowed";
    }
    else
    {
        obj.accept();
        fstream wr;
        wr.open("mydatafile.txt",ios::app);
        wr.write((char*)&obj, sizeof(obj));
        wr.close();
        cout<<endl<<"File written";
    }
}
void namesearch()
{
    int flag = 0;
    char name[50];
    cout<<endl<<"Enter Name: ";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1; i<=size; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        obj.display();
    }
    else
    {
        cout<<endl<<"Name not found";
    }
}
void numbersearch()
{
    int flag =0;
    char mobile[50];
    cout<<endl<<"Enter Mobile number: ";
    cin>>mobile;
    fstream rd;
    rd.open("mydatafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1; i<=size; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.mobile,mobile)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        obj.display();
    }
    else
    {
        cout<<endl<<"Mobile number not found";
    }
}
void emailsearch()
{
    int flag=0;
    char email[50];
    cout<<endl<<"Enter Email ID: ";
    cin>>email;
    fstream rd;
    rd.open("mydatafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1; i<=size; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.email,email)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        obj.display();
    }
    else
    {
        cout<<endl<<"Email ID  not found";
    }
}
int main()
{
    int choice;
    int e=0;
    while(e==0)
    {
        cout<<endl<<"Enter 1 to Add a new contact ";
        cout<<endl<<"Enter 2 to Display all contacts ";
        cout<<endl<<"Enter 3 to Update a contact ";
        cout<<endl<<"Enter 4 to delete a contact ";
        cout<<endl<<"Enter 5 to search by name ";
        cout<<endl<<"Enter 6 to search by mobile number ";
        cout<<endl<<"Enter 7 to search by email ID ";
        cout<<endl<<"Enter 8 to exit ";
        cout<<endl<<"Your choice: ";
        cin>>choice;
        if(choice == 1)
        {
            add_mycontacts();
        }
        else if(choice == 2)
        {
            read_data();
        }
        else if(choice == 3)
        {
            update_contact();
        }
        else if(choice == 4)
        {
            remove_contact();
        }
        else if(choice == 5)
        {
            namesearch();
        }
        else if(choice == 6)
        {
            numbersearch();
        }
        else if(choice == 7)
        {
            emailsearch();
        }
        else if(choice == 8)
        {
            e = 1;
        }
        else
        {
            e = 1;
        }
    }
}
