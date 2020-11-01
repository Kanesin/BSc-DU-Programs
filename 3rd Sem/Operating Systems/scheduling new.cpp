#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstdlib>
using namespace std;

	struct processes
	{	
		int PID,Burst,Arrival,Priority,WT,TaT,RunTime;
	};

class Scheduling
{
	public:
	struct processes *Process;
	int nProcess;
	
	
	void operator=(Scheduling ob)
	{
		nProcess=ob.nProcess;
		Process=new struct processes [nProcess];
		for(int i=0;i<nProcess;i++)
			Process[i]=ob.Process[i];
	}
	
	/*======================
	INPUT 
	=========================*/
	void input()
	{
		cout<<"Enter No. of process\n";
		cin>>nProcess;
		Process=new struct processes [nProcess];
		for(int i=0;i<nProcess;i++)
		{
			cout<<"Process "<<i+1<<"\n";
			Process[i].PID=i+1;
			cout<<"Enter Burst Time\n";
			cin>>Process[i].Burst;
			Process[i].Arrival=0;
			Process[i].Priority=0;
			Process[i].WT=0;
			Process[i].TaT=0;
			Process[i].RunTime=0;			
		}
	}
	
	/*======================
	FIRST COME FIRST SERVE
	=========================*/
	void FCFS()
	{
		for(int i=0;i<nProcess;i++)
		{
			if(i==0)
				{
					Process[i].WT=0;	
					Process[i].TaT=Process[i].Burst;
				}
			else
				{
					Process[i].WT=Process[i-1].WT+Process[i-1].Burst;
					Process[i].TaT=Process[i-1].TaT+Process[i].Burst;
				}
		}		
	}
	
	/*======================
	Burst Sort for SJF,SRTF
	=========================*/
	void BurstSort(int size)
	{
		processes temp;
		for(int i=0;i<size;i++)
		{
			for(int j=i;j<size;j++)
			{
				if(Process[i].Burst>Process[j].Burst)
				{
					temp=Process[i];
					Process[i]=Process[j];
					Process[j]=temp;	
				}
			}
		}
	}
	/*======================
	Shortest Job First
	=========================*/
	void SJF()
	{
		BurstSort(nProcess);
		FCFS();
	}
	
	/*======================
	Shortest Remaining Time first
	=========================*/	
	void SRTF()
	{
		for(int i=0;i<nProcess;i++)
		{
			cout<<"Enter Arrival Time for Process ID "<<Process[i].PID<<" ";
				cin>>Process[i].Arrival;
		}
		arrivalSort();
		int counter=0, arrived=1, tq=0, totalRun=0, firstArive=Process[0].Arrival;
		while(counter!=nProcess)
		{
			if(arrived<nProcess)
				tq=Process[arrived].Arrival-Process[arrived-1].Arrival;			
			else
			{
				for(int x=0;x<nProcess;x++)
				{
					if(Process[x].Burst!=0)
					{
						tq=Process[x].Burst;
						break;
					}
				}
			}	
			BurstSort(arrived);

			for(int i=0;i<arrived;i++)
			{	
				if(Process[i].Burst<=tq&&Process[i].Burst!=0)
				{
					for(int j=0;j<arrived;j++)
					{
						if(i!=j&&Process[j].Burst!=0)
							Process[j].WT+=Process[i].Burst;						
					}	
					Process[i].RunTime+=Process[i].Burst;
					totalRun+=Process[i].Burst;
					tq-=Process[i].Burst;
					Process[i].Burst=0;
					counter++;
					
				}
				else if(Process[i].Burst>tq)
				{
					for(int j=0;j<arrived;j++)
					{
						if(i!=j&&Process[j].Burst!=0)
							Process[j].WT+=tq;	
					}
					Process[i].RunTime+=tq;
					Process[i].Burst-=tq;
					totalRun+=tq;
				}
				if(totalRun==(Process[arrived].Arrival-firstArive))
					break;		
			}
			if(arrived<nProcess)
				arrived++;		
		}
		for(int i=0;i<nProcess;i++)
			Process[i].TaT=Process[i].WT+Process[i].RunTime;		
	}
	
