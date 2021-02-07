// Quick Sort //


#include<iostream>
using namespace std;

int swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[],int s, int e) {
	
	int pivote = arr[e];
	int pIndex = s;
	
	for (int i = s; i < e; i++) {
		
		if(arr[i] < pivote ) {
			
			swap(&arr[i], &arr[pIndex]);
			pIndex++;
		}
	}
	
	swap(&arr[e], &arr[pIndex]);
	
	return pIndex;
}

int quickSort(int arr[], int s, int e) {
	
	if (s < e) {
		
		int p = partition(arr, s, e);
		
		quickSort(arr, s, p-1);
		
		quickSort(arr, p + 1, e);
	}
}

int main() {
	
	int n;
	cout << "Enter the Number of elements : ";
	cin >> n;
	
	int arr[n];
	cout << "Enter the array elements : ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	cout << "Unsorted array is : ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout<<endl;
	quickSort(arr, 0 ,n-1);
	
	cout << "Sorted array is : ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}
