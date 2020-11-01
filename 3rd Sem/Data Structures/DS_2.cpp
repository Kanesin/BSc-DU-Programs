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
class Demo
{ 
	Node *head,*tail;
	public:
	Demo()
	{
		head=tail=NULL;
	}
	void InsertAtBeg(int data1)
	{
		Node *temp=new Node(data1);
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
	void InsertAtEnd(int data2)
	{
		Node *temp=new Node(data2);
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
	void InsertAtMid(int data3)
	{
		Node *current=head;
		int i=0;
		while(current!=NULL)
		{
			i++;
			current=current->next;
		}
		int mid=i/2;
		int j=0;
		current=head;
		while(j!=mid-1)
		{
			current=current->next;
			j++;
			
		}
		Node* temp=new Node(data3);
		temp->next=current->next;
		current->next=temp;
	}
	int DeleteFromBeg()
	{
		int x=head->info;
		Node *temp;
		if(head==tail)
		{
			delete head;
			head=tail=NULL;
		}
		temp=head;
		head=head->next;
		delete temp;
		return x;
	}
	int DeleteFromEnd()
	{
		int x=tail->info;
		Node *temp;
		temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
			
		}
		
		Node *temp2;
		temp2=tail;
		tail=temp;
		temp->next=NULL;
		delete temp2;
		return x;
	
	}
	void Delvalue(int data4)
	{
		if(head==NULL)
		throw "Link List is Empty";
		else if(head->info==data4)
		DeleteFromBeg();
		else if(data4==tail->info)
		DeleteFromEnd();
		else
		{
			Node *current=head->next;
			Node *previous=head;
			while(current->info!=data4&&current!=tail)
			{
				current=current->next;
				previous=previous->next;
			}
			if(current->info==data4)
			{
				previous->next=current->next;
				delete current;
			}
			else
			throw "No DATA FOUND!!";
		}
	}
	bool search(int data5)
	{
		int f=0;
		if(head==NULL)
		throw "Link List is empty";
		else 
		{
			Node *current=head;
			while(current!=NULL)
			{
				if(current->info==data5)
				{
					f=1;
				   break;
				}
			    	current=current->next;
				
			}
			if(f==1)
			return true;
			else
			return false;
		}
		
	}
	void reverse()
	{
		if(head==NULL)
		throw "Link List is Empty";
		else if(head==tail)
		{ }
		else
		{
			Node *current=head;
			Node *previous=NULL;
			Node *Nextnode=head->next;
			while(current!=NULL)
			{
				current->next=previous;
				previous=current;
				current=Nextnode;
				if(Nextnode!=NULL)
				Nextnode=Nextnode->next;
			}
			Node *temp=head;
			head=tail;
			tail=temp;
		}
	}
	void count()
	{
		Node *current=head;
		int i=0;
		while(current!=NULL)
		{
			i++;
		}
		cout<<"\nThe no of nodes in the Link List are: "<<i;
	}
	
	
	void Display()
	{
		Node *current=head;
		while(current!=NULL)
		{
			cout<<current->info<<" ";
			current=current->next;
		}
	}
	void conc(Demo D1,Demo D2)
	{
		if(D1.head==NULL)
		{
			head=D2.head;
			tail=D2.tail;
		}
		else if(D2.head==NULL)
		{
			head=D1.head;
			tail=D1.tail;
		}
		else
		{
			head=D1.head;
			D1.tail->next=D2.head;
			tail=D2.tail;
		}
		cout<<"\nThe Concatinated linked list is: ";
		Node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->info<<"\n";
			temp=temp->next;
		}
	}
	
	Demo operator+(Demo D1)
	{
		Demo obj;
		if(head==NULL)
		{
			obj.head=D1.head;
			obj.tail=D1.tail;
			
		}
		else if(D1.head==NULL)
		{
			obj.head=head;
			obj.tail=tail;
			
		}
		else
		{
			obj.head=head;
			tail->next=D1.head;
			obj.tail=D1.tail;
		}
		return obj;
		
	}
	
