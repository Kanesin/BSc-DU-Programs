import java.util.*;
class Q5
{
	void dec(int a)
	{
		int k=0;	
		int c=0;
		int n=a;
		int m=n;		
		while(n>0)
		{
			int r=n%2;
			c++;
			n=n/2;
		}
		int A[]=new int[32];
		while(m>0)
		{
		
			int r=m%2;
			A[k++]=r;
			m=m/2;
		}
		for(int p=c;p<=31;p++)
		{
			A[p]=0;
		}
		System.out.print("Binary of the number is:");
		for(int l=31;l>=0;l--)
		{
			System.out.print(A[l]);
		}
	}
	public static void main(String args[])
	{
		Scanner I=new Scanner(System.in);
		{
			System.out.println("Enter the number:");
			int a=I.nextInt();
			Q5 ob=new Q5();
			ob.dec(a);
		}
	}
}
