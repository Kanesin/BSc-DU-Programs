#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
#include<math.h>
using namespace std;
struct Frame{
	int seq, data;
	void input(int a,int b)
	{
		seq=a;
		data=b;
	}
};
class go_back_n
{
	public:
	int nF,sW,pos,rs,done;
	struct Frame *Window,*Sent;
	void input()
	{
		
		cout<<"Enter no. of frames\n";
		cin>>nF;
		cout<<"Enter no. of Bits of seq\n";
		int m;
		cin>>m;
		sW=pow(2,m)-1;
		Window=new struct Frame [sW];
		Sent=new struct Frame[sW];
		pos=rs=done=0;
		
	}	

	void sender(int frameseq,int data)
	{
		Window[pos].input(frameseq,data);
		Sent[pos].input(frameseq,data);
		pos++;			
	}
	void transmission(int end)
	{
		int ack,flag=0;
		for(int i=0;i<end;i++)
		{
			try
			{
				
				ack=receiver(Sent[rs++]);
				if(ack==((Window[0].seq+1)%(sW+1)))
				{
					for(int j=0;j<pos-1;j++)
						Window[j]=Window[j+1];				
					pos--;
					done++;
				}
				else
					flag=1;
			}
			catch(int x)
			{
				flag=1;
				cout<<"\n\nReceiver side";
				if(x==1)
					cout<<"\nNo data Received, no ACK sent";
				else if(x==2)
					cout<<"\nData Send, but acknowledgment not received";
				cout<<"\n________________________\n";
			}
			
		}
		if(flag==1)
		{
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~\n";
			cout<<"Resending data due to failure";
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~\n";
			rs=done;
			if(pos!=0)			
			transmission(pos);	
			
		}
	}
	int receiver(Frame F)
	{
		int ch;
		ch=rand()%3;
		if(ch==0)
		{
			cout<<"\nReceiver side";
			cout<<"\nFrame Received: "<<F.seq<<F.data;
			cout<<"\nData: "<<F.data;
			int ack=F.seq;
			ack++;
			ack%=(sW+1);
			cout<<"\nACK send: "<<ack<<"\n________________________\n";		
			return ack;	
		}
		else if(ch==1)
			throw 1;
		else
			throw 2;
	}
void prog()
	{
		input();
		cout<<"Network Layer: Sending packets to Data Link Layer\n";
		cout<<"Data Link Layer: Receiving packets from Network Layer\n";
		cout<<"Data Link Layer: Converting packets and making frames\n";
		
		int seq=0,data,tf=0;
		for(int i=0;i<(nF/sW)+1;i++)
		{	
			pos=0;
			
			for(int j=0;j<sW;j++)
			{	
				if(tf==nF)
					break;
				cout<<"\nSender side\n";
				cout<<"Enter Data to send: ";
				cin>>data;
				cout<<"Data sending: "<<data<<"\n________________________\n";
				sender(seq,data);
				seq++;
				seq%=(sW+1);
				tf++;	
			}
			rs=done=0;			
			if(i<(nF/sW))
			transmission(sW);
			else			
			transmission(nF%sW);
		}		
		cout<<"\n\nData Link Layer: Converting frames to packets\n";		
	}	
};

int main()
{
	srand(time(NULL));
	go_back_n s;
	s.prog();
	getch();
}
