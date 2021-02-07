#include<iostream>
#include<stack>
using namespace std;

void binary(int num){
	stack<int> s;
	int q, r;
	
	do{
		q = num / 2;
		r = num % 2;
		s.push(r);
		num = q;
	}while(q!=0);
	
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
	
}

int main(){
	int dec;
	cout<<"Enter a number"<<endl;
	
	cin>>dec;
	
	binary(dec);
	return 0;
}
