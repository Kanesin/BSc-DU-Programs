#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main()
{
pid_t pid;
pid=fork();
cout<<"M=======\n";
cout<<"Main: Created process pid: "<<pid<<endl;
cout<<"Main: Running process pid: getpid()= "<<getpid()<<"\n";
cout<<"M=======\n";
if(pid<0)
	cout<<"\nIf no child created- this is the process \n";
else if(pid==0)
{
	cout<<"\nChild Process: \n";
	cout<<"C======\n";
	cout<<"C: Which process executing: pid= "<<pid<<endl;
	cout<<"C: Which process running: getpid()= "<<getpid()<<endl<<endl;
}
else
{
	cout<<"\nParent Process: \n";
	cout<<"P======\n";
	cout<<"P: Which process executing: pid= "<<pid<<endl;
	cout<<"P: Which process running: getpid()= "<<getpid()<<endl<<endl;
}
return 0;
}
