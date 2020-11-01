#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;
int main()
{
	pid_t pid;
	pid=fork();
	cout<<"p1"<<getpid()<<endl;
	cout<<"\np"<<pid<<endl;
	if(pid<0)
	cout<<"\nNo Process Entered";
	else if(pid==0)	
	{
		cout<<"\ncget"<<getpid()<<endl;
		cout<<"\ncpid"<<pid<<endl;
		execlp("/bin/ls","pwd",NULL);
		cout<<"Child Process";
	}
	else
	{
		cout<<"\npget"<<getpid()<<endl;
		cout<<"\nppid"<<pid<<endl;
		cout<<"Parent Process";
	}
return 0;


}
