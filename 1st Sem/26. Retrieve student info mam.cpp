#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
struct student
{
	char name[32];
	int rollno, year,Class, totmarks; 
};
int main()
{
	ifstream fin("/home/dell/Desktop/c++/file",ios::out|ios::binary);
	student s;
	int i=0;
	while(fin.read((char*)&s,sizeof(s)))
	{
		cout<<"Student "<<i+1<<": "<<s.rollno<<"\t"<<s.name<<"\t"<<s.totmarks<<endl;
		i++;
	}
	fin.close();
	getch();
	return 0;
}

