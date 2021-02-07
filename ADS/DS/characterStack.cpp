//#include<iostream>
//using namespace std;
//
//char stack[100];
//int MaxSize, tos;
//
//void initStack(int size) {
//	MaxSize = size;
//	tos = -1;
//}
//
//void push(char c) {
//	stack[++tos] = c;
//}
//
//int isFull() {
//	if (tos == MaxSize - 1) {
//		return 1;
//	}
//	else return 0;
//}
//
//int isEmpty() {
//	if (tos == -1) {
//		return 1;
//	}
//	else return 0;
//}
//
//char pop() {
//	return stack[tos--];
//}
//
//char atTop() {
//	return stack[tos];
//}
//
//void printStack() {
//	for (int i = tos; i > -1; i--) {
//		cout << stack[i] << "\t";
//	}
//	cout << endl;
//}
//int main() {
//	int size, ch;
//	char e;
//	cout << "Enter the max size of stack"<<endl;
//	cin >> size;
//
//	initStack(size);
//
//	do {
//		cout << "Enter Choice"<<endl<<
//							"\n1.Push\n2.Pop\n3.atTop\n4.PrintStack\n0.Exit" << endl;
//		cin >> ch;
//		switch (ch) {
//		case 1:
//			if (isFull() == 1) {
//				cout << "Stack is full" << endl;
//			}
//			else {
//				cout << "Enter the character to push" << endl;
//				cin >> e;
//				push(e);
//			}
//			break;
//		case 2:
//			if (isEmpty() == 1) {
//				cout << "Stack is empty" << endl;
//			}
//			else {
//				cout << pop();
//			}
//			break;
//		case 3:
//			if (isEmpty() == 1) {
//				cout << "Stack is empty" << endl;
//			}
//			else {
//				cout << atTop();
//			}
//			break;
//		case 4:
//			if (isEmpty() == 1) {
//				cout << "Stack is empty" << endl;
//			}
//			else {
//				printStack();
//			}
//			break;
//		case 0:
//			cout << "Exiting" << endl;
//			break;
//
//		default:
//			cout << "Error: Try Again" << endl;
//			break;
//		}
//
//	} while (ch != 0);
//	
//	return 0;
//
//}