#include<iostream>
using namespace std;

int stack[100],tos,maxsize;

initStack(int size){
	tos=-1;
	maxsize = size;
}

push(int num){
	tos++;
	stack[tos]=num;
}

bool isFull(){
	if(tos == maxsize-1){
		return true;
	}
	else return false;
}

bool isEmpty(){
	if(tos == -1)
	return true;
	
	else return false;
}

int pop(){
	return stack[tos--];
}

int atTop(){
	return stack[tos];
}

bool isOperator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/'){
		return true;
	}
	else return false; 
}

int calculate(int n1,char c, int n2){
	switch(c){
		case '+':
			return n1+n2;
			break;
		case '-':
			return n1-n2;
			break;
		case '/':
			return n1/n2;
			break;
		case '*':
			return n1*n2;
			break;
		default:
			return 0;
			break;
	}
}

int main(){
string postfix;
cout<<"enter postfix to evaluate"<<endl;
cin>>postfix;
initStack(postfix.length());
for(int i = 0; i<=postfix.length();i++){
	if(postfix[i]>='0' && postfix[i]<='9'){
		int no = postfix[i] -'0';
		push(no);
	}
	else if(isOperator(postfix[i])){
		int num1 = pop();
		int num2 = pop();
		int ans = calculate(num2,postfix[i],num1);
		push(ans);		
	}
}
cout<<"Evaluation of postfix: "<<pop();
return 0;
}

