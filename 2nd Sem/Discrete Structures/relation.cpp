#include<iostream>
#include<conio.h>
using namespace std;
class relation
{
	public:
		int n,A[20],B[3][3],C[20],i,j,d;
		void input()
		{
			cout<<"\nEnter the number of elements: ";
			cin>>n;
			cout<<"\nEnter the elements: ";
			for(i=0;i<n;i++)
			{
				cin>>A[i];
			}
		}
		void insert()
		{ int x;
		  for(i=0;i<n;i++)
		  {
		  	for(j=0;j<n;j++)
			  {
			  	cout<<"\nIs ("<<A[i]<<","<<A[j]<<") in the relation?: ";
			  	cin>>x;
			  	if(x==1)
			  	   B[i][j]=1;
			  	else
			  	   B[i][j]=0;
			  }
		  }
		  cout<<endl;
		  for(i=0;i<n;i++)
		  {
		  	for(j=0;j<n;j++)
		  	{
		  		cout<<B[i][j]<<" ";
		  	}cout<<"\n";
		  	
		  }
		}
		void checkref()
		{ int c=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(B[i][j]==1)
					
					{
						if(i==j)
						{
						c++;
					    }
					}
					
					
				}
			}
			if(c==n)
			cout<<"\n Relation is reflexive";
			else
			cout<<"\n Relation is not reflexive";
		}
	    void arry()
		{
			 
			for(i=0;i<=n-1;i++)
			{
				for(j=0;j<=n-1;j++)
				{
				if(B[i][j]==1)
				 	{
				 	C[d++]=A[i];
				 	C[d++]=A[j];
	                }
	        }
	        }
	cout<<endl;
	
	for(int l=0;l<d;l++)
		cout<<C[l]<<" ";
	}
	void checksym()
	{int f=0;
	int x=n*n;
		for(i=0;i<n;i++)
		{ 
			for(j=0;j<n;j++)
			{ 
				if(B[i][j]==B[j][i])
			    {
			    	
			    	
			    	f++;
			        
				}
			}
		}
		if(f==x)
		cout<<"\nIt is symmetric";
		else
		cout<<"\n It is not symmetric";
	}
	
};
int main()
{
	relation R;
	R.d=0;
	R.input();
	R.insert();
	R.checkref();
	R.arry();
	R.checksym();
	
	getch();
	return 0;
}
