#include <iostream>
#include <conio.h>
using namespace std;
class box
{
	public:
		float L,B,H;
		box()
		{
			L=B=H=0;
		}
		Box (const box & obj)
		{
			L=obj.L;
			B=obj.B;
			H=obj.H;
		}
		void input()
		{
			cout<<"\n Enter length of the box";
			cin>>L;
			cout<<"\n Enter breadth of the box";
			cin>>B;
			cout<<"\n Enter height of the box";
			cin>>H;
		}
		void display()
		{
			cout<<"\n Display object details";
			cout<<"\n Length is"<<L;
			cout<<"\n Breadth is"<<B;
			cout<<"\n Height is"<<H;
		}
		void calcSA()
		{
			double SA= 2* ((L*B)+(B*H)+(H*L));
			cout<<"\n Surface area is"<<SA;
		}
		void calcVol()
		{
			double Vol=L*B*H;
			cout<<"\n Volume is"<<Vol;
		}
		box & operator++()
		{
			L++;
			B++;
			H++;
			return (*this);
		}
	    box & operator -- ()
		{
			L--;
			B--;
			H--;
			return (*this);
		}
		const box & operator ++ (int)
		{
			const box ob(*this);
			L++;
			B++;
			H++;
			return (ob);
		}
		const box & operator -- (int)
		{
			const box ob(*this);
			L--;
			B--;
			H--;
			return (ob);
		}
		friend void operator == (const box & ob1, const box & ob2);
		box & operator= (const box & obj)
		{
			L=obj.L;
			B=obj.B;
			H=obj.H;
		}
		void check()
		{
			if (L==B && B==H && H==L)
			cout<<"\n It's a cube";
			else
			cout <<"\n It's a cuboid";
		}
};
void operator == (const box & ob1, const box & ob2)
{
	if ((ob1.L==ob2.L)&&(ob1.B==ob2.B)&&(ob1.H==ob2.H))
	cout<<"\n Both boxes have the same dimension";
	else
	cout<<"\n Both boxes have the same dimension";
}
int main()
{
	box b1,b2,b3,b4;
	cout<<"Input";
	b1.input();
	cout<<"\n Surface area";
	b1.calcSA();
	cout<<"Volume";
	b1.calcVol();
	cout<<"\n \nAssignment operator";
	b3=b1;
	b1.display();
	b3.display();
	cout<<"\n \n Checking equality";
	b3==b1;
	cout<<"\n \n Prefix increment";
	b2=++b1;
	b1.display();
	b2.display();
	cout<<"\n \n Postfix increment";
	b2=b1++;
	b1.display();
	b2.display();
	cout<<"\n \n Prefix decrement";
	b2=--b1;
	b1.display();
	b2.display();
	cout<<"\n \n Postfix decrement";
	b2=b1--;
	b1.display();
	b2.display();
	cout<<"\n \n Checking cube or cuboid";
	b1.check();
	getch();
	return 0;
}
