#include <iostream>
#include <conio.h>
using namespace std;
class fun
{
	int *A, size;
	public:
		void input()
	{
		cout << "Enter size of array";
		cin >> size;
		A = new int[size];
		for(int i=0;i<size;i++)
			cin >> A[i];		
	}	
	void bubbleSort()
	{
		int temp;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size-i-1;j++)
			{
				if(A[j+1]<A[j]){				
					temp=A[j+1];
					A[j+1]=A[j];
					A[j]=temp;
				}
				
			}
		}	
	}
	void insertionSort(){
		for(int i=1;i<size;i++){
			int key = A[i], j = i-1;
			while(j>=0 && key<A[j]){
				A[j+1]=A[j];
				j--;
			}
			A[j+1]=key;
		}
	}
	void selectionSort(){
		for(int i=0;i<size;i++){
			int min = i;
			for(int j=i+1;j<size;j++){
				if(A[j]<A[min])
					min = j;
			}
			int temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
	}
	void linear(int ele)
	{
		int i;
		cout<<"\n Element found at the position:";
		for (i=0; i<size; i++)
		{
			if (ele==A[i])
			{
				cout<<i+1;
			}
		}
	}
	void binary(int ele)
	{
	 	int first=0,last=size-1;
		int mid,pos,f=0;
		while(first<last)
		{
			mid=(first+last)/2;
			if(A[mid]==ele)
			{
				f=1;
				pos=mid;
		    	break;
			}
			else if(A[mid]>ele)
			last--;
			else
			first++;
		}
		if(f==1)
		cout<<"\n Element found at position: "<<pos+1; 
	}
	void display()
	{
		int i;
		cout<<"\n Values invoked are:";
		for(i=0;i<size;i++)
		{
			cout<<A[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	fun f;
	f.input();
	int choice,ele;
	char ch;
	do
	{
		cout<<"MENU: \n1.Linear Search \n2.Binary Search \n3.Bubble Sort \n4.Insertion Sort \n5.Selection sort \n6.Exit\nEnter Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"\n Enter the element to be searched:";
				   cin>>ele;
				   f.linear(ele);
				   break;
			case 2:cout<<"\n Enter the element to be searched:";
				   cin>>ele;
				   f.binary(ele);
				   break;
			case 3: f.bubbleSort();
					f.display();
					break;
			case 4: f.insertionSort();
					f.display();
					break;
			case 5: f.selectionSort();
					f.display();
					break;
			default:cout<<"\n Invalid Input!";
		}
		cout<<"\nDo you want to continue(Y/N)?: ";
		cin>>ch;
	}
	while(ch=='Y'||ch=='y');
	getch();
	return 0;
}

