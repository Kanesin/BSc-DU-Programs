#include<iostream>
#include<conio.h>
using namespace std;
class relation
{
	public:
		int n,A[20],B[3][3],C[20],i,j,d;
		int cs,cr,ct,cas;
		
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
			{
				
			cr=1;
			cout<<"\n Relation is reflexive";
			
			}else
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
	
	cout<<"{";
	for(int l=0;l<d;l=l+2)
	{
	
		
    cout<<C[l]<<","<<C[l+1]<<"    ";
    }
    cout<<"}";
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
		{
		cs=1;
		cout<<"\nIt is symmetric";
	    }
		else
		cout<<"\n It is not symmetric";
	}
	void checktrans()
	{ 
	    int f=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					
					
						if(B[i][j]==1&&B[j][k]==1)
						{
							
							if(B[i][k]!=1)
							f=1;
							
						}
					
				}
			}
		}
		if(f!=1)
		{
		ct=1;
		cout<<"\nIt is transitive";
		}
		else
		cout<<"\nIt is not  transitive";
		
		
	}
	void antisym()
	{
		int f=0;
		for(i=0;i<n;i++)
		{
			
			for(j=0;j<n;j++)
			{
				if(B[i][j]==1&&(i!=j))
				{
					if(B[j][i]!=0)
					{
						f=1;
						break;
					}
				}
			}
		}
		if(f==1)
		
		cout<<"\nIt is not anti symmetric";
	    
		else
		{
		cas=1;	
		cout<<"\nIt is anti symmetric";
	    }
	}
	void closure()
	{
		 cout<<"{";
		 for(int l=0;l<d;l=l+2)
	     {
	     cout<<C[l]<<","<<C[l+1]<<"    ";
         }
	     	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
				{
					if(B[i][j]==0)
					{
						cout<<A[i]<<","<<A[i]<<"   ";
					}
				}
			}
		}
		cout<<"}";
	}
	
};
int main()
{
	relation R;
	R.d=0;
	R.cr=0;R.ct=0;R.cs=0;R.cas=0;
	R.input();
	R.insert();
	R.arry();
	R.checkref();
	R.checksym();
	R.checktrans();
	R.antisym();
	cout<<"\nThe reflexive closure is: ";
    R.closure();
    if((R.cr==1)&&(R.cas==1)&&(R.ct==1))
    cout<<"\nThe relation is partial ordered relation";
    
	if((R.cr==1)&&(R.ct==1)&&(R.cs==1))
    cout<<"\nThe relation is equivalence";
    
	if((R.ct==0)&&(R.cas==0))
    cout<<"\nIt's neither partial ordered not equivalence relation";
	getch();
	return 0;
}
