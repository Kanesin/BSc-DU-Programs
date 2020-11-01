#include<iostream>
#include<fstream>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
int main(int argc, char*argv[])
{
	struct stat s1;
	int fd;
	if(argc!=3)
	{
	cout<<"\n Error File not Found\n";
	exit(0);
	}
	fd=open(argv[1],0);
	if(fd<0)
	{
		cout<<"\n Error File not Found\n";
		exit(0);
	}
	int fd2=creat(argv[2],6666);
	if(fd<0)
	{
		cout<<"\n Error File not Found\n";
		exit(0);
	}
	close(fd);
	cout<<"\n Owner UID="<<s1.st_uid;
	cout<<"\n Group UID="<<s1.st_gid;
	cout<<"\n Access Permission="<<s1.st_mode;
	cout<<"\n Size="<<s1.st_size;
	cout<<"\n No. of Links="<<s1.st_nlink;
	cout<<"\n Last Access Time="<<&s1.st_atime;
	cout<<"\n Last Modified Time="<<&s1.st_mtime<<"\n";
return 0;
}
