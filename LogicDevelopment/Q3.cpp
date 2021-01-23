#include<iostream>
using namespace std;

int main(){
	int n,fact=1;
	
	cout<<"Enter number :";
	cin>>n;
	do{
		fact = fact*n;
		n--;
	}while(n>0);
	
	cout<<fact;
	return 0;
}
