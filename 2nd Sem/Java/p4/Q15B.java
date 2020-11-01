package p4;
class Q15B
{
	public static void main(String [] args)
	{
		Q15A ob=new Q15A();
		Q15B ob1=new Q15B();
		ob.input();
		ob1.display(ob.S);
	}
	void display (String n)
	{
		System.out.println("The message entered by you is:"+n);
	}
}