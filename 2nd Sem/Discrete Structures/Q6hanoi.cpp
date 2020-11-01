#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class Hanoi
{
	public:
	int n;
    char A,B,C;
	void input()
	{
		cout<<"\nEnter the number of disks: ";
		cin>>n;
		A='A';
		B='B';
		C='C';
	}
	int func(int n,char A,char B,char C)
    {
    	if(n==1)
    	{
    	cout<<"\n Shift from "<<A<<" TO "<<C;
	    return -1;
		}
		else
		{
			func(n-1,A,C,B);
			func(1,A,B,C);
			func(n-1,B,A,C);
		}	
    } 
};
int main()
{
	Hanoi H;
	H.input();
	H.func(H.n,H.A,H.B,H.C);
	getch();
	return 0;
}
