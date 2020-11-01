#include<iostream> 
#include<conio.h>
#include<cstdlib>
#include<math.h>
using namespace std;
class set
{
	int A[20],B[20],C[50],D[50],m,n,ch,p,k;
	public:
		void Union();
		void Intersection();
		void setdiff();
		void symdiff();
		void subset();
		void comp();
		void cart();
		void input();
		int menu();
};
int set::menu()
{
	cout<<"\nMENU";
	cout<<"\n1.SUBSET";
	cout<<"\n2.UNION";
	cout<<"\n3.INTERSECTION";
	cout<<"\n4.COMPLEMENT";
	cout<<"\n5.SET DIFFERENCE";
	cout<<"\n6.SYMMETRIC DIFFERENCE";
	cout<<"\n7.CARTESIAN PRODUCT";
	cout<<"\n8.EXIT";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	return ch;
	
}
void set::input()
{
    cout<<"\nEnter the size of the first set: ";
	cin>>m;
	cout<<"\nEnter the elements of the first set: ";
	for(int i=0;i<m;i++)
	{
		cin>>A[i];
	}
	cout<<"\nEnter the size of the second set: ";
	cin>>n;
	cout<<"\nEnter the elements of the second set: ";
	for(int i=0;i<n;i++)
	{
		cin>>B[i];
	}
}
void set::Union()
{

	p=0;
	for(int i=0;i<m;i++)
	{
		C[p++]=A[i];
	}
	for(int i=0;i<n;i++)
	{
		C[p++]=B[i];
	}
	for(int g=0;g<p;g++)
	{
		for(int h=g+1;h<p;h++)
		{
			if(C[g]==C[h])
			{
				for(int x=h;x<p;x++)
				{
					C[x]=C[x+1];
				}
			p--;
			}
		}
	}
	cout<<"\nThe union of the sets is: ";
	
	for(int i=0;i<p;i++)
	{
		cout<<C[i]<<" ";
	}
}
void set::Intersection()
{
	k=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(A[i]==B[j])
			{
		     	D[k++]=A[i];
			}
		}
	}
	cout<<"\nThe intersection of the sets is: ";
	for(int i=0;i<k;i++)
	{
		cout<<D[i]<<" ";
	}
}
void set::subset()
{
	cout<<"\nTHE SUBSET OF A: ";
	int ps=pow(2,m);
	cout<<"\n The power set is: ";
	cout<<"{";
	for(int i=0;i<ps;i++)
	{
		
		cout<<"{";
		for(int j=0;j<m;j++)
		{
		     if(i&(1<<j))
		     {
		     	cout<<A[j]<<" ";
		     }
		     
		     
		}
		cout<<"} ";
	}cout<<"}";
	cout<<"\n\nTHE SUBSET OF B: ";
	int us=pow(2,n);
	cout<<"\n The power set is: ";
	cout<<"{";
	for(int i=0;i<us;i++)
	{
		cout<<"{";
		for(int j=0;j<n;j++)
		{
		     if(i&(1<<j))
		     {
		     	cout<<B[j]<<" ";
		     }
		     
		}
		cout<<"} ";
	}cout<<"}";
}
void set::setdiff()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(A[i]==B[j])
			{
				for(int k=i;k<m;k++)
				{
					A[k]=A[k+1];
				}
				m--;
			}
		}
	}
	cout<<"\nA-B: ";
	for(int t=0;t<m;t++)
	{
		cout<<A[t]<<" ";
	}
}
void set::comp()
{

    Union();
	cout<<"\nComplement of A: ";
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(C[i]==A[j])
			{
			   for(int k=i;k<p;k++)
			   {
			   	C[k]=C[k+1];
			   }
			   p--;
		}
       }
     }
     for(int i=0;i<p;i++)
	 {
	 	cout<<C[i]<<" ";
	 }   
}
void set::symdiff()
{
	Union();
	Intersection();
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(C[i]==D[j])
			{
				for(int k=i;k<p;k++)
				{
					C[k]=C[k+1];
				}
				p--;
			}
		}
	}
	cout<<"\nThe symmetric difference is: ";
	for(int i=0;i<p;i++)
	{
		cout<<C[i]<<" ";
	}
	
}
void set::cart()
{
	cout<<"\nThe cartesian product is:{ ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
	  		cout<<"{"<<A[i]<<","<<B[j]<<"}";
		}
		

	}
	cout<<"}";
}
int main()
{
	char ch;
	do
	{
	
	set S;
	
	S.input();
	int c=S.menu();
	switch(c)
	{
		case 1:S.subset();
		       break;
		case 2:S.Union();
		       break;
		case 3:S.Intersection();
		       break;
		case 4:S.comp();
		       break;
		case 5:S.setdiff();
		       break;
		case 6:S.symdiff();
		      break;
		case 7:S.cart();
		     break;
		case 8:exit(0);
		       break;
		default:cout<<"\nWRONG CHOICE!!!";	    	   	   	   	   	   	          
	}
	
	cout<<"\nDO YOU WANT TO CONTINUE?(Y FOR YES): ";
	cin>>ch;
    }while(ch=='y'||ch=='Y');
	
	getch();
	return 0;
}
