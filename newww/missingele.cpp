#include<iostream>
using namespace std;

int main(){
	int a[10] = {1,2,4,5,6,7,8,9,10};
	
	int totalEle = sizeof(a)/sizeof(a[0]);
	
//	cout<<totalEle;
	int sumOfArrayEle = (totalEle*totalEle + totalEle)/2;
	
	int sum = 0;
	for(int i=0;i<totalEle;i++){
		sum+=a[i];
	}
	
	int missingEle = sumOfArrayEle - sum;
	cout<<"Missing Element = "<<missingEle<<endl;
}
