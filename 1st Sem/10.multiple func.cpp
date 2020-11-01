#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class tn
{
	public :
		void even_nos(int A[], int n)
		{
			cout<<"\n The even elements of array are";
			for (int i=0; i<n; i++)
			{
				if (A[i]%2==0)
				cout<<A[i]<<" ";
			}
		}
		void odd_nos (int A[], int n)
		{
			cout<<"\n The odd elements of array are";
			for (int i=0; i<n; i++)
			{
				if (A[i]%2!=0)
				cout<<A[i]<<" ";
			}
		}
		void sumavg (int A[], int n)
		{
			float s=0, avg;
			for (int i=0; i<n; i++)
			{
				s+=A[i];
			}
			avg=s/n;
			cout<<"\n The sum of the elements is"<<s;
			cout<<"\n The average of the elements is"<<avg;
		}
		void maxmin(int A[], int n)
		{
			int max=A[0], min=A[0];
			for (int i=0;i<n;i++)
			{
				if (A[i]>max)
				max=A[i];
				else
				min=A[i];
			}
			cout<<"\n Maximum"<<max;
			cout<<"\n Minimum"<<min;
		}
		void duplicate(int A[], int n)
		{
			for(int i=0; i<n; i++)
			{
				for (int j=i+1; j<n; j++)
				{
					if (A[i]==A[j])
				{
				    for (int k=j; k<n-1; k++)
				{
					A[k]=A[k+1];
				}n--;
			}
		}
	}
	cout<<"\n Array after removing duplicate elements";
	for(int i=0; i<n; i++)
	{
	cout<<A[i]<<" ";
	}
	}
	void reverse(int A[], int n)
	{
		cout<<"\n Array in reverse order";
		for (int i=n-1; i>=0; i--)
		cout<<A[i]<<" ";
	}
};
int main()
{
	tn a;
	int c; char ch;
	do
	{
		int n;
		cout<<"\n Enter the size of array";
		cin>>n;
		int A[n];
		cout<<"\n Enter the elements of the array";
		for(int i=0; i<n; i++)
		{
			cin>>A[i];
		}
		cout<<"\n MENU";
		cout<<"\n 1. Print even elements";
		cout<<"\n 2. Print odd elements";
		cout<<"\n 3. Calculate and print sum and average elements of array";
		cout<<"\n 4. Print maximum and minimum elements of array";
		cout<<"\n 5. Remove duplicate elements";
		cout<<"\n 6. Print array in reverse order";
		cout<<"\n 7. Exit";
		cout<<"\n Enter your choice";
		cin>>c;
		if (c==1)
		a.even_nos(A,n);
		else if (c==2)
		a.odd_nos(A,n);
		else if (c==3)
		a.sumavg(A,n);
		else if (c==4)
		a.maxmin(A,n);
		else if (c==5)
		a.duplicate(A,n);
		else if (c==6)
		a.reverse(A,n);
		else 
		exit(0);
		cout<<"\n Want to continue ( y for yes)";
		cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	getch();
	return 0;
}
