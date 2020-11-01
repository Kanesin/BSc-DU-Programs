#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main()
{
pid_t a=fork();
cout<<a;
if(a<0)
{
cout<<"\nThis Process";
}
else
{
cout<<"\n"<<getpid()<<"\n Process continues";
}
return 0;
}

