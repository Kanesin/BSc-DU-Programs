#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
class euler
{   
    int A[10][10],n,indeg[10],outdeg[10],deg[10];
	public:
		void input()
		{   int x; 
			cout<<"\nEnter the number of vertices:";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<"\nIs there an edge between vertex "<<char(97+i)<<" and vertex "<<char(97+j)<<"(enter 0 or 1):";
					cin>>x;
					if(x==0)
					A[i][j]=0;
					else
					A[i][j]=1;
				}
			}
		}
		void finddeg()
		{
			
			for(int i=0;i<n;i++)
			{   
			    indeg[i]=0;
			    outdeg[i]=0;
				for(int j=0;j<n;j++)
				{
					if(A[i][j]==1)
					{
						outdeg[i]++;
					}
					if(A[j][i]==1)
					{
						indeg[i]++;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				deg[i]=indeg[i]+outdeg[i];
			}
			
		}
		void ecircuit()
		{
			int f=0;
			for(int i=0;i<n;i++)
			{
				if(deg[i]%2!=0)
				{
					f=1;
					break;
				}
			}
			if(f!=1)
			cout<<"\nThere's an euler circuit";
			else
			cout<<"\nNo euler circuit";
		}
		void epath()
		{
			int f=0;
			for(int i=0;i<n;i++)
			{
				if(deg[i]%2!=0)
				f++;
			}
			if(f==2)
			cout<<"\nThere's an euler path";
			else
			cout<<"\nNo euler path";
		}
};
int main()
{
	euler E;
	E.input();
	E.finddeg();
	E.epath();
	E.ecircuit();
	getch();
	return 0;
}
