#include<iostream>
#include<conio.h>

using namespace std;

int fact(int c)
{
	if(c==0)
	return 1;
	else 
	return (fact(c-1)*c);
}

int fab(int d)
{
	if(d==0)
	return 0;
	else if(d==1)
	return 1;
	else 
	return(fab(d-1)+fab(d-2));
}
int main()
{
	int x;
	cout<<"\nEnter the number";
	cin>>x;
	
	cout<<"\nFactorial of number = "<<fact(x);
	cout<<"\n";
	for(int i=0;i<x;i++)
	cout<<fab(i)<<" ";
	getch();
	
	
}


