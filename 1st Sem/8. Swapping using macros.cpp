#include <iostream>
#include <conio.h>
#define swap(a,b) {int t; t=a; a=b; b=t;} 
using namespace std;
int main ()
{
	int x,y;
	cout<<"\n Enter two numbers ";
	cin>>x>>y;
	cout<<"\n Before swapping ";
	cout<<"x="<<x<<" "<<"y="<<y;
	cout<<"\n After swapping ";
	swap (x,y);
	cout<<"x="<<x<<" "<<"y="<<y;
	getch();
	return 0;
}
