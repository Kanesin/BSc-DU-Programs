import java.util.*;
class Q4
{
	public static void main(String args[])
	{
		Scanner I=new Scanner(System.in);
		System.out.println("Enter length of the array:");
		int a=I.nextInt();
		System.out.println("Enter breadth of the array:");
		int b=I.nextInt();
		int A[][]=new int[a][b];	
		System.out.println("Enter the array elements:");
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				A[i][j]=I.nextInt();		
			}
		}
		System.out.println("The number of rows are:"+A.length);
		System.out.println("The number of columns are:"+A[0].length);
	}
}

