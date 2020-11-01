#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main(int argc char*argv[])
{
	ifstream input;
	ofstream output;
	input.open(argv[1],ios::in);
	string line;
	output.open(argv[2],ios::out);
	if(input.is_open()&&output.is_open())
	{
		while(getLine(argv[1],line))
			cout<<line<<"\n";
		input.close();
		output.close();
	}
	else
		cout<<"Unable to open files";	
}
