#include <iostream>
#include <conio.h>
using namespace std;
class pattern
{
	public:
		int printpattern()
		{
	    int n,i,j,k;
		cout<<"\n Enter the rows";
		cin>>n;
		int c=n;
		for (i=1; i<=n; i++)
		{
			for (j=1; j<c; j++)
			{
			    cout<<" ";
			}
			for (k=0; k<(2*i)-1; k++)
			{
				cout<<"*";
			}
		
		cout<< endl; c--;}
	}
};
int main()
{
	pattern p;
	p.printpattern();
	getch();
	return 0;
}
 
