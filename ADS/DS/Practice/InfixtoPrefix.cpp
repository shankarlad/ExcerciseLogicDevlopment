#include<iostream>
#include<stack>
using namespace std;


bool isAlphabet(char c){
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') ? true : false;
}

bool isOperator(char c){
	return (c == '+' || c == '-' || c == '/' || c == '*') ? true : false; 
}

int prec(char c){
	if(c == '*' || c == '/')
		return 2;
		
	else if(c == '+' || c == '-')
		return 1;
	
	else return 0;
}

string reverse(string s){
	string rev;
	for(int i=s.length()-1; i>=0; i--){
		rev+=s[i];
	}
	return rev;
}

string InfixToPrefix(string infix){
	string prefix;
	char c;
	stack<char> s;
	
	for(int i=(infix.length()-1);i>=0;i--){
		c = infix[i];
		
		if(isAlphabet(c))
			prefix+=c;
		
		else if(c == ')')
			s.push(c);
		
		else if(isOperator(c)){
			if(s.empty())
				s.push(c);
			
			else{
				if(prec(c) >= prec(s.top()))
					s.push(c);
				
				else{
					while(prec(c) < prec(s.top()) && !s.empty()){
						char ch = s.top();
						prefix+=ch;
						s.pop();
					}
					s.push(c);
				}
			}

		}
		else if(c == '('){
			while(s.top() != ')' && !s.empty()){
				char ch = s.top();
				prefix+=ch;
				s.pop();
			}
			if(s.top() == ')')
				s.pop();
		}
	}
	
	while(!s.empty()){
        prefix+=s.top();
        s.pop();
    }
	
	
	
	return reverse(prefix);
	
}

int main(){
	string infix;
	cout<<"Enter a infix expression"<<endl;
	cin>>infix;
	
	string prefix = InfixToPrefix(infix);
	
	cout<<"Postfix is:  "<<prefix;
	return 0;
}



