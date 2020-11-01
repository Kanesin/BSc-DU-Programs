#include<stdio.h>
#include<sys/vfs.h>
#include<sys/sysinfo.h>
#include<sys/utsname.h>
int main()
{
	int r,a,q,p,b;
	struct sysinfo s1; //returns system information,provides a simple way of getting overall system statistics
	struct utsname s2; //get name and information about current kernel
	struct statfs s3; //get filesystem statistics
	r=sysinfo(&s1); 
	q=uname(&s2); //returns system information in the structure pointed to by
			//buf.   The utsname struct is defined in <sys/utsname.h>
	p=statfs("./",&s3);
	a=(1024*1024);
	b=(a*1024);
	if(r==0&&q==0&&p==0) //On Success, returns zero
	{
		printf("\nSystem Name:%s ",s2.sysname);
		printf("\nVersion:%s ",s2.version);
		printf("\nRelease:%s ",s2.release);
		printf("\nMachine:%s ",s2.machine);
		printf("\nTotal RAM:%ldMB ",(s1.totalram/a)); /* Total usable main memory size*/
		printf("\nFree RAM:%ldMB ",(s1.freeram/a)); /* Available memory size*/
		printf("\nUsed RAM:%ldMB ",((s1.totalram-s1.freeram)/a));
		printf("\nTotal Size of Partition:%ldGB ",(s3.f_bsize*s3.f_blocks)/b); /* Optimaltransfer block size
		 Total data blocks in filesystem */
	}
	else
	{
		printf("\nERROR");
	}
}
