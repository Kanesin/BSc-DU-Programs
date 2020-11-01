import java.util.*;
class Stack
{
	
	int size,top;
	int a[]=new int[100];
	void input(int cap)
	{
		size=cap;
		a=new int[size];
		top=-1;
	}
	void push(int n)
	{	
		if(top==size-1)
		System.out.println("Stack is full");
		else 
		a[++top]=n;
	}
	int pop()
	{
		if(top==-1)
		{
			System.out.println("Stack is empty");
			return(-999);
		}
		else
		return(a[top--]);
	}
	void menu()
	{
		
	}
	void disp()
	{
		System.out.println("Stack elements");
		for(int i=0;i<=top;i++)
		System.out.println(a[i] + " ");
	}
	void choice()
	{	int ch;
		Scanner s=new Scanner(System.in);
		char c;
		do{
		
  			System.out.println("MENU OPTION:\n1. push\n 2 pop\n enter your choice ");
			ch=s.nextInt();
				
			switch(ch)
			{
				case 1: System.out.println("Enter number to be pushed");
					int x=s.nextInt();
					push(x);
					break;
				case 2: int g=pop();
					System.out.println("Popped number is:"+g);
					break;
					default:System.out.println("INVALID CHOICE");
			}
			System.out.println("Do you want to continue(Y/y)");
			c=s.next().charAt(0);
			
			
		}while(c=='Y' || c=='y');
		disp();
	}
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter capacity of stack");
		int cap=s.nextInt();
		Stack ob=new Stack();
		ob.input(cap);
		ob.choice();

	}
}
