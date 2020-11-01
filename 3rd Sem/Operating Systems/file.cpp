#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<iostream>

using namespace std;

int main(int argc,char *argv[])
{
struct stat s1;
int fd;
if(argc!=2)
{
cout<<"Wrong no of arguments";
exit(0);
}
fd=open(argv[1),O_RDONLY);
fstat(fd,&s1);
close(fd);
cout<<"\nOwner id: "<<s1.st_uid;
cout<<"\nGroup id: "<<s1.st_gid;
cout<<"\nAccess Permission= "<<s1.st_mode;
cout<<"\nSize: "<<s1.st_size;
cout<<"\nNo of links: "<<s1.st_nlink<<"\n";
cout<<"\nlast Accesss Time: "<<(&s1.st_atime)<<"\n";
cout<<"\nlast Modified Time: "<<(&s1.st_mtime)<<"\n";
return 0;
}

