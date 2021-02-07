//#include<iostream>
//using namespace std;
//
//int stack[100], MaxSize, tos;
//
//void initStack(int size) {
//	MaxSize = size;
//	tos = -1;
//}
//
//void push(int num) {
//	stack[++tos] = num;
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
//int pop() {
//	return stack[tos--];
//}
//
//int atTop() {
//	return stack[tos];
//}
//
//void printStack() {
//	for (int i = tos; i > -1; i--) {
//		cout << stack[i] << " ";
//	}
//	cout << endl;
//}
//
//
//void binary(int num) {
//	int q, r;
//	initStack(20);
//	do {
//		q = num / 2;
//		r = num % 2;
//		num = q;
//		push(r);
//	} while (q != 0);
//	printStack();
//
//}
//
//int main() {
//	cout << "Enter a number to convert to decimal";
//	int num;
//	cin >> num;
//	binary(num);
//}