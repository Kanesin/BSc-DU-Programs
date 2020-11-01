#include <iostream>
#include <conio.h>
using namespace std;
class GCD
{
	public:
		int input()
		{
			int ch,x,y;
			cout<<"\n Enter two nos.";
			cin>>x>>y;
			cout<<"\n Enter choice";
			cout<<"\n 1.GCD using recursion";
			cout<<"\n 2.GCD using iteration \n";
			cin>>ch;
			switch(ch)
			{
				case 1:cout<<"\n GCD using recursion: "<<recursion(x,y);
				break;
				case 2:cout<<"\n GCD usign iteration: "<<iteration(x,y);
				break;
				default:cout<<"Wrong choice!";
			}
		}
		int iteration(int a, int b)
		{
			int x;
			for (int i=1; i<=b; i++)
			{
				if ((a%i==0)&&(b%i==0))
				x=i;
			}
			return x;
		}
		int recursion(int a , int b)
		{
			if (b!=0)
			return recursion(b,a%b);
			else
			return a;
		}
};
int main()
{
	GCD g;
	g.input();
	getch();
	return 0;
}
