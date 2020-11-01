#include<iostream>
#include<conio.h>
#include<cstdlib>
#define Max_Process 10
using namespace std;
struct process{
	int PID, process_size, *page_table, page_table_size;
	process()
	{
		PID=-1;
		process_size=-1;
		page_table_size=0;
		page_table =new int[page_table_size];				
	}
	process(int pid,int ps,int page_size)
	{		
		PID=pid;
		process_size=ps;
		page_table_size=process_size/page_size;
		if(process_size%page_size!=0)
			page_table_size++;
		page_table =new int[page_table_size];				
	}
};

class paging{
	
	int page_s,physical_m_s,* frame_table,* free_mem,sFM,process_counter;
	process *processes;
	void input()
	{
		cout<<"\nEnter Page size in MB: ";
		cin>>page_s;
		cout<<"Enter Memory size in MB:";
		cin>>physical_m_s;
		sFM=physical_m_s/page_s;		
		free_mem=new int[sFM];
		frame_table=new int[sFM];
		for(int i=0;i<sFM;i++)
		{
			free_mem[i]=i;
			frame_table[i]=-1;
		}
		processes=new process[Max_Process];
		process_counter=0;		
	}
	
	void addProcess()
	{
		int ps;
		cout<<"\nProcess ID:"<<++process_counter;
		cout<<"\nEnter Process size:";
		cin>>ps;
		process P(process_counter,ps,page_s);
		int i=0;
		while(processes[i].PID!=-1)
			i++;
		if(i<Max_Process)	
			processes[i]=P;
		else
			throw "Delete any Existing Process before adding more Processes";
		for(int j=0;j<processes[i].page_table_size;j++)
		{
			int random_pos=rand()%sFM;
			processes[i].page_table[j]=free_mem[random_pos];
			frame_table[free_mem[random_pos]]=processes[i].PID;
			for(int k=random_pos;k<sFM-1;k++)
				free_mem[k]=free_mem[k+1];			
			sFM--;
		}	
	}
	
	int getFrame()
	{
		int id,p_no;
		cout<<"\nEnter Process ID:";
		cin>>id;
		cout<<"\nEnter Page No.:";
		cin>>p_no;
		int i=0;
		while(processes[i].PID!=id&&i<Max_Process)
			i++;			
		if(processes[i].PID==id&&p_no<processes[i].page_table_size)
		cout<<"\nFrame no. At page no. "<<p_no<<" is "<<processes[i].page_table[p_no];
		else
		throw "Invalid input";		
	}
	
	void deleteProcess()
	{
		int  id;
		cout<<"\nEnter Process ID:";
		cin>>id;
		int i=0;
		while(processes[i].PID!=id&&i<Max_Process)
			i++;
		if(processes[i].PID==id)
		{
			process p;
			processes[i]=p;	
			for(int j=0;j<physical_m_s/page_s;j++)
			{
				if(frame_table[j]==id)
				{
					frame_table[j]=-1;	
					free_mem[sFM++]=j;
				}
			}
		}	
		else
		throw "Invalid input";			
	}
	void displayProcesses()
	{
		int i=0;
		while(processes[i].PID!=-1)
		{
			cout<<"\nPID:"<<processes[i].PID;
			cout<<"\nP_size:"<<processes[i].process_size<<endl;
			cout<<"\nPage_no.\tFrame_no.\n";
			for(int j=0;j<processes[i].page_table_size;j++)
				cout<<j<<"\t\t"<<processes[i].page_table[j]<<"\n";
			i++;
		}
	}
	
	void displayFrameTable()
	{
		cout<<"Frame no.\tPID\n";
		int x;
		for(int j=0;j<physical_m_s/page_s;j++)
		{
			x=frame_table[j];
			if(x!=-1)
			cout<<j<<"\t\t"<<x<<"\n";			
			else
			cout<<j<<"\t\t"<<"N/A"<<"\n";			
		}
	}
	
	int menu()
	{
		cout<<"\nMENU\n";
		cout<<"1. Add new Process\n";
		cout<<"2. All Process Page Table\n";
		cout<<"3. Get Specific Frame no.\n";
		cout<<"4. Delete Process\n";
		cout<<"5. View Frame Table\n";
		cout<"6. EXIT\n";
		cout<<"Enter choice\n";
		int ch;
		cin>>ch;
		return ch;	
	}
	public:
	void prog()
	{
		input();
		while(true)
		{
			try{
			int ch=menu();	
			switch(ch)
			{
				case 1: addProcess();
				break;
				case 2: displayProcesses();
				break;
				case 3: getFrame();
				break;
				case 4: deleteProcess();
						displayFrameTable();
				break;
				case 5: displayFrameTable();
				break;
				case 6: exit(0);
				break;
				default: cout<<"Wrong choice entered \n";
						exit(0);					
			}	
			}
			catch(const char *c)
			{
				cout<<c;
			}			
		}		
	}
	/*
	void display()
	{
		cout<<"Free memory table:\n";
		for(int j=0;j<sFM;j++)
		{
			cout<<j<<"\t"<<free_mem[j]<<"\n";
		}
		cout<<"Frame table:\n";
		for(int j=0;j<physical_m_s/page_s;j++)
		{
			cout<<j<<"\t"<<frame_table[j]<<"\n";
		}
		int i=0;
		while(processes[i].PID!=-1)
		{
			cout<<"\nPID:"<<processes[i].PID;
			cout<<"\nP_size:"<<processes[i].process_size<<endl;
			cout<<"\n Page_no.\tFrame_no.\n";
			for(int j=0;j<processes[i].page_table_size;j++)
				cout<<j<<"\t\t\t"<<processes[i].page_table[j]<<"\n";
			i++;
		}
		deleteProcess();
		cout<<"Free memory table:\n";
		for(int j=0;j<sFM;j++)
		{
			cout<<j<<"\t"<<free_mem[j]<<"\n";
		}
		cout<<"Frame table:\n";
		for(int j=0;j<physical_m_s/page_s;j++)
		{
			cout<<j<<"\t"<<frame_table[j]<<"\n";
		}
		i=0;
				while(processes[i].PID!=-1)
		{
			cout<<"\nPID:"<<processes[i].PID;
			cout<<"\nP_size:"<<processes[i].process_size<<endl;
			cout<<"\n Page_no.\tFrame_no.\n";
			for(int j=0;j<processes[i].page_table_size;j++)
				cout<<j<<"\t\t\t"<<processes[i].page_table[j]<<"\n";
			i++;
		}		
	}*/
		
};

int main()
{
	paging p;
	p.prog();
	getch();
}
