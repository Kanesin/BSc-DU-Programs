#include <iostream>
#include <conio.h>
using namespace std;
class person
{
	public:
		int x;
		virtual void demo()=0;
};
class teacher: public person
{
	public: void demo()
	{cout<<"\n Teacher enters a no.";
	cin>>x;
	}
};
class student: public person
{
	public: void demo()
	{cout<<"\n Suudent enters a no.";
	cin>>x;
	}
};
int main()
{
	person *p= new teacher;
	p->demo();
	cout<<"\n Number entered by the teacher"<<p->x;
	person *b= new student;
	b->demo();
	cout<<"\n Number entered by the teacher"<<b->x;
	cout<<"\n Deleting objects!";
	delete p;
	delete b;
	getch();
	return 0;
}
