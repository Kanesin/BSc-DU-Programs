#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class hamming
{
    public:
    	 int data[10],datar[10];
    int  parity()
    {
    int m;
    cout<<"Enter number of bits for i/p message"<<endl;
    cin>>m;
    for(int i=1;i<=5;i++)
    {
        if(pow(2,i)>=m+i+1)
        {
            return i;
            break;
        }
    }
    cout<<endl;
}
    void even()
    {
       
    cout<<"Enter 4 bits of data one by one\n"<<endl;
    cin>>data[3];
    cin>>data[5];
    cin>>data[6];
    cin>>data[7];
 
    //Calculation of even parity
    data[1]=data[3]^data[5]^data[7];
    data[2]=data[3]^data[6]^data[7];
    data[4]=data[5]^data[6]^data[7];
 
    cout<<"\nEncoded data is\n";
    for(int i=1;i<8;i++)
    cout<<data[i];


}
void recieved()
{
	int c1,c2,c3,c;
	cout<<"\nenter the recieved data";
	for(int i=1;i<8;i++)
	{
		cin>>datar[i];
	}
	c1=datar[1]^datar[3]^datar[5]^datar[7];
	c2=datar[2]^datar[3]^datar[6]^datar[7];
	c3=datar[4]^datar[5]^datar[6]^datar[7];
	c=c1+c2*2+c3*4;
	cout<<"\nerror is in bit "<<c;

	datar[c]=!(datar[c]);
		cout<<"\ncorrected data is ";
		for(int i=1;i<8;i++)
	{
		cout<<datar[i];
	}
}
};
int main()
{
    hamming ob;
    int res=ob.parity();
    cout<<"No of bits"<<res<<endl;
    ob.even();
    ob.recieved();
    getch();
    return 0;
}
