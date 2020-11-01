class Factorial
{
	void cal(int a)
	{
		int n=a;
		int p=1;
		for(int i=1;i<=n;i++)
		{
			p=p*i;
		}
		System.out.println("The factorial of the number is:"+p);
	}
	public static void main(String args[])
	{
		Factorial ob=new Factorial();
		int a=Integer.parseInt(args[0]);
		ob.cal(a);
	}
}		
	
