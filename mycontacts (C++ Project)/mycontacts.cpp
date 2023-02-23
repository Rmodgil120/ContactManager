#include<iomanip>
class mycontacts
{
private:
    char name[50],mobile[50],email[50],insta[50],twit[50];
public:
    void accept()
    {
        cout<<endl<<"Enter Name : ";
        cin>>name;
        cout<<endl<<"Enter Mobile : ";
        cin>>mobile;
        cout<<endl<<"Enter email : ";
        cin>>email;
        cout<<endl<<"Enter Instagram ID : ";
        cin>>insta;
        cout<<endl<<"Enter Twitter ID : ";
        cin>>twit;
    }
    void display()
    {
        cout<<endl;
        cout<<left;
        cout<<setw(30);
        cout<<name;
        cout<<setw(35);
        cout<<email;
        cout<<setw(15);
        cout<<mobile;
        cout<<setw(20);
        cout<<insta;
        cout<<setw(20);
        cout<<twit;
    }
    friend void remove_contact();
    friend void update_contact();
    friend void namesearch();
    friend void numbersearch();
    friend void emailsearch();
    friend void add_mycontacts();
};
void remove_contact();//friend function is declared here
void update_contact();
void namesearch();
void numbersearch();
void emailsearch();
void add_mycontacts();
