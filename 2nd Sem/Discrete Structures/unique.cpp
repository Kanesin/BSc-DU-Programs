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
		int
		int menu();
		
		
};
int set::menu()
{
	cout<<"\n\n\t\t\tMENU";
	cout<<"\n\t\t\t1.Find unique set of elements";
	cout<<"\n\t\t\t5.EXIT";
	cout<<"\n\nEnter your choice: ";
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

int main()
{
	set S;
	int i,a;
	char ch;
	do{
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
		
			
			default:cout<<"\n\n Wrong choice!!";
				   	           
		  
		}
		cout<<"\nDO you want to continue?(y for yes): ";
		  cin>>ch;
	}
		while(ch=='y'||ch=='Y');
	getch();
	return 0;
}

