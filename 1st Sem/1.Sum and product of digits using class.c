#include <iostream>
#include <conio.h>
using namespace std;
class sp
{
	public:
		int input()
		{
			int a;
			cout<<"\n Enter the number";
			cin>>a;
			return a;
		}
		void sumpro(int b)
		{
			int r,s=0,p=1;
			while(b>0)
		{
			r=b%10;
			s=s+r;
			p=p*r;
			b=b/10;
		}
		cout<<"\n The sum of the digits of the number is:"<<s;
		cout<<"\n The product of the digits of the number is:"<<p;
	    }
	};
	int main()
	{
		sp s1;
		int c;
		c=s1.input();
		s1.sumpro(c);
		getch();
		return 0;
		}
