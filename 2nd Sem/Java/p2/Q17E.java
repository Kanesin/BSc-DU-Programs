package p2;
import p1.*;
class Q17E
{
	Q17E()
	{
		p1.Q17A p=new p1.Q17A();
		System.out.println("other package constructor");
		System.out.println("n_pub="+p.n_pub);
	}
}