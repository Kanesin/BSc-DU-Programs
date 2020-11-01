#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
struct student
{
	int r,c,y,t;
	char name[30];
};
int main()
{
	student S[10];
	int i;
	cout<<"\n Enter details of 10 students";
	for(i=0; i<10; i++)
	{
	cout<<"\n Enter name";
	cin>>S[i].name;
	cout<<"\n Enter class";
	cin>>S[i].c;
	cout<<"\n Enter roll no.";
	cin>>S[i].r;
	cout<<"\n Enter year";
	cin>>S[i].y;
	cout<<"\n Enter marks";
	cin>>S[i].t;
    }
    ofstream f1;
    f1.open("new.txt");
    for (i=0; i<100; i++)
    {
    	f1<<S[i].name;
    	f1<<"\t \t";
    	f1<<S[i].c;
    	f1<<"\t \t";
    	f1<<S[i].r;
    	f1<<"\t \t";
    	f1<<S[i].y;
    	f1<<"\t \t";
    	f1<<S[i].t;
    	f1<<"\n";
	}
	f1.close();
	getch();
    return 0;
}
