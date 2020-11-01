package p3;
class A
{
	public int a=1;
	protected int b=2;
	private int c=3;
	int d=4;
	public void show()
	{
		System.out.println("a: "+a);
		System.out.println("b: "+b);
		System.out.println("c: "+c);		
		System.out.println("d: "+d);
	}
}
class B extends A
{
	public void show1()
	{
		System.out.println("public access specifier of class a=" +a);		
		System.out.println("protected access specifier of class a=" +b);				
		System.out.println("default access specifier of class a=" +d);		
	}
}
class Derived
{
	public void show2()
	{
		System.out.println("Package p3, non sub class");
		System.out.println("a :"+a);
		System.out.println("b :"+b);
		System.out.println("d :"+d);
	}
}
