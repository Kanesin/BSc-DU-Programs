#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<string.h>
using namespace std;
class power{
	
	string word;
	void input()
	{
		
		cout<<"Enter String\n";
		getline(cin,word);
		if(word.length()==0)
			getline(cin,word);
		
		reverse(0,word.length()-1);
		cout<<"Reverse is "<<word;						
	}
	int reverse(int i,int j)
	{
		if(i>=j)
		{
		}
		else
		{
			char temp=word[i];
			word[i]=word[j];
			word[j]=temp;
			reverse(++i,--j);
		}
	}
	
	public:
	void prog()
	{
		while(true)
		{	char Y;
			input();
			cout<<"\ndo you want to continue(Y/N)?";
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
