#include <iostream>
using namespace std;

template<class T>

class queue{

	private:		
	
	int size;
	int rare;
	int front;
	T *store;

	public:
		queue(int size){
			this->size = size;
			front = rare = -1;
			store = new T[size];
		}
		~queue(){
			delete[] store;
		}
		int isEmpty(){
			if( front == rare){
				return 1;
			}	
			return 0;
		}
		int isFull(){
			if(rare == (size - 1) ){
				return 1;
			}
			return 0;	
		}
		void enqueue(T data){
			rare++;
			store[rare] = data;
			
		}

		T dequeue(){
			front++;
			T data = store[front];
			if( front == rare){
				front = rare = -1;
			}
			return data;
		}
};
