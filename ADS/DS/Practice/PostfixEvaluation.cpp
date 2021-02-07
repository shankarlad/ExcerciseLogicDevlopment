#include<iostream>
#include<stack>
using namespace std;


bool isNumber(char c){
	if(c >= '0' && c<= '9')
		return true;
	
	else return false;
}

int convertToNumber(char c){
	return (c - '0');
}


int operate(int n2, char c, int n1){
	switch(c){
		case '+':{
			
			return n2 + n1;
			break;
		}
		case '-':{
			
			return n2 - n1;
			break;
		}
		case '/':{
			
			return n2 / n1;
			break;
		}
		case '*':{
			
			return n2 * n1;
			break;
		}
	}
}

int EvaluatePostfix(string postfix){
	char c;
	int n1, n2;
	stack<int> s;
	for(int i=0; i<postfix.length(); i++){
		c = postfix[i];
		
		if(isNumber(c)){
			s.push(convertToNumber(c));
			}
		
		else{
			n1 = s.top();
			s.pop();
			n2 = s.top();
			s.pop();
			s.push(operate(n2,c,n1));			
		}
		}
		
		return s.top(); 
	}
	
	
	


int main(){
	cout<<"Enter postfix expression:"<<endl;
	string postfix;
	cin>>postfix;
	
	cout<<"Evaluation: "<<EvaluatePostfix(postfix);
	return 0;
}

