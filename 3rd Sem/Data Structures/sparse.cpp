#include<iostream>
#include<conio.h>
using namespace std;
class Sparsematrix{
	public:
	//int *A,sA;
	void input()
	{
		
	}
	
	void diagonal()
	{
		int sA;
		cout<<"Enter matrix size\n";
		cin>>sA;
		int A[sA];
		cout<<"Enter data\n";
		for(int i=0;i<sA;i++)
		{
			cout<<"("<<i+1<<","<<i+1<<")=";
			cin>>A[i];			
		}
		cout<<"Actual Matrix\n";
		for(int i=0;i<sA;i++)
		{
			for(int j=0;j<sA;j++)
			{
				if(i!=j)
				cout<<"0";
				else
				cout<<A[i];
				cout<<"\t";
			}
			cout<<"\n";
		}
	}
	void uppertriangle()
	{
		int sA;
		cout<<"Enter matrix size\n";
		cin>>sA;
		int s=0,NS=sA;
		for(int i=1;i<=sA;i++)
			s+=i;
		sA=s;
		s=0;
		int A[sA];
		cout<<"Enter data\n";
		for(int i=0;i<NS;i++)
		{
			for(int j=0;j<NS;j++)
			{				
				if(i<=j)
				{
					cout<<"("<<i+1<<","<<j+1<<")=";
					cin>>A[s++];	
				}				
				if(s==sA)
					break;							
			}
		}		
		s=0;
		cout<<"Actual Matrix\n";
		for(int i=0;i<NS;i++)
		{
			for(int j=0;j<NS;j++)
			{
				if(i>j)
					cout<<"0";
				else if(i<=j)
					cout<<A[s++];
				cout<<"\t";
			}
			cout<<"\n";
		}
	}
	
	void symmetric()
	{
		int sA;
		cout<<"Enter matrix size\n";
		cin>>sA;
		int s=0,NS=sA;
		for(int i=1;i<=sA;i++)
			s+=i;
		sA=s;
		s=0;
		int A[sA];
		cout<<"Enter data\n";
		for(int i=0;i<NS;i++)
		{
			for(int j=0;j<NS;j++)
			{				
				if(i<=j)
				{
					cout<<"("<<i+1<<","<<j+1<<")=";
					cin>>A[s++];	
				}				
				if(s==sA)
					break;							
			}
		}		
		s=0;
		cout<<"Actual Matrix\n";
		int bk=1;
		for(int i=0;i<NS;i++)
		{
			for(int j=0;j<NS;j++)
			{
				if(i<=j)
				cout<<A[s++];
				else if(i>j)
				{
					//if(i!=0&&j!=0)
					cout<<A[i*j+i];
					//else if(i==0||j==0)
					//cout<<A[i*j+i]
						
				}
				
				bk++;				
				cout<<"\t";
			}			
			cout<<"\n";
		}
	}
	
	void lowertriangle()
	{
		int sA;
		cout<<"Enter matrix size\n";
		cin>>sA;
		int s=0,NS=sA;
		for(int i=1;i<=sA;i++)
			s+=i;
		sA=s;
		s=0;
		int A[sA];
		cout<<"Enter data\n";
		for(int i=0;i<NS;i++)
		{
			for(int j=0;j<NS;j++)
			{				
				if(i>=j)
				{
					cout<<"("<<i+1<<","<<j+1<<")=";
					cin>>A[s++];	
				}				
				if(s==sA)
					break;							
			}
		}		
		s=0;
		cout<<"Actual Matrix\n";
		for(int i=0;i<NS;i++)
		{
			for(int j=0;j<NS;j++)
			{
				if(i<j)
					cout<<"0";
				else if(i>=j)
					cout<<A[s++];
				cout<<"\t";
			}
			cout<<"\n";
		}
	}
	
	int menu()
	{
		cout<<"\nMENU\n";
		cout<<"1. Diagnal Matrix\n";
		cout<<"2. Upper Triangle Matrix\n";
		cout<<"3. Lower Triangle Matrix\n";
		cout<<"4. Symetric Matrix\n";
		cout<<"5. Exit\n";
		cout<<"Enter choice\n";
		int ch;
		cin>> ch;
		return ch;
	}
};

int main()
{
	Sparsematrix sm;
	//sm.diagonal();
	sm.uppertriangle();
	//sm.lowertriangle();
	//sm.symmetric();
	getch();
	
}

