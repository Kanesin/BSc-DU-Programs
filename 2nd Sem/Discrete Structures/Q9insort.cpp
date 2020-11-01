#include<iostream>
#include<conio.h>
using namespace std;
class insertion
{
	public:
		int n,i,j,k,temp,A[10];
		void input()
		{
			cout<<"\nEnter the numnber of elements: ";
			cin>>n;
			cout<<"\nEnter the elements: ";
			for(i=0;i<n;i++)
			{
				cin>>A[i];
			}
			
		}
		void sort()
		{
			for(i=1;i<n;i++)
			{
				k=A[i];
				j=i-1;
				int c=0;
				while(j>=0&&A[j]>k)
				{
					A[j+1]=A[j];
					A[j]=k;
					j--;
					c++;
				}
				
				cout<<"\nAfter "<<i<<" pass and "<<c<<" comparison the array is: ";
				for(int g=0;g<n;g++)
				{
					cout<<A[g]<<" ";
					
				}
			}
			cout<<"\nThe final array is: ";
			for(int g=0;g<n;g++)
			{
				cout<<A[g]<<" ";
			}
			
		}
};
int main()
{
	insertion X;
	X.input();
	X.sort();
	getch();
	return 0;
}
