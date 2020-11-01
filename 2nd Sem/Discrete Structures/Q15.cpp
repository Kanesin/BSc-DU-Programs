#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class Recurrence
{
	int n;
	public:
		void inp()
		{
			cout<<"Enter the value of n for Recurrence relation T(n) : ";
			cin>>n;
		}
		int Rec1(int n)
		{
			if(n==0)
				return 1;
			else
				return( Rec1(n-1)+n );
		}
		int Rec2(int n)
		{
			if(n==0)
				return 1;
			else
				return( Rec2(n-1)+pow(n,2) );
		}
		int Rec3(int n)
		{
			if(n==1)
				return 1;
			else
				return( ( (2*Rec3(n-1))/2 )+n );
		}
		void menu()
		{
			int c;
			cout<<"\nMENU : ";
			cout<<"\n1.T(n)=T(n-1)+n. ";
			cout<<"\n2.T(n)=T(n-1)+n^2.";
			cout<<"\n3.T(n)=(2*T(n-1))/2+n. ";
			cout<<"\nEnter your choice : ";
			cin>>c;
			if(c<=3)
				choice(c);
			else
				cout<<"Wrong Input!!";
		}
		void choice(int m)
		{
			inp();
			int a,b,c;
			char ch='Y';
			do
			{
				switch(m)
				{
					case 1: a=Rec1(n);
							cout<<"\nRecurrence Relation T("<<n<<") : "<<a;
							break;
					case 2: b=Rec2(n);
							cout<<"\nRecurrence Relation T("<<n<<") : "<<b;
							break;
					case 3: c=Rec3(n);
							cout<<"\nRecurrence Relation T("<<n<<") : "<<c;
							break;
					default :cout<<"Wrong choice ";
				}
				cout<<"\nDo you want to continue(Y/N) : ";
				cin>>ch;
				if(ch=='Y' || ch=='y')
					menu();
				else
				{
					cout<<"Exiting the program ";
					exit(0);
				}
					
			}while(ch=='Y' || ch=='y');
		}
}R;
int main()
{
	R.menu();
	getch();
	return 0;
}
