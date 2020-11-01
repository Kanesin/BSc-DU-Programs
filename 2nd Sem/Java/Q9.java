import java.util.*;
class q9
{
int d;
int f;
q9 convert ( int  c)
{
double m=c;
double i;
f=(int)(m/30.48);
d=(int)((c%(30.48))/2.54);
return (this);
}
void output()
{ 
System.out.println("Your height is:"+ f + " feet " + d + " inches ");
}
 
public static void main(String args[])
{
Scanner I=new Scanner(System.in);
System.out.println("Enter your height in cm:");
int c=I.nextInt();
q9 ob1=new q9();
q9 ob2=new q9();
ob1=ob2.convert(c);
ob1.output();
}
}  
   
