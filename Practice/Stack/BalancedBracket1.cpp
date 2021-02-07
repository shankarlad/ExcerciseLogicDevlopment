#include<iostream>
#include<assert.h>
using namespace std;

class Stack{
	private :
		int top;
		int size;
		int *store;
	
	public:
		Stack(int size){
			top = -1;
			this->size = size;
			store = new int[size];
		}
		
		bool isFull(){
			if(top == size-1)
				return true;
			else
				return false;		
		}
		
		bool isEmpty(){
			if(top == -1)
				return true;
			else
				return false;
		}
		
		void push(char data){
			assert(!isFull());
            top++;
            store[top]=data;
		}
		
		void pop(){
			assert(!isEmpty());
            char data=store[top];
            top--;
		}	
		
		char atTop(){
			return store[top];
		}	
		
		bool isBalanced(string s);	
};

bool Stack::isBalanced(string s){
	for(int i=0;i<s.length();i++){
		char c = s[i];
		
		if(c=='(' || c == '{' || c == '[')
			push(c);
		else{
			if(c==')'){
				if(isEmpty() || atTop() != '(')
					return false;
				else 
					pop();
			}
			else if(c=='}'){
				if(isEmpty() || atTop() != '{')
					return false;
				else 
					pop();
			}
			else if(c==']'){
				if(isEmpty() || atTop() != '[')
					return false;
				else 
					pop();
			}
			
		}
	}
	
	if(!isEmpty())
		return false;
	else 
		return true;

}


int main(){
	cout<<"Enter an expression"<<endl;
	string exp;
	cin>>exp;
	Stack stack(exp.length());
	
	if(stack.isBalanced(exp))
		cout<<"Balanced"<<endl;
	else
		cout<<"Not Balanced"<<endl;
		
	return 0;
}
