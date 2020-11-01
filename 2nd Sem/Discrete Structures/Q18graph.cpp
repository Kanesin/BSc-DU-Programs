#include<iostream>
#include<conio.h>
using namespace std;
class graph2
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
					cout<<"\nIs there an edge between vertex "<<char(i+1+96)<<" to "<<char(j+1+96)<<"(enter 0 or 1):";
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
	    void calc()
	    {
	    	int B[n];
	    	
	    	for(i=0;i<n;i++)
	    	{ 	B[i]=0;
	    		for(j=0;j<n;j++)
	    		{
	    			if(A[i][j]==1)
	    				B[i]++;
	    		}
	    		cout<<"\nThe out degree of vertex "<<char(i+1+96)<<" is:"<<B[i];
	    	}
	    	cout<<endl;
	    	int M[n];
	    	for(i=0;i<n;i++)
	    	{ M[i]=0;
	    		for(j=0;j<n;j++)
	    		{
	    			if(A[j][i]==1)
	    			M[i]++;
	    		}
	         cout<<"\nThe in degree of vertex "<<char(i+1+96)<<" is:"<<M[i];
			}
	    	
	    }
};
int main()
{
	graph2 R;
	R.input();
	R.calc();
	getch();
	return 0;
}
