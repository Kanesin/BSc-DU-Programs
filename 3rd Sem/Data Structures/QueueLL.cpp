#include<iostream>
#include<conio.h>
#include<stdlib.h>
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
class Queue
{
	public:
		Node *rear,*front;
		Queue()
		{
			front=rear=NULL;
		}
		bool isEmpty()
		{
			if(front==NULL)
			throw "Underflow";
			else
			return 1;
		}
		void enqueue(int data)
		{
			Node* temp=new Node(data);
			if(front==NULL)
			{
				front=rear=temp;
			}
			else
			{
				rear->next=temp;
				rear=temp;
			}
		}
		int dequeue()
		{
			if(isEmpty()==0)
			{}
			else if(front==rear)
			{
				int data=front->info;
				delete front;
				front=rear=NULL;
				return data;
			}
			else
			{
				int data=front->info;
				Node* temp=front;
				front=front->next;
				delete temp;
				return data;
			}
		}
		void display()
		{
			Node* current=front;
			cout<<"Linked list is:";
			while(current!=NULL)
			{
				cout<<current->info<<" ";
				current=current->next;
			}
		}
		void clear()
		{
			while(front!=NULL)
			{
				dequeue();
			}
			cout<<"Queue is cleared";
		}
		void option()
		{
			int choice;
			cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Clear\nEnter your choice:";
			cin>>choice;
			menu(choice);
		}
		void menu(int choice)
		{
			Queue ob;
			int ch,data;
			char cha;
			do{
					switch(ch)
					{
						case 1:
						{
							cout<<"Enter the data you want to enqueue in the queue:";
							cin>>data;
							enqueue(data);
							break;
						}
						case 2:
						{
							int a=ob.dequeue();
							cout<<"Value deleted is:"<<a<<endl;
							break;
						}
						case 3:ob.display();
							   break;	
						case 4:ob.clear();
							   break;
						}
						cout<<"\nDo you want to continue(y/n):";
						cin>>cha;
				if (cha=='y'||cha=='Y')
				{
					option();
				}
				exit(0);
			}
				while(cha=='y'||cha=='Y');
		}
};
int main()
{
	Queue q;
	q.option();
	getch();
	return 0;
}

	

		

