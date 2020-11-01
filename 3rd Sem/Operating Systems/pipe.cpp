#include<sys/types.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1
using namespace std;
int main()
{
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];
	cout<<"Enter message: ";
	cin.get(write_msg,BUFFER_SIZE);
	int fd[2];
	pid_t pid;
	if(pipe(fd)==-1)
		cout<<"Pipe fail\n";
	pid=fork();
	if(pid<0)
		cout<<"Fork fail\n";
	if(pid>0)
	{
		close(fd[READ_END]);
		write(fd[WRITE_END],write_msg,strlen(write_msg)+1);
		close(fd[WRITE_END]);
	}	
	else
	{
		close(fd[WRITE_END]);
		read(fd[READ_END],read_msg,BUFFER_SIZE);
		cout<<"Read Message: "<<read_msg<<endl;
		close(fd[READ_END]);
	}
}
