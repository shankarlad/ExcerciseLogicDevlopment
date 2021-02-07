#include <iostream>

using namespace std;

#ifndef __LINKLIST__
#define __LINKLIST__

template <class T>

class Node{

	T data;
	Node<T> *next;
	public:
		Node(){ next = NULL; }
		
		~Node(){
			next = NULL;
		}

		Node(T data){
			this->data = data;
			this->next = NULL;
		}
	
		T getData(){
			return data;
		}	

		Node* getNext(){
			return next;
		}
		
		void setNext(Node * next){
			this->next = next;
		}
};

template<class T>

class LinkList{
	Node<T> *head;
	public:
		LinkList(){
			head = NULL;
		}

		void insertE(T data){
			Node<T> *node = new Node<T>(data);
			if( head == NULL){
				head = node;
			}else{
				Node<T> *temp = head;
				while( temp->getNext() != NULL){
					temp = temp->getNext();	
				}
				temp->setNext( node );

			}
		}	

		void insertB(T data){
			Node<T> *node = new Node<T>(data);
			if( head == NULL){
				head = node;
			}else{
				node->setNext(head);				    	  head = node;        	
			}
		}	

		int isFull(){
			Node<T> *node = new Node<T>();
			if( node != NULL){
			    delete node;
			    return 0;                   
			}
			return 1;
		}

		int isEmpty(){
			if(head == NULL)
				return 1;
			return 0;
		}
		
		T deleteB(){
			Node<T>* temp = head;
			head = head->getNext();
		return temp->getData();	 
		}
		
		void insertAfter(T tobe, T after){
			Node<T> *node = new Node<T>( tobe );
			Node<T> *temp = head;
			while( temp != NULL 
			     && temp->getData() != after){
				temp = temp->getNext(); 

			}
			if( temp== NULL){
				cout<<"Data Not Found"<<endl;
			}else{
				node->setNext( temp->getNext());
				temp->setNext(node);

			}
		}

		void print(){
			Node<T> *temp = head;
			while( temp != NULL){
				cout<<temp->getData()<<"->";
				temp = temp->getNext();	
			}
			cout<<endl;

		}

		~LinkList(){
			while( head != NULL ){
				Node<T> *temp = head;
				head = head->getNext();
				delete temp;
			}
		}	

};
#endif
