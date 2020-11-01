#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class palindrome
{
	public:
		string s;
		void palin()
		{
			int i, l=0, j, f=0;
			cout<<"\n Enter the string:";
			cin>>s;
			for (i=0; s[i]!='\0'; i++)
			{
				l++;
			}
			for (i=0, j=l-1; s[i]!='\0'; i++, j--)
			{
				if (s[i]!=s[j])
				{
					f=1;
					break;
				}
			}
			if (f!=1)
			cout<<"\n Palindrome";
			else
			cout<<"\n Not Palindrome";
		}
};
int main()
{
palindrome p;
p.palin();
getch();
return 0;	
}
