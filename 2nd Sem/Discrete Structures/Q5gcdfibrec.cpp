#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class rec
{
	public:
		int ch;
		
		int menu()
		{
			cout<<"\nMENU";
			cout<<"\n1.FACTORIAL";
			cout<<"\n2.FIBONACCI";
			cout<<"\n3.GCD";
			cout<<"\n4.EXIT";
			cout<<"\nEnter your choice: ";
			cin>>ch;
			return ch;
		}
		int fib(int n)
		{
			if(n<=1)
			   return n;
			else
			   return fib(n-1)+ fib(n-2);
			  
		}
		long fac(long n)
		{   
		    
			if(n==1)
			  return 1;
			else
			{
			  return fac(n-1)*n;
			}  
		}
		int gcd(int a,int b)
		{
			
			if(b==0)
			  return a;
			else
			{
				gcd(b,a%b);
			}  
		}
};

int main()
{
	char c;
	do
	{
	
	rec R;
	
    int x=R.menu();
    int n,a,b;
    long n1;
    switch(x)
    {
    	case 1:cout<<"\nEnter the number: ";
    	       cin>>n1;
    	       cout<<"\nThe factorial is: "<<R.fac(n1);
    	       break;
    	case 2:cout<<"\nEnter the number of terms: ";
		       cin>>n;
			   int i;
			    cout<<"0 1 ";
			   for(i=2;i<n;i++)
			   {
			   	cout<<R.fib(i)<<" ";
			   }        
			   break;
		case 3:cout<<"\nEnter the two numbers: ";
		       cin>>a>>b;
			   cout<<"\nThe GCD of the numbers you entered: "<<R.gcd(a,b);
			   break;
		case 4:exit(0);
		       break;
		default:cout<<"\nWRONG CHOICE!!!";
		        break;	   	   	   
    }
    cout<<"\nDo you want to continue?(y for yes): ";
    cin>>c;
    }while(c=='y'||c=='Y');
    getch();
    return 0;
}

