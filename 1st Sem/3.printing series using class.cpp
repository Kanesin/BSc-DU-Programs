#include <iostream>
#include <conio.h>
using namespace std;
class sum
{
	public:
		int n;
		void input()
		{
			cout<<"\n Enter the number upto which the series is to be printed";
			cin>>n;
			series (n);
		}
		void series(int a)
		{
			float s=1.0;
			int i;
			for(i=2; i<=a; i++)
			{
				s=s+(1.0/i);
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
