#include<iostream>
using namespace std;

char stack[20];
int MaxSize, tos;

void initStack() {	
	MaxSize = 20;
	tos = -1;
}

void push(char c) {
	stack[++tos] = c;
}

int isFull() {
	if (tos == MaxSize - 1) {
		return 1;	}
	else return 0;
}

int isEmpty() {
	if (tos == -1) {
		return 1;
	}
	else return 0;
}

char pop() {
	return stack[tos--];
}

char atTop() {
	return stack[tos];
}

void printStack() {
	for (int i = tos; i > -1; i--) {
		cout << stack[i] << "\t";
	}
	cout << endl;
}



int main() {
	string exp;
	initStack();

	cout << "Enter the Expression";
	cin >> exp;
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
			push(exp[i]);
		}
		else if (exp[i] == '}') {
		if (pop() != '{') {
				cout << "Expression not well formed";
				exit(0);
			}
		}
		else if (exp[i] == ']') {
			if (pop() != '[') {
				cout << "Expression not well formed";
				exit(0);
			}
		}
		else if (exp[i] == ')') {
			if (pop() != '(') {
				cout << "Expression not well formed";
				exit(0);
			}
		}
	}

	if (isEmpty() == 1) {
		cout << "Well formed expression";
	}

	else cout << "Expression not well formed: extra brackets";
	return 0;

}
