#include <iostream>
#include<conio.h>
using namespace std;
class rev
{
	public:
		int input()
		{ int a;
		cout<<"\n Enter the number";
		cin>>a;
		return a;
		}
		void reverse(int n)
		{
			int r,s=0;
			while(n>0)
			{
				r=n%10;
				s=(s*10)+r;
				n=n/10;
			}
			cout<<"\n The reverse of the number is"<<s;
		}
};
int main()
{
rev s;
int c;
c=s.input();
s.reverse(c);
getch();
return 0;
}
