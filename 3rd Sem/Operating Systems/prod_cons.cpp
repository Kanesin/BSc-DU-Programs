#include<iostream>
#include<conio.h>
#include<semaphore.h>
using namespace std;
class pro_con{
private:
	int mutex=1,full=0,empty=3,x=0;
	int wait(int s)
	{
		return --s;
	}
	int signal(int s)
	{
		return ++s;
	}
	void producer()
	{
		mutex=wait(mutex);
		full=signal(full);
		empty=wait(empty);
		x++;
		cout<<"P-"<<x<<"\n";
		mutex=signal(mutex);
	}
	
	void consumer()
	{
		mutex=wait(mutex);
		full=wait(full);
		empty=signal(empty);
		x--;
		cout<<"C-"<<x<<"\n";
		mutex=signal(mutex);
	}
	
	void menu()
	{
		cout<<"\n\n MENU\n\n";
		cout<<"1. Producer\n";
		cout<<"2. Consumer\n";
		cout<<"3. Exit\n";
		cout<<"Enter choice\n";
		int ch;
		cin>>ch;
		return ch;
		
	}
	void prog()
	{
		int ch;
		while(true)
		{
			ch=menu();
			switch(ch)
			{
				case 1: if((mutex==1)&&(empty!=0))
						producer();
						else
						cout<<"FULL\n";
				break; if((mutex==1)&&(empty!=0))
						producer();
						else
						cout<<"FULL\n";
			}
		}
	}
};
int main()
{
	
}
