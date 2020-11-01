class Greater
{ 
   void check(int c,int b,int d)
	{
		
		if (c>b && c>d)
		System.out.println(c+"\t"+"is Greater");
		if (b>c && b>d)
     		System.out.println(b +"\t" + "is Greater");
		else 
		System.out.println(d +"\t" + "is Greater");	
	}
 	public static void main(String args[])
	{ 
		int c=Integer.parseInt(args[0]);
		int b=Integer.parseInt(args[1]);
		int d=Integer.parseInt(args[2]);
		
	Greater ob=new Greater();
	ob.check(c,b,d);
}}
