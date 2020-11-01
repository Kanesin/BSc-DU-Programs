class Pattern3
{ 
void fun(int m)
{ 
int n=m;
for(int i=1;i<n;i++)
{ 
 for(int j=1;j<=i;j++)
{ 
if(j==1||j==i)
System.out.print("*");
else 
System.out.print(" ");
} 
System.out.println();
} 
for(int k=1;k<=n;k++)
{ 
System.out.print("*");
}
} 
public static void main(String args[])
{
Pattern3 ob1=new Pattern3();
 int m=Integer.parseInt(args[0]);
ob1.fun(m);
}
}
