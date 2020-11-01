#include<iostream>
#include<conio.h>
using namespace std;
int linear(int A[],int front,int last,int x)
{
	if(front>last)
		return -1;
	if(A[front]==x)
		return front;
	if(A[last]==x)
		return last;	
	linear(A,front+1,last-1,x);
	
}
int main()
{
	int A[10],sA;
	cout<<"SIZE:";
	cin>>sA;
	cout<<"DATA: ";	
	for(int i=0;i<sA;i++)
	{
		cin>>A[i];
	}
	int data;
	cout<<"SEARCH: ";
	cin>>data;	
	int x=linear(A,0,sA-1,data);
	cout<<x;
	getch();
}

