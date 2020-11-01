package p3.p5;
import java.util.Scanner;
class B
{
	public static void main(String[] args) 
	{
        	Scanner s = new Scanner(System.in);
        	System.out.print("Enter the value of n: ");
        	int n = s.nextInt();
        	A ob= new A();
       		ob.fibon(n);
	}
}
