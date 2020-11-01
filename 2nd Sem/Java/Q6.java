import java.util.*;
class Q6
{
void prime(int a)
{
int n=a;
int x=0;
for(int i=1;i<=n/2;i++)
{
if(n%i==0)
x++;
}
if (x<2)
System.out.println("it is a prime number");
else
System.out.println("it is not a prime number");
}
	
	public static void main(String agrs[])
{ 
	Scanner I=new Scanner(System.in);
	System.out.println("Please Enter a Number");
	int a=I.nextInt();
	Q6 ob1=new Q6();
	ob1.prime(a);
} 
} 
