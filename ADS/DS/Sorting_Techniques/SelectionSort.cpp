#include<iostream>
using namespace std;

void print(int *arr, int size){
	for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void selectionSort(int *arr, int size){
	int i,j,min,pos;
	for(i = 0 ; i<size-1;i++){
		min = arr[i];
		pos = i;
		for(j=i+1;j<size;j++){
			if(arr[j]<min){
				min = arr[j];
				pos = j;
			}
		}
		arr[pos] = arr[i];
		arr[i] = min;
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
	selectionSort(arr,size);
	print(arr,size);
}


