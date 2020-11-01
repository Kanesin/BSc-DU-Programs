import java.util.*;
class Q18
{
	public static void main(String args[])
	{
		Scanner I=new Scanner(System.in);
		int a,b;
		System.out.println("Enter a");	
		a=I.nextInt();
		System.out.println("Enter b");	
		b=I.nextInt();
		try
		{
			int c=a/b;
			System.out.println("The qoetient is : "+c);
		}
		catch(ArithmeticException e)
		{
			System.out.println("You cannot divide a number by zero "+e);
		}
	}
}
