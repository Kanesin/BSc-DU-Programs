import java.util.*;
class Q11
{
	void f1(int x)
	{
		System.out.println("First function is called:"+x);
	}
	void f1(double y)
	{
		System.out.println("Second function is called:"+y);		
	}
	public static void main(String args[])
	{
		Scanner I=new Scanner(System.in);	
		System.out.println("Enter a number in byte");
		byte n=I.nextByte();
		Q11 ob=new Q11();
		ob.f1(n);
		System.out.println("Enter a number in short");		
		short num=I.nextShort();
		ob.f1(num);
		System.out.println("Enter a number in long");		
		long l=I.nextLong();
		ob.f1(l);
	}
}
