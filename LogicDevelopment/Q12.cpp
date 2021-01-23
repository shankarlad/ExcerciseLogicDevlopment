#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int rev=0,digit;
	int n;
	cin>>n;
	int temp = n;
	while(n!=0){
		digit = n%10;
		rev = rev*10 + digit;
		n=n/10;
	}
	
	if(temp == rev){
		cout<<"palindrome";
	}else{
		cout<<"Not Palindrome";
	}
	
	char string1[20];
    int i, length;
    int flag = 0;
    
	cout << "Enter a string: "; 
	cin >> string1;
    
    length = strlen(string1);
    
    for(i=0;i < length ;i++){
        if(string1[i] != string1[length-i-1]){
            flag = 1;
            break;
   }
	 
    if (flag) {
        cout << string1 << " is not a palindrome" << endl; 
    }    
    else {
        cout << string1 << " is a palindrome" << endl; 
    }
    system("pause");
	
	return 0;
}
}
