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

int main(){
	cout<<"Enter the string"<<endl;
	string s;
	cin >> s;
	Stack stack(s.length());
	
	for(int i = 0;i<s.length();i++){
		char c = s[i];
		stack.push(c);
	}
	
	cout<<"Reverse string is"<<endl;
	for(int i = 0;i<s.length();i++)
		cout<<stack.pop();
}






















