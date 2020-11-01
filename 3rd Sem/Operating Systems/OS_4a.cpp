#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main()
{

	pid_t pid;
	pid=fork();
	cout<<"\nMain: Created process pid: "<<pid;
	cout<<"\nMain: Running process pid: "<<getpid();
	if(pid<0)
	cout<<"\nNo chld created. This is a process";
	else
	{
		cout<<"\nWhich process executing: pid="<<pid; 
		cout<<"\nRunning process pid: getpid()= "<<getpid()<<"\n";
	}
	return 0;

}
