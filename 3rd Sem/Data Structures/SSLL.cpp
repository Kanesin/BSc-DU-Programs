#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace  std;
class  Node
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
class SSLL
{
		private:
			Node *head,*tail;
			public:
			SSLL()
			{	
				head=tail=NULL;
			}
			void insert(int data)
			{
				Node *temp=new Node(data);
				if(head==NULL)
				{
					head=tail=temp;
				}
				else
				{
					Node *current=head;
					Node *prev=NULL;
					while(current!= NULL && current->info < data )
					{
						prev=current;
						current=current->next;
					}
					if(current==NULL)
					{
						prev->next=temp;
						tail=temp;
					}	
					else
					{
						temp->next=current;
						prev->next=temp;
					}			
				}
			}
			void del(int data)
			{
				if(head==NULL)
					throw "Linked List is empty";
				else if(head==tail)
				{	
					delete head;
					head=tail=NULL;
				}
				else 
				{
					Node *current=head;
					Node *prev=NULL;
					while(current->next != NULL && current->info < data)
					{
						prev=current;
						current=current->next;
					}
					prev->next=current->next;
					delete current;
				}
			}
			SSLL Merge(SSLL ob) 
			{
				SSLL a;
				if(head==NULL) 
				a=ob; 
				else if(ob.head==NULL) 
				a=*this; 
				else if(head==NULL&&ob.head==NULL) 
				a.head=a.tail=NULL; 
				else 
				{
					Node*current1=head; 
					Node*current2=ob.head; 
					if(head->info < ob.head->info) 
					{
					 	a.head=head;
			 		    current1=current1->next; 
					}
				 	else 
					{
			 			a.head=ob.head; 
						current2=current2->next;
					}
			 		Node*current3=a.head; 
					while(current1!=NULL&&current2!=NULL)
			 		{
			 			if(current1->info < current3->info) 
						{
							 current3->next=current1;
							 current1=current1->next; 
							 current3=current3->next;
			 			} 
						else
			 			{
							 current3->next=current2; 
							 current2=current2->next;
							 current3=current3->next; 
						} 
					}
			 		if(current1==NULL) 
					{
			 				current3->next=current2; 
							a.tail=ob.tail; 
					} 
					if(current2==NULL)
			 		{
			 				current3->next=current1; 
							a.tail=tail; 
					}
			 		return a;
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
			void option()
			{
				int choice;
				cout<<"1.Insert\n2.Delete\n3.Merge\n4.Display \n5.Exit \nEnter your choice:";
				cin>>choice;
				menu(choice);
			}
			void menu(int choice)
			{
				SSLL ob1,ob2,ob3;
				SSLL ob;
				int ch,data;
				char cha;
				do{
						switch(ch)
						{
							case 1:
							{
								cout<<"Enter the data you want to Insert:";
								cin>>data;
								insert(data);
								break;
							}
							case 2:
							{
								int a=del(data);
								cout<<"Value deleted is:"<<a<<endl;
								break;
							}
							case 3:int n1,n2,val1,val2;
								   cout<<"\n Enter the number of elements in First LL:";
								   cin>>n1;
								   cout<<"\n Enter the elements:";
								   for (int i=0;i<n1;i++)
								   {
								   		cin>>val1;
								   		ob1.insert(val1);
								   }
								   cout<<"\n Enter the number of elements in Second LL:";
								   cin>>n2;
								   cout<<"\n Enter the elements:";
								   for (int i=0;i<n2;i++)
								   {
								   		cin>>val2;
								   		ob2.insert(val2);
								   }
								                                                     
							case 4:display();
								   break;	
							case 5:exit(0);
							default: cout<<"\n Invalid Input!";
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
	SSLL l;
	l.option();
	getch();
	return 0;
}
				
