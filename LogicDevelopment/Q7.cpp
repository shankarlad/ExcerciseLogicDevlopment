#include<iostream>
using namespace std;

int main(){
	int a,b,temp;
	cout<<"Enter two numbers"<<endl;
	cin>>a>>b;
	
	cout<<"before Swap a = "<<a<<" b = "<<b<<endl;
	
	temp = a;
	a = b;
	b = temp;

	cout<<"After Swap a = "<<a<<" b = "<<b<<endl;	
}
