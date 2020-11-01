#include<iostream>
#include<conio.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int main(int argc,char* argv[])
{
	char ch1;
	if(argc>=2)
	{
		int tab[26];
		for(int k=0;k<26;k++)
		{
			tab[k]=0;
		}
		int i=1;
		while(argc>i)
		{
			for(int j=0;j<strlen(argv[i]);j++)
			{
				char ch=tolower(argv[i][j]);
				tab[ch-'a']++;
			}
			i++;
		}
		for(int k=0;k<26;k++)
		{
			ch1='a'+k;
			cout<<ch1.<<" "<<tab[k]<<"\n";
		}
	}
	getch();
	return 0;
	
}
