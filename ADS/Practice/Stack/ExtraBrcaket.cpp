#include<iostream>
#include<assert.h>
using namespace std;

class Stack{
	private :int top;
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
		
		char pop(){
			assert(!isEmpty());
            		char data=store[top];
            		top--;
            		return data;
		}	
		
		char atTop(){
			return store[top];
		}	
		
};

int main() {
	string exp;
	cout << "Enter the Expression"<<endl;
	cin >> exp;
	Stack stack(exp.length());
	
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
			stack.push(exp[i]);
		}
		else if (exp[i] == '}') {
		if (stack.pop() != '{') {
				cout << "Expression not well formed";
				exit(0);
			}
		}
		else if (exp[i] == ']') {
			if (stack.pop() != '[') {
				cout << "Expression not well formed";
				exit(0);
			}
		}
		else if (exp[i] == ')') {
			if (stack.pop() != '(') {
				cout << "Expression not well formed";
				exit(0);
			}
		}
	}

	if (stack.isEmpty() == true) {
		cout << "Well formed expression";
	}else 
		cout << "Expression not well formed: extra brackets";
		
		
	return 0;

}

