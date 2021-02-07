#include<iostream>
#include<stack>
using namespace std;

stack<int> sortStack(stack<int> s){
	stack<int> t;
	
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		while(!t.empty() && t.top()>temp){
			
			int temp2 = t.top();
			t.pop();
			s.push(temp2);
		}
		t.push(temp);
		
	}
	return t;
}

int main(){
	stack<int> s;
	s.push(5);
	s.push(10);
	s.push(3);
	s.push(12);
	s.push(7);
	
	stack<int> sortedStack = sortStack(s);
	
	while(!sortedStack.empty()){
		cout<<sortedStack.top()<<" ";
		sortedStack.pop();
	}
}
