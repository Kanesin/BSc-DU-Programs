#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace  std;
class Queue
{
	int * items;
	int size,front,rear;
	public:
		Queue(int capacity)
		{
			front=rear=-1;
			items=new int (capacity);
			size=capacity;
		}
		bool isFull()
		{
			return((rear+1)%size==front);
		}
		bool isEmpty()
		{
			return(front==-1);
		}
		void enqueue(int val)
		{
			if (isFull())
			cout<<"\n Overflow Condition";
			else
			{
				rear=(rear+1)%size;
				items[rear]=val;
				if (front==-1)
				front=0;			
			}
		}
		int dequeue()
		{
			if (isEmpty())
			{
				cout<<"\n Underflow Condition";
				return -1;
			}
			else
			{
				int v=items[front];
				front=(front+1)%size;
				if ((rear+1)%size==front)
				{
					rear=front=-1;
				}
				return v;
			}
		}
		void display()
		{
			if (isEmpty())
				cout<<"\n Queue is Empty";
			else
			{
				int i=front;
				while (i!=rear)
				{
					cout<<items[i];
					i=(i+1)%size;
				}
				cout<<items[i];
			}
		}
		void option()
		{
			int choice;
			cout<<"\nMENU:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Clear\nEnter your choice:";
			cin>>choice;
			menu(choice);
		}
		void menu(int choice)
		{
			int a,data;
			char ch;
			do{
	
						switch(choice)
						{
							case 1:cout<<"Enter the data you want to enqueue in the stack:";
								   cin>>data;
								   enqueue(data);
				                   break;
		                    case 2:a=dequeue();
								   cout<<"Value deleted is:"<<a<<endl;
						      	   break;
		 					case 3:display();
							       break;		   
							default: cout<<"\n Invalid Input!";
						}
						cout<<"\nDo you want to continue(y/n):";
						cin>>ch;
						if (ch=='y'||ch=='Y')
						{
							option();
						}
						exit(0);
				  }
			while(ch=='y'||ch=='Y');
		}
};
int main()
{
	int n;
	cout<<"Enter the size of Stack";
	cin>>n;
	Queue ob (n);
	ob.option();
	getch();
	return 0;
}

