#include<iostream>
#include<conio.h>
using namespace std;
class graph
{
	public:
		int n,A[10][10],i,j;
		void input()
		{
			cout<<"\nEnter the number of vertices:";
			cin>>n;
			int x;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<"\nIs there an edge between vertex "<<i+1<<" and "<<j+1<<"(enter 0 or 1):";
					cin>>x;
					if(x==0)
				       A[i][j]=0;
				    else
				       A[i][j]=1;
					      
				}
			}
			cout<<"\nThe matrix is:"<<endl;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<A[i][j]<<" ";
				}
				cout<<endl;
		    }
		}    
		void check()
		{
			int f=0; 
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i<j)
					{
						if(A[i][j]!=1)
						{
							f=1;
							break;
						}
					}
					
				}
			}
			int g=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i==j)
					{
						if(A[i][j]==1)
						{
							g=1;
							break;
						}
					}
					
				}
			}
			if(f!=1&&g==0)
			cout<<"\nGraph is a complete graph";
			else
			cout<<"\nIt's not a complete graph";
		}
};
int main()
{
	graph G;
	G.input();
	G.check();
	getch();
	return 0;
	
}
