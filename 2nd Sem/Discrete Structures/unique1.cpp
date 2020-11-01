#include<iostream.h>
#include<conio.h>
using namespace std;
class sets
public:
	int A[20],B[20],sA,sB;
	{cout<<"\nEnter the size of set A";
	cin>>sA;
	while(sA<1||sA>20)
	{ cout<<"enter the size of set a elements 1 to 20";
	cin>>A;
	}cout<<"\n Enter elements of set A";
	for(int i=0;i<sA;i++)
	{ cin>>A[i];
	}
	}
	void inputB()
	{ cout<<"\n enter the size of set B";
	  cin>>sB;
	  while(sb<1||sb>20)
	  { cout<<"enter the size of B elements 1 to 20";
	    cin>>sB;
	  }
	  cout<<"\nEnter elements of set B";
	  for(int i=0;i<sB;i++)
	  {cin>>B[i];
	  }
	}
	void unique(int x[],*sA)
	{
		int u[*s],su=0,1;
		for(int i=0;i<*sX;i++)
		{ f=1;
		if(i==0)
		u[su++]=x[i];
		size
		{ for(int i=);i<su;i++)
		if(u[1]==x[i])
		{f=0;
		break;
		
		}
		if(f==1)
		}u[xu++]=x[i];
		
		
		}
	}
	*sX=sU;
	cout<<*sX;
	for(int i=0;i<*sX;i++)
	x[i]=u[i];
	cout<<"\n";
	for(int i=0;i<*sX;i++)
	{
		cout<<x[i]<<"\t";
	}cout<<"\n";
	
	void complement()
	{ int C[20],sC=0
	for(int i=0;i<sA;i++)
	{f=1;
	for(int j=0;j<sB;j++)
	{ if(x[i]==B[i])
	f=0;
	if(f==1);
	c[sC++]=B[i];
	
	}
	}
	cout<<"\n";
	for(int i=0;i<sC;i++)
	{ cout<<C[i]<<"\t";
	}
}
