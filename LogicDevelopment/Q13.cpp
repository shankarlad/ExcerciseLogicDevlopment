#include<iostream>
using namespace std;

int main(){
	int n,r;
	bool flag = false;
	cout<<"Enter number :";
	cin>>n;
	for(int i=2;i<=n/2;i++){
		r = n%i;
		if(r==0){
			flag = true;
		}
	}
	if(!flag)
		cout<<"Prime"<<endl;
	else
		cout<<"Not Prime"<<endl;
	return 0;
}

