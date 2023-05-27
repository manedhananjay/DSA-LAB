#include<iostream>
using namespace std;
class Priority
{
    int front,rear;
    string queue[20];
    int priority[20];
    int size;
    public:
    Priority()
    {
        front=-1;
        rear=-1;
        cout<<"\nEnter size of queue :";
        cin>>size;
       
    }
    bool is_full()
    {
        if(front ==0 && rear==size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_empty()
    {
        if(front==-1 && rear==-1)
        {
            return true;
        }
        else if(rear=front+1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void dol(string name,int val)
    {
        if(is_full()==false)
        {
            if(front==-1 && rear==-1)
            {
                front=0;
                rear=0;
                priority[rear]=val;
                queue[rear]=name;
            }
            else
            {
                int i=rear;
                if(priority[rear]>val)
                {
                    while (val<priority[i] && i>=0)
                    {
                        priority[i+1]=priority[i];
                        queue[i+1]=queue[i];
                        rear=i+1;
                        i--;
                    }
                    priority[i+1]=val;
                    queue[i+1]=name;
                }
                else
                {
                    rear++;
                    priority[rear]=val;
                    queue[rear]=name;
                }
            }
        }
        else
        {
            cout<<"\n Queue is empty ...";
        }
    }

    void insert()
    {
        for(int i=0;i<size;i++)
        {
            string name;
            int val;
            cout<<"\n Enter patient name :";
            cin>>name;
            cout<<"\nEnter patient priority :";
            cin>>val;
            dol(name,val);
        }
    }

    void display()
    {
        cout<<"\n-------Patient list along with their priorities---------"<<endl;
        cout<<"\n";
        for(int i=0;i<size;i++)
        {
            cout<<queue[i]<<"\t";
        }
        cout<<"\n";
        for(int i=0;i<size;i++)
        {
            cout<<priority[i]<<"\t";
        }
    }
};
int main()
{
    Priority p;
    p.insert();
    p.display();
    return 0;
}