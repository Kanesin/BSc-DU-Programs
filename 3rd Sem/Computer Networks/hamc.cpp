#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;
class Hamc{
	private:
	int A[10],sA,pB,B[14],sB,C[10],sC;
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
	}
	
	void genWord()
	{
		int a=1,c=0;
		for(int i=0;i<sB;i++)
			if(i==a-1)
			{
				a=a*2;
				B[i]=5;
			}
			else
				B[i]=A[c++];
		B[0]=B[2]^B[4]^B[6];
		B[1]=B[2]^B[5]^B[6];
		B[3]=B[4]^B[5]^B[6];
	}
	
	void display(int X[],int sX)
	{	
		for(int i=0;i<sX;i++)
			cout<<X[i]<<"\t";
		cout<<endl;
	}
	
	void input2()
	{
		cout<<"Entered Received Data\n";
		sC=sB;		
		for(int i=0;i<sC;i++)
			cin>>C[i];
	}
	
	
	void random()
	{
		sC=sB;
		for(int i=0;i<sC;i++)
			C[i]=B[i];
		srand(time(NULL));
		int a=rand();
		a=a%7;
		C[a]=1^C[a];
	}
	
	void check()
	{		
		random();
		cout<<"Random Noised data\n";
		display(C,sC);
		int X[3];
		X[0]=C[0]^C[2]^C[4]^C[6];
		X[1]=C[1]^C[2]^C[5]^C[6];
		X[2]=C[3]^C[4]^C[5]^C[6];
		int pos=X[2]*4+X[1]*2+X[0];
		if(pos!=0)
			{
			cout<<"Error at Pos "<<pos<<endl;
			C[pos-1]=1^C[pos-1];	
			}
		else
			cout<<"Error Free";
	}
	public:
	void prog()
	{
		input();
		calParBit();
		genWord();
		cout<<"Data to be sent\n";
		display(A,sA);
		cout<<"Data sent\n";
		display(B,sB);
		check();
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
