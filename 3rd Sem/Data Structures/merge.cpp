#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
class prac
{	
	private:
	int Arr[20],sArr,p;
	void input()
	{
		cout<<"\nEnter Size of Array \n";
		cin>>sArr;
		cout<<"Enter Array values\n";
		for(int i=0;i<sArr;i++)
			cin>>Arr[i];
			p=0;
	}			
	
	void merge(int arr[], int l, int m, int r) 
	{ 
	    int i, j, k; 
	    int n1 = m - l + 1; 
	    int n2 =  r - m; 
	    int L[n1], R[n2]; 
	    for (i = 0; i < n1; i++) 
	        L[i] = arr[l + i]; 
	    for (j = 0; j < n2; j++) 
	        R[j] = arr[m + 1+ j]; 
	    i = 0;
	    j = 0;
	    k = l; 
	    while (i < n1 && j < n2) 
	    { 
	        if (L[i] <= R[j]) 
	            arr[k++] = L[i++]; 	            
	        else
	            arr[k++] = R[j++]; 
	    } 
	    while (i < n1) 
	        arr[k++] = L[i++]; 
	    while (j < n2) 
	        arr[k++] = R[j++]; 
	} 

	void mergeSort(int arr[], int l, int r) 
	{ 
	    if (l < r) 
	    { 
	        int m = (l+r)/2;
	        mergeSort(arr, l, m);
	        mergeSort(arr, m+1, r);
	        cout<<"\nPass: "<<++p<<" ";
	        print();
	        merge(arr, l, m, r);
	    } 
	} 
	
	void print()
	{	cout<<endl;
		for(int i=0;i<sArr;i++)
		{
			cout<<Arr[i]<<"\t";
		}
	}
	
	public:
	void prog()
	{	
	while(true)
	{
		input();
		mergeSort(Arr,0,sArr);
		cout<<"\nFinal Array: ";
		print();
	}
	}
};
int main()
{
	prac p;
	p.prog();
}
