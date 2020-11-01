import java.util.*;
class Q8
{
public static void main(String args[])
{
Scanner I=new Scanner(System.in);
System.out.println("Enter string1,string2,string3");
String str=I.nextLine();
String str1=I.nextLine();
String str2=I.nextLine();
str.setCharAt(3,'y');
System.out.println(str);
str.setLength(20);
System.out.println(str);
str.append(str1);
System.out.println(str);
str1.insert(4,"bye");
System.out.println(str1);
System.out.println(str1.equals(str2));
}
}
