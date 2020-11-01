#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class ipc{
	string ipadd;	
	int calc()
	{	
		string a,b,c,d;
		int counter=0;
		if(!ipadd.empty())
		{			
			for(int i=counter;ipadd[i]!='.';i++)
				a+=ipadd[counter++];
			counter++;
			for(int i=counter;ipadd[i]!='.';i++)
				b+=ipadd[counter++];
			counter++;
			for(int i=counter;ipadd[i]!='.';i++)
				c+=ipadd[counter++];
			counter++;
			for(int i=counter;ipadd[i]!='\0';i++)
				d+=ipadd[counter++];
			counter++;	
						
			if(checkNULL(a)||checkNULL(b)||checkNULL(c)||checkNULL(d))
				return -1;
			if(checkLead0(a)||checkLead0(b)||checkLead0(c)||checkLead0(d))
				return -1;
			if(checkChar(a)||checkChar(b)||checkChar(c)||checkChar(d))
				return -1;
			if(a.length()<=3&&b.length()<=3&&c.length()<=3&&d.length()<=3)
			{
				int valA=stringToInt(a);
				int valB=stringToInt(b);
				int valC=stringToInt(c);
				int valD=stringToInt(d);
				if(checkRange(valA)&&checkRange(valB)&&checkRange(valC)&&checkRange(valD))
					return valA;
				else
					return -1;
			}
			else
				return -1;
		}
		else
		{
			cout<<"No IP address Provided";
			return -2;
		}		
	}
	
	bool checkNULL(string x)
	{
		return ( x.length()==0);
	}
	
	bool checkLead0(string x)
	{
		return (x.length()>1&&x[0]=='0');
	}
	
	bool checkRange(int x)
	{
		return (x>=0&&x<=255);
	}
	
	bool checkChar(string x)
	{
		int f=0;
		for(int i=0;i<x.length();i++)
		{
			if(x[i]<'0'||x[i]>'9')
				{
					f=1;
					break;	
				}
		}
		return f;
	}
	
	int stringToInt(string s)
	{
			int A[3],sA=0;
			int val=0;
			for(int i=0;s[i]!='\0';i++)
				A[sA++]=s[i]-48;
			int i=0;
			while(i<sA)
				val=val*10+A[i++];
			return val;
	}
	
	public:	
	void input()
	{
		cout<<"Enter the IP address\n";
		getline(cin,ipadd);
	}
	
	void Findtype()
	{
		string classType="";
		int val=calc();
		if(val>=0&&val<=127)
			classType="CLASS A";
		else if(val>=128&&val<=191)
			classType="CLASS B";
		else if(val>=192&&val<=223)
			classType="CLASS C";
		else if(val>=224&&val<=239)
			classType="CLASS D";
		else if(val>=240&&val<=255)
			classType="CLASS E";
		else if(val==-1)
			cout<<"Not a valid IPV4 address\n";			
		cout<<"\n"<<classType;
	}	
};

int main()
{
	ipc v;
	v.input();
	v.Findtype();
	getch();
}
