#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student
{
    int id;
    string name;
    string div;
    string add;
};
void add()
{
    Student s;
    ofstream file("student.txt",ios::app);
    cout<<"\nEnter student id:";
    cin>>s.id;
    cout<<"\nEnter student name:";
    cin>>s.name;
    cout<<"\nEnter student division:";
    cin>>s.div;
    cout<<"\nEnter student address:";
    cin>>s.add;
    file<<s.id<<" "<<s.name<<" "<<s.div<<" "<<s.add<<endl;
    file.close();
}
void display()
{
    Student s;
    ifstream file("student.txt");
    int id;
    cout<<"\nEnter employee id :";
    cin>>id;
    bool found=false;
    while(file>>s.id>>s.name>>s.div>>s.add)
    {
        if(s.id==id)
        {
            found=true;
            cout<<"\n ID :"<<s.id;
            cout<<"\n NAME :"<<s.name;
            cout<<"\n DIVISION :"<<s.div;
            cout<<"\n ADDRESS :"<<s.add<<endl;
            break;
        }
    }
    file.close();
    if(!found)
    {
        cout<<"\nStudent not found"<<endl;
    }
}
void deletee()
{
    Student s;
    int id;
    cout<<"\nEnter employee id :";
    cin>>id;
    bool found=false;
    ifstream file("student.txt");
    ofstream temp("temp.txt");
    while(file>>s.id>>s.name>>s.div>>s.add)
    {
        if(s.id!=id)
        {
            temp<<s.id<<" "<<s.name<<" "<<s.div<<" "<<s.add<<endl;
        }
        else
        {
            found=true;
        }
    }
    file.close();
    temp.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
    if(found)
    {
        cout<<"\nStudent deleted successfully..."<<endl;
    }
    else
    {
        cout<<"\nStudent not found....";
    }
}
int main()
{
    int choice;
    do
    {
        cout<<"\n---MAIN MENU---";
        cout<<"\n1.Add student";
        cout<<"\n2.Display student";
        cout<<"\n3.Delete Student";
        cout<<"\n4.Exit";
        cout<<"\nEnter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                deletee();
                break;
            case 4:
                break;
            default:
                cout<<"\nPlease enter correct choice :";
        }
    }while(choice!=4);
    return 0;
}
