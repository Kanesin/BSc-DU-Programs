#include<iostream>
#include<stdlib.h>
using namespace std;
class Process
{
	int a;
	int total_wt;
	int total_ta;
	int avg_wt;
	int avg_ta;
	struct prcP
	{
	int wt;
	int bt;
	int ta;
	int pid;
	int pr;
	}*ob;
	public:
		Process(int b)
		{
			ob= new prcP[b];
			a=b;
		}
		void input()
		{	
			for(int i=1;i<=a;i++)
			{
				cout<<"\nEnter Process ID: ";
				cin>>ob[i].pid;
				cout<<"\nEnter Burst Time: ";
				cin>>ob[i].bt;
				cout<<"\nEnter Priority: ";
				cin>>ob[i].pr;
			}
		}
		void fcfs()
		{	
			ob[1].wt=0;
			for(int i=1;i<=a;i++)
			{
				ob[i+1].wt=ob[i].bt+ob[i].wt;	
				total_wt+=ob[i].wt;			
			}
			avg_wt=(float)total_wt/a;			
		
		
			for(int i=1;i<=a;i++)
			{
				ob[i].ta=ob[i-1].ta + ob[i].bt;	
				total_ta+=ob[i].ta;			
			}
			avg_ta=(float)total_ta/a;
			
		}
		void sort()
		{
			for (int i=1; i<a; i++)
			{
				for (int j=i+1; j<=a; j++)
				{
					if (ob[i].bt>ob[j].bt);
					{
						int t=ob[i].bt;
						ob[i].bt=ob[j].bt;
						ob[j].bt=t;
						t=ob[i].pid;
						ob[i].pid=ob[j].pid;
						ob[j].pid=t;
					}
				}
			}	
		}
		void sortpri()
		{
			for(int i=0;i<a-1;i++)
			{
				for(int j=0;j<a-1-i;j++)
				{
					if(ob[j].pr>ob[j+1].pr)
					{
						int t=ob[j].pr;
						ob[j].pr=ob[j+1].pr;
						ob[j+1].pr=t;
						t=ob[j].pid;
						ob[j].pid=ob[j+1].pid;
						ob[j+1].pid=t;
					}
				}
			}
		}
		void sjf()
		{
			sort();
			fcfs();
		}
		void priority()
		{
			sortpri();
			fcfs();
		}
		void display()
		{cout<<"Processes"<<"\t"<<"Burst Time"<<"\t"<<"Waiting Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Priority";	
			for(int i=1;i<=a;i++)
			{
				
							
				cout<<"\nP"<<ob[i].pid<<"\t\t"<<ob[i].bt<<"\t\t"<<ob[i].wt<<"\t\t"<<ob[i].ta<<"\t\t"<<ob[i].pr<<"\n";
						
							
			}
			cout<<"\nAverage Waiting Time: "<<avg_wt;
			cout<<"\nAverage TurnAround Time: "<<avg_ta<<"\n";
		}
};
int main()
{	
	int a;
	cout<<"\n Enter the number of Processes:";
	cin>>a;
	Process o(a);
	o.input();
	int choice;
	char ch;
			do
			{
				cout<<"MENU: \n1.FCFS \n2.SJF \n3.Priority \n4.Exit\nEnter Choice: ";
				cin>>choice;
				switch(choice)
				{
					case 1:o.fcfs();
						   o.display();
						   break;
					case 2:o.sjf();
						   o.display();
						   break;
					case 3:o.priority();
						   o.display();
						   break;
					case 4:exit(0);
					default:cout<<"\n Invalid Input!";
				}
				cout<<"\nDo you want to continue(Y/N)?: ";
				cin>>ch;
			}
			while(ch=='Y'||ch=='y');
	return 0;
}
