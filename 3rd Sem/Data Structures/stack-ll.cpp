#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class Node{
	public:
		int info;
		Node *next;
		Node(int data)
		{
			info=data;
			next=NULL;
		}
};
class stack{
	public:
	Node *top;
	stack()
	{
		top=NULL;
	}
	void push(int data)
	{
		Node *temp=new Node(data);
			if(top==NULL)
				top=temp;
			else
			{
				temp->next=top;
				top=temp;	
			}
	}
	
	int pop()
	{
		int val;
		if(top==NULL)
			throw "Stack is empty";
		else 
		{	
			val=top->info;
			Node *temp=top;
			top=top->next;
			delete temp;
			return val;					
		}
	}
	
	int topVal()
	{
		if(top!=NULL)
			return top->info;
		else
			throw "Stack is empty";
	}
	void display()
	{
		Node *current=top;
			if(current!=NULL)
			{
				int count=1;
				while(current!=NULL)
				{	
					cout<<"S.NO. "<<count++<<".\t"<<current->info<<"\n";			
					current=current->next;				
				}
			}
			else
				cout<<"Stack is Empty\n";
	}
	
	void clear()
	{
		if(top==NULL)
			throw "Linked List is empty";
		else
			{
				Node* current=top->next;
				Node* prev=top;
				while(current!=NULL)
				{
					delete prev;
					prev=current;
					current=current->next;
				}
				if(current==NULL)
					delete prev;
				top=NULL;
			}
	}
	
	int menu()
	{
		cout<<"\nMENU\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Clear\n";
		cout<<"4. display\n";
		cout<<"5. Exit\n";
		cout<<"Enter Choice\n";
		int ch;
		cin>>ch;
		return ch;		
	}
	
	void prog()
	{
		try
		{
			int data,ch;
			do{
				ch=menu();
				switch (ch)
				{
					case 1: cout<<"Enter Data\n";
							cin>>data;
							push(data);
					break;
					case 2: data=pop();
							cout<<"\n Deleted Data= "<<data;
					break;
					case 3: clear();
							cout<<"Deleted All Data\n";
					break;
					case 4: display();
					break;
					case 5:exit(0);
					break;
					default: cout<<"wrong choice entered\n";
							exit(0);						
				}
			}while(true);
		}
		catch(const char*c)
		{
			cout<<c;
		}
	}
};

int main()
{	
	stack s;
	s.prog();	
	getch();
}
