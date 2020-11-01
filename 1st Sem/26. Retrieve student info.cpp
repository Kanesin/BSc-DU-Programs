#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
int main()
{
	ifstream f1;
	char ch;
	f1.open("new.txt");
	if (!f1)
	cout<<"\n Not found";
	else
	{
		while (f1.get(ch))
		{
			cout<<ch;
		}
	}
	getch();
	return 0;
 } 
