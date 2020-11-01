#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template <class T>class Node
{
	public:
		T info;
		Node<T> * next;
		Node<T> * prev;
		Node(T data)
		{
			info=data;
			next=prev=NULL;
		}
};
template <class T>class DLL
{
	private:
		Node<T> *head,*tail;
	public:
		DLL()
		{
			head=tail=NULL;
		}
		void insertAtBeg(T data)
		{
			Node<T> *temp= new Node<T>(data);
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
		void insertAtEnd(T data)
		{
			Node<T> *temp2= new Node<T>(data);
			if(tail==NULL)
			{
				head=tail=temp2;
			}
			else
			{
				tail->next=temp2;
				temp2->prev=tail;
				tail=temp2;
			}
		}
		void insertAtk(T data,T k)
		{
			Node<T> *temp=new Node<T>(data);
			if(head==NULL)
			head=tail=temp;
			else if(k==1)
			insertAtBeg(data);
			else
			{
				Node<T> * current=head;
				while(k>2)
				{
					current=current->next;
					k--;
				}
				temp->next=current->next;
				current->next=temp;
				temp->prev=current;
				current=current->next->next;
				current->prev=temp;
			}
			
		}
		int deleteBeg()
		{	
			if(head==NULL)
				throw ("Linked List is empty");
			else if(head==tail)
				{	
					T val=head->info;
					delete head;
					head=tail=NULL;
					return val;
				}
			else 
				{	
					T val=head->info;
					head=head->next;
					delete head->prev;
					head->prev=NULL;
					return val;					
				}
		}
		int deleteEnd()
		{	
			if(head==NULL)
				throw ("Linked List is empty");
			else if(head==tail)
				{	
					T val=head->info;
					delete head;
					head=tail=NULL;
					return val;
				}
			else 
				{	
					T val=tail->info;
					tail=tail->prev;
					delete tail->next;
					tail->next=NULL;
					return val;					
				}
		}
		int delPart(T data)
		{
			T value;
			if(head==NULL)
				throw ("empty linked list");
			else if(head==tail && head->info!=data)
				throw ("Value not found");
			else if(head->info == data)
			{
				value=deleteBeg();	
				return value;
			}
			else if(tail->info ==  data)
			{
				value=deleteEnd();
				return value;
			}
			else 
			{
				Node<T> *current=head->next;
				Node<T> *temp=head;
				if(current->info == data)
				{
					
				}	
				else
				{
					
				}
				return value;
			}
		}
		void display()
		{	Node<T> *temp3=head;
			T count=0;
			while(temp3!=NULL)
			{
				cout<<temp3->info<<" ";
				temp3=temp3->next;
				count++;
			}
			cout<<"\nNumber of Nodes: "<<count;
		}
		void reverse()
		{
				if(head == NULL)
			throw "Linked list is empty";
			else if(head == tail)
			cout<<"Do nothing";
			else 
			{
				Node<T> *current=head;
				Node<T> *temp;
				while(current != NULL)
				{
					temp=current->prev;
					current->prev=current->next;
					current->next=temp;
					current=current->prev;
				}
				temp=head;
				head=tail;
				tail=temp;
			}
		}
		bool isPresent(T data)
		{	T f=0;
			Node<T> *temp=head;
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
		void countNodes()
		{	Node<T> *temp3=head;
			T count=0;
			while(temp3!=NULL)
			{
				cout<<temp3->info<<" ";
				temp3=temp3->next;
				count++;
			}
			cout<<"\nnumber of Node<T>s: "<<count;
		}
		void option()
		{
		T choice;
		cout<<"MENU: \n1.InsertAtBeg \n2.InsertAtEnd \n3.Insert at k \n4.Delete from beginning \n5.Delete from end \n6.Display \n7.Count the number of Nodes \n8.Reverse \n9.Search \n10.Exit\nEnter Choice: ";
		cin>>choice;
		menu(choice);
		                 	
		}
		void menu(T choice)
		{
			T ele;
			T data;
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
							T posData;
							cin>>posData;
							insertAtk(ele,posData);
							break;
					case 4: data=deleteBeg();
							cout<<"Deleted data value at Beginning: "<<data<<"\n";	
							break;		
					case 5: data=deleteEnd();
							cout<<"Deleted data value at End: "<<data<<"\n";	
							break;
					case 6:display();
							break;
					case 7: countNodes();
							break;
					case 8: reverse();
							break;
					case 9: cout<<"Enter data to be searched\n";
							cin>>data;
							if(isPresent(data))
							cout<<"Data is present\n";
							else
							cout<<"Data is not present\n";							
							break;			
					case 10:exit(0);
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
			}while(ch=='Y'||ch=='y');
		}

		
};
int main()
{
	DLL<int> ob;
	ob.option();
	getch();
	return 0;
}

