#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class pandc
{
	int n,r,nfac,rfac,nmr;
	public:
		int fac(int n)
		{
       		if(n==0||n==1)
			   return 1;
			   else if(n<r)
			{
			   cout<<"N is smaller than R";
			   exit(0);
			}
			else
			{
				return fac(n-1)*n;
			}
		}
	
		void input()
		{
			cout<<"\nEnter the number n:";
			cin>>n;
			cout<<"\nEnter the number r:";
			cin>>r;
		}
	    void calc()
	    {
			nfac=fac(n);
			rfac=fac(r);
	    	nmr=fac(n-r);
		}
		void display()
		{
			cout<<"\nThe permutations:"<<nfac/nmr;
			cout<<"\nThe combinations:"<<nfac/(nmr*rfac);
		}
};
int main()
{
	pandc P;
	P.input();
	P.calc();
	P.display();
	getch();
	return 0;
}
