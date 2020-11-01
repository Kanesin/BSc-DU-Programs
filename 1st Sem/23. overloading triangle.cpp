#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
class Triangle
{ 
    public:
    	double area;
    	float s1, s2, s3, h;
    	Triangle()
    	{
    		s1=s2=s3=h=area=0;
		}
		Triangle (float x)
		{
			s1=x;
			s2=s3=h=0;
			calcarea(1);
		}
		Triangle (float x, float y)
		{
			s1=x;
			h=y;
			s3=s2=0;
			calcarea(1,2);
		}
		Triangle (float x, float y, float z)
		{
		 if((x+y)>=z && (x+z)>=y && (z+y)>=x)
		{
			s1=x;
			s2=y;
			s3=z;
			h=0;
			calcarea(1,2,3);
		}
		else
		area=0;
	}
	void calcarea(int)
	{
		area=sqrt(3)*s1*s1/4;
	}
	void calcarea(int, int)
	{
		area=(s1*h)/2;
	}
	void calcarea(int, int, int)
	{
		float p=(s1+s2+s3)/2;
		double q = p* (p-s1)* (p-s2)* (p-s3);
		area= sqrt (q);
	}
	void display()
	{
		if (area!=0)
		cout<<"\n Area of triangle"<<area;
		else
		cout<<"\n Error, triangle can't be formed";
	}
	Triangle & operator= (const Triangle&ob)
	{
		area=ob.area;
		s1=ob.s1;
		s2=ob.s2;
		s3=ob.s3;
		h=ob.h;
	    return (*this);
	}
	void operator==(const Triangle&ob)
	{
		if ((area==ob.area)&&(s2=ob.s2)&&(s3=ob.s3)&&(h=ob.h))
	    cout<<"\n Both triangles are congruent";
	    else
	    cout<<"\n The triangles are not congruent";
	}
};
int main()
{
	Triangle T, T1(4), T2(6.8,4),T3(5,6,4);
	T.display();
	T1.display();
	T2.display();
	T3.display();
	T=T2;
	T.display();
	T==T2;
	getch();
	return 0;
}
