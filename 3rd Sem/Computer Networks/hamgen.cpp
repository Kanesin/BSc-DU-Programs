#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<math.h>
using namespace std;
class Hamc{
	public:
	int A[100],sA,pB,B[107],sB,C[107],sC;
	int BC[128][7],rC,cC;
	bool o_e;
	void input()
	{	int f;
		cout<<"Enter Size of data to be sent\n";
		cin>>sA;
		cout<<"Enter Data\n";
		for(int i=0;i<sA;i++)
		{	
			cin>>f;
			if(f==0)
			A[i]=0;
			else
			A[i]=1;
		}
		cout<<"Odd parity (1)or Even Parity(0)?\n";
		cin>>o_e;
		o_e%=2;
		calParBit();			
	}
	
	void binC(int size)
	{
		rC=pow(2,size);
		cC=size;
		for(int i=0;i<rC;i++)
		{
			for(int j=0;j<cC;j++)
			{
			if(1<<j&i)
				BC[i][j]=1;
			else
				BC[i][j]=0;	
			}
		}	
	}
	
	void calParBit()
	{
		int a=1;
		int p=0;
		while(a<p+sA+1)
		{
			a=a*2;
			p++;
		}
		pB=p;
		sB=sA+pB;
		binC(pB);
	}
	
	void genSendWord()
	{
		int a=1,c=0;
		for(int i=0;i<sB;i++)
			if(i==a-1)
			{
				a=a*2;
				B[i]=0;
			}
			else
				B[i]=A[c++];
		cout<<"Data to be sent\n";
		display(B,sB);
		for(int i=0;i<pB;i++)
		{
			int pos=pow(2,i)-1;
			B[pos]=calc(i,B,sB,o_e);
		}
		cout<<"Data actually sent\n";
		display(B,sB);
	}
	
	bool calc(int a,int X[],int sX,bool o_e)
	{
		bool val=o_e;
		for(int j=0;j<sX+1;j++)
		{
			if(BC[j][a]==1)
				val^=X[j-1];
		}		
		return val;
	}
	
	void display(int X[],int sX)
	{	
		for(int i=0;i<sX;i++)
			cout<<X[i]<<"\t";
		cout<<endl;
	}	
	
	void randomNoise()
	{
		sC=sB;
		for(int i=0;i<sC;i++)
			C[i]=B[i];
		srand(time(NULL));
		int a=rand();
		a=a%sB;
		C[a]=1^C[a];
	}

	void checkRecWord()
	{	cout<<"\nReciever Side\n";
		randomNoise();
		cout<<"Random Noised data\n";
		display(C,sC);
		int X[pB];
		for(int i=0;i<pB;i++)
			X[i]=calc(i,C,sC,o_e);
		int pos=0;		
		for(int i=0;i<pB;i++)
			pos+=X[i]*pow(2,i);			
		if(pos!=0)
			{
			cout<<"Error at Pos "<<pos<<endl;
			C[pos-1]=1^C[pos-1];	
			}
		else
			cout<<"Error Free";
	}
	
	void prog()
	{
		input();		
		cout<<"\nSender Side\n";
		cout<<"Original Data\n";
		display(A,sA);
		genSendWord();		
		checkRecWord();
		cout<<"Correct Received Bits\n";
		display(C,sC);
	}
		
};
int main()
{
	Hamc h;
	h.prog();
	getch();
}
