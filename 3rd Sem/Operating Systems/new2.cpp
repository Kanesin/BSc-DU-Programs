#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
	float a=123.45;
	cout<<setw(10)<<a<<endl;
	cout<<setw(10)<<setfill('*')<<a<<endl;
	cout<<setw(10)<<setfill(' ')<<a<<endl;
	getch();
	return 0 ;
}
