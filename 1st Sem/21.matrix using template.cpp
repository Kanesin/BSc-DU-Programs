#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
template <class X>
class matrix
{
	public:
		int a,b,m,n;
		X A[20][20], B[20][20];
		void input()
		{
			cout<<"\n Enter the size of matrix A";
			cin>>a>>b;
			cout<<"\n Enter the elements of matrix A";
			for(int i=0; i<a; i++)
			{
				for (int j=0; j<b; j++)
				cin>>A[i][j];
			}
			cout<<"\n Enter the size of matrix B";
			cin>>m>>n;
			cout<<"\n Enter the elements of matrix B";
			for(int i=0; i<m; i++)
			{
	            for (int j=0; j<n; j++)
			    cin>>B[i][j];
			}
	}
		void sum()
		{
			X  C[20][20];
			int i;
			if (a==m && b==n)
			{
				for (i=0; i<m; i++)
				for (int j=0; j<n; j++)
				C[i][j]=A[i][j] + B[i][j];
			cout<<"\n Sum of the matrices";
			for (int i=0; i<m; i++)
			{
				for (int j=0; j<n; j++)
				{
					cout<< C[i][j]<<" ";
				}
				cout<<endl;
			}
		}
			else
			cout<<"\n ERROR";
	 
	    }
		void difference()
		{
			X C[20][20];
			if (a==m && b==n)
			{
				for (int i=0; i<m; i++)
				for (int j=0; j<n; j++)
				C[i][j]=A[i][j] - B[i][j];
			    cout<<"\n Difference of the matrices";
			    for (int i=0; i<a; i++)
			    {
				   for (int j=0; j<b; j++)
				{
					cout<< C[i][j]<<" ";
				}
				cout<<endl;
			}
		}
			else
			cout<<"\n ERROR";
		}
		void multi()
		{
			int i,j,k;
			X C[20][20];
			if (b==m)
			{
				for (i=0; i<a; i++)
				{
					for (j=0; j<n; j++)
					{
						C[i][j]=0;
						for (k=0; k<n; k++)
						C[i][j]+= A[i][k]*B[k][j];
					}
				}
				cout<<"\n Result";
				for (i=0; i<a; i++)
				{
					for (j=0; j<n; j++)
					{
						cout<<C[i][j]<<" ";
					}
					cout<<endl;
				}
			}
			else
			cout<<"\n ERROR";
	    }   
		void transpose ()
		{
		   cout<<"\n Transpose is";
		   for (int i=0; i<a; i++)
		   {
		   	for(int j=0; j<b; j++)
		   	{ 
		   	   cout<<A[j][i]<<" ";
			   }
			   cout<<endl;
		   }
	    }
};
int main()
{
	matrix <int> m;
	char ch;
	int c;
	do
	{
		cout<<"\n Enter the matrices";
		m.input();
		cout<<"\n MENU";
		cout<<"\n 1. Sum of the matrices";
		cout<<"\n 2. Difference of the matrices";
		cout<<"\n 3. Multiplication of the matrices";
		cout<<"\n 4. Transpose of the matrices";
		cout<<"\n Enter your choice";
		cin>>c;
		switch (c)
		{
			case 1: m.sum();
			break;
			case 2: m.difference();
			break;
			case 3: m.multi();
			break;
			case 4: m.transpose();
			break;
			default: cout<<"\n Wrong choice";
		}
		cout<<"\n Want to continue ( y for yes)";
		cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	getch();
	return 0;
}
