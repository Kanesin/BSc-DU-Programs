import java.util.*;
class Q3
{
	public static void main(String args[])
	{
		Scanner I=new Scanner(System.in);
		System.out.println("Enter the size of array:");
		int s=I.nextInt();
		int a[]=new int[s];
		System.out.println("Enter the array elements:");
		for(int i=0;i<s;i++)
		{
			a[i]=I.nextInt();
		}
		System.out.println("Elements of the array are:");
		for(int j=0;j<s;j++)
		{
			System.out.print(a[j]+" ");
		}
	}
}
