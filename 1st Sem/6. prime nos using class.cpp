#include <iostream>
#include <conio.h>
using namespace std;
class factor
{
	public:
		int i=1;
		void counter()
		{
			i++;
			while (i<=100)
			{
				printprime(i);
			}
		}
		void printprime(int x)
		{
			int j, f=0;
			for (j=2; j<=x/2; j++)
			{
				if(x%j==0)
				{
					f=1;
					break;
				}
			}
			if (f==0)
			cout<<x<<" ";
			counter();
		}
}obj;
int main()
{
	obj.counter();
	getch();
	return 0;
}
