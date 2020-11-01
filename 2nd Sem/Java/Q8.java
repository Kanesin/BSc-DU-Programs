import java.util.*;
class Q8
{
	public static void main(String args[])
	{
		Scanner I=new Scanner(System.in);
		System.out.println("Enter the string 1");
		StringBuffer S1=new StringBuffer(I.nextLine());
		System.out.println("Enter the string 2");
		StringBuffer S2=new StringBuffer(I.nextLine());
		System.out.println("Enter the string 3");
		StringBuffer S3=new StringBuffer(I.nextLine());
		System.out.println("Enter the string 4");
		String S4=I.nextLine();
		System.out.println("Enter the string 5");
		String S5=I.nextLine();
		System.out.println("Replacing first character of string S1 with a");
		S1.setCharAt(0,'a');
		System.out.println(S1);
		System.out.println("Changing length of string S1 with 10");
		System.out.println("Old length:"+S1.length());
		S1.setLength(10);
		System.out.println("New length:"+S1.length());
		System.out.println("Inserting string 1 in string 2 at 4 position");
		S1.insert(4,S1);
		System.out.println(S1);
		System.out.println("Concatinate fourth string with fifth");
		System.out.println(S4.concat(S5));
		System.out.println("Append first string with fourth string at position 3 and 3 characters");
		S1.append(S4,3,3);
	}
}
