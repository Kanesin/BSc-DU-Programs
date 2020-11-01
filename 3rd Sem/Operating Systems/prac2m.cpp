#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<time.h>
using namespace std;
int main(int argc,char *argv[])
{
struct stat s1;
int fd;
if(argc!=2)
{
	cout<<"Wrong Number of arguments";
	exit(0);
} 
fd=open(argv[1],O_RDONLY);

fstat(fd,&s1);

cout<<"Owner uid= "<<s1.st_uid<<"\n";
cout<<"Group id= "<<s1.st_gid<<"\n";
cout<<"Access Permission "<<s1.st_mode<<"\n";
cout<<std::oct<<"Access Permission "<<s1.st_mode<<"\n";

cout<<"Size= "<<s1.st_size<<"\n";
cout<<"No. of Links="<<s1.st_nlink<<"\n";
cout<<"Last Access Time= "<<(&s1.st_atime)<<"\n";
char date[36];
strftime(date,36,"%d.%m.%Y %H:%M:%S", localtime(&s1.st_atime));
cout<<date<<endl;
cout<<"Last Modified time="<<(&s1.st_mtime)<<"\n";
return 0;
}
