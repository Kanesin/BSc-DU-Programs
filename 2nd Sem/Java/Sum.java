class Sum
{
	public static void main(String [] args)
	{
		int num=args.length;
		int s=0;
		for(int i=0; i<num; i++)
		{
			s=s+(Integer.parseInt(args[i]));
		}
		System.out.println("The sum is:"+s);
	}
}