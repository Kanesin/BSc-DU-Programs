#include<iostream>

#include<sys/vfs.h>
#include<sys/sysinfo.h>
#include<sys/utsname.h>
using namespace std;
int main()
{
int s1,s2,s3;
struct sysinfo a;
struct statfs b;
struct utsname c;
s1=sysinfo(&a);
s2=statfs("./",&b);
s3=uname(&c);
if(s1==0&&s3==0)
{
int mb=1024*1024;
int gb=mb*1024;
cout<<"\n Information     | \tDetails";
cout<<"\n_________________|__________________________";
cout<<"\n Version         : \t"<<c.sysname;
cout<<"\n Release         : \t"<<c.release;
cout<<"\n Machine         : \t"<<c.machine;
cout<<"\n Total Ram       : \t"<<(a.totalram)/mb<<" MB";
cout<<"\n Free Ram        : \t"<<(a.freeram)/mb<<" MB";
cout<<"\n Used Ram        : \t"<<(a.totalram)/mb-(a.freeram)/mb<<" MB";
cout<<"\n Disk Partition  : \t"<<(b.f_bsize*b.f_blocks)/gb<<" GB\n";
}
return 0;
}
