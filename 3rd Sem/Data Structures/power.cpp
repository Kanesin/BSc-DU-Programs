#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class power{
	
	void input()
	{
		int base,pow,result;
		cout<<"Enter base\n";
		cin>>base;
		cout<<"Enter Power\n";
		cin>>pow;
		result=recPower(base,pow);
		cout<<base<<"^"<<pow<<"= "<<result<<endl;				
	}
	
	int recPower(int x,int y)
	{
		if (y >= 1)
        return (x*recPower(x, y-1));
    else
        return 1;
	}
	
	public:
	void prog()
	{
		while(true)
		{	char Y;
			input();
			cout<<"do you want to continue(Y/N)?";
			cin>>Y;
			if(Y=='y'||Y=='Y')
				prog();
			else
				exit(0);
		}
	}
};

int main()
{
	power p;
	p.prog();
	getch();	
}
