#include<iostream>
#include<math.h>
#include "stack-array.cpp"
using namespace std;
class expressions
{	
	float postfix(string postfixexp)
	{
		int n1,n2;
		
		stack <float> ob(30);
		char ch;
		float sum;
		try
		{
		for(int i=0;postfixexp[i]!='\0';i++)
		{
			ch=postfixexp[i];
			switch(ch)
			{
				case '+': 	n2=ob.pop();
							n1=ob.pop();
							ob.push(n1+n2);
				break;
				case '-': 	n2=ob.pop();
							n1=ob.pop();
							ob.push(n1-n2);
				break;
				case '*': 	n2=ob.pop();
							n1=ob.pop();
							ob.push(n1*n2);
				break;
				case '/': 	n2=ob.pop();
							n1=ob.pop();
							ob.push((float)n1/(float)n2);
				break;
				case '^': 	n2=ob.pop();
							n1=ob.pop();
							ob.push(pow(n1,n2));
				break;
				default:  ob.push(ch-48);		
			}
		}
		sum=ob.pop();
		if(!ob.isEmpty())
			throw "error";		
		else
			return sum;
			
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
		float sum=postfix(expression);
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
		}
			
	}
};
int main()
{
	expressions e;
	e.prog();
	getch();
}
