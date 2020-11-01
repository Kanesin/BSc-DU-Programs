#include<iostream>
#include<conio.h>
using namespace std;
class bubble
{
	public:
		int n,i,j,k,A[10],temp;
		void input()
		{
			cout<<"\nEnter the number of elements: ";
			cin>>n;
			cout<<"\nEnter the elements: ";
			for(i=0;i<n;i++)
			{
				cin>>A[i];
			}
		}
		void sort()
		{
			for(i=0;i<n;i++)
			{
				int c=0;
				for(j=0;j<n-i-1;j++)
				{
					if(A[j]>A[j+1])
					{
						temp=A[j];
						A[j]=A[j+1];
						A[j+1]=temp;
						c++;
					}
					 
				}
				cout<<"\nAfter "<<i+1<<" pass and "<<c<<" comparison the array is: ";
				for(int k=0;k<n;k++)
				{
					cout<<A[k]<<" ";
				}
			}
			cout<<"\nThe final array is: ";
			for(int k=0;k<n;k++)
			{
				cout<<A[k]<<" ";
			}
		}
		
		
};
int  main()
{
	bubble B;
	B.input();
	B.sort();
	getch();
	return 0;
}
