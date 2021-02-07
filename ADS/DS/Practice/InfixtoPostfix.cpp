#include<iostream>
#include<stack>
using namespace std;


bool isAlphabet(char c){
	if((c >='A' && c<='Z') || (c >='a' && c<='z'))
	return true;
	else return false;
}

bool isOperator(char c){
	if(c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	else return false;
}

int prec(char c){
	if(c == '*' || c=='/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
		
	else return 0;
}

string InfixToPostfix(string infix){
	stack<char> s;
	string postfix;
	char c;
	for(int i=0; i<infix.length();i++){
		c = infix[i];
		
		if(isAlphabet(c))
			postfix+=c;
			
		else if(c == '(')
			s.push(c);
		
		else if(isOperator(c)){
			if(s.empty())
				s.push(c);
			
			else{
				if(prec(c) > prec(s.top())){
					s.push(c);
				}
				
				else{
					while(prec(c)<= prec(s.top()) && !s.empty()){
						char ch = s.top();
						postfix+=ch;
						s.pop();
					}
					
					s.push(c);			
				}
			}	
		}
		
		else if(c == ')'){
			while(s.top() != '(' && !s.empty()){
				char ch = s.top();
				postfix+=ch;
				s.pop();
			}
			if(!s.empty() && s.top() == '(')
			s.pop();
		}
			
		
	}
	return postfix;
}


int main(){
	string infix;
	cout<<"Enter a infix expression"<<endl;
	cin>>infix;
	
	string postfix = InfixToPostfix(infix);
	
	cout<<"Postfix is:  "<<postfix;
	return 0;
}
