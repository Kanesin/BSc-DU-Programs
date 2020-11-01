import java.util.*;
class Q19
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

				int z[]=new int[5];
				z[41]=5;
			
			try
			{
				System.out.println("Going to divide");	
				int c=a/b;
				System.out.println(c);
			}
			catch(ArithmeticException e)
			{
				System.out.println(" Cannot be divide by zero :" +e);
			}
			}
			catch(ArrayIndexOutOfBoundsException e1)
			{
				System.out.println("Array is out of bound :"+e1);
			}
	 
		finally
		{
			System.out.println("NORMAL FLOW");
		}
	}
}
				
