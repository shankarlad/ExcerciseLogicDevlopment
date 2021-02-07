#include<iostream>
using namespace std;

int stack[100],tos1,tos2,maxsize;

void initStack(int size){
	maxsize = size;
	tos1 = -1;
	tos2 = maxsize;
}

bool isFull(){
	if(tos1+1 == tos2 || tos2-1 == tos1)
	return true;
	else return false;
}

bool isEmpty1(){
	if(tos1 == -1)
	return true;
	else return false;
}
bool isEmpty2(){
	if(tos2 == maxsize)
	return true;
	else return false;
}

void push1(int e){
	if(isFull()){
		cout<<"stack is Full!!!\n";
	}
	else{
		stack[++tos1] = e;	
	}
}

void push2(int e){
	if(isFull()){
		cout<<"stack is Full!!!\n";
	}
	else{
		stack[--tos2] = e;	
	}
}

void pop1(){
	if(isEmpty1()){
		cout<<"stack is Empty!!!\n";
	}
	else{
		cout<<"Popped element: "<<stack[tos1]<<endl;
		stack[tos1] = 0;
		tos1--;
	}
}

void pop2(){
	if(isEmpty2()){
		cout<<"stack is Empty!!!\n";
	}
	else{
		cout<<"Popped element: "<<stack[tos2]<<endl;
		stack[tos2] = 0;
		tos2++;
	}
}

int atTop1(){
	if(isEmpty1()){
		cout<<"stack is Empty!!!\n";
	}
	else{
		return stack[tos1];
	}
}

int atTop2(){
	if(isEmpty2()){
		cout<<"stack is Empty!!!\n";
	}
	else{
		return stack[tos2];
	}
}



int main(){
	int size;
	cout<<"Enter stack size\n";
	cin>>size;
	initStack(size);
	int ch,e;
	do{
		cout<<"Please enter choice\n"<<
		"1. Push on stack-1\n"<<
		"2. Push on stack-2\n"<<
		"3. Pop from stack-1\n"<<
		"4. Pop from stack-2\n"<<
		"0. Exit\n";	
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"Enter number\n";	
				cin>>e;
				push1(e);
				break;
			}
			case 2:{
				cout<<"Enter number\n";	
				cin>>e;
				push2(e);
				break;
			}
			case 3:{
				pop1();
				break;
			}
			case 4:{
				pop2();
				break;
			}
			case 0:{
				cout<<"Exiting!!!!!!!!!!!!\n";
				break;
			}
			default:
				cout<<"Invalid Choice\n";
				break;
		}
	}
	while(ch);
}

