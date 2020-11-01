package p3.p5;
public class Q16A
{
	public void fibon(int n)
	{	
		if (n==0) 
		{
                	System.out.println("0");
       		} 
		else if (n==1) 
		{
           		System.out.println("0 1");
       		}
		else	
		{
           		System.out.print("0 1 ");
           		int a=0;
           		int b=1;
           		for (int i=1; i<n; i++) 
			{
               			int c=a+b;
               			System.out.print(c+ " ");
               			a=b;
               			b=c;
          		}
		}
		
	}

}
