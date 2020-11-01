#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class fun
{
	public:
		char s[20];
		void input()
		{
			cout<<"\n Enter the string:";
			gets(s);
		}
		void address()
		{
			char*p;
			p=s;
			int i=0;
			while (*p!='\0')
			{
			cout<<"\n Address of"<<*p<<"="<<(int*)&s[i]<<endl;
			p++;i++;
		    }
		}
		void concat()
		{
			char t[20];int i=0;
			int l=strlen(s);
			cout<<"\n Enter the second string:";
			cin>>t;
			while (t[i]!='\0')
			{
				s[l++]=t[i];
				i++;
			}
			cout<<endl<<s;
		}
		void concat2()
		{
			char t[20];
			cout<<"\n Enter the second string:";
			cin>>t;
			strcat(s,t);
			cout<<s;
		}
		void comp()
		{
		    char t[20];
		    cout<<"\n Enter the second string:";
		    cin>>t;
			int a=strcmp(s,t);
			if (a==0)
			cout<<"\n Strings are equal";
			else if (a>=1)
			cout<<"\n String 1 is larger";
			else
		    cout<<"\n String 2 is larger";
		}
		void calclength()
		{
			char *p;
			p=s;
			int i=0;
			while (*p-'\0')
			{
				i++;
				p++;
			}
			cout<<"\n The length of the string is:"<<i;
		}
		void lowtoup()
		{
			for (int i=0; s[i]!='\0'; i++)
			{
				if (islower(s[i]))
				s[i]=toupper(s[i]);
			}
			cout<<endl<<s;
		}
		void uptolow()
		{
			for (int i=0; s[i]!='\0'; i++)
			{
				if (isupper(s[i]))
				s[i]=tolower(s[i]);
			}
			cout<<endl<<s;
		}
		void calcvow()
		{
			int c=0;
	    	for (int i=0; s[i]!='\0'; i++)
	    	{
	    		switch (s[i])
	    		{
	    			case 'a':
	    			case 'e':
	    			case 'i':
	    			case 'o':
	    			case 'u':
	    			case 'A':
	    			case 'E':
	    			case 'I':
	    			case 'O':
	    			case 'U': c++;
	    			break;
				}
			}
			cout<<endl<<c;
		}
		void rev()
		{
			int l=strlen(s);
			char tmp;
			for (int i=0,j=l-1; i<l/2; i++,j--)
			{
				tmp=s[i];
				s[i]=s[j];
				s[j]=tmp;
			}
			cout<<s;
		}
};
int main()
{
	fun D;
	int c;
	char ch;
	D.input();
	do
	{
		cout<<"\n MENU";
		cout<<"\n 1.Show address of each character in the string";
		cout<<"\n 2.Concatenate two strings without using the strcat function";
		cout<<"\n 3.Concatenate two strings using the strcat function";
		cout<<"\n 4.Compare two strings";
		cout<<"\n 5.Calculate the lenth of string using pointers";
		cout<<"\n 6.Convert lowercase letters to uppercase letters";
		cout<<"\n 7. Convert uppercase letters to lowercase letters";
		cout<<"\n 8.Calculate number of vowels";
		cout<<"\n 9.Reverse the string";
		cout<<"\n 10. Exit";
		cout<<"\n Enter your choice";
		cin>>c;
		if (c==1)
		D.address();
		else if (c==2)
		D.concat();
		else if (c==3)
		D.concat2();
		else if (c==4)
		D.comp();
		else if (c==5)
		D.calclength();
		else if (c==6)
		D.lowtoup();
		else if (c==7)
		D.uptolow();
		else if (c==8)
		D.calcvow();
		else if (c==9)
		D.rev();
		else
		exit (0);
		cout<<"\n Want to continue (y for yes)";
		cin>>ch;
	}
	while (ch=='y'||ch=='Y');
	getch();
	return 0;
}

