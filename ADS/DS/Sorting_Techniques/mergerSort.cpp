#include<iostream>
using namespace std;
int size;
void print(int *arr, int size){
	for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void merger(int *arr,int start,int mid,int end){
	int temp[size];
	int i = start;
	int j = mid+1;
	int ti = start;
	while(i<=mid && j<=end){
		if(arr[i]<arr[j])
		temp[ti++] = arr[i++];
		else
		temp[ti++] = arr[j++];
	}
	while(i<=mid){
		temp[ti++] = arr[i++];
	}
	while(j<=end){
		temp[ti++] = arr[j++];
	}
	for(int k=start;k<=end;k++){
		arr[k] = temp[k];
	}
}

void mergeSort(int *arr,int start,int end){
	int mid;
	if(start<end){
		mid = (start+end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merger(arr,start,mid,end);
	}
	
}

int main(){
	int *arr;
	cout<<"Enter Size\n";
	cin>>size;
	cout<<"Enter "<<size<<" elements\n";
	arr = new int[size];
	for(int i=0;i<size;i++)
	cin>>arr[i];
	print(arr,size);
	mergeSort(arr,0,size-1);
	print(arr,size);
}


