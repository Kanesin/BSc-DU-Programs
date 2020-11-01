class Q13
{
	public static int  a;
	public static void f1()
	{
		System.out.println("This is a static function");
		a++;
		System.out.println(a);
	}
	public void f2(int ... b)
	{
 		System.out.println("Total number of arguments:" + b.length);
		for(int i=0;i<b.length;i++)
		System.out.print(b[i]+ " ");
	}
	public static void main(String args[])
	{
	Q13 ob=new Q13();
	Q13.f1();
	ob.f2(1,2,3,4,5,6,7,8);
	}
}
