import java.util.*;
class Q7
{ 
void display(int a)
{
System.out.println("Please Enter Numbers:");
Scanner I=new Scanner(System.in);
int t=0;

for(int i=1;i<=a;i++)
{ 
int n=I.nextInt();
t+=n;
}
System.out.println("Sum is " + t);
} 

	public static void main(String args[])
{ 
	int a=Integer.parseInt(args[0]);
	Q7 ob1=new Q7();
	ob1.display(a);
} 
} 


