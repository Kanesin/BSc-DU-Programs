import java.util.Scanner;
class Prog11
{	public static void main(String[] args)
	{	Scanner ob=new Scanner(System.in);
		System.out.println("Enter number in centimeters:");
		Prog11 obj=new Prog11();	
		byte a=ob.nextByte(10);
		obj.show(a);
	}
	void show(long x)
	{	System.out.println("your value in long is:"+x);
	}
} 
