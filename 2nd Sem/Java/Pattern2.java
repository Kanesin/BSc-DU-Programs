class Pattern2
{
void fun(int r,int c)
{
int m=r;
int n=c;
for(int i=1;i<=m;i++)
{
for(int j=1;j<=c;j++)
{
if(i==1 ||i==m ||j==1 ||j==n)
System.out.print("*");
else
System.out.print(" ");
}
System.out.println();
}
}
	public static void main(String args[])
{ 
Pattern2 ob1=new Pattern2();
int r=Integer.parseInt(args[0]);
int c=Integer.parseInt(args[1]);
ob1.fun(r,c);
}
}

