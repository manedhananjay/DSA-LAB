#include<iostream>
using namespace std;
typedef struct btree
    {
        int data;
        struct btree *left,*right;
    
    }node;
    node *root,*New,*temp,*parent;
class bintree
{
    public:
    bintree()
    {
        root=NULL;
    }
    public:
    void create();
    void insert(node *,node *);
    void display();
    void delet();
    void find();
    void min();
    void max();

    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void search(node **,int,node **);
    void del(node *,int);
    
};
void bintree :: create()
{
    int c;
    do
    {
       
        New=new node;
        New->left=NULL;
        New->right=NULL;
        cout<<"\n Enter The Element:";
        cin>>New->data;
        if(root==NULL)
        {
            root=New;
        }
        else
        {
            insert(root,New);
        }
        cout<<"\n Do you want to add more elements is yes then press 0 otherwise press 1 :";
        cin>>c;
    }while(c==0);
}
void bintree::insert(node *root,node *New)
{
    if(New->data < root->data)
    {
        if(root->left==NULL)
        {
            root->left=New;
        }
        else
        {
            insert(root->left,New);
        }
    }
    if(New->data > root->data)
    {
        if(root->right==NULL)
        {
            root->right=New;
        }
        else
        {
            insert(root->right,New);
        }
    }
}

void bintree::display()
{
    if(root==NULL)
    {
        cout<<"\nTree is not created";
    }
    else
    {
        cout<<"\n Thre tree is :";
        cout<<"\n Inorder representation of tree is :",inorder(root);
        cout<<"\n Preorder representation of tree is :",preorder(root);
        cout<<"\n Postorder representation of tree is :",postorder(root);
        cout<<"\n Minimum element of tree is :",min();
        cout<<"\n Minimum element of tree is :",max();
    }
}
void bintree::inorder(node *temp)
{
    if(temp!=NULL)
    {
            inorder(temp->left);
            cout<<" "<<temp->data;
            inorder(temp->right);
    }
}
void bintree::preorder(node *temp)
{
    if(temp!=NULL)
    {
            cout<<" "<<temp->data;
            preorder(temp->left);
            preorder(temp->right);
    }
}
void bintree::postorder(node *temp)
{
    if(temp!=NULL)
    {
            postorder(temp->left);
            postorder(temp->right);
            cout<<" "<<temp->data;
    }
}

void bintree::min()
{
    node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    cout<<temp->data<<endl;
}

void bintree::max()
{
    node *temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    cout<<temp->data<<endl;
}
int main()
{
    int choice=0;
    bool flag=false;
    int element;
    bintree bt;
    do
    {
         cout<<"\n 1.Create \n 2.Display \n 3.Mirror \n 4.Find \n5.Exit";
         cout<<"\n Enter Your choice :";
         cin>>choice;
         switch (choice)
         {
            case 1:
                bt.create();
                break;
            case 2:
                bt.display();
                break;
            case 3:
                temp=root;
                node *t;
                t=temp->left;
                temp->left=temp->right;
                temp->right=t;
                cout<<"\n Inorder Mirror is :";
                bt.inorder(temp);
                break;
            case 4:
                cout<<"\n Enter element do you want to search :";
                cin>>element;

                temp=root;
                if(element > root->data)
                {
                    while(temp!=NULL)
                    {
                        temp=temp->right;
                        if(temp->data == element || temp->left->data==element)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
                else
                {
                    while(temp!=NULL)
                    {
                        temp=temp->left;
                        if(temp->data == element || temp->right->data==element)
                        {
                            flag=true;
                            break;
                        }
                    }
                }

                if(flag)
                {
                    cout<<"\n Element is found :";
                }
                else
                {
                    cout<<"\n Element does not found :";
                }
                break;
         default:
            cout<<"\n Enter correct choice :";
         }
    } while (choice!=4);
    
   
}