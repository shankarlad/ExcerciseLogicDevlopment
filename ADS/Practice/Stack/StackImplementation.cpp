// Stack Implementation

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
			if(top == size-1){
				cout<<"Stack Is Full..."<<endl;
				return true;
			}else{
				return false;
			}		
		}
		
		bool isEmpty(){
			if(top == -1){
				cout<<"Stack Is Empty..."<<endl;
				return true;
			}else{
				return false;
			}
		}
		
		void push(int data){
			assert(!isFull());
            		top++;
            		store[top]=data;
		}
		
		int pop(){
			assert(!isEmpty());
            		int data=store[top];
            		top--;
            		return data;
		}	
		
		int atTop(){
			return store[top];
		}	
		
		void printStack() {
			for (int i = top; i > -1; i--) {
			cout << store[i]<<"\t";
			}
			cout << endl;
		}
};

int main(){
	int s,ch,e;
	cout << "Enter the max size of stack"<<endl;
	cin >> s;

	Stack stack(s);

	do {
		cout << "Enter Choice"<<endl<<"\n1.Push\n2.Pop\n3.atTop\n4.PrintStack\n0.Exit" << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			if (stack.isFull() == true) {
				cout << "Stack is full" << endl;
			}
			else {
				cout << "Enter the number to push" << endl;
				cin >> e;
				stack.push(e);
			}
			break;
		case 2:
			if (stack.isEmpty() == true) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << stack.pop()<<endl;
			}
			break;
		case 3:
			if (stack.isEmpty() == true) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << stack.atTop()<<endl;
			}
			break;
		case 4:
			if (stack.isEmpty() == true) {
				cout << "Stack is empty" << endl;
			}
			else {
				stack.printStack();
			}
			break;
		case 0:
			cout << "Exiting" << endl;
			break;

		default:
			cout << "Error: Try Again" << endl;
			break;
		}

	} while (ch != 0);

    return 0;
}
