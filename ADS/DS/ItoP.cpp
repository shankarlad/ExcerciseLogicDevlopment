#include<iostream>
using namespace std;

char s[100];
int MaxSize, tos;

void createStack(int size) {
	MaxSize = size;
	tos = -1;
}

void push(char c) {
	s[++tos] = c;
}

int isFull() {
	if (tos == MaxSize - 1) {
		return 1;
	}
	else return 0;
}

int isEmpty() {
	if (tos == -1) {
		return 1;
	}
	else return 0;
}

char pop() {
	return s[tos--];
}

char atTop() {
	return s[tos];
}

void printStack() {
	for (int i = tos; i > -1; i--) {
		cout << s[i] << "\t";
	}
	cout << endl;
}

int prec(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
	else
		return 0;
}

int strlen(char a[]){
	int i;
	for(i=0;a[i]!='\0';i++);
	//cout<<i;
	return i;
}

int main()
{
	char in[100], post[100], c;
	int i, pi = 0;

	int n = strlen(in);

	createStack(n);

	cout << "enter infix"<<endl;
	cin >> in;


	for (int i = 0; i < n; i++)
	{
		c = in[i];

		switch (c)
		{
		case'(':
			push(c);
			break;

		case')':
			while (s[tos] != '(')
			{
				post[pi] = pop();
				pi++;
			}
			break;
		case'+':case'-':case'*':case'/':
			while ((prec(c) <= prec(s[tos])) && (isEmpty() != 1))

			{
				post[pi] = pop();
				pi++;

			}
			push(c);
			break;

		default:post[pi] = c;
			pi++;
			break;


		}
	}
	while (isEmpty() != 1)
	{
		post[pi] = pop();
		pi++;

	}
	cout << post;
}
