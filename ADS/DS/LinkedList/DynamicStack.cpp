#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};


class DynamicStack{
	private:
		Node *tos;
		
	public:
		void initStack();
		void push(int e);
		int pop();
		bool isEmpty();
		void printStack();
};

void DynamicStack::initStack(){
	tos = NULL;	
}

bool DynamicStack::isEmpty(){
	if(tos == NULL)
	return true;
	else return false;
}

void DynamicStack::push(int e){
	Node *n;
	n = new Node;
	n->data = e;
	n->next = NULL;
	
	if(isEmpty()){
		tos = n;
	}
	
	else{
		n->next = tos;
		tos = n;
	}
}

int DynamicStack::pop(){
	Node *t;
	int e;
	if(!isEmpty()){
		t = tos;
		tos = tos->next;
		e = t->data;
		delete t;
		return e;
	}
}


void DynamicStack::printStack(){
	Node *t;
	if(isEmpty()){
		cout<<"Stack is Empty!!!\n";
	}	
	else{
		t = tos;
		while(t!=NULL){
			cout<<t->data<<" ";
			t = t->next;
		}
		cout<<endl;
	}
}

int main(){
	DynamicStack s;
	s.initStack();
	
	int choice,e;
	do{
		cout<<"Enter Choice\n";
		cout<<"1. PUSH\n";
		cout<<"2. POP\n";
		cout<<"3. PRINTSTACK\n";
		cout<<"0. EXIT\n";
		cin>>choice;
		switch(choice){
			case 1:
				{
					cout<<"Enter number to push\n";
					cin>>e;
					s.push(e);
					break;
				}
			case 2:
				{
					if(s.isEmpty())
					cout<<"Stack Empty!!!\n";
					else
					cout<<"Popped element: "<<s.pop()<<endl;
					break;				
				}
			case 3:
				{
					s.printStack();
					break;
				}
			case 0:
				{
					cout <<"Exiting\n";
					break;
				}
			default:
			{
				cout<<"Invalid Choice\n";	
				break;
			}
		}	
	}while(choice);
	return 0;
}


