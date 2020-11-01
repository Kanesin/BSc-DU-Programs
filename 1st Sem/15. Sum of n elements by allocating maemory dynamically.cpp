#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class sumdyn
{
	public:
		void sum(int n)
		{
			int*p;
			p=(int*)malloc(n* sizeof(int));
			int s=0;
			cout<<"\n Enter elements";
			for(int i=0; i<n; i++)
			{
				cin>>*p;
				s+=*p;
			}
			cout<<"\n The sum is"<<s;
		}
};
int main()
{
	sumdyn s;
	int n;
	cout<<"\n Enter n";
	cin>>n;
	s.sum(n);
	getch();
	return 0;
}

