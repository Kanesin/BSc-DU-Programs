#include <iostream>
#include <conio.h>
using namespace std;
class pointer
{
	public:
		void swapup(int*p, int*q)
		{
			int t;
			t=*p;
			*p=*q;
			*q=t;
		}
};
int main()
{
	pointer A;
	int a, b;
	cout<<"\n Enter two nos.";
	cin>>a>>b;
	A.swapup(&a, &b);
	cout<<"\n After swapping"<<endl;
	cout<<"a="<<a<<""<<"b="<<b;
	getch();
	return 0;
}
