#include<iostream>
using namespace std;

void print(int *arr, int size){
	for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void insertionSort(int *a, int size){
	int i,j,key;
	for(i = 1 ; i<size;i++){ //start loop from index 1;
		key = a[i];  // elemet at that index will be assumed as minimum(key)
		j = i-1;     // place j, one step behind.
		while(j>=0 && key<a[j]){  // if key < elment where j is pointing and j>=0
			a[j+1] = a[j];		// right shift till key < that element 
			j--;
		}
		a[j+1] = key; //now place key element at the index where the while loop stopped.
	}
	
}

int main(){
	int *arr, size;
	cout<<"Enter Size\n";
	cin>>size;
	cout<<"Enter "<<size<<" elements\n";
	arr = new int[size];
	for(int i=0;i<size;i++)
	cin>>arr[i];
	print(arr,size);
	insertionSort(arr,size);
	print(arr,size);
}


