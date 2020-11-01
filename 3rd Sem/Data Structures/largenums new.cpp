#include<iostream>
#include<iomanip>
#include "stack-array.cpp"
using namespace std;
class largenums{

string largesum(string num1,string num2)
{
	stack <int> S1(32),S2(32),S3(33);	
	for(int i=0;num1[i]!='\0';i++)
			S1.push(num1[i]-48);
	for(int i=0;num2[i]!='\0';i++)
			S2.push(num2[i]-48);	
	int carry=0,val=0,n1,n2;
	while(!S1.isEmpty()||!S2.isEmpty())
	{
		if(S1.isEmpty())
			n1=0;
		else
			n1=S1.pop();
			
		if(S2.isEmpty())
			n2=0;
		else
			n2=S2.pop();
		val=n1+n2+carry;
		S3.push(val%10);
		carry=val/10;
	}
	if(carry!=0)
		S3.push(carry);
	string sum;
	while(!S3.isEmpty())
		sum+=S3.pop()+48;
	return sum;
}

public:
void prog()
{
	char Y;
	int width;
	string num1,num2,sum;
	cout<<"\nEnter Number 1\n";
	cin>>num1;
	cout<<"Enter Number 2\n";
	cin>>num2;
	sum=largesum(num1,num2);
	if(num1.length()>num2.length())
		width=num1.length();
	else
		width=num2.length();
	cout<<"\nADDITION\n";
	cout<<"\t"<<setw(width)<<num1<<"\n";
	cout<<"+\t"<<setw(width)<<num2<<"\n";
	cout<<"________________\n";
	cout<<"=\t"<<setw(width)<<sum<<"\n";
	cout<<"\nPerform another addition(Y/N)?\t";
	cin>>Y;
	if(Y=='Y'||Y=='y')
	prog();	
}
	
};

	
int main()
{
	largenums l;
	l.prog();	
}
