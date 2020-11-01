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
	ofstream fout ("/home/dell/Desktop/c++/file",ios::out|ios::binary);
	for (int i=0; i<10; i++)
	{
		student s;
		cout<<"Student "<<i+1<<":-\n Name: ";
		cin>>s.name;
		cout<<"Roll number: ";
		cin>>s.rollno;
		cout<<"Class: ";
		cin>>s.Class;
		cout<<"Year: ";
		cin>>s.year;
		cout<<"Total Marks: ";
		cin>>s.totmarks;
		cout<<endl;
		fout.write((char*)&s, sizeof(s));
	 }
	 fout.close();
	 cout<<"\n\n Stored all records in file!\n";
	 getch();
	 return 0;
}
