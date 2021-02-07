#include<iostream>
using namespace std;

char stack[100];
int maxsize,tos;

initStack(int size){
    tos = -1;
    maxsize = size;
}

int isFull(){
    if(tos == maxsize-1)
    return 1;
    else return 0;
}

push(char c){
    tos = tos+1;
    stack[tos] = c; 
}

int isEmpty(){
    if(tos == -1)
    return 1;
    
    else return 0;
}

char pop(){
    char c = stack[tos];
    stack[tos] = '\0';
    tos--;
    return c;
}

char atTop(){
    return stack[tos];
}

int precedence(char c){
    if(c == '*' || c == '/')
    return 2;
    
    else if(c == '+' || c == '-')
    return 1;
    
    else return -1;
}

int isOperator(char c){
    if(c=='*' || c=='/' || c=='+' || c=='-'){
        return 1;
    }
    else return 0;
}

string reverse(string s){
	initStack(s.length());
	for(int i = 0;i<s.length();i++){
		push(s[i]);
	}

	for(int i = 0;i<s.length();i++){
		s[i] = pop();
	}	
	return s;
}

string InfixToPrefix(string infix){
    string prefix;
    initStack(infix.length());
    for(int i= (infix.length()-1); i>=0; i--){
        if(infix[i] >= 'a' && infix[i] <= 'z' ||infix[i] >= 'A' && infix[i] <= 'Z'  ){
            prefix+=infix[i];
        }
        else if(infix[i] == ')'){
            push(infix[i]);
        }
        else if(infix[i] == '('){
            while((atTop() != ')') && (isEmpty() != 1)){
                prefix+= pop();  
            }
            if(atTop()==')')
            pop();
        }
        else if(isOperator(infix[i])){
            if(isEmpty() == 1){
                push(infix[i]);
            }
            else{
                if(precedence(infix[i])>=precedence(atTop())){
                    push(infix[i]);
                }
                else if(precedence(infix[i])<precedence(atTop())){
                    while(precedence(infix[i])<precedence(atTop()) && (isEmpty() != 1)){
                        prefix+=pop();
                    }
                    push(infix[i]);
                }
            }
        }
    }
    
    while(isEmpty() == 0){
        prefix+=atTop();
        pop();
    }
 
 prefix = reverse(prefix);
 return prefix;
}

int main(){
    string infix_exp, prefix_exp;
    cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix_exp;

  	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	
  	prefix_exp = InfixToPrefix(infix_exp);
  	
  	cout<<endl<<"POSTFIX EXPRESSION: "<<prefix_exp;
   
 return 0;
}



