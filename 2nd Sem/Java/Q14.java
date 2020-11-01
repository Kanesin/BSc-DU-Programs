import java.util.*;
class Q14
{
	public static void main(String args[])
	{
		Scanner I=new Scanner(System.in);
		System.out.println("Enter a number:");
		int n=I.nextInt();
		Integer k=new Integer(n);
		System.out.println("BOXING:"+k);
		int m=k;
		System.out.println("UNBOXING:"+m);		
	}
}	
