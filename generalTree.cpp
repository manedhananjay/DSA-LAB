#include<iostream>
#define max 10
using namespace std;

struct node
{
	int number_of_chapters;
	string chapter_name;
	struct node *next[max];
};
class generalTree
{
	public:
		node* createTree();
		void displayTree(node *root_node);
};
node* generalTree :: createTree()
{
	//string name;
	node *root=new node;
	cout<<"\nEnter the Book name : ";

	cin>>root->chapter_name;
	cout<<"**Book created";

	cout<<"\n\nEnter number of chapters : ";
	cin>>root->number_of_chapters;
	
	for(int i=0; i < root->number_of_chapters; i++)
	{
		root->next[i]=new node;
		cout<<"\nEnter the name of Chapter : ";
		cin>>root->next[i]->chapter_name;

		cout<<"\nEnter the number of sections for "<<root->next[i]->chapter_name;
		cin>>root->next[i]->number_of_chapters;
		for(int j=0; j < root->next[i]->number_of_chapters; j++){
			root->next[i]->next[j]=new node;
			cout<<"\nEnter the section name : ";
			cin>>root->next[i]->next[j]->chapter_name;
		}
		
	}
	cout<<"\n\n\t**Chapters and sections added successfully...!!";
	return root;
	
}
void generalTree :: displayTree(node * root_node)
{
	cout<<"\n\n------ Tree ------";
	cout<<"\nBook name : "<<root_node->chapter_name;
	cout<<"\nNumber of chapter : "<<root_node->number_of_chapters;
	for(int i=0; i < root_node->number_of_chapters; i++)
	{
		cout<<"\n\tName of Chapter "<<i+1<<" : "<<root_node->next[i]->chapter_name;
		cout<<"\n\tNumber of Section of Chapter "<<i+1<<" :"<<root_node->next[i]->number_of_chapters;
		for(int j=0; j < root_node->next[i]->number_of_chapters; j++){
			cout<<"\n\t\tName of Section "<<j+1<<" : "<<root_node->next[i]->next[j]->chapter_name;
		}
	}
}
int main()
{
	int ch;
	generalTree gtObj;
	node *demo;
	do{
	cout<<"\n-----General Tree-----";
	cout<<"\n=== Menu ===";
	cout<<"\n\t1 : Generate Tree\n\t2 : Display Tree\n\t3 : Exit";
	cout<<"\n\nEnter your choice :->";
	cin>>ch;
	switch(ch)
	{
		case 1:
			demo=gtObj.createTree();
		break;
		case 2:
			gtObj.displayTree(demo);
		break;
		case 3:
			cout<<"Program terminated...!!";
		break;
		default:
			cout<<"Enter valid choice...";
		break;
	}
	}while(ch!=3);
}
