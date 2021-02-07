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
		
		void middleEle(int count){
			Node *temp = head;
			int cnt = 0;
			
			while(temp->getNext()!=NULL && cnt != count/2){
				cnt++;
				temp = temp->getNext();
			}
			cout<<temp->getData();
		}
		
		void middleElement(){
			Node *temp = head;
			int count = 0;
			while(temp->getNext()!=NULL){
				count++;
				temp=temp->getNext();
			}			
			
			middleEle(count);
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
			linkList.middleElement();
		//	linkList.print();
		}
		
		
		if(cmd == "exit"){
			exit(0);
		}
	}
	
	return 0;
	
}

