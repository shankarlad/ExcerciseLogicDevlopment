#include<iostream>
using namespace std;

bool isPowerOfTen(int n){
	
//	if(n % 10 != 0 || n == 0) {
//            return false;
//        }

        if (n == 10) {
            return true;
        }	
        
        return isPowerOfTen(n/10);
}

        
int main(){
	int n;
	cin>>n;
 	bool a = isPowerOfTen(n);
 	if(a){
 		cout<<"power of 10";
	 }else{
	 	cout<<"Not power of 10";
	 }
}
