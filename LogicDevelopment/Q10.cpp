#include<iostream>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a>b && a>c){
		cout<<"First one is greater";
	}else if(b>a && b>c){
		cout<<"second one is greater";
	}else{
		cout<<"Third one is greater";
	}
	return 0;
}
