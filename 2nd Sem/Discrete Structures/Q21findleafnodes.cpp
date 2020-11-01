#include<iostream>
#include<conio.h>
using namespace std;
class leaf
{
	int m,l,i;
	public:
		void find()
		{
			cout<<"\nEnter the type of tree(binary or ternary or else) or enter the value of m:";
			cin>>m;
			cout<<"\nEnter the number of internal vertices:";
			cin>>i;
			l=(m-1)*i + 1;
			cout<<"\nThe number of leaf nodes is:"<<l;
		}
};
int main()
{
	leaf L;
	L.find();
	getch();
	return 0;
}
