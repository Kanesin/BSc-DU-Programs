#include <iostream>
#include <conio.h>
using namespace std;
class merge
{
	public:
		void arrmer()
		{
			int a[20],b[20],c[40],m,n;
			cout<<"\n Enter size of array 1:";
			cin>>m;
			cout<<"\n Enter the elements of array";
			for (int i=0; i<m; i++)
			{
				cin>>a[i];
			}
			cout<<"\n Enter the size of array 2:";
			cin>>n;
			cout<<"\n Enter the elements of array";
			for (int i=0; i<n; i++)
			{
				cin>>b[i];
			}
			cout<<"\n Merged array is";
			int i=0, j=0, k=0;
			while (i<m && j<n)
			{
				if (a[i]<b[j])
				c[k++]=a[i++];
				else
				c[k++]=b[i++];
			}
			while (i<m)
			{
				c[k++]=a[i++];
			}
			while (j<n)
			{
				c[k++]=b[j++];
			}
			for (int i=0; i<m+n; i++)
			{
				cout<<c[i]<<" ";
			}
		}
};
int main()
{
	merge M;
	M.arrmer();
	getch();
	return 0;
}
