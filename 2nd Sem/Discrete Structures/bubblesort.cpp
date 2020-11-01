#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int A[20],n,i,j,temp;
	cout<<"\nEnter the size of the array: ";
	cin>>n;
	cout<<"\nEnter the elements: ";
	for(i=0;i<n;i++)
	{
		cin>>A[i];
		
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i]<A[j])
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
			
		}
		cout<<"\nAfter "<<i<<" pass:";
		for(i=0;i<n;i++)
			{
				cout<<A[i]<<" ";
				
			}
			cout<<"\n";
	}
	for(i=0;i<n;i++)
			{
				cout<<A[i]<<" ";
				
			}
	getch();
	return 0;
	
}
