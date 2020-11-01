#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<math.h>
using namespace std;
class set
{
	int i,j,a,k,ch;
	public:
		int n,s,A[20];
		void input();
		int* unique(int A[]);
		bool ismember(int a,int A[]);
		void cardinality(int A[]);
		void powerset(int A[]);
	    int menu();
};
int set::menu()
{
	cout<<"\nMENU";
	cout<<"\n1.Find unique set of elements";
	cout<<"\n2.Check the membership of the element";
	cout<<"\n3.Determine the Cardinality";
	cout<<"\n4.Find power set";
	cout<<"\n5.EXIT";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	return ch;  
}
void set::input()
{
		cout<<"\n Enter the size of the set:";
			cin>>n;
			cout<<"\n Enter the set:";
			for(i=0;i<n;i++)
			{
				cin>>A[i];
			}		
}
int* set::unique(int A[])
{
	int *p;
	s=n;
	int c[n];
	for(i=0;i<n;i++)
	{c[i]=0;
		for(j=0;j<n;j++)
		{
			if(A[i]==A[j])
			{
				c[i]++;
			}
		}
	}
	int max=c[0];
	for(i=0;i<n;i++)
	{
		if(c[i]>max)
		{
			max=c[i];
		}
	}
	for(int x=0;x<max;x++)
	{
	
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(A[i]==A[j])
			{
				for(k=j;k<s;k++)
				{
					A[k]=A[k+1];
				
				}s--;
				
				
			}
		
		}
	
	}
}
	p=A;
	return p;
}
bool set::ismember(int a,int A[])
{   int f=0; 
	for(i=0;i<n;i++)
	{
		if(a==A[i])
		{
			f=1;
			break;
		}
	}
	if(f==1)
	return true;
	else
	return false;
}
void set::cardinality(int A[])
{
	cout<<"\n The Cardinality of set:"<<s;
}
void set::powerset(int A[])
{
	int ps=pow(2,n);
	cout<<"\n The powerset is:";
	cout<<"{";
	for(i=0; i<ps; i++)
	{
		cout<<"{";
		for(j=0; j<s; j++)
		{
			if (i & (1<<j))
			{
				cout<<A[j]<<" ";
			}
		}
		cout<<"}";
	}
	cout<<"}";
}
int main()
{
	set S;
	int i,a;
	char ch;
	do
	{
		S.input();
		int x=S.menu();
		switch(x)
		{
			case 1:int* l;
	               l=S.unique(S.A);
		           cout<<"\n";
				   for(i=0;i<S.s;i++)
				   {
				   	cout<<*(l+i)<<" ";
			
				   } 	        
		           break;
		           case 2:cout<<"\n Enter the element to be searched";;
		           		  cin>>a;
		           		  bool h;
				          h=S.ismember(a,S.A);
				          (h==true)?cout<<"\n The element is a member":cout<<"\n Not a member";
				          break;
				          case 3:int* b;
				          		 b=S.unique(S.A);
				          		 S.cardinality(S.A);
				          		 break;
				          		 case 4:int* f;
				          		 		f=S.unique(S.A);
				          		 		cout<<"\n";
				          		 		for (i=0; i<S.s; i++)
				          		 		{
				          		 			cout<<* (f+i)<<" ";
										}
										S.powerset(S.A);
										break;
										case 5:exit(0);
											   break;
				   default:cout<<"\n\n Wrong choice!!";  
		}
		cout<<"\nDo you want to continue?(y for yes): ";
		  cin>>ch;
	}
		while(ch=='y'||ch=='Y');
	getch();
	return 0;
}
