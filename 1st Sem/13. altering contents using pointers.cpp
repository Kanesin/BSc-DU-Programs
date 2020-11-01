#include <iostream>
#include <conio.h>
using namespace std;
class alter
{
	public:
		void change(int*p, int*q)
		{
			*p+=10;
			*q+=10;
		}
};
int main()
{
	alter A;
	int a, b;
	cout<<"\n Enter two nos.";
	cin>>a>>b;
	cout<<"\n Before alteration"<<endl;
	cout<<"a="<<a<<""<<"b="<<b;
	A.change(&a, &b);
	cout<<"\n After alteration"<<endl;
	cout<<"a="<<a<<""<<"b="<<b;
	getch ();
	return 0;
}
