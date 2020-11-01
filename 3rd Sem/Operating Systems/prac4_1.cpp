#include<iostream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main()
{
pid_t a=fork();
cout<<"ID for New process created: "<<a;
cout<<"\nID for Current Running Process: "<<getpid();
cout<<"\n_____		_____		_____		_____\n";
if(a<0)
cout<<"\nNo New Process\n";
else  
{cout<<"\nNext Process executing: "<<a;
cout<<"\nRunning process ID: "<<getpid();
}
cout<<"\n____________________________________________________\n";
return 0;
}
