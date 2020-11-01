#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class bin
{
	public:
		int n,mid,x;
		int A[20];
		void input()
		{
			cout<<"\nEnter the size of the array: ";
			cin>>n;
			
			cout<<"\nEnter the elements of the array(must be sorted): ";
			for(int i=0;i<n;i++)
			{
				cin>>A[i];
			}
			
		}
		int check()
		{
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(A[i]>A[j])
					{
		
				        return -1;
						
					}
				}
			}
		}
		void sear()
		{
			cout<<"\nEnter the element to be searched: ";
			cin>>x;
			
		}
		int sea(int A[],int first,int last)
		{
			if(first>last)
			return -1;
		    
			 mid=(first+last)/2;
			
			if(A[mid]==x)
			return mid;
			
			else if(A[mid]>x)
            {
             	
               return 	sea(A,first,mid-1);
            }
			else
			{
		    	
		       return sea(A,mid+1,last);
		    }
		}
		
};
int main()
{
	bin B;
	int c,i,j,f=0;
	char ch;
	do
	{
		
	cout<<"\nMENU";
	cout<<"\n1.BINARY SEARCH";
	cout<<"\n2.EXIT";
	cout<<"\nEnter your choice: ";
	cin>>c;
	if(c==1)
	{
	B.input();
	B.check();
	if(B.check()==-1)
	{
		cout<<"\n Invalid Input";
		cout<<"\nEnter valid input";
	  B.input();
	
	}
	B.sear();
    int i=B.sea(B.A,0,B.n-1);
	if(i==-1)
	cout<<"\nElement not found";
	else
	cout<<"\nElement found at  position: "<<i+1;
    }
    
    else if(c==2)
    {
    	exit(0);
    }
    else
    cout<<"\nWrong choice!!!";
    cout<<"\nDo you wanna continue?(y for yes): ";
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    
	getch();
	return 0;
}

