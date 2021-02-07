#include<iostream>
using namespace std;

char stack[100];
int MaxSize, tos;

void initStack(int size) {
	MaxSize = size;
	tos = -1;
}

void push(char c) {
	tos++;
	stack[tos] = c;
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
	char c = stack[tos];
	stack[tos] = '\0';
	tos--;
	return c;
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

int precedence(char c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	else return 0;
}

int strlen(char a[]){
	int i;
	for(i=0;a[i]!='\0';i++);
	return i;
}

convert(char infix[]){
	char postfix[50];
	char c;
	
	int len = strlen(infix);
	
	initStack(len);
	
	int i=0,j=0;
	
	while(infix[i]!='\0'){
		c =infix[i];
		
		if(c=='(')
        {
            push(c);
            i++;
        }
        else if(c==')')
        {
            
                while(stack[tos]!='(')
                {               
					postfix[j] = pop(); 
					j++;
                }
				pop();
                i++;
        }
        else if(c>='a' && c<='z'|| c>='A'&& c<='Z')          
        {
            postfix[j] = c; 
			j++;
            i++;
        }
        else            
        {
            if(tos==-1)
            {
                push(c);
                i++;
            }
 
            else if( priority(infix[i]) <= priority(stk[top])) {
                postfix.insert(postfix.end(),pop());
               
                while(priority(stk[top]) == priority(infix[i])){
                    postfix.insert(postfix.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])) {
                push(infix[i]);
                i++;
            }
        }
	}
}


int main() {
	char infix[50];
	
	cout << "Enter Infix Expression"<<endl;
	cin>>infix;
	
	convert(infix);
	

	
	
	
	
	
	for (int i = 0; i < len; i++) {
		c = infix[i];

		if (c == '(') {
			push(c);
		}

		else if (c == ')') {
			while (atTop() != '(') {
				postfix[j++] = pop();
			} 
			pop();
			
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			while ((precedence(c) <= precedence(atTop())) && (isEmpty() != 1)) {
				postfix[j++] = pop();
			}
			push(c);
			}

		else{
			postfix[j++] = pop();
		}
	}
	
	while (isEmpty() != 1)
	{
		postfix[j++] = pop();
	}
	
	len = strlen(postfix);
	for(int i =0;i<len;i++){
		cout<<postfix[i];
	}
	return 0;
}

