#include<iostream>
#include<conio.h>
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
class Stack
{	
	Node *top;
	public:
		Stack()
		{
			top=NULL;
		}
		bool isEmpty()
		{
			if(top==NULL)
			throw "Stack is empty";
			else
			return 1;
		}
		void push(int data)
		{
			Node* temp=new Node(data);
			if(top==NULL)
			{
				top=temp;
			}
			else
			{
				temp->next=top;
				top=temp;
			}
		}
		int pop()
		{
			if(isEmpty()==0)
			{
				//Do Nothing			
			}
			else
			{
				int data=top->info;
				Node* temp=top;
				top=top->next;
				delete temp;
				return data;
			}
		}
		void display()
		{	
			Node* current=top;
			cout<<"STACK: ";
			while(current!=NULL)
			{
				cout<<current->info<<" ";
				current=current->next;
			}
		}
		void clear()
		{
			while(top!=NULL)
			{
				pop();
			}
			cout<<"CLEARED!!";
		}
		void option()
		{
			int choice;
			cout<<"\nMENU:\n1.Push\n2.Pop\n3.Display\n4.Clear\nEnter your choice:";
			cin>>choice;
			menu(choice);
		}
		void menu(int choice)
		{
			int ch,data;
		char ch;
	do{
		try{
	
	switch(choice)
	{
		case 1:
			{
				cout<<"Enter the data you want to push in the stack:";
				cin>>data;
				ob.push(data);
				break;
			}
		case 2:
			{
				int a=ob.pop();
				cout<<"Value deleted is:"<<a<<endl;
				break;
			}
		case 3:
			ob.display();
			break;	
		case 4:
			ob.clear();
			break;
		}
		cout<<"\nDo you want to continue(y/n):";
		cin>>cha;
	}
	catch(const char *msg)
	{
		cout<<msg;
	}
	}while(cha=='y'||cha=='Y');
		}
};
int main()
{
	Stack ob;
	int ch,data;
	char cha;
	do{
		try{
	cout<<"\nMENU:\n1.Push\n2.Pop\n3.Display\n4.Clear\nEnter your choice:";
	cin>>ch;
		//try{
	switch(ch)
	{
		case 1:
			{
				cout<<"Enter the data you want to push in the stack:";
				cin>>data;
				ob.push(data);
				break;
			}
		case 2:
			{
				int a=ob.pop();
				cout<<"Value deleted is:"<<a<<endl;
				break;
			}
		case 3:
			ob.display();
			break;	
		case 4:
			ob.clear();
			break;
		}
		cout<<"\nDo you want to continue(y/n):";
		cin>>cha;
	}
	catch(const char *msg)
	{
		cout<<msg;
	}
	}while(cha=='y'||cha=='Y');
	getch();
	return 0;
}
	
		
