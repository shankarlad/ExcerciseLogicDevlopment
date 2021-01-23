#include <iostream>
using namespace std;

int main(){
	int a[] = {89, 34 ,50, 23, 100, 39,455};
	int l = sizeof(a)/sizeof(a[0]);
//	cout<<l;
	int max = a[0];
	for(int i=1;i<l;i++){
		if(max<a[i])
		max = a[i];
	}
	
	cout<<max;
}
