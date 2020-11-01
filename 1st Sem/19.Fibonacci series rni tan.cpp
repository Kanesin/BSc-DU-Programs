#include <iostream>
#include <conio.h>
using namespace std;
class fibonacci
{
	public:
		int input()
		{
			int n;
			cout<<"\n Enter the no. of elements:";
			cin>>n;
			return n;
		}
		int choice()
		{
			int ch;
			cout<<"\n Enter choice ";
			cout<<"\n 1.Fibonacci series using iteration";
			cout<<"\n 2.Fibonacci series using recursion";
			cin>>ch;
			int size;
			switch (ch)
			{
				case 1: fibonacci_loop(input());
				break;
				case 2:size=input();
				cout<<"\n Fibonacci series is:";
				for (int i=0; i<size; i++)
				{
					cout<<fibonacci_recursion(i)<<"\t";
				}
				break;
				default:cout<<"Wrong choice!";
			}
		}
		void fibonacci_loop(int n)
		{
			cout<<"\n Fibonacci series is:";
			int fn=0,sn=1,tn;
			if (n==1)
			cout<<fn<<"\t";
			else if (n==2)
			{
				cout<<fn<<"\t";
				cout<<sn<<"\t";
			}
			else if (n>2)
			{
				cout<<fn<<"\t";
				cout<<sn<<"\t";
				for (int i=3; i<=n; i++)
				{
					tn=fn;
					fn=sn;
					sn=sn+tn;
					cout<<sn<<"\t";
				}
			}
		}
		int fibonacci_recursion(int i)
		{
			if (i==0||i==1)
			return i;
			else
			return (fibonacci_recursion(i-1)+fibonacci_recursion(i-2));
		}
};
int main()
{
	fibonacci f;
	f.choice();
	getch();
	return 0;
}
