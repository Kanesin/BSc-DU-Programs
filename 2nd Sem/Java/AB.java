import p3.*;
package p4;
class Package2 extends A
{
	public void show3()
	{
		System.out.println("public access specifier a of class A: "+a);
		System.out.println("protected access specifier b of class A: "+b);
	}
}
class AB
{
	public void show4()
	{
		System.out.println(" public access specifier a of class A :"+a);
	}
}
class Prog
{
	public static void main(String args[])
	{
		B ob=new B();
		Derived ob1=new Derived();
		AB ob2=new AB();
		ob.show();
		ob.show1();
		ob1.show2();
		ob.show3();
		ob2.show4();
	}
}
