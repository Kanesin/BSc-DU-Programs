class Command
{ 
	void sum(int c,int b,int d)
       { 
	int f=c+b+d;
	System.out.println(f);
}
	public static void main(String args[])
	{ 
 		int c=Integer.parseInt(args[0]);
		int b=Integer.parseInt(args[1]);
		int d=Integer.parseInt(args[2]);
	Command ob1=new Command();
	ob1.sum(c,b,d);
		
    } 
} 

