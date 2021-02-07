#include<iostream>
using namespace std;

int stack[100], maxsize, tos;

void initStack(int size){
	maxsize = size;
	tos = -1;
}

void push(int e){
	tos++;
	stack[tos] = e;
}

int pop(){
	int temp = stack[tos];
	stack[tos] = 0;
	tos--;
	return temp;		
}

bool isEmpty(){
	if(tos==-1)
		return true;
	else
		return false;
}

bool isFull(){
	if(tos == maxsize-1)
		return true;
	else
		return false;
}

void printStack(){
	for(int i=tos;i>=0;i--)
		cout<<stack[i]<<" ";
	cout<<endl;
}

int main(){
	int size;
	cout<<"Enter the size of the stack"<<endl;
	cin>>size;
	
	initStack(size);
	
	int choice;
	
	do{
		cout<<"Enter choice:\n"<<
				"1.Push\n"<<
				"2.Pop\n"<<
				"3.printstack\n"<<
				"0.exit\n";
		cin>>choice;
		switch(choice){
			case 1:{
				if(isFull())
					cout<<"Stack is full"<<endl;
				else{
					int e;
					cout<<"Enter number to push"<<endl;
					cin>>e;
					push(e);
				}
				break;
			}
			case 2:{
				if(isEmpty())
					cout<<"Stack is Empty"<<endl;
				else{
					cout<<"Popped out element: "<<pop()<<endl;
				}
				break;
			}
			case 3:{
				if(isEmpty())
					cout<<"Stack is Empty"<<endl;
				else{
					printStack();
				}
				break;
			}
			
			case 0:{
				cout<<"Exiting!!!!!!!!"<<endl;
				break;
			}
			
			default:{
				cout<<"Invalid input, Retry Again"<<endl;
				break;
			}


		}
		
		
		
	}while(choice);
	
}
