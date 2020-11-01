#include<iostream>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		cout<<endl<<"no process entered";
	}
	else if(pid==0)
	{
		execlp("ps","ps",NULL);
		cout<<"Child Process";
	}
	else
	{
		cout<<"Parent process";
	}
	return 0;
}
