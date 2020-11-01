import java.util.*;
class q10
{
int f;
double i;
q10()
{
	f=0;
	i=0.0;
}
q10(int feet,double inch)
{
	f=feet;
	i=inch;
}
public void assign(q10 ob)
{
	this.f=ob.f;
	this.i=ob.i;
}
void output()
{ 
System.out.println("Your height is:"+ f + " feet " + i + " inches ");
}
 
public static void main(String args[])
{
Scanner I=new Scanner(System.in);
System.out.println("Enter your height in cm:");
int c=I.nextInt();
double m=c;
int ft=(int)(m/30.48);
double in=(int)((c%(30.48))/2.54);
q10 obj=new q10();
q10 ob1=new q10(ft,in);
System.out.println("\nCalling for object 1 :");
ob1.output();
q10 ob2=ob1;
System.out.println("\nCalling for object 2(as a reference of object 1) :");
ob2.output();
q10 ob3=new q10();
ob3.assign(ob1);
System.out.println("\nCalling for object 3(as a clone) :");
ob3.output();

}
}  
   
