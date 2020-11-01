#include <iostream>
#include <conio.h>
using namespace std;
class array
{
	public:
		int n, A[20],*p;
		int*input()
		{
			cout<<"\n Enter the size of array";
			cin>>n;
			cout<<"\n Enter elements";
			for (int i=0; i<n; i++)
			{
				cin>>A[i];
			}
			p=A;
			return p;
		}
void reverse(int *p)
{
	int i,j,temp;
	for (i=0, j=n-1; i<n/2; i++, j--)
	{
		temp=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=temp;
	}
	for (i=0; i<n; i++)
	{
		cout<<*(p+i);
		cout<<" ";
	}
}
};
int main()
{
	array A;
	int*x;
	x=A.input();
	A.reverse(x);
	getch();
	return 0;
}
