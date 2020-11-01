#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/syscall.h>
#define num_th 10
using namespace std;
int sum;int done,a;
void *runner(void*);
int main(int argc,char*argv[])
{

	pthread_t tid[num_th];
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
	done=1;	
	pthread_attr_init(&attr);
	a=atoi(argv[1]);
	int b;
	char*c;
	for(int i=0;i<num_th;i++)
	{	
		b=(done+(a/num_th));
		c=(char*)&b;
		
		pthread_create(&tid[i],&attr,runner,c);
		pthread_join(tid[i],NULL);
		cout<<"SUM= "<<sum<<"  "<<endl;
	}
}

void*runner(void* param)
{
	pid_t x=syscall(__NR_gettid);
	cout<<"T_ID "<<x<<" ";
	int i, upper=*((int*)param);
	sum=0;
	for(i=done;i<upper;i++)
		sum+=i;
	done+=a/num_th;
	pthread_exit(0);
}


