#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
int main()
{
	ifstream f1;
	ofstream f2;
	f1.open("/users/digprov/Documents/c++/new.txt");
	char ch;
	f2.open("/users/digprov/Documents/c++/oop.txt");
	while(f1.get(ch))
	{
	if (ch!=' ')
	f2.put(ch); 
}
f1.close();
f2.close();
getch();
return 0;
}
