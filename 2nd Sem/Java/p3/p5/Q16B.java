package p3.p5;
import java.util.Scanner;
class Q16B
{
	public static void main(String[] args) 
	{
        	Scanner s = new Scanner(System.in);
        	System.out.print("Enter the value of n: ");
        	int n = s.nextInt();
        	Q16A ob= new Q16A();
       		ob.fibon(n);
	}
}
