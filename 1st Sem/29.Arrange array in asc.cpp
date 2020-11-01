#include <iostream>
#include <conio.h>
using namespace std;
class array
{
	public:
		int n, A[30],*p;
		int *input()
		{
			cout<<"\n Enter size";
			cin>>n;
			cout<<"\n Enter elements";
			for (int i=0; i<n; i++)
			{
				cin>>A[i];
			}
			p=A;
			return p;
		}
		void asc (int*p)
		{
			int i,j,temp;
			for (int i=0; i<n; i++)
			{
				for (j=i+1; j<n; j++)
				{
					if(*(p+i)>*(p+j))
					{
						temp=*(p+i);
						*(p+i)=*(p+j);
						*(p+j)=temp;
					}
				}
			}
			for (int i=0; i<n; i++)
			{
				cout<<*(p+i)<<" ";
			}
		}
		void des (int *p)
		{
			int i,j,temp;
			for (int i=0; i<n; i++)
			{
				for (j=i+1; j<n; j++)
				{
					if (*(p+i)<*(p+j))
					{
						temp=*(p+i);
						*(p+i)=*(p+j);
						*(p+j)=temp;
					}
				}
			}
			
		for (int i=0; i<n; i++)
		{
			cout<<*(p+i)<<" ";
		}
		}
};
int main()
{
	array A;
	int c,*x;
	x=A.input();
	cout<<"\n Ascending or descending?";
	cin>>c;
	if (c==1)
	A.asc(x);
	else if (c==2)
	A.des(x);
	else
	cout<<"\n Wrong Choice!";
	getch();
	return 0;
	}
