#include<iostream>
#include<conio.h>
using namespace std;
class crc
{
	private:
		int m,n,A[20],B[10],C[20],u;
		
	public:
		void enter()
		{
			int k;
			cout<<"\nEnter the no of degree of message: ";
			cin>>m;
			cout<<"\nEnter the digits of message: ";
			for(int i=0;i<m;i++)
			{
				cin>>A[i];
			}
			cout<<"\nEnter the size of divisor: ";
			cin>>n;
			cout<<"\nEnter the digits of divisor: ";
			for(int i=0;i<n;i++)
			{
				cin>>B[i];
			}
			k=m;
			u=n;
			for(int i=0;i<m;i++)
			{
				C[i]=A[i];
				
			}
			for(int i=0;i<n-1;i++)
			{
				C[k++]=0;
			}
			cout<<"\nThe message is: ";
			for(int i=0;i<m+n-1;i++)
			{
				cout<<C[i]<<" ";
			}
	divide(C,B);
		}
		
		
		
		
		void  divide(int a[],int b[])
		{
			
			int j=0,z[n+1];
			while(j<m+n)
				{
		  for(int i=0;i<n;i++)
			{
				
				z[i]=(a[i]^b[i]);
					
				j=j+n;
					
				}
		
			
			
			
			
			z[u]=C[u++];	
			 for(int i=1;i<u+1;i++)
			{	z[i-1]=z[i];
					u--; 
			}
				
			divide(z,B);
			
			
			
			}
		
			for(int i=0;i<n;i++)
			{
				cout<<z[i];
			}
		
		
			
			
		}
	
		
};
int main()
{
	
	crc c;
	c.enter();
	

	getch();
	return 0;
	
}
