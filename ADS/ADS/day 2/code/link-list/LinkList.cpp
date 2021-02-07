#include <iostream>

using namespace std;

class Node{

	int data;
	Node *next;

	public:
		Node(){ next = NULL; }
		
		~Node(){
			next = NULL;
		}

		Node(int data){
			this->data = data;
			this->next = NULL;
		}
	
		int getData(){
			return data;
		}	

		Node* getNext(){
			return next;
		}
		
		void setNext(Node * next){
			this->next = next;
		}
};

class LinkList{
	Node *head;
	public:
		LinkList(){
			head = NULL;
		}

		void insertE(int data){
			Node *node = new Node(data);
			if( head == NULL){
				head = node;
			}else{
				Node *temp = head;
				while( temp->getNext() != NULL){
					temp = temp->getNext();	
				}
				temp->setNext( node );

			}
		}	

		void insertB(int data){
			Node *node = new Node(data);
			if( head == NULL){
				head = node;
			}else{
				node->setNext(head);				    	  head = node;        	
			}
		}	
		
		void insertAfter(int tobe, int after){
			Node *node = new Node( tobe );
			Node *temp = head;
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
			Node *temp = head;
			while( temp != NULL){
				cout<<temp->getData()<<"->";
				temp = temp->getNext();	
			}
			cout<<endl;

		}

		~LinkList(){
			while( head != NULL ){
				Node *temp = head;
				head = head->getNext();
				delete temp;
			}
		}	

};

int main(){
	LinkList ll;
	int data;
	cin>>data;
	ll.insertE( data );
	cin>>data;
	ll.insertE( data );
	cin>>data;
	ll.insertE( data );
	cin>>data;
	ll.insertE( data );
	ll.insertAfter( 15, 20 );
	ll.print();
return 0;
}
