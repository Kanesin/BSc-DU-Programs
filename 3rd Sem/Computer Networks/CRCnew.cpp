#include<iostream>
#include<conio.h>
using namespace std;
class crc{
	public:
	int A[10],B[5],F[4];
	int sA,sB,sF;
	void input()
	{	int f;
		cout<<"Enter Size of dataword\n";
		cin>>sA;
		cout<<"Enter Dataword\n";
		for(int i=0;i<sA;i++)
		{
			cin>>f;
			if(f==0)
			A[i]=0;
			else
			A[i]=1;
		}			
		cout<<"Enter size of Generator\n";
		cin>>sB;
		cout<<"Enter Generator\n";
		for(int i=0;i<sB;i++)
		{
			cin>>f;
			if(f==0)
			B[i]=0;
			else
			B[i]=1;
		}				
	}
	void remainder(int X[],int Y[],int sX,int sY)
	{	if(sX>sY-1)
		{	
		for(int i=0;i<sY;i++)
		X[i]=X[i]^Y[i];
		for(int i=0;i<sX-1;i++)
			X[i]=X[i+1];
		sX--;		
		while(X[0]==0&&sX>sY-1)
			{
			for(int i=0;i<sX-1;i++)
			X[i]=X[i+1];
			sX--;
			}
		remainder(X,Y,sX,sY);
		}	
	}
	void calcrcbits()
	{
		int C[14];
		int sC=sA+sB-1;
		for(int i=0;i<sA;i++)
			C[i]=A[i];
		for(int i=sA;i<sC;i++)
			C[i]=0;		
		cout<<"\nMessage Sent=";
		for(int i=0;i<sC;i++)
			cout<<C[i];			
		remainder(C,B,sC,sB);
		cout<<"\nCRC Bits=";;
		for(int i=0;i<sB-1;i++)
		cout<<C[i];
		sF=sB-1;
		for(int i=0;i<sF;i++)
			F[i]=C[i];
	}
	void calrbits()
	{
		int D[14];
		int sD=sA+sB-1;
		for(int i=0;i<sA;i++)
			D[i]=A[i];
		for(int i=sA;i<sD;i++)
			D[i]=F[i-sA];			
		cout<<"\nMessage Recieved=";
		for(int i=0;i<sD;i++)
			cout<<D[i];			
		remainder(D,B,sD,sB);
		cout<<"\nRemainder=";
		for(int i=0;i<sB-1;i++)
		cout<<D[i];
	}
	void prog()
	{	input();
		cout<<"\nSender Side:";
		cout<<"\nEntered DataWord=";
		for(int i=0;i<sA;i++)
			cout<<A[i];
		cout<<"\nEntered Generator=";
		for(int i=0;i<sB;i++)
			cout<<B[i];
		calcrcbits();
		cout<<"\n\nReciever Side:";
		calrbits();		
	}	
};
int main()
{
	crc c;
	c.prog();
	getch();
}
