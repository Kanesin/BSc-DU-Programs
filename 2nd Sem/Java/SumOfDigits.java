class SumOfDigits
{
public static void main(String args[])
{
int n=78,t=0,r;
while(n>0)
{
r=n%10;
t=t+r;
n=n/10;
}
System.out.println("Sum of Digits is:"+t);
}
}
