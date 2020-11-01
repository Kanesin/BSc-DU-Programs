#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int n;
	cout<<"\nEnter the size: ";
	cin>>n;
	int i,A[n];
	cout<<"\nEnter the elements: ";
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int x;
	cout<<"\nEnter the element to be searched: ";
	cin>>x;
	int first=0,last=n-1;
	int mid,pos,f=0;
	while(first<last)
	{
		mid=(first+last)/2;
		if(A[mid]==x)
		{
		f=1;
		pos=mid;
	    break;
		}
		else if(A[mid]>x)
		last--;
		else
		first++;
	}
	if(f==1)
	cout<<"\n element found at position: "<<pos+1;
	getch();
	return 0;
}
