#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class matrix_common{
	
	protected:
	int sA;	
	int *A;
	int rows,cols;
	public:	
	int getRow()
	{
		return rows;
	}
	int getCol()
	{
		return cols;
	}
	virtual void setValue(int i,int j,int val){	};
	virtual int getValue(int i,int j){	};
		void display()
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
					cout<<getValue(i,j)<<"\t";
			cout<<"\n";
		}
	}		
};
class diagonalMatrix:public matrix_common{
	
	public:
	diagonalMatrix(int r,int c)
	{
		if(r!=c)
			throw "Not a square matrix";
		else
		{
			rows=cols=r;
			sA=r;
			A=new int[sA];
			for(int i=0;i<sA;i++)
				A[i]=0;
		}
	}
	
	void setValue(int i,int j,int val)
	{
		if((i<0)||(j<0)||(i>rows-1)||(j>rows-1))
			throw "Invalid indexes";
		else
		{
			if(i==j)
				A[i]=val;
			else
			{
				if(val!=0)
					throw "for diagnal sparse matrix non diagnal elements should be 0";
			}
		}
	}
	
	int getValue(int i,int j)
	{
		if((i<0)||(j<0)||(i>rows-1)||(j>rows-1))
			throw "Invalid indexes";
		else
		{
			if(i!=j)
				return 0;
			else
				return A[i];
		}
	}
};

class lowertriangleMatrix:public matrix_common{
	public:
	lowertriangleMatrix(int r,int c)
	{
		if(r!=c)
			throw "Not a square matrix";
		else
		{
			rows=cols=r;
			sA=(r*(r+1))/2;
			A=new int[sA];
			for(int i=0;i<sA;i++)
			A[i]=0;
		}
	}
	
	void setValue(int i,int j,int val)
	{
		if((i<0)||(j<0)||(i>rows-1)||(j>rows-1))
			throw "Invalid indexes";
		else
		{
			if(i>=j)
				A[(i*(i+1)/2)+j]=val;
			else
			{
				if(val!=0)
					throw "for lower triangle sparse matrix upper triangle elements should be 0";
			}
		}
	}
	
	int getValue(int i,int j)
	{
		if((i<0)||(j<0)||(i>rows-1)||(j>rows-1))
			throw "Invalid indexes";
		else
		{
			if(i<j)
				return 0;
			else
				return A[(i*(i+1)/2)+j];
		}
	}
};

class symmetricMatrix:public matrix_common{
	public:
	symmetricMatrix(int r,int c)
	{
		if(r!=c)
			throw "Not a square matrix";
		else
		{
			rows=cols=r;
			sA=(r*(r+1))/2;
			A=new int[sA];
			for(int i=0;i<sA;i++)
			A[i]=0;
		}
	}
	
	void setValue(int i,int j,int val)
	{
		if((i<0)||(j<0)||(i>rows-1)||(j>rows-1))
			throw "Invalid indexes";
		else
		{
			if(i>=j)
				A[(i*(i+1)/2)+j]=val;			
			else
				A[(j*(j+1)/2)+i]=val;			
		}
	}
	
	int getValue(int i,int j)
	{
		if((i<0)||(j<0)||(i>rows-1)||(j>rows-1))
			throw "Invalid indexes";
		else
		{
			if(i<j)
				return A[(j*(j+1)/2)+i];
			else
				return A[(i*(i+1)/2)+j];
		}
	}
};

class uppertriangleMatrix:public matrix_common{
	public:
	uppertriangleMatrix(int r,int c)
	{
		if(r!=c)
			throw "Not a square matrix";
		else
		{
			rows=cols=r;
			sA=(r*(r+1))/2;
			A=new int[sA];
			for(int i=0;i<sA;i++)
			A[i]=0;
		}
	}
	
	void setValue(int i,int j,int val)
	{
		if((i<0)||(j<0)||(i>rows-1)||(j>rows-1))
			throw "Invalid indexes";
		else
		{
			if(i<=j)
				A[(j*(j+1)/2)+i]=val;
			else
			{
				if(val!=0)
					throw "for upper triangle sparse matrix lower triangle elements should be 0";
			}
		}
	}
	
	int getValue(int i,int j)
	{
		if((i<0)||(j<0)||(i>rows-1)||(j>rows-1))
			throw "Invalid indexes";
		else
		{
			if(i>j)
				return 0;
			else
				return A[(j*(j+1)/2)+i];
		}
	}
};

class matrixMenu
{
	public:
	matrix_common *ob;
	int menu1()
	{
		cout<<"\nMENU 1\n";
		cout<<"1. Diagonal Matrix\n";
		cout<<"2. Lower Triangle Matrix \n";
		cout<<"3. Upper Triangle Matrix\n";
		cout<<"4. Symmetric Matrix\n";
		cout<<"5. Exit\n";
		int ch;
		cin>>ch;
		return ch;
	}
	
	int menu2()
	{
		cout<<"\nMENU 2\n";
		cout<<"1. Re-/Insert All Data\n";
		cout<<"2. Insert Individual Element\n";
		cout<<"3. View All Data\n";
		cout<<"4. View Individual Element\n";
		cout<<"5. Exit\n";
		int ch;
		cin>>ch;
		return ch;
	}
	
	void prog1()
	{		
		int ch,r,c;
		while(true)
		{
			ch=menu1();
			cout<<"\nEnter  no. of rows: ";
			cin>>r;			
			cout<<"Enter no. of cols: ";
			cin>>c;
			diagonalMatrix M1(r,c);	
			uppertriangleMatrix M3(r,c);	
			lowertriangleMatrix M2(r,c);	
			symmetricMatrix M4(r,c);	
			switch(ch)
			{
				case 1: ob=&M1;					
				break;
				case 2: ob=&M2;
				break;
				case 3: ob=&M3;
				break;
				case 4: ob=&M4;
				break;
				default: exit(0);				
			}
			prog2();
		}
	}
	
	void prog2()
	{
		int ch2;
		int r=ob->getRow(),c=ob->getCol();
		int data;
		int e1,e2;
		int tf=1;		
		while(tf)
		{
			ch2=menu2();
			try
			{
				switch(ch2)
				{
					case 1: 
							cout<<"Enter Values:\n";
							for(int i=0;i<r;i++)
							{
								for(int j=0;j<c;j++)
								{
									cout<<"("<<i+1<<","<<j+1<<")=";
									cin>>data;
									ob->setValue(i,j,data);
								}									
							}	
					break;
					case 2:  
							cout<<"\nEnter Row index:";
							cin>>e1;	
							cout<<"\nEnter Column index:";
							cin>>e2;
							cout<<"\nEnter Value:";
							cin>>data;
							ob->setValue(e1-1,e2-1,data);						
					break;
					case 3: ob->display();
					break;
					case 4: 
							cout<<"\nEnter Row index:";
							cin>>e1;	
							cout<<"\nEnter Column index:";
							cin>>e2;
							cout<<ob->getValue(e1-1,e2-1);
					break;
					default: tf=0;
				}
			}
			catch(const char*c)
			{
				cout<<c;
			}												
		}		
	}	
};

int main()
{
	matrixMenu m;
	m.prog1();	
	getch();	
}
