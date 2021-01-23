#include<iostream>
using namespace std;

int main(){
	int a,b,temp;
	cout<<"Enter two numbers"<<endl;
	cin>>a>>b;
	
	cout<<"before Swap a = "<<a<<" b = "<<b<<endl;
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	cout<<"After Swap a = "<<a<<" b = "<<b<<endl;
}
