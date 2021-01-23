#include<iostream>
using namespace std;
int main(){
	int n,rem,num=0;
	
	cin>>n;
	int temp = n;
	for(int i=0;i<=n;i++){
		while(i!=0){
		rem = n%10;
		num = num + rem*rem*rem;
		n = n/10;
	}
	}

	
	if(num == temp)
		cout<<"Armstrong";
	else
		cout<<"Not a Armstrong";
		
		return 0;
}
