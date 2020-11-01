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
cout<<"p"<<pid<<endl;
if(pid<0)
cout<<"\nNo process entered";
else if(pid==0)
{
	cout<<"\ncget"<<getpid();
	cout<<"\ncpid"<<pid;
	execlp("/bin/ls","pwd",NULL);
	cout<<"\nChild Process";
}
else
{
	wait(NULL);
	cout<<"pget"<<getpid()<<endl;
	cout<<"\nppid"<<pid<<endl;
	cout<<"\nParent Process";
}
return 0;
}
