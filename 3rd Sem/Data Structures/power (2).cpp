#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class power{
	
	void input()
	{
		float base,pow,result;
		cout<<"Enter base\n";
		cin>>base;
		cout<<"Enter Power\n";
		cin>>pow;
		result=recPower(base,pow);
		if(pow<0)
		result=1/result;
		cout<<base<<"^"<<pow<<"= "<<result<<endl;				
	}
	
	float recPower(float x,float y)
	{
		if(y<0)
		return ((x*recPower(x, y+1)));
		else if (y > 0)
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
