#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
int main (int argc, char*argv[])
{
	int l=strlen (argv [1]);
	char s[l];
	strcpy (s,argv[1]);
	int i,j,c=0;
	for (i=0; i<l; i++)
	{
		c=0;
		for (int j=0; j<l; j++)
		{
			if (s[i]==s[j])
			c++;
		}
		cout<<"\n The frequency of"<< s[i]<<"="<<c;
	}
	getch();
	return 0;
}
