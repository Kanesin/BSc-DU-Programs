class Q21 extends Thread
{
	public void main()
	{
		System.out.println("Inside run method");
	}
	public static void main(String [] args)
	{
		Q21 t1=new Q21();
		Q21 t2=new Q21();
		Q21 t3=new Q21();
		System.out.println("t1 Thread priority:"+t1.getPriority());
		System.out.println("t2 Thread priority:"+t2.getPriority());
		System.out.println("t3 Thread priority:"+t3.getPriority());
		t1.setPriority(2);
		t2.setPriority(5);
		t3.setPriority(8);
		System.out.println("t1 Thread priority:"+t1.getPriority());
		System.out.println("t2 Thread priority:"+t2.getPriority());
		System.out.println("t3 Thread priority:"+t3.getPriority());
		System.out.println(Thread.currentThread().getName());
		System.out.println("Main Thread Priority:"+currentThread().getPriority());
		Thread.currentThread().setPriority(10);
		System.out.println("Main Thread Priority:"+currentThread().getPriority());
	}
}
		
		
		
