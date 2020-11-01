#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace  std;
class Stack
{
	int * items;
	int top,size;
	public:
		Stack(int len)
		{
			items=new int [len];
			top=-1;
			size=len;
		}
		bool isEmpty()
		{
			return (top==-1);
		}
		bool isFull()
		{
			return (top==size-1);
		}
		void push(int value)
		{
			if (isFull())
			cout<<"\n Overflow Condition!";
			else
			{
				top++;
				items[top]=value;
			}
		}
		int pop()
		{
			if (isEmpty())
			{
				cout<<"\n Underflow Condition";
				return -1;
			}
			else
			{
				int value=items[top];
				top--;
				return value;
			}
		}
		int topEle()
		{
			return items[top];
		}
		void display()
		{
			if (!isEmpty())
			{
				for(int i=top;i>-1;i--)
				cout<<items[i]<<"\t";
			}
			else
			cout<<"\n Stack is Empty!";
		}
		void clear()
		{
			while (top!=-1)
			{
				pop();
			}
			cout<<"Cleared!";
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
			int a,data;
			char ch;
			do{
	
						switch(choice)
						{
							case 1:cout<<"Enter the data you want to push in the stack:";
								   cin>>data;
								   push(data);
				                   break;
		                    case 2:a=pop();
								   cout<<"Value deleted is:"<<a<<endl;
						      	   break;
		 					case 3:display();
							       break;	
		                    case 4:clear();
								   break;
						    case 5:topEle();
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
	Stack ob (n);
	ob.option();
	getch();
	return 0;
}


