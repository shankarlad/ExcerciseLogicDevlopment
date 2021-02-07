#include<iostream>
using namespace std;

class Node{
	private:
			int data;
			Node *next;
			
	public:
		Node(int data){
			this->data = data;
			next = NULL;
		}
		
		int getData(){
			return data;
		}
		
		Node *getNext(){
			return next;
		}
		
		void setNext(Node *next){
			this->next = next;
		}
};

class Linklist{
	public:
		Node *head;
	public:
		Linklist(){
			head = NULL;
		}
		
		// Insert At Begining
		void insertAtBegining(int data){
			Node * node = new Node(data);
			if(head == NULL)
				head = node;
			else{
				node->setNext(head);
				head = node;
			}
		}
		
		// Insert At End
		void insertAtEnd(int data){
			Node * node = new Node(data);
			if(head == NULL)
				head = node;
			else{
				Node * temp = head;
				while(temp->getNext() != NULL){
					temp = temp->getNext();
				}
				temp->setNext(node);
			}
		}
		
		void firstLast(){
			Node *temp = head;
			Node *prev;
			while(temp->getNext()!=NULL){
				prev = temp;
				temp=temp->getNext();
			}
			insertAtBegining(temp->getData());
			prev->setNext(NULL);
		}
		
	// Print
	void print(){
		Node *temp = head;
		while(temp->getNext() != NULL){
			cout<<temp->getData()<<"->";
			temp = temp->getNext();
		}
		cout<<temp->getData()<<endl;
	}	
};


int main(){
	Linklist linkList;
	
	string cmd;
	int data,number;
	
	while(1){
		cin>>cmd;
		
		if(cmd == "ie"){
			cin>>data;
			linkList.insertAtEnd(data);
		}

		if(cmd == "print"){
			linkList.firstLast();
			linkList.print();
		}
		
		
		if(cmd == "exit"){
			exit(0);
		}
	}
	
	return 0;
	
}

