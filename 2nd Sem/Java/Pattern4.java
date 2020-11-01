class Pattern4
{ 
void fun(int m)
{ 
int n=m;
for(int i=1;i<=(n/2)+1;i++)
{
for(int j=1;j<=(n/2)+1;j++)
{
if(i==1 ||i==((n/2)+1) ||j==1 ||j==((n/2)+1))
System.out.print("*");
else
System.out.print(" ");
}
System.out.println();
}
for(int k=1;k<=n/2;k++)
{
System.out.println("*");
}
}
public static void main(String args[])
{
Pattern4 ob1=new Pattern4();
int m=Integer.parseInt(args[0]);
ob1.fun(m);
}
}
