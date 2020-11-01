#include <iostream>
#include<conio.h>
using namespace std;
class path
{
  
int n,G[10][10],u,v,k;
public:
	int input()
	{   int x;
		cout<<"\nEnter the number of vertices:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"\nIs there an edge between vertex "<<i<<" and vertex "<<j<<"(enter 0 or 1):";
				cin>>x;
				if(x==0)
				G[i][j]=0;
				else
				G[i][j]=1;
			}
		}
		cout<<"\n\nThe graph is:"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<G[i][j]<<" ";
			}cout<<endl;
		}
		cout<<"\nEnter the initial and the final vertex: ";
		cin>>u>>v;
		cout<<"\nEnter the length of the path:";
		cin>>k;
		int p=checkpath(u,v,k);
		return p;
	}
	
	
int checkpath(int u, int v, int k)
{
   
   if (k == 0 && u == v)      return 1;
   if (k == 1 && G[u][v]) return 1;
   if (k <= 0)                return 0;
 
   
   int count = 0;
   for (int i = 0; i < n; i++)
       if (G[u][i] == 1)  
           count += checkpath(i, v, k-1);
 
   return count;
}
};

int main()
{
    
    path P;
    int no=P.input();
    cout<<"\nThe number of paths is:"<<no;
	getch();
    return 0;
}
