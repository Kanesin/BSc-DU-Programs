#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
template <class T> class stack{

	T *arr;
	int sArr,top;
	public:
	stack(int size)
	{
		sArr=size;
		arr=new T[sArr];
		top=-1;		
	}
	
	bool isEmpty()
	{
		return (top==-1);
	}
	
	bool isFull()
	{
		return (top==sArr-1);
	}
	
	void push(T val)
	{
		if(!isFull())
		{
			top++;
			arr[top]=val;	
		}
		else
			throw "Stack is Full";
	}
	
	T pop()
	{
		T val;
		if(!isEmpty())
		{
			val=arr[top];
			top--;
			return val;
		}
		else
			throw "Stack is empty";		
	}
	
	T topVal()
	{
		if(!isEmpty())
			return arr[top];
		else
			throw "Stack is empty";
	}
	
	void display()
	{	
		int c=0;
		if(!isEmpty())
		{
			for(int i=top;i>=0;i--)
				cout<<++c<<".\t"<<arr[i]<<"\n";	
		}
		else
			cout<<"Stack is empty";		
	}
	
	void clear()
	{
		while(!isEmpty())
			pop();
	}
	
	int menu()
	{
		cout<<"\nMENU\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Clear\n";
		cout<<"4. display\n";
		cout<<"5. Exit\n";
		cout<<"Enter Choice\n";
		int ch;
		cin>>ch;
		return ch;		
	}
	
	void prog()
	{
		try
		{
			T data;
			int ch;
			do{
				ch=menu();
				switch (ch)
				{
					case 1: cout<<"Enter Data\n";
							cin>>data;
							push(data);
					break;
					case 2: data=pop();
							cout<<"Deleted Data= "<<data;
					break;
					case 3: clear();
							cout<<"Deleted All data";
					break;
					case 4: display();
					break;
					case 5:exit(0);
					break;
					default: cout<<"wrong choice entered\n";
							exit(0);						
				}
			}while(true);		
		}
		catch(const char*c)
		{
			cout<<c;
		}
	}
};


