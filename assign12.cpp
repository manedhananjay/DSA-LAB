#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Employee
{
    int id;
    string name;
    string desg;
    double salary;
};
void add()
{
    Employee e;
    cout<<"\nEnter employee id:";
    cin>>e.id;
    cout<<"\nEnter employee name:";
    cin>>e.name;
    cout<<"\nEnter employee designation:";
    cin>>e.desg;
    cout<<"\nEnter employee salary:";
    cin>>e.salary;
    ofstream file("employee.txt",ios::app);
    file<<e.id<<" "<<e.name<<" "<<e.desg<<" "<<e.salary<<endl;
    file.close();
}
void display()
{
    int id;
    Employee e;
    cout<<"\nEnter id to find employee :";
    cin>>id;
    ifstream file("Employee.txt");
    bool found=false;
    while(file>>e.id>>e.name>>e.desg>>e.salary)
    {
        if(e.id==id)
    {
        found=true;
        cout<<"ID:"<<e.id<<endl;
        cout<<"Name:"<<e.name<<endl;
        cout<<"Designation:"<<e.desg<<endl;
        cout<<"Salary:"<<e.salary<<endl;
        break;
    }
    }
    file.close();
    if(!found)
    {
        cout<<"\nEmployee not found..."<<endl;
    }
}
void deletee()
{
    Employee e;
    int id;
    cout<<"\nEnter id to find employee :";
    cin>>id;
    ifstream file("employee.txt");
    ofstream temp("temp.txt");
    bool found=false;
    while(file>>e.id>>e.name>>e.desg>>e.salary)
    {
        if(e.id!=id)
        {
            temp<<e.id<<" "<<e.name<<" "<<e.desg<<" "<<e.salary<<endl;
        }
        else
        {
            found=true;
        }
    }
    file.close();
    temp.close();
    remove("employee.txt");
    rename("temp.txt","employee.txt");
    if(found)
    {
        cout<<"\n Employee deleted successfully..."<<endl;
    }
    else
    {
        cout<<"\nEmployee not found...!";
    }
}
int main()
{
    int choice;
    do
    {
        cout<<"\n ----MAIN MENU ----";
        cout<<"\n1.Add Employee";
        cout<<"\n2.Display Employee";
        cout<<"\n3.Delete Employee";
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
            default:
                cout<<"\nplease enter correct choice.."; 
        }
    }while(choice!=4);
    return 0;
}