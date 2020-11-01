class Pattern
{
	void num(int a)
	{
		int n=a;
		int m=n;
		for(int i=1;i<=n;i++)
		{
			for(int k=m-1;k>=0;k--)
			{
				System.out.print(" ");
			} 	
			m--;	
			for(int j=1;j<=(2*i)-1;j++)
			{ 
				System.out.print("*");
			} 
			System.out.println();
}
}
	public static void main(String args[])
{ 
Pattern ob=new Pattern();
int a=Integer.parseInt(args[0]);
ob.num(a);
}
}

