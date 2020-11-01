#include<iostream>
#include<conio.h>
using namespace std;
class Sparsematrix{
	public:
	int *A,sA;
	void input()
	{
		
	}
	
	void diagnal()
	{
		cout<<"Enter matrix size\n";
		cin>>sA;
		A=new int (sA);
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
		cout<<"Enter matrix size\n";
		cin>>sA;
		int s=0;
		for(int i=1;i<=sA;i++)
			s+=i;
		sA=s;
		s=0;	
		A=new int (sA);
		cout<<"Enter data\n";
		for(int i=0;i<sA;i++)
		{
			for(int j=0;j<sA;j++)
			{
				if(i!=j)
				{
					cout<<"("<<j+1<<","<<i+1<<")=";
					cin>>A[s++];					
				}				
			}
		}
		for(int i=0;i<sA;i++)
		cout<<A[i]<<'\t';
		/*cout<<"Actual Matrix\n";
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
		}*/
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
	sm.uppertriangle();
	getch();
	
}

