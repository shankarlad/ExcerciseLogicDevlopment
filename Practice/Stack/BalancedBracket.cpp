#include<iostream>
using namespace std;
#include<stack>

bool isBalanced(string s){
	stack<char> Stack;
	for(int i=0;i<s.length();i++){
		char c= s[i];
		
		if(c=='(' || c == '{' || c == '[')
			Stack.push(c);
		else{
			if(c==')'){
				if(Stack.empty() || Stack.top() != '(')
					return false;
				else Stack.pop();
			}
			else if(c=='}'){
				if(Stack.empty() || Stack.top() != '{')
					return false;
				else Stack.pop();
			}
			else if(c==']'){
				if(Stack.empty() || Stack.top() != '[')
					return false;
				else Stack.pop();
			}
			
		}
	}
	
	if(!Stack.empty())
		return false;
	else 
		return true;
}

int main(){
	cout<<"Enter an expression"<<endl;
	string exp;
	
	cin>>exp;
	
	if(isBalanced(exp))
		cout<<"Balanced"<<endl;
	else
		cout<<" Not Balanced"<<endl;
	return 0;
}

