#include<iostream>
#include<conio.h>

using namespace std;

class truth
{
	int x[2],y[2],i,j;
	public:
		void conjunction()
		{
			cout<<"\nConjunction\n";
			cout<<"x y x&y"<<endl;
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{ 
				   cout<<i<<" "<<j<<" ";
				   if(i&&j)cout<<"1";
				   else
				   cout<<"0";
				   cout<<endl;	
				}
			}
		}
		
		void disjunction()
		{
			cout<<"\nDisjunction\n";
			cout<<"x y x|y\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					cout<<i<<" "<<j<<" ";
					if(i||j)
					cout<<"1";
					else
					cout<<"0";
					cout<<endl;
				}
			}
		}
		void negation()
		{
			cout<<"\nNegation\n";
			cout<<"x x'\n";
			for(i=0;i<2;i++)
				cout<<i<<" "<<(!i)<<endl;
		}
		void nand()
		{
			cout<<"\nNAND\n";
			cout<<"x y (x^y)'\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					cout<<i<<" "<<j<<" "<<!(i&&j)<<"\n";
				}
			}
			
		}
		void nor()
		{
			cout<<"\nNOR\n";
			cout<<"x y (xVy)'\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					cout<<i<<" "<<j<<" "<<!(i||j)<<"\n";
					
				}
			}
			
		}
		void conditional()
		{
			cout<<"\nConditional\n";
			cout<<"x y (x->y)\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					cout<<i<<" "<<j<<" ";
					if(i==0)cout<<"1\n";
					if(i==1&&j==1)cout<<"1\n";
					if(i==1&&j==0)cout<<"0\n";
				}
			}
			
		}
		void biconditional()
		{
			cout<<"\nBiconditional\n";
			cout<<"x y (x<->y)\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					cout<<i<<" "<<j<<" ";
					if(i==j)cout<<"1\n";
					else
					cout<<"0\n";
				}
			}
		}
		void Xor()
		{
			cout<<"\nXOR\n";
			cout<<"x y (x^y)\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					/*cout<<i<<" "<<j<<" ";
					if(i!=j)cout<<"1\n";
					else
					cout<<"0\n";*/
					cout<<i<<" "<<j<<" "<<(i^j)<<"\n";
				}
			}
	    }
	    void Xnor()
	    {
	    	cout<<"\nXNOR\n";
	    	cout<<"x y (x^y)'\n";
	    	for(i=0;i<2;i++)
	    	{
	    		for(j=0;j<2;j++)
	    		{
	    			cout<<i<<" "<<j<<" "<<!(i^j)<<"\n";
	    			
	    		}
	    	}
	    }
};
int main()
{
	truth T;
	int ch;
	char a;
	do
	{
	
	cout<<"\tMenu\n1 T.conjunction()\n2 T.disjunction()\n3 T.negation()\n4 T.nand()\n5 T.nor()\n6 T.conditional()\n7 T.biconditional()\n8 T.Xor()\n9 T.Xnor()";
	cout<<"\nEnter your choice\n";
	cin>>ch;

	switch(ch)
{
	
		case 1:
	 T.conjunction();
	 break;
	 case 2:
	 T.disjunction();
	 break;
	 case 3:
	 T.negation();
	 break;
	 case 4:
	 T.nand();
	 break;
	 case 5:
	 T.nor();
	 break;
	 case 6:
	 T.conditional();
	 break;
	 case 7:
	 T.biconditional();
	 break;
	 case 8:
	 T.Xor();
	 break;
	 case 9:
	 T.Xnor();
	 break;
	 default:
		cout<<"Wrong choice\n";
		
	}
	cout<<"\nWant to enter more\n";
	cin>>a;
}while(a=='y'||a=='Y');
	getch();
	return 0;
}
