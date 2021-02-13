#include<bits/stdc++.h>
using namespace std;
 
void printRepeating(int arr[], int size)
{
    int i, j;
    printf(" Repeating elements are ");
    for(i = 0; i < size; i++)
        for(j = i + 1; j < size; j++)
        if(arr[i] == arr[j])
            cout << arr[i] << " ";
} 
 
// Driver Code
int main()
{
    int n;
    cout<<"Enter No of array elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elemtents: "<<endl;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    printRepeating(arr, arr_size);
}

