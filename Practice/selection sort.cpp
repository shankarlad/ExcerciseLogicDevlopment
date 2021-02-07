// Selection Sort Algorithm //

#include<iostream>
using namespace std;

int swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int selectionSort(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		
		int min = i;
		
		for (int j = i+1; j < n; j++) {
			
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		
		if (min != i){

			swap(&arr[min],&arr[i]);
		}
	}
}

int main() {
	
	int n;
	cout << "Please Enter the Number of element : ";
	cin >> n;
	
	int arr[n];
	cout << "Enter the array elements : ";
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << endl;
	cout << "Unsorted array is : ";
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	selectionSort(arr,n);
	cout << "Sorted array is : ";
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}
