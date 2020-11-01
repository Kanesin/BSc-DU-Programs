class Pal
{ 
void palin(int n)
{
int h,r,t=0,temp;
h=n;
temp=h;

while(n>0)
{
r=n%10;
t=t*10+r;
n=n/10;
}
if(t==temp)
System.out.println("It is a palindrome");
else
System.out.println("It is not a palindrome");
}
public static void main(String args[])
{
int a=Integer.parseInt(args[0]);
Pal ob=new Pal();

ob.palin(a);
}
}
 
