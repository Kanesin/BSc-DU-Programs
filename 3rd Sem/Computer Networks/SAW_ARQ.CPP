#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
using namespace std;
class SAW_ARQ{
	public:
	int sF;
	int DataWord;
	void input()
	{
		cout<<"Enter no. of frames\n";
		cin>>sF;
		cout<<"Enter data to be sent\n";
		cin>>DataWord;
	}
	
	void sender(int frameseq,int data,int ch)
	{	
		int *frames=&frameseq;
		*(frames+1)=data;		
		int ack=0,r;		
		if(ch==0)
		{
			ack=receiver(frames);	
			if(ack^frameseq==1)
				cout<<"\nSUCCESS";
			else
				cout<<"\nNO SUCCESS";
		}
		else if(ch==1)
		{
			cout<<"\nNo data Received, Resending data";
			cout<<"\nData send "<<data;
			r=rand()%3;
			sender(frameseq,data,r);	
		}
		else if (ch==2)
		{
			cout<<"\nData Send, but acknowledgment not received, Resending data";
			cout<<"\nData send "<<data;
			r=rand()%3;
			sender(frameseq,data,r);	
		}	
	}
	int receiver(int *p)
	{
		cout<<"\n\nReceiver side";
		cout<<"\nFrame Received: "<<*p<<*(p+1);
		cout<<"\nData: "<<*(p+1);
		int ack=*p;
		ack^=1;
		cout<<"\nACK send: "<<(*(p)^1);		
		return ack;	
	}
	public:
	void prog()
	{
		input();
		cout<<"Network Layer: Sending packets to Data Link Layer\n";
		cout<<"Data Link Layer: Receiving packets from Network Layer\n";
		cout<<"Data Link Layer: Converting packets and making frames\n";
		
		int seq=0;
		srand(time(NULL));
		int type;
		for(int i=0;i<sF;i++)
		{	type=rand()%3;
			cout<<"\n________________________\nSender side";
			cout<<"\nData send "<<DataWord;
			sender(seq,DataWord,type);
			usleep(800000);
			seq^=1;
		}		
		cout<<"\n\nData Link Layer: Converting frames to packets\n";		
	}	
};

int main()
{
	SAW_ARQ s;
	s.prog();
	getch();
}
