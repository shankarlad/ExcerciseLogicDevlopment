#include <iostream>

using namespace std;

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

int main(){
	LinkList<char> ll;
	char data;
	cin>>data;
	ll.insertE( data );
	cin>>data;
	ll.insertE( data );
	cin>>data;
	ll.insertE( data );
	cin>>data;
	ll.insertE( data );
	ll.insertAfter( 'n', 'a' );
	ll.print();
return 0;
}
