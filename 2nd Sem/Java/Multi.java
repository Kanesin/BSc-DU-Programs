package p2;
import java.util.Scanner;

public class Multi
{ 
	public void output(int n)
	{
		int a=0;
		int b=1;
		int c=0;
		System.out.print("0" + " " + "1" + " "); 
		for(int i=3;i<n;i++)
		{
			c=a+b;
			System.out.print(c+" ");
			a=b;
			b=c;
		}
	}
}