	int insert(int pos)
	{
		int data_n;
		cout<<"enter data of neew element";
		cin>>data_n;
		if(pos==1)
		InsertAtBeg(data_n);
		else
		{
		Node *temp=new Node(data_n);
		Node *current=head;
		int i=1;
		while(current!=NULL)
		{
			if(i<pos-1){
			
			current=current->next;
			i++;}
			else
			break;
		}
	
			
		if(current!=NULL)
		{
			cout<<current->info;
			temp->next=current->next;
			current->next=temp;
	 	}
	 	else
	 	cout<<"\nERROR!!";
	}}
	
	
	                                                                                                                                                                                                                    
	
	
};
int main()
{
	Demo d,d1,d2;
	int ch;
	char c;
	int data;
	bool e;
	do
	{
		cout<<"\nMENU";
		cout<<"\n1. Insert Node at the Beggining";
		cout<<"\n2. Insert Node at the End";
		cout<<"\n3. Insert Node at the Middle";
		cout<<"\n4. Delete Node at the Beggining";
		cout<<"\n5. Delete Node at the End";
		cout<<"\n6. Delete Node at the particular Node";
		cout<<"\n7. Display the no of Nodes";
		cout<<"\n8. Search for a Node";
		cout<<"\n9. Reverse the Link List";
		cout<<"\n10. Concat Linked List " ;
		cout<<"\n11. Concat using operator Overloading";
		cout<<"\n12. Insert Node at particular position";
		cout<<"\n13. Display the Link List";
		cout<<"\nEnter your choice: " ;
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nEnter the data to be inserted: ";
					cin>>data;
					d.InsertAtBeg(data);
					break;
			case 2: cout<<"\nEnter the data to be inserted: ";
					cin>>data;
					d.InsertAtEnd(data);
					break;
			case 3: cout<<"\nEnter the data to be inserted: ";
					cin>>data;
					d.InsertAtMid(data);
					break;
			case 4: data=d.DeleteFromBeg();
					cout<<"\nThe deleted element is: "<<data;
					break;
			case 5: data=d.DeleteFromEnd();
				   	cout<<"\nThe deleted element is: "<<data;
					break;
			case 6: cout<<"\nEnter the data to be deleted: ";
					cin>>data;
				   	d.Delvalue(data);
					break;
			case 7: d.count();
					break;
			case 8:	cout<<"\nEnter the data to be searched: ";
					cin>>data;
					e=	d.search(data);
					if(e==true)
					cout<<"\nElement FOUND!!";
					else
					cout<<"\nElement NOT FOUND!!";
					break;
			case 9: cout<<"\nThe Reverse Order of the Link lIst is: ";
					d.reverse();
					d.Display();
					break;
					
					
			case 10:int a;     
					cout<<"Enter no of elements for second link list: ";
					cin>>a;
					for(int i=0;i<a;i++)
					{
						int data;
						cout<<"Enter data";
						cin>>data;
						d1.InsertAtBeg(data);
					}
						d1.conc(d,d1);
					break;
			case 11:int b;     
					cout<<"Enter no of elements for second link list: ";
					cin>>b;
					for(int i=0;i<b;i++)
					{
						int data;
						cout<<"Enter data";
						cin>>data;
						d1.InsertAtBeg(data);
					}
					 d2=d+d1;
					d2.Display();
					break;
			case 12: int pos1;
					cout<<"Enter the position where you want to insert node: ";
					cin>>pos1;
					d.insert(pos1); 
			 		
			case 13: cout<<"\nThe content of Link List is as Follows: ";
					d.Display();
					break;
			default: cout<<"\nWrong CHOICE!!";
		}
		cout<<"\nwant to enter more(Y for yes): ";
		cin>>c;
	}while(c=='Y'||c=='y');
	getch();
	return 0;
}
