#include<iostream>
#include<conio.h>
using namespace std;
class prin
{
	char dig[10],*p;
	int n;
	public:
		void input()
		{
			cout<<"\nEnter the number of elements:";
			cin>>n;
			cout<<"\nEnter the elements:";
			for(int i=0;i<n;i++)
			cin>>dig[i];
	    }
		void calc()
		{
			char *p=dig;
			
			
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n-1;j++)
				{
					cout<<p<<"\n";
					char temp=dig[j];
					dig[j]=dig[j+1];
					dig[j+1]=temp;
					
				}
			}
		}
};
int main()
{
	prin P;
	P.input();
	P.calc();
	getch();
	return 0;
}
