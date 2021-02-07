#include <iostream>
#include "LinkList.cpp"	
using namespace std;

#ifndef __STACK__
#define __STACK__

template<class T>

class stack{

	private:
		LinkList<T> store;
	public:
		stack(){}
		
		int isFull(){
			if( store.isFull() ){
				cout<<"Stack is Full"<<endl;	
				return 1;
			}
			return 0;
		}
		
		int isEmpty(){
			if( store.isEmpty() ){
				cout<<"Stack is Empty"<<endl;	
				return 1;
			}
			return 0;
		}

		void push(T data){
			store.insertB( data );
		}
		
		T pop(){
			return store.deleteB();
		}

};
#endif