	/*======================
	Priority Sort for Non Premptive & Preemptive Priority
	=========================*/
	void prioritySort(int size)
	{
		processes temp;
		for(int i=0;i<size;i++)
		{
			for(int j=i;j<size;j++)
			{
				if(Process[i].Priority>Process[j].Priority)
				{
					temp=Process[i];
					Process[i]=Process[j];
					Process[j]=temp;	
				}
			}
		}
	}
	
	/*======================
	Non Preemptive Priority
	=========================*/
	void NPP()
	{
		for(int i=0;i<nProcess;i++)
		{
			cout<<"Enter Priority Time for Process ID "<<Process[i].PID;
				cin>>Process[i].Priority;
		}
		prioritySort(nProcess);
		FCFS();	
	}
	
	/*======================
	Arrival Sort for Premptive Priority And SRTF
	=========================*/
	void arrivalSort()
	{
		processes temp;
		for(int i=0;i<nProcess;i++)
		{
			for(int j=i;j<nProcess;j++)
			{
				if(Process[i].Arrival>Process[j].Arrival)
				{
					temp=Process[i];
					Process[i]=Process[j];
					Process[j]=temp;	
				}
			}
		}
	}
	
	/*======================
	Preemptive Priority
	=========================*/	
	void PP()
	{
		for(int i=0;i<nProcess;i++)
		{
			cout<<"Enter Arrival Time for Process ID "<<Process[i].PID<<" ";
				cin>>Process[i].Arrival;
			cout<<"Enter Priority for Process ID "<<Process[i].PID<<" ";
				cin>>Process[i].Priority;
		}
		arrivalSort();
		int counter=0, arrived=1, tq=0, totalRun=0, firstArive=Process[0].Arrival;
		while(counter!=nProcess)
		{
			
			if(arrived<nProcess)
				{
					tq=Process[arrived].Arrival-Process[arrived-1].Arrival;	
					prioritySort(arrived);			
				}
			else
			{
				prioritySort(arrived);
				for(int x=0;x<nProcess;x++)
				{
					if(Process[x].Burst!=0)
					{
						tq=Process[x].Burst;
						break;
					}
				}			
			}
			for(int i=0;i<arrived;i++)
			{	
				if(Process[i].Burst<=tq&&Process[i].Burst!=0)
				{
					for(int j=0;j<arrived;j++)
					{
						if(i!=j&&Process[j].Burst!=0)
							Process[j].WT+=Process[i].Burst;						
					}	
					Process[i].RunTime+=Process[i].Burst;
					totalRun+=Process[i].Burst;
					tq-=Process[i].Burst;
					Process[i].Burst=0;
					counter++;
					
				}
				else if(Process[i].Burst>tq)
				{
					for(int j=0;j<arrived;j++)
					{
						if(i!=j&&Process[j].Burst!=0)
							Process[j].WT+=tq;	
					}
					Process[i].RunTime+=tq;
					Process[i].Burst-=tq;
					totalRun+=tq;
				}
				if(totalRun==(Process[arrived].Arrival-firstArive))
					break;		
			}
			if(arrived<nProcess)
				arrived++;			
		}
		for(int i=0;i<nProcess;i++)
			Process[i].TaT=Process[i].WT+Process[i].RunTime;		
	}
	
