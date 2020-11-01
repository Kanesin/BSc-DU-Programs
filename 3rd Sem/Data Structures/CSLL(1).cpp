#include<iostream>
#include<conio.h>
#include<cstdlib>
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
class CSLL
{	private:
		Node *tail;
	public:		
		CSLL()
		{
			tail=NULL;
		}	
		void insertAtBeg(int data)
		{
			Node *temp=new Node(data);
			if(tail==NULL)
			{
				tail=temp;
				tail->next=tail;
			}
			else
			{
				temp->next=tail->next;
				tail->next=temp;
			}
		}		
		void insertAtEnd(int data)
		{
			Node *temp=new Node(data);
			if(tail==NULL)
			{
				tail=temp;
				tail->next=tail;
			}
			else
			{
				temp->next=tail->next;
				tail->next=temp;
				tail=tail->next;
			}	
		}
		void insertAtk(int data,int k)
		{
			Node *temp=new Node(data);
			if(tail==NULL)
			{
				tail=temp;
				tail->next=tail;
			}
			else if(tail->next==tail && k>1)
				insertAtEnd(data);
			else if(k==1)
				insertAtBeg(data);
			else
			{
				Node *current=tail->next;				
				while(k>2&&current!=tail)
				{
					current=current->next;	
					k--;
				}
				if(current==tail)
					insertAtEnd(data);
				else
				{
					temp->next=current->next;
					current->next=temp;
					current=current->next->next;	
				}				
			}
		}				
		int deleteBeg()
		{
			int val;
			if(tail==NULL)
				throw "Linked List Empty\n";
			else if(tail->next==tail)
				{
					val=tail->info;
					delete tail;
					tail=NULL;
					return val;
				}
			else
				{	
					val=tail->next->info;
					Node *temp=tail->next;
					tail->next=tail->next->next;
					delete temp;
					return val;
				}
		}	
		int deleteEnd()
		{
			int val;
			if(tail==NULL)
				throw "Linked List Empty\n";
			else if(tail->next==tail)
				{
					val=tail->info;
					delete tail;
					tail=NULL;
					return val;
				}
			else
				{	
					val=tail->info;
					Node *temp=tail->next;
					while(temp->next!=tail)
						temp=temp->next;
					temp->next=tail->next;
					delete tail;
					tail=temp;
					return val;
				}
		}	
		int deleteData(int data)
		{
			if(tail==NULL)
					throw "\n Linked List Empty";
			else if (tail->next==tail)
			{
				if(tail->info==data)
					deleteBeg();
				else
					throw "\n No such data in Linked List";
			}
			else if(tail->next->info==data)
				deleteBeg();
			else if(tail->info==data)
				deleteEnd();
			else 
			{
				Node *current=tail->next;
				while(current->next->info!=data&&current!=tail)
					current=current->next;
				if(current!=tail)
				{
					Node*temp=current->next;
					current->next=current->next->next;						
					delete temp;
				}
				else
					throw "\n No such data in Linked List";						
			}
		}
		void count()
		{
			if(tail!=NULL)
			{Node *current=tail->next;
			
				int count=0;
				do{
					current=current->next;				
					count++;
				}while(current!=tail->next);
				cout<<"\n Total Elements in Linked List "<<count;
			}
			else
				cout<<"\n Empty Linked List";
		}			
		void display()
		{	
			int count=1;
			if(tail!=NULL)
			{
				Node *current=tail->next;
				if(current!=tail)
				{		
					while(current!=tail)
					{	
						cout<<"S.NO. "<<count++<<".\t"<<current->info<<"\n";			
						current=current->next;				
					}	
				}
				if(current==tail)
				cout<<"S.NO. "<<count++<<".\t"<<current->info<<"\n";
			}			
			else
				cout<<"\n Empty Linked List";
		}
		bool reverse()
		{
			if(tail!=NULL)
			{
			Node *prev=tail;
			Node *current=tail->next;
			Node *forward=current->next;
			while(current!=tail)
				{	current->next = prev;
					prev=current;
	            	current =forward;            	
	            	forward=forward->next;           	
				}
			if(current==tail)
				current->next=prev;
			tail=forward;							
			}		
		}		
		bool isPresent(int data)
		{	
			int f=0;
			if(tail->info==data)
				return 1;
			else 
			{
				Node *temp=tail->next;				
				while(temp!=tail)
				{	if(temp->info==data)
					{
						f=1;
						break;
					}
					temp=temp->next;
				}
				if(f==1)
					return 1;
				else
					return 0;
			}
		}
		void option()
		{
		int choice;
		cout<<"MENU: \n1.InsertAtBeg \n2.InsertAtEnd \n3.Insert at particular position \n4.Delete from beginning \n5.Delete from end \n6.Delete a particular element \n7.Searching a particular data \n8.Count the num of nodes \n9.Reverse \n10.Display \n11.Exit\nEnter Choice: ";
		cin>>choice;
		menu(choice);                 	
		}
		void menu(int choice)
		{
			int ele;
			int data;
			char ch;
			do
				try
				{
				switch(choice)
				{
					case 1: cout<<"Enter Info: ";
							cin>>ele;
							insertAtBeg(ele);
							break;
					case 2: cout<<"Enter Info: ";
							cin>>ele;
							insertAtEnd(ele);
							break;
					case 3: cout<<"Enter Info: ";
							cin>>ele;
							cout<<"Enter the position where you want to insert";
							int posData;
							cin>>posData;
							insertAtk(ele,posData);
							break;
					case 4: data=deleteBeg();
							cout<<"Deleted data value at Beginning: "<<data<<"\n";	
							break;		
					case 5: data=deleteEnd();
							cout<<"Deleted data value at End: "<<data<<"\n";	
							break;
					case 6: cout<<"Enter a data to delete";
							cin>>ele;
							data=deleteData(ele);
							cout<<"Deleted data value that you entered: "<<data<<"\n";	
							break;
					case 7: cout<<"Enter data to be searched\n";
							cin>>data;
							if(isPresent(data))
							cout<<"Data is present\n";
							else
							cout<<"Data is not present\n";							
							break;		
					case 8: count();
							break;
					case 9: reverse();
							break;		
					case 10:display();
							break;
					case 11:exit(0);
							break;
					default:cout<<"Invalid Input!!!";
					
					}
					cout<<"\nDo you want to continue(Y/N)?: ";
					cin>>ch;	
					if(ch=='Y'||ch=='y')
					{
						option();
					}	
					else
					{
						cout<<"\nExiting!!!";
						exit(0);
						break;
					}
				}
				catch(const char *c)
				{
					cout<<c;
				}
			while(ch=='Y'||ch=='y');
		}
};
int main()
{
	CSLL ob;
	ob.option();
	getch();
	return 0;
}
