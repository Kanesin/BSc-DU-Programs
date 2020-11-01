#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Bin
{
	public:
		int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x)   
            return mid; 
        if (arr[mid] > x)  
            return binarySearch(arr, l, mid-1, x); 
        return binarySearch(arr, mid+1, r, x); 
   } 
   return -1; 
};
int main() 
{
	Bin b;
	int n;
	cout <<"Enter the size of an array \n";
	cin >> n;
	int arr[n],x;
	cout <<"Enter the sorted values \n";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout <<"Enter a value to be searched\n";
	cin>>x;
	int res=b.binarySearch(arr, 0, n-1, x);
	if(res==1)
		cout<<"\nValue Found\n "<<res;
	else 
		cout<<"\nValue not found\n ";
	return 0;
}