	/*======================
	Round Robin
	=========================*/
	void RR()
	{
		int TQ;
		cout<<"Enter Time quantum\n";
		cin>>TQ;
		int counter=0,rt;
		while(counter!=nProcess)
		{	
			for(int i=0;i<nProcess;i++)
			{
				if(Process[i].Burst<=TQ&&Process[i].Burst!=0)
				{
					for(int j=0;j<nProcess;j++)
					{
						if(i!=j&&Process[j].Burst!=0)
							Process[j].WT+=Process[i].Burst;			
					}
					Process[i].RunTime+=Process[i].Burst;
					Process[i].Burst=0;
					counter++;
				}
				else if(Process[i].Burst>TQ)
				{
					for(int j=0;j<nProcess;j++)
					{
						if(i!=j&&Process[j].Burst!=0)
							Process[j].WT+=TQ;	
					}
					Process[i].RunTime+=TQ;
					Process[i].Burst-=TQ;
				}	
			}
									
		}
		for(int i=0;i<nProcess;i++)
				Process[i].TaT=Process[i].WT+Process[i].RunTime;		
	}
	
	
	/*======================
	Content Display
	=========================*/	
	void displayData()
	{	
		if(Process==NULL)
			cout<<"No Data Provided\n";
		else
		{
			cout<<"\n"<<"PID"<<setw(16)<<"BURST TIME"<<setw(16)<<"Arrival Time"<<setw(16)<<"Priority\n";
			for(int i=0;i<nProcess;i++)
				cout<<Process[i].PID<<setw(16)<<Process[i].Burst<<setw(16)<<Process[i].Arrival<<setw(16)<<Process[i].Priority<<"\n";	
		}			
	}	
	
	/*======================
	Process ID order Sort
	=========================*/
	void ProcessSort()
	{
		processes temp;
		for(int i=0;i<nProcess;i++)
		{
			for(int j=i;j<nProcess;j++)
			{
				if(Process[i].PID>Process[j].PID)
				{
					temp=Process[i];
					Process[i]=Process[j];
					Process[j]=temp;	
				}
			}
		}
	}	
	
	/*======================
	OUTPUT
	=========================*/
	void FinalOutput()
	{	
		ProcessSort();
		float aWt=0,aTat=0;
		int tWt=0,tTat=0;
		cout<<"\n";
		cout<<"Process ID"<<"\t"<<"Waiting Time"<<"\t"<<"Turn-around Time"<<"\n";
		for(int i=0;i<nProcess;i++)
			{
				cout<<Process[i].PID<<"\t\t"<<Process[i].WT<<"\t\t"<<Process[i].TaT<<"\n";
				tWt+=Process[i].WT;
				tTat+=Process[i].TaT;
			}
		aWt=(float)tWt/nProcess;
		aTat=(float)tTat/nProcess;
		cout<<"Average Time:"<<"\t"<<aWt<<"\t\t"<<aTat<<"\n";		
	}
	
	int menu()
	{
		cout<<"\nMENU\n";
		cout<<"1. Enter/Re-Enter Process Information\n";
		cout<<"2. View Process Information\n";
		cout<<"3. First Come First Serve\n";
		cout<<"4. Shortest Job First\n";
		cout<<"5. Shortest Remaining Time First\n";
		cout<<"6. NON Premptive Priority\n";
		cout<<"7. Premptive Priority\n";
		cout<<"8. Round Robin\n";
		cout<<"9. EXIT\n";
		cout<<"Enter Choice\n";
		int ch;
		cin>>ch;
		return ch;
	}

	void prog()
	{
		Scheduling  duplicate;
		int ch=0;
		while(true)
		{
			ch=menu();
			if(ch!=1&&Process==NULL)
			{
				cout<<"No Data Provided, Enter Data to Proceed\n";
				ch=1;
			}
			if(Process!=NULL)
				*this=duplicate;
			switch(ch)
			{
				case 1: input();
						duplicate=*this;
				break;
				case 2: displayData();
				break;
				case 3: FCFS();					
				break;
				case 4: SJF();
				break;
				case 5: SRTF();
				break;
				case 6: NPP();
				break;
				case 7: PP();
				break;
				case 8: RR();
				break;
				case 9: exit(0);
				break;
				default:cout<<"Wrong choice\n"; 
						exit(0);
			}
			if(ch!=1&&ch!=2)
			FinalOutput();	
		}		
	}
	
};

int main(){
	Scheduling s;
	s.prog();
	getch();
}
