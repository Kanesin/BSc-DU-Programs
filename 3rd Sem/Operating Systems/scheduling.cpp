#include<iostream>
#include<conio.h>
using namespace std;
class scheduling{
	public:
	int Burst[10],Process[10],sProcess;
	int Wt[10],Rt[10],Tat[10];
	float avg[3];
	void input()
	{
		cout<<"Enter No. of process";
		cin>>sProcess;
		for(int i=0;i<sProcess;i++)
		{
			cout<<"Enter Process ID\n";
			cin>>Process[i];
			cout<<"Enter Burst Time\n";
			cin>>Burst[i];
		}
	}
	
	void fcfs()
	{
		for(int i=0;i<sProcess;i++)
		{
			if(i==0)
				{
					Wt[i]=0;
					Rt[i]=0;	
					Tat[i]=Burst[i];
				}
			else
				{
					Wt[i]=Wt[i-1]+Burst[i-1];
					Rt[i]=Rt[i-1]+Burst[i-1];						
					Tat[i]=Tat[i-1]+Burst[i];
				}
		}		
	}
	
	void asc()
	{	int temp;
		for(int i=0;i<sProcess;i++)
		{
			for(int j=i;j<sProcess;j++)
			{
				if(Burst[i]>Burst[j])
				{
					temp=Burst[i];
					Burst[i]=Burst[j];
					Burst[j]=temp;
					temp=Process[i];
					Process[i]=Process[j];
					Process[j]=temp;	
				}
			}
		}
	}
	void sjf()
	{
		asc();
		fcfs();
	}
	void avgVal()
	{	int tWt=0,tTat=0,tRt=0;
		for(int i=0;i<sProcess;i++)
		{
			tWt+=Wt[i];
			tRt+=Rt[i];
			tTat+=Tat[i];
		}
		avg[0]=(float)tWt/sProcess;
		avg[1]=(float)tRt/sProcess;
		avg[2]=(float)tTat/sProcess;
		cout<<"Average Time:"<<"\t"<<avg[0]<<"\t\t"<<avg[1]<<"\t\t"<<avg[2]<<"\n";
		
	}
	void display()
	{	cout<<"\n";
		cout<<"Process ID"<<"\t"<<"Waiting Time"<<"\t"<<"Response Time"<<"\t"<<"Turn-around Time"<<"\n";
		for(int i=0;i<sProcess;i++)
		{
			cout<<Process[i]<<"\t\t"<<Wt[i]<<"\t\t"<<Rt[i]<<"\t\t"<<Tat[i]<<"\n";
		}
		avgVal();
	}
	
};

int main()
{
	scheduling s;
	s.input();
	s.fcfs();
	s.display();
	s.sjf();
	s.display();
	getch();
	
}
