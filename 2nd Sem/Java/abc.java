class abc
{
	int a,b,c=0,p=1;
	abc()
	{
		a=0;
		b=0;
	}
	abc(int c,int d)
	{
		a=c;
		b=d;
	}
	void add()
	{
		c=a+b;	
	}
	void product()
	{
		p=a*b;
	}
	void disp()
	{

		System.out.println("Sum of the numbers is:"+c);
		System.out.println("Product of the numbers is:"+p);
	}
	public static void main(String args[])
	{
		abc ob=new abc();
		abc ob1=new abc(3,4);
		ob.add();
		ob1.add();
		ob.product();
		ob1.product();
		ob.disp();
		ob1.disp();
	}
}		

