#include<sys/types.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
using namespace std;
#define BUFFER_SIZE 26
#define READ_END 0
#define WRITE_END 1
int main(void)
{
	char write_msg[BUFFER_SIZE];
	cout<<"\nENTER THE MESSAGE(length should be less than 26):";
	cin>>write_msg;
	char read_msg[BUFFER_SIZE];
	int fd[2];
	pid_t pid;
	if(pipe(fd)==-1)
	{
	cout<<"\nPIPE FAILED";  
	return 1; 
    }
    pid=fork();
    if(pid<0)
    {
    	cout<<"\nFORK FAILED";
    	return 1;
    }
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
    	cout<<read_msg;
    	close(fd[READ_END]);
    }
    return 0;
} 
