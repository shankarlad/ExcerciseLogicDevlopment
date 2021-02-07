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
//
//void reverse(char str[]) {
//	int len = strlen(str);
//	initStack(len);
//	for (int i = 0; i < len; i++) {
//			push(str[i]);
//	}
//
//	for (int i = 0; i < len; i++) {
//		str[i] = pop();
//	}
//}
//
//
//int main() {
//	char str[50];
//	cout << "Enter the String to reverse"<<endl;
//	cin >> str;
//	reverse(str);
//	
//	
//	cout << str;
//	return 0;
//
//}