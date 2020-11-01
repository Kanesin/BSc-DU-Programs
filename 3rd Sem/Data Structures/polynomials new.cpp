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
				if(head->power >= temp->power)
				{	
					if(head->power==temp->power)
					{
						head->coeff+=temp->coeff;
						if(head->coeff==0)
						{
							Node*temp=head;
							head=head->next;
							delete temp;
						}	
					}
					else
					{
						temp->next=head;
						head=temp;		
					}					
				}				
				else if(tail->power <= power)
				{
					if(tail->power==temp->power)
					{
						tail->coeff+=temp->coeff;
						if(tail->coeff==0)
						{
							Node*temp=head;
							while(temp->next!=tail)
								temp=temp->next;
							temp->next=NULL;
							delete tail;
							tail=temp;	
						}						
					}	
					else
					{
						tail->next=temp;
						tail=temp;
					}					
				}				
				else 
				{
					Node*current=head;
					Node*prev=head;
					int i=0;
					while(current->next!=tail&&current->next->power<=temp->power)
					{
						current=current->next;
						i++;
						if(i!=1)
						prev=prev->next;	
					}
					if(current->power==temp->power)
					{
						current->coeff+=temp->coeff;
						if(current->coeff==0)
						{
							prev->next=current->next;
							delete current;
						}
					}	
					else
					{
						temp->next=current->next;
						current->next=temp;			
					}							
				}				
			}
		}
		
		void insertData(int power,int coeff)
		{
			Node* t=new Node(power,coeff);
			if(tail==NULL)
				head=tail=t;
			else
			{
				tail->next=t;
				tail=t;					
			}
		}
		
		polynomials add(polynomials &ob)
		{	
			polynomials a;
			Node*currentA=head;
			Node*currentB=ob.head;
			while(currentA!=NULL&&currentB!=NULL)
			{
				if(currentA->power==currentB->power)
				{
					if(currentA->coeff+currentB->coeff!=0)
					a.insertData(currentA->power,currentA->coeff+currentB->coeff);
					currentA=currentA->next;
					currentB=currentB->next;
				}			
				
				else if(currentA->power<currentB->power)
				{
					if(currentA->coeff!=0)
					a.insertData(currentA->power,currentA->coeff);
					currentA=currentA->next;						
				}
							
				else if(currentA->power>currentB->power)
				{	
					if(currentB->coeff!=0)					
					a.insertData(currentB->power,currentB->coeff);
					currentB=currentB->next;
				}
			}
			if(currentA==NULL)
			{
				while(currentB!=NULL)
				{
					if(currentB->coeff!=0)
					a.insertData(currentB->power,currentB->coeff);
					currentB=currentB->next;	
				}					
			}
			if(currentB==NULL)
			{
				while(currentA!=NULL)
				{
					if(currentA->coeff!=0)
					a.insertData(currentA->power,currentA->coeff);
					currentA=currentA->next;						
				}					
				
			}					
			return a;	
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
				cout<<"Enter Degree of term "<<i+1<<" ";
				cin>>deg;
				cout<<"Enter Coefficient for X^"<<deg<<" ";
				cin>>co;
				cout<<"\n";
				if(co!=0)
					addterm(deg,co);
			}
			
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
			p3=p1.add(p2);
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
