#include<iostream>
#include<unistd.h>
#include<conio.h>
#include<cstdlib>
#include<math.h>
#include<time.h>
int cf=0;

using namespace std;

int seq_range;
struct frame
{
	int data;
	int seq;
}*Frame,*Sender,*Rec;

class SEL
{
	int n,sq,ws,ptr,ctr,t,y,nd,r_ind,c;
	bool done;
	public:
		void enter()
		{
			
			
			int _data;
			cout<<"\nEnter the number of bits in the sequence number:";
			cin>>sq;
			ws=pow(2,sq)/2;
			
			//to get the sequence number in range
			seq_range=pow(2,sq);
			
			//initializing the sender and receiver frames
			Sender=new struct frame[ws];
			Rec=new struct frame[ws];
			
			
			cout<<"\nEnter the number of Frames:";
			cin>>n;
			Frame=new struct frame[n];
            
			cout<<"\nEnter the data in frames:";
			
			int temp=0;
			r_ind=0;
			for(int i=0;i<n;i++)
			{
				
				//inserting data and sequence number in frame
				cin>>_data;
				Frame[i].data=_data;
				Frame[i].seq=temp;
				temp=(temp+1)%seq_range;
			}
			
		}
		void sender()
		{
				ctr=ptr=t=0;
				
								nd=0;

				if((n-ctr)>=ws)
				{
					for(int i=0;i<ws;i++)
					{
						Sender[i].data=Frame[t].data;
						Sender[i].seq=Frame[t].seq;
						cout<<"\nFrame "<<t+1<<" sent";
						t++;
						nd++;
						c=nd;
				    }
				}
				else
				{
					for(int i=0;i<(n-ctr);i++)
					{
						Sender[i].data=Frame[t].data;
						Sender[i].seq=Frame[t].seq;
						cout<<"\nFrame "<<t+1<<" sent";
						t++;
						nd++;
						c=nd;
				    }
				}
				while(ctr<n)
			    {
			    	
			    	
		
				
				
				r_ind=0;
				
				
				ptr=0;
				while(1)
				{
					here:
					int ack=rec(Sender[ptr].seq,Sender[ptr].data);
					usleep(800000);					
					if(ack==(Sender[ptr].seq+1)%seq_range)
					{
						cout<<"\nFrame with data "<<Sender[ptr].data<<" sent successfully";
						
						//to get the number of frames sent successfully
						ctr++;
						
						if(n-ctr>=ws)
						c=ws;
						else
						c=n-ctr;
						
						for(int h=ptr;h<c;h++)
						Sender[h]=Sender[h+1];
						
						if(t<n)
						Sender[c-1]=Frame[t++];
						
						cout<<"\n{{{value in sender}}}\n";
						for(int i=0;i<c;i++)
						cout<<Sender[i].data<<"==>>";
						
						done=true;
					}
					else
					{
						cout<<"\nError in sending frame with data "<<Sender[ptr].data;
						ptr++;
						done=false;
					}
					if(c==ptr)
						ptr=0;
					
					
										
					if(c==0)
					break;
				}
				if(c==0)
				break;
			}
			cout<<"\nFRAMES SENT SUCCESSFULLY!!";
		}
		
		int rec(int s,int d)
		{
				
			  cout<<"\n\nSENDING ACK\n\n";
			
		
			   int r_no=rand()%2;
			
			if(r_no==0)
			{
				cout<<"\n\nFrame with data "<<d<<" received at receiver side";
				Rec[r_ind].data=d; 
				Rec[r_ind].seq=s;
				r_ind++;
				return (s+1)%seq_range;
			}
			else
			return -1;
		    
		}
};
int main()
{
		srand(time(NULL));
	SEL S;
	S.enter();
	S.sender();
	getch();
	return 0;
}
