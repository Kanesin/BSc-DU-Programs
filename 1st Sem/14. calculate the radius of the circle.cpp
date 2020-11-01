#include <iostream>
#include <conio.h>
using namespace std;
class circle
{
   public:
   	float area (float r)
   	{
   		float a= 3.14*r*r;
   		return a;
	   }
	   float circum(float r)
	   {
	   	float c= 3.14*2*r;
   		return c;
	   }
};
int main ()
{
	circle C; float r;
	cout<<"\n Enter the radius of the circle";
	cin>>r;
	cout<<"\n Area"<<C.area(r);
	cout<<"\n Circumference"<<C.circum(r);
	getch ();
	return 0;
}


