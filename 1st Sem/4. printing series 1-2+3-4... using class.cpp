#include <iostream>
#include<conio.h>
using namespace std;
class sum
{
	public:
		int n;
		void input()
		{
			cout<<"\n Enter the number upto which the series is to be printed";
			cin>>n;
			series(n);
		}
		void series(int a)
		{
			int s=1,i;
			for(i=2; i<=a; i++)
			{
				if(i%2==0)
				s=s-i;
				else
				s=s+i;
			}
			cout<<"\n The sum of the series"<<s;
		}
};
int main()
{
	sum s;
	s.input();
	getch();
	return 0;
	}
