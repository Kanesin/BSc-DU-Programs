#include<iostream>
#include<conio.h>
#include "stack-array.cpp"
using namespace std;
class LargeNums
{	public:
	stack <int> S1(32);
	stack <int> S2(32);
	stack <int> S3(32);
	void input()
	{
		string num1,num2;
		cout<<"Enter number 1\n";
		cin>>num1;
		for(int i=0;num1[i]!='\0';i++)
			S1.push(num1[i]-48);
		cout<<"Enter number 2\n";
		cin>>num2;
		for(int i=0;num2[i]!='\0';i++)
			S2.push(num2[i]-48);
		
		sum(S1,S2);		
	}
	
	void sum(stack <int> ob1,stack <int> ob2)
	{
		int carry=0,val=0,n1,n2;
		while(!ob1.isEmpty()||!ob2.isEmpty())
		{
			if(ob1.isEmpty())
				n1=0;
			else
				n1=ob1.pop();
				
			if(ob2.isEmpty())
				n2=0;
			else
				n2=ob2.pop();
			val=n1+n2+carry;
			S3.push(val%10);
			carry=val/10;
		}
		if(carry!=0)
			ob3.push(carry);
	}	
	
	void output()
	{
		S3.display();
	}
};

int main()
{
	LargeNums l;
	l.input();
	l.output();
}

