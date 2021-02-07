// Insertion Sort //

#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
	
	int i,j,key;
	
	for (i = 1; i < n; i++) {
		
		key = arr[i];
		j = i-1;
		
		while (j >= 0 && arr[j] > key) {
			
			arr[j+1] = arr[j];
			j = j-1;
		}
		
		arr[j+1] = key;
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
	insertionSort(arr, n);
	
	cout << "Sorted array is : ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}
