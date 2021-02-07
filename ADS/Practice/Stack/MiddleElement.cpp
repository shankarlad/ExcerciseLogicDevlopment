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
		
		int atMiddle(){
			return store[(size+2)/2];
		}		
};

int main(){
	cout<<"Enter the size"<<endl;
	int size;
	cin>>size;

	Stack stack(size);
			int c;
	for(int i = 0;i<size;i++){
		cin>>c;
		stack.push(c);
	}
	
	cout<<"The Middle element is "<< endl;
	cout<<stack.atMiddle();	
}
