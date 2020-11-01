import java.util.*;
class Q12
{
	public int a;
	public final int b=45;
	public void sum(int c)
	{
		c=c+10;
		System.out.println("Implementing call by value : ");
		System.out.println("Value of x is "+c);
	}
	void CBR(Q12 ob1)
	{
		this.a=ob1.a+5;
		System.out.println("Implementing call by reference:"+this.a);
	}	
}
class B
{
	public static void main(String args[])
	{
		Q12 ob=new Q12();
		int x=10;
		System.out.println("Before calling call by value:"+x);
		ob.sum(x);
		ob.a=5;
		System.out.println("After calling call by value:"+x);
		Q12 ob2=new Q12();
		System.out.println("Before calling call by reference:"+ob2.a);
		ob2.CBR(ob);
		System.out.println("After calling call by reference:"+ob2.a);
		System.out.println("The value of final variable is: "+ob2.b);
	}
}
