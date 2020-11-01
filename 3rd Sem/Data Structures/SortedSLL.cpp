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
class SortedSLL
{
		private:
		Node *head,*tail;
		public:
			
		SortedSLL()
		{
			head=tail=NULL;
		}
		SortedSLL (const SortedSLL &ob)
		{
			head=ob.head;
			tail=ob.tail;
		}
		
		void insertData(int data)
		{
			Node*temp=new Node(data);
			if(head==NULL)
				head=tail=temp;
			else
			{
				Node*current=head;
				if(head->info > data)
				{
					temp->next=head;
					head=temp;	
				}
				else 
				{
					while(current!=tail&&current->next->info<data)
						current=current->next;
					if(current==tail)
					{
						tail->next=temp;
						tail=temp;
					}	
					else
					{
						temp->next=current->next;
						current->next=temp;			
					}							
				}				
			}
		}
		
		void deleteData(int data)
		{
			if(head==NULL)
				throw "\n Linked List is Empty";
			else if(head->info==data)
			{
				if(head==tail)
				{						
					delete head;
					head=tail=NULL;				
				}
				else
				{
					Node *temp=head;
					head=head->next;
					delete temp;
				}
			}
			else if(tail->info==data)
			{
				if(head==tail)
				{						
					delete head;
					head=tail=NULL;				
				}
				else
				{
					Node *temp=head;
					while(temp->next->next!=NULL)
						temp=temp->next;
					temp->next=NULL;
					delete tail;
					tail=temp;
				}
			}
			else
			{				
				Node*current=head;
				while(current!=tail&&current->next->info!=data)
					current=current->next;
				if(current!=tail)
				{
					if(current->next->info==data)
					{
						Node*temp=current->next;
						current->next=temp->next;
						delete temp;	
					}				
				}
				else
					throw "\n No such data in Linked List";	
			}
		}
		
		SortedSLL merge(SortedSLL &ob)
		{	
			SortedSLL a;
			if(head==NULL)
				a=ob;
			else if(ob.head==NULL)
				a=*this;
			else if(head==NULL&&ob.head==NULL)
				a.head=a.tail=NULL;
			else
			{
				Node*currentA=head;
				Node*currentB=ob.head;
				if(head->info<ob.head->info)
					{
					a.head=head;
					currentA=currentA->next;	
					}
				else
					{
						a.head=ob.head;
						currentB=currentB->next;
					}
					Node*currentC=a.head;
					while(currentA!=NULL&&currentB!=NULL)
					{
						if(currentA->info<currentB->info)
						{
								currentC->next=currentA;
								currentA=currentA->next;
								currentC=currentC->next;	
						}
						else							
						{
							currentC->next=currentB;
							currentB=currentB->next;
							currentC=currentC->next;	
						}							
					}
					if(currentA==NULL)
					{
						currentC->next=currentB;
						a.tail=ob.tail;	
					}
					if(currentB==NULL)
					{
						currentC->next=currentA;
						a.tail=tail;	
					}
					return a;
			}		
		}
		void display()
		{	
			Node *current=head;
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
				cout<<"\n Empty Linked List";
		}
		int menuA()
		{	int ch;
			cout<<"\nMENU\n";
			cout<<"1. Insert Data\n";
			cout<<"2. Remove Data\n";
			cout<<"3. Display\n";
			cout<<"4. Exit\n";
			cout<<"Enter Choice\n";
			cin>>ch;
			return ch;
		}
		int menuB()
		{	int ch;
			cout<<"\nMENU\n";
			cout<<"1. Change in Linked List 1\n";
			cout<<"2. Change in Linked List 2\n";
			cout<<"3. Merge Both Linked Lists\n";
			cout<<"4. Exit\n";
			cout<<"Enter Choice\n";
			cin>>ch;
			return ch;
		}
		
		void progA()
		{
			bool tf=1;
			int ch,data;
			while(tf)
			{
				ch=menuA();
				try
				{
				switch(ch)
				{
					case 1: cout<<"Enter Data to be inserted\n";
							cin>>data;
							insertData(data);
					break;
					case 2: cout<<"Enter Data to be deleted";
							cin>>data;
							deleteData(data);
					break;
					case 3: display();
					break;
					case 4: tf=0;
					break;
					default: tf=0;
							throw "Wrong choice entered";
				}					
				}
				catch(const char*c)
				{
					cout<<c;
				}
				
			}	
		}
			
		void progB()
		{
			bool tf=1;
			int ch;
			SortedSLL a,b,c;
			while(tf)
			{
				ch=menuB();
				switch(ch)
				{
					case 1: a.progA();
					break;
					case 2: b.progA();
					break;
					case 3: c=a.merge(b);
							c.display();
					break;
					case 4: exit(0);
					break;
					default: exit(0);
				}				
			}	
		}
		
};
int main()
{
	SortedSLL x;
	x.progB();
	getch();
}
