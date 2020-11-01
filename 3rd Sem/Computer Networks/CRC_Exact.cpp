#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class CRC
{
	int A[20],B[20],C[40],bits[20],m,n,c;
	public:
		void enter()
		{
			cout<<"ENter the size of dataword";
			cin>>m;
			cout<<"Enter the dataword in binary";
			for(int i=0;i<m;i++)
			{
				cin>>A[i];
			}
			cout<<"Enter the size of generator";
			cin>>n;
			if(n>m)
			{
				cout<<"INVALID INPUT";
				getch();
				exit(0);
			}
			cout<<"Enter the generator in binary";
			for(int i=0;i<n;i++)
			{
				cin>>B[i];
			}
		
		}
		
		void create()
		{
			c=0;
			for(int i=0;i<m;i++)
			{
				C[c++]=A[i];
			}
			for(int j=0;j<n-1;j++)
			{
				C[c++]=0;
			}
		
		
		cout<<"\n The data word sender side is: ";
			for(int i=0;i<c;i++)
			{
			cout<<	C[i];
			}

		rem(C,B,c,n);
		cout<<"\n THe CRC bit on the reciever side is:";
		for(int i=0;i<n-1;i++)
		{
			cout<<C[i];
		}

		}
		void rem(int X[],int Y[],int s,int t)
		
		{
			if(s>t-1)
			{
				for(int i=0;i<t;i++)
				{
					X[i]=X[i]^Y[i];
				}
				
				for(int i=0;i<s-1;i++)
				{
					X[i]=X[i+1];
				}	
				s--;
				while(X[0]==0&&s>t-1)
				{
					for(int i=0;i<s-1;i++)
					{
						X[i]=X[i+1];
					}
					s--;
					
					
				}
				rem(X,Y,s,t);
			}
	
		}
		void rec_side()
		{
			int F[c],t=0;
			for(int i=0;i<m;i++)
			{
				F[t++]=A[i];
			}
			for(int i=0;i<n-1;i++)
			{
				F[t++]=C[i];
			}
			cout<<"\n\n the data on the reciver side is ";
			for(int i=0;i<c;i++)
			{
				cout<<F[i];
			}
			rem(F,B,c,n);
			cout<<"\n The crc bit on the recievers side is";
			for(int i=0;i<n-1;i++)
			{
				cout<<F[i];
				
			}
			int flag=0;
			for(int i=0;i<n-1;i++)
			{
				if(F[i]==1)
				{
					flag=1;
					break;
				}
				
			}
			if(flag==1)
			{
				cout<<"\n ERRORRORORORR";
			}
			else
			{
				cout<<"\n NOERROR";
			}
		}
		
		
};
int main()
{
	CRC c;
	c.enter();
	c.create();
	c.rec_side();
	getch();
	return 0;
}
