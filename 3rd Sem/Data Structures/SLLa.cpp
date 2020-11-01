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
class SLL
{
	private:
		Node *head,*tail;
	public:
		SLL()
		{
			head=tail=NULL;
		}
		void insertAtBeg(int data)
		{
			Node *temp= new Node(data);
			if(head==NULL)
			{
				head=tail=temp;
			}
			else
			{
				temp->next=head;
				head=temp;
			}
		}
		void insertAtEnd(int data)
		{
			Node *temp2= new Node(data);
			if(tail==NULL)
			{
				head=tail=temp2;
			}
			else
			{
				tail->next=temp2;
				tail=temp2;
			}
		}
		void insertAtk(int data,int k)
		{
			Node *temp=new Node(data);
			if(head==NULL)
			head=tail=temp;
			else if(k==1)
			insertAtBeg(data);
			else
			{
				Node *current=head;
				while(k>2)//Instead of while ,you can also use for loop;for(;k>2;k--)
				{
					current=current->next;
					k--;
				}
				temp->next=current->next;
				current->next=temp;
			}
		}
		void change(int data)
		{
			if (head==NULL)
			throw ("Linked List is empty");
			else if(head==tail)
			{	
			}
			else
			{	
				Node*current=head;
				head=head->next;
				tail->next=current;
				tail=current;
				current->next=NULL;
			}
		}		
		int deleteAtBeg()
		{	int value;
			if(head==NULL)
				throw ("Linked List is empty");
			else if(head==tail)
				{	
					value=head->info;
					delete head;
					head=tail=NULL;
					return value;
				}
			else 
				{	
					value=head->info;
					Node *temp=head;
					head=head->next;
					delete temp;
					return value;					
				}
		}
		int deleteAtEnd()
		{	int value;
			if(head==NULL)
				throw ("Linked List is empty");
			else if(head==tail)
				{	
					value=head->info;
					delete head;
					head=tail=NULL;
					return value;
				}
			else 
				{	
					value=tail->info;
					Node *temp=head;
					while(temp->next->next!=NULL)
						temp=temp->next;
					temp->next=NULL;
					delete tail;
					tail=temp;
					return value;					
				}
		}
		int delPart(int data)
		{
			int value;
			if(head==NULL)
				throw "Empty linked list";
			//else if (head==tail && head->info!=value)
			//	throw "Value not found";
			else if(head->info == data)
			{
				value=deleteAtBeg();	
				return value;
			}
			else if(tail->info == data)
			{
				value=deleteAtEnd();
				return value;
			}
			else 
			{
				Node *current=head->next;
				Node *prevNode=head;
				if(current->info == data)
				{
					value=current->info;
					prevNode->next=current->next;
					delete current;
				}	
				else
				{
					prevNode=prevNode->next;
					if(current->next != NULL)
					current=current->next;
				}
				return value;
			}
		}
		void display()
		{	Node *temp3=head;
			int count=0;
			while(temp3!=NULL)
			{
				cout<<temp3->info<<" ";
				temp3=temp3->next;
				count++;
			}
			cout<<"\nNumber of nodes: "<<count;
		}
		void countnodes()
		{	Node *temp3=head;
			int count=0;
			while(temp3!=NULL)
			{
				cout<<temp3->info<<" ";
				temp3=temp3->next;
				count++;
			}
			cout<<"\nnumber of nodes: "<<count;
		}
		bool isPresent(int data)
		{	int f=0;
			Node *temp=head;
			while(temp!=NULL)
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
		void reverse()
		{
			if(head == NULL)
			throw ("Linked list is empty");
			else if(head == tail)
			cout<<"Do nothing";
			else 
			{
				Node *current=head;
				Node *prev=NULL;
				Node *nextNode=head->next;
				while(current != NULL)
				{
					current->next=prev;
					prev=current;
					current= nextNode;
					if(nextNode !=NULL)
					nextNode=nextNode->next;
				}
				tail=head;
				head=prev;
			}
			
		}	
		void option()
		{
		int choice;
		cout<<"MENU: \n1.InsertAtBeg \n2.InsertAtEnd \n3.Insert at particular position \n4.Delete from beginning \n5.Delete from end \n6.Delete a particular data \n7.Searching a particular data \n8.Count the num of nodes \n9.Reverse \n10.Display \n11.First to Last \n12.Exit\nEnter Choice: ";
		cin>>choice;
		menu(choice);
		                 	
		}
		void menu(int choice)
		{
			int ele;
			int data;
			char ch;
			do
			{
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
					case 4: data=deleteAtBeg();
							cout<<"Deleted data value at Beginning: "<<data<<"\n";	
							break;		
					case 5: data=deleteAtEnd();
							cout<<"Deleted data value at End: "<<data<<"\n";	
							break;
					case 6: cout<<"Enter a data to delete:";
							cin>>ele;
							data=delPart(ele);
							cout<<"Deleted data value that you entered: "<<data<<"\n";	
							break;
					case 7: cout<<"Enter data to be searched\n";
							cin>>data;
							if(isPresent(data))
							cout<<"Data is present\n";
							else
							cout<<"Data is not present\n";							
							break;		
					case 8: countnodes();
							break;
					case 9: reverse();
							break;		
					case 10:display();
							break;
					case 11:change(ele);
							break;
					case 12:exit(0);
							break;
					default:cout<<"Invalid Input!!!";
					
					}
					option();
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
			}while(ch=='Y'||ch=='y');
		}

		
};
int main()
{
	SLL ob;
	ob.option();
	getch();
	return 0;
}
