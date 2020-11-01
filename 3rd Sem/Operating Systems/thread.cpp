#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<pthread.h>
using namespace std;
int sum;
void *runner(void*);
int main(int argc,char*argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	if(argc!=2)
	{
		cout<<"Incorrect no. of parameters passed\n";
		exit(1);
	}
	if(atoi(argv[1])<0)
	{
		cout<<"Incorrect no. of parameter value passed\n";
		exit(1);
	}
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	cout<<"SUM= "<<sum;
}

void*runner(void* param)
{
	pid_t x=syscall(__NR_gettid);
	cout<<"T_ID "<<x<<" ";
	int i, upper=atoi((char*)param);
	sum=0;
	for(i=1;i<=upper;i++)
		sum+=i;
		pthread_exit(0);
}

