#include<iostream>
#include<conio.h>
#include "stack-array.cpp"
using namespace std;
class delimeter
{
	int delim(string code)
	{
		stack <char> ob(30);
		char ch,temp;
		try
		{
			int i=0;
		for(;code[i]!='\0';i++)
		{
			
			
			ch=code[i];
			if(ch=='/')
			{
				if(code[i+1]=='*')
					{
						int j=i+2;
						while((code[j]!='*'&&code[j+1]!='/')&&code[j]!='\0')
							j++;
						i=j-1;
						continue;
					}
			}
			switch(ch)
			{
				case '{': 	ob.push('{');
				break;
				case '}': 	temp=ob.pop();
							if(temp!='{');
				break;
				case '[': 	ob.push('[');
				break;
				case ']': 	temp=ob.pop();
							if(temp!='[');
				break;
				case '(': 	ob.push('(');
				break;
				case ')': 	temp=ob.pop();
							if(temp!='(');
				break;
				default: continue;
			}
		}
		if(!ob.isEmpty())
			throw "error";		
		else
			return 1;
		}
		catch(const char*c)
		{
			throw "invalid amount of operands";
		}			
	}
	
	public:
	void prog()
	{
		char Y;
		string expression;
		cout<<"\nEnter Expression\n";
		cin>>expression;
		try
		{
		int sum=delim(expression);
		cout<<"\nProvided Expression\n";
		cout<<expression<<"\n";
		cout<<"Calculated Result\n";
		cout<<"="<<sum<<"\n";
		cout<<"\nEvaluate another expression(Y/N)?\t";
		cin>>Y;
		if(Y=='Y'||Y=='y')
		prog();	
			
		}
		
		catch(const char*c)
		{
			cout<<c;
			getch();
		}
			
	}
};

int main()
{
	delimeter d;
	d.prog();
}
