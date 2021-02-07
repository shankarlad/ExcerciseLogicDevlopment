// Bubble Sort //

#include<iostream>
using namespace std;

int swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void bubbleSort(int arr[], int n) {
	
	for (int i = 0; i < n-1; i++) {
		
		for (int j = 0; j < n-i-1; j++) {
			
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
			}
		}
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
	bubbleSort(arr, n);
	
	cout << "Sorted array is : ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}
