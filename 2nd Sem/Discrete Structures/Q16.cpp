#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class Q16
{
	int n,b[10];
	public:
		
		void input()
		{
			cout<<"Enter the highest degree of polynomial\n";
			cin>>n;
		}
		void enter()
		{
			for(int i=n;i>=0;i--)
			{
				cout<<"Enter the coeficient of x^"<<i<<" : ";
				cin>>b[i];
			}
		}
		int calc(int a)
		{
			int x=0;
			for(int i=0;i<=n;i++)
			{
				x+=b[i]*pow(a,i);
			}
			return x;
		}
};
int main()
{
	Q16 ob;
	ob.input();
	cout<<"Enter the value of x \n";
	int a;
	cin>>a;
	ob.enter();
	int s=ob.calc(a);
	cout<<"The answer of the polynomial is  :  "<<s;
	getch();
	return 0;
}
