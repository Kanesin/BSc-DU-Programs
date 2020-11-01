#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
	public:
		int info;
		Node *next,*prev;
		Node(int data)
		{
			info=data;
			next=prev=NULL;
		}		
};
class DLL
{
	Node *head,*tail;
	public:
		DLL()
		{
			head=tail=NULL;
			
		}
		
		void insert_at_beg(int data)
		{
			Node *temp=new Node(data);
			if(head==NULL)
			{
				head=tail=temp;
			}
			else 
			{
				temp->next=head;
				head->prev=temp;
				head=temp;
			}
			
		}
		
		void insert_at_end(int data)
		{
			Node *temp=new Node(data);

			if(head==NULL)
			{
				head=tail=temp;
			}
			else
			{
				temp->prev=tail;
				tail->next=temp;
				tail=temp;
				
			}
		}
		
		void insert_at_k(int pos)
		{
			int data;
			cout<<"\nEnter the data for new node";
			cin>>data;
			Node *temp=new Node(data);
			if(head==NULL)
			{
				head=tail=temp;
			}
			else
			{
				Node *current = head;
				int j=1;
				while(j<pos-1)
				{
					
					j++;
					current=current->next;
				}
				
					temp->prev=current;
					temp->next=current->next;
					current->next->prev=temp;
					current->next=temp;
			}
			
		}
			
		int del_from_beg()
		{	
			if(head==NULL)
			{
					cout<<"\nDLL is empty";
			}
			else if(head==tail)
			{
					int data=head->info;
					delete head;
					head=tail=NULL;
					return data;
			}				
			else
			{
					Node *temp;
					int data=head->info;
					temp=head;
					head=head->next;
					head->prev=NULL;
					delete temp;
					return data;
			}
		}
				
		int del_from_end()
		{	
			if(head==NULL)
				{
					cout<<"DLL is empty";
					
				}
				
				else if(head==tail)

				{	int data=head->info;
					delete head;
					head=tail=NULL;
					return data;
				}				
				else
				{
					Node *temp;
					int data=tail->info;
					temp=tail;
					tail=tail->prev;
					tail->next=NULL;
					delete temp;
					return data;
				}
		}
		int count()
		{
			int n;
			Node *current=head;
			while(current!=NULL)
			{
				n++;
				current=current->next;
			}
			return n;
		}
		
		void del_at_k(int pos)
		{
			int n=count();
 			if(head==NULL)
			{
				cout<<"LINK LIST IS EMPTY"<<endl;
			}
			else if(pos==1)
			
			{
				cout<<"DELETED DATA IS:"<<del_from_beg();
				
			
			}
			else if(pos==n)
			{
				cout<<"DELETED DATA IS:"<<del_from_end();
			}
			else
			{
				Node *current = head;
				int j=1;
				while(j<pos-1)
				{
					
					j++;
					current=current->next;
				}
					Node *temp=current->next;
					current->next=temp->next;
					temp->next->prev=current;
					delete temp;
				 
			}
			
		}
				
				bool search(int data)
				{
					if(head==NULL)
					{
						cout<<"The DLL is empty";
						return false;
					}
					else
					 {
					 	Node *current=head;
					 	while(current->next!=NULL)
					 	{
					 		if(current->info==data)
					 		{
					 			return true;
					 			
					 		}
					 		else
					 		{
					 			return false;
					 		}
					 		current=current->next;
					 	}
					
					
					}
					
			  		
				}
				
		 void reverse()
			{
					
				if(head==NULL)
				{
					cout<<"DLL is empty";
					
				}
				else{
				
				Node *temp,*current;
				current=head;
				while(current!=NULL)
				{
					Node *t=current->prev;
					current->prev=current->next;
					current->next=t;
					current=current->prev;
				}
				temp=head;
				head=tail;
				tail=temp;
				
				
			}
				
			}		
			void display()
			{
				cout<<"THE DLL IS:"<<"\n";
					Node *current=head;
 					while(current!=NULL)
					{
						cout<<current->info<<"   ";
						current=current->next;
						
						
					}
			}
			
			
		
		
};
int main()
{
	DLL d;
	d.insert_at_beg(10);
	d.insert_at_beg(9);
	d.insert_at_end(15);
	d.insert_at_end(20);
	d.insert_at_k(3);
	
	d.del_at_k(2);
	d.display();cout<<endl; 
	
	bool i=d.search(20);
	cout<<i<<endl;
	d.display();
	d.reverse();
	d.display();
	



	getch();
	return 0;
}

