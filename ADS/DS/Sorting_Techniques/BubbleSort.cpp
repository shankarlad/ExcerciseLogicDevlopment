#include<iostream>
using namespace std;

void print(int *arr, int size){
	for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void bubbleSort(int *arr, int size){
	int i,j,temp;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
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
	bubbleSort(arr,size);
	print(arr,size);
}


