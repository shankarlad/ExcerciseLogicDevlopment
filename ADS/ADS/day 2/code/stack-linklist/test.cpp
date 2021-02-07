#include "stack.cpp"
#include "LinkList.cpp"

int main(){

	stack<string> stk;
	stk.push("manish");	
	stk.push("prakash");	
	stk.push("anil");	
	stk.push("raushan");	
	stk.push("arvind");	
	stk.push("virat");	
	
	cout<<stk.pop()<<endl;
	cout<<stk.pop()<<endl;
	cout<<stk.pop()<<endl;
	cout<<stk.pop()<<endl;
	cout<<stk.pop()<<endl;
	cout<<stk.pop()<<endl;
	if( !stk.isEmpty() ){
		cout<<stk.pop()<<endl;
	}
	
	LinkList<int> ll;
	ll.insertB(10);
	ll.insertB(11);
	ll.insertB(12);
	ll.insertE(13);
	ll.insertE(14);
	ll.print();
	ll.deleteB();
	ll.print();

return 0;
}
