#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class Node
{	
	public:
		int power;
		int coeff;
		Node *next;
		Node(int pow,int co)
		{
			power=pow;
			coeff=co;
			next=NULL;
		}
};
class polynomials{
	private:
		Node *head,*tail;
		public:
			
		polynomials()
		{
			head=tail=NULL;
		}
		
		polynomials (const polynomials &ob)
		{
			head=ob.head;
			tail=ob.tail;
		}
		
		void addterm(int power,int coeff)
		{
			Node*temp=new Node(power,coeff);
			if(head==NULL)
				head=tail=temp;
			else
			{
				Node*current=head;
				if(head->power > power)
				{
					temp->next=head;
					head=temp;	
				}
				else 
				{
					while(current!=tail&&current->next->power<power)
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
		
		void merge_common()
		{
			if(head!=tail&&head!=NULL)
			{
				Node * current=head;
				while(current->next!=tail)
				{
					if(current->power==current->next->power)
						{
							Node *temp=current->next;			
							current->coeff+=temp->coeff;							
							current->next=temp->next;
							delete temp;
						}
					else
						current=current->next;
				}
				if(current->next==tail)
				{
					if(current->power==tail->power)
						{
							current->coeff+=tail->coeff;
							current->next=NULL;
							delete tail;
							tail=current;
						}					
				}
					
			}
			rem0();

		}
		
		void rem0()
		{
			if(head!=NULL&&head!=tail)
			{
				if(head->coeff==0)
				{
					Node*temp=head;
					head=head->next;
					delete temp;
				}
				else
				{
					Node*current=head->next;
					Node*prev=head;
					while(current!=tail)
					{
						if(current->coeff==0)
						{
							prev->next=current->next;
							delete current;
							current=prev->next;
						}
						else
						{
							current=current->next;
							prev=prev->next;
						}
					}
					if(current==tail&&current->coeff==0)
					{
						delete tail;
						tail=prev;
						tail->next=NULL;
					}
				}			
			}
			if(head==NULL)
			{
				
			}
			else if(head==tail)
			{
				if(head->coeff==0)
				{
					delete head;
					head=tail=NULL;	
				}
			}
			
			
		}
		
		polynomials merge(polynomials &ob)
		{	
			polynomials a;
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
				if(head->power<ob.head->power)
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
					if(currentA->power<currentB->power)
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
				while(current!=NULL)
				{	
					if(current->coeff>=0)
						cout<<"+";											
					cout<<current->coeff;
					if(current->power!=0)
						cout<<"X^"<<current->power;	
					cout<<"  ";		
					current=current->next;				
				}
			}
			else
				cout<<"\n No polynomial provided";
		}
			
		void input()
		{
			int deg,term,co;
			cout<<"Enter the number of terms in polynomial\n";
			cin>>term;			
			for(int i=0;i<term;i++)
			{
				cout<<"Enter Degree of term "<<i+1<<"\n";
				cin>>deg;
				cout<<"Enter Coefficient for X^"<<deg<<" ";
				cin>>co;
				addterm(deg,co);
			}
			merge_common();
		}	
		void prog()
		{
				char Y;
				polynomials p1,p2,p3;
				cout<<"Polynomial 1\n";
				p1.input();
				cout<<"Polynomial 2\n";
				p2.input();
				cout<<"\nEntered polynomial 1\n";
				p1.display();
				cout<<"\nEntered polynomial 2\n";
				p2.display();			
				p3=p1.merge(p2);
				p3.merge_common();
				cout<<"\n Result after Addition\n";
				p3.display();			
				cout<<"\nDo you want to continue(Y/N)\n";
				cin>>Y;
				if(Y=='Y'||Y=='y')
					prog();
				else
					exit(0);			
		}
};

int main()
{
	polynomials p;
	p.prog();	
	getch();
}

