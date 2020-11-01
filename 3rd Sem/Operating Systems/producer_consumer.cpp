#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
using namespace std;
class Buffer
	{
		int *Arr,front, rear, sArr;
		public:
		Buffer()
		{
			front=rear=sArr=0;
			Arr = new int [sArr];
		}
		Buffer(int size)
		{
			sArr = size;
			Arr = new int [size];
			front = rear = -1;
		}
		bool isFull()
		{
			return ((rear+1)%sArr==front) ;
		}
		bool isEmpty()
		{
			return ( front==-1 );
		}
		void enqueue(int value)
		{
			if (isFull())
				throw 0;
			else
			{
				rear = (rear + 1)%sArr;
				Arr[rear] = value;
				if (front == -1)
				front = 0;
			}
		}
		int dequeue()
		{
			if (isEmpty())
				throw 1;
			else
			{
				int value = Arr[front];
				front = (front + 1)%sArr;
				if ((rear+1)%sArr == front)
				front = rear = -1;
				return value;
			}
		}
		void display()
		{
			if (isEmpty())
				throw 2;
			int index = front;
			int count = 1;
			while(index != rear)
			{
			cout<<count++<<".\t"<<Arr[index]<<"\n";
			index = (index+1) % sArr;
			}
			cout<<count++<<".\t"<<Arr[rear]<<"\n";
		}	
	}; 
	class Producer_consumer
	{
		Buffer B;
		void input()
		{
			int sB;
			cout<<"Enter Buffer Size\n";
			cin>>sB;
			Buffer ob(sB);
			B=ob;
		}
		int producer()
		{
			int a;
			cout<<"\nEnter data to be produced= ";
			cin>>a;
			cout<<"\nProduced: "<<a;
			return a;
		}
		void consumer(int x)
		{
			cout<<"\nConsumed: "<<x;
		}
		public:
		void prog()
		{
			input();
			int ch;
			char y;
			B.enqueue(producer());
			while(true)
			{
				try
				{				
					ch=rand()%2;
					if(ch==0)
						B.enqueue(producer());
					else
						consumer(B.dequeue());
					cout<<"\n\nPress N to exit or Press B to see Buffer else any other key to continue: ";
					cin>>y;
					if(y=='n'||y=='N')
						exit(0);
					if(y=='b'||y=='B')
						B.display();
				}
				catch(int x)
				{
					if(x==0)
						cout<<"\nProduction halted as Buffer is Full";
					else if(x==1)
						cout<<"\nConsumption halted as Buffer is Empty";
					else
						cout<<"\n Buffer is empty";
				}
				usleep(100000);
			}
		}
	};
int main()
{	
	srand(time(NULL));
	Producer_consumer p;
	p.prog();
	getch();
}
