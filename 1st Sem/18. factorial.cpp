#include <iostream>
#include <conio.h>
using namespace std;
class factorial
{
	public:
		int input()
		{
			int ch;
			long int x;
			cout<<"\n Enter a number to find factorial:";
			cin>>x;
			cout<<"\n Enter Choice";
			cout<<"\n Factorial using recursion";
			cout<<"\n Factorial using  iteration";
			cin>>ch;
			switch (ch)
			{
				case 1: cout<<"\n Factorial is:"<<recursion(x);
				break;
				case 2: cout<<"\n Factorial is:"<<iteration(x);
				break;
				default: cout<<"Wrong choice!";
			}
		}
		long int iteration(long int a)
		{
			long int x=1;
			for (int i=a; i>0; i++)
			{
				x=x*i;
			}
			return x;
		}
		long int recursion(long int a)
		{
			if (a==0||a==1)
			return 1;
			else
			return (a*recursion(a-1));
		}
};
int main ()
{
	factorial F;
	F.input();
	getch();
	return 0;
}
