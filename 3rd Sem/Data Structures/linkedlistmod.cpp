#include <iostream>
#include <conio.h>
using namespace std;
class Node
{
	public:
		int info;
		Node *next;
		
		Node(int data)
		{
			info=data;
			next=NULL;
			
				
		}
		
};


class Meth
{
	Node *head,*tail;
	public:
		
		Meth()
		{
			head=tail=NULL;
		}
		void end(int data)
		{
			Node *temp= new Node(data);
			if(head==NULL)
			{
				head=tail=temp;
			}
			else
			{
				tail->next=temp;
				tail=temp;
				
			}
			
		}
		void beg(int data)
		{
			Node *temp1= new Node(data);
			if(head==NULL)
			{
				head=tail=temp1;
			}
			else
			{
				temp1->next=head;
				head=temp1;
			}	
			
		}
		int display()
		{
			Node *temp= head;
			while(temp!=NULL)
			{
				cout<<temp->info;
				temp=temp->next;
				
			}
			
		}
};
int main()
{
	Node *head, *tail;
	Meth obj;
	char y;
	int n;
	
	do{
		cout<<"Enter choice \n 1. Add at start \n 2. Add at end";
		cin>>y;
		cout<<"Enter the element to be entered \n";
		cin>>n;
		
		if(y==1){
			obj.beg(n);
		}
		else
		obj.end(n);
		cout<<"Enter y to continue";
		cin>>y;
	}while(y=='y');
	
	
	obj.display();
	getch();
	return 0;
	
}


