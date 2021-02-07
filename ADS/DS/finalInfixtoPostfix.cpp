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

string InfixToPostfix(string infix){
    string postfix;
    initStack(infix.length());
    for(int i=0;i<infix.length();i++){
        if(infix[i] >= 'a' && infix[i] <= 'z' ||infix[i] >= 'A' && infix[i] <= 'Z'  ){
            postfix+=infix[i];
        }
        else if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while((atTop() != '(') && (isEmpty() != 1)){
                postfix+= pop();  
            }
            if(atTop()=='(')
            pop();
        }
        else if(isOperator(infix[i])){
            if(isEmpty() == 1){
                push(infix[i]);
            }
            else{
                if(precedence(infix[i])>precedence(atTop())){
                    push(infix[i]);
                }
                else if(precedence(infix[i])<=precedence(atTop())){
                    while(precedence(infix[i])<=precedence(atTop()) && (isEmpty() != 1)){
                        postfix+=pop();
                    }
                    push(infix[i]);
                }
            }
        }
    }
    
    while(isEmpty() == 0){
        postfix+=atTop();
        pop();
    }
 
 return postfix;
}

int main(){
    string infix_exp, postfix_exp;
    cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix_exp;

  	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	
  	postfix_exp = InfixToPostfix(infix_exp);
  	
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
   
 return 0;
}



