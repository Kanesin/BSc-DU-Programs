#include <iostream>
#include <conio.h>
using namespace std;
class factor
{
	public:
		int input()
		{
			int n;
			cout<<"\n Enter the number ";
			cin>>n;
			return n;
		}
		void checkfactor(int a)
		{
			int i;
			cout<<"\n The factors of "<<a<<" are ";
			for (i=1; i<=a; i++)
			{
				if (a%i==0)
				cout<<i<<" ";
			}
		}
};
int main()
{
	factor f;
	int x;
	x=f.input();
	f.checkfactor(x);
	getch();
	return 0;
}
