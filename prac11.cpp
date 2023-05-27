#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;
class Employee
{
    typedef struct Emp
    {
        char name[10];
        int emp_id;
        int salary;
        char desgin[20];
    }Rec;

    typedef struct  INDEX
    {
        int emp_id;
        int position;
    }Ind_Rec;
    Rec Records;
    Ind_Rec Ind_Records;

    public:
        Employee();
        void create();
        void display();
        void update();
        void del();
        void append();
        void search();
};
Employee::Employee()
{
    strcpy(Records.name," ");
}
void Employee::create()
{
    int i;
    char ch='y';
    fstream seqfile;
    fstream indexfile;
    i=0;
    indexfile.open("abc.txt",ios::in | ios::out | ios::binary);
    seqfile.open("abc.bcd",ios::in | ios::out | ios::binary);
    do
    {
       cout<<"\nEnter name :";
       cin>>Records.name;
       cout<<"\nEnter Employee ID :";
       cin>>Records.emp_id;
       cout<<"\nEnter salary :";
       cin>>Records.salary;
       cout<<"\nEnter Designation :";
       cin>>Records.desgin;

       seqfile.write((char*)&Records,sizeof(Records))<<flush;
       Ind_Records.emp_id=Records.emp_id;
       Ind_Records.position=i;
       indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
       i++;
       cout<<"\nDo you want to add more records ?";
       cin>>ch;
    } while (ch=='y');
    seqfile.close();
    indexfile.close();
}
void Employee::display()
{
    fstream seqfile;
    fstream indexfile;
    int i;
    indexfile.open("abc.txt",ios::in | ios::out | ios::binary);
    seqfile.open("abc.bcd",ios::in | ios::out | ios::binary);
    indexfile.seekg(0,ios::beg);
    seqfile.seekg(0,ios::beg);

    cout<<"\nThe contents of file are ...."<<endl;
    i=0;

    while (indexfile.read((char*)&Ind_Records,sizeof(Ind_Records)))
    {
        i=Ind_Records.position*sizeof(Rec);
        seqfile.seekg(i,ios::beg);
        seqfile.read((char *)&Records,sizeof(Records));
        if(Records.emp_id!=-1)
        {
            cout<<"\n Name :"<<Records.name;
            cout<<"\n ID :"<<Records.emp_id;
            cout<<"\n Salary :"<<Records.salary;
            cout<<"\n Designation :"<<Records.desgin;
        }
    }
    indexfile.close();
    seqfile.close(); 
}
int main()
{
    Employee e;
    e.create();
    e.display();
}