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
		
	Node* reverse(Node* head, int k){
    
	    if (!head)
	        return NULL;
	    Node* current = head;
	    Node* next = NULL;
	    Node* prev = NULL;
	    int count = 0;
 
	    while (current != NULL && count < k) {
	        next = current->getNext();
	        prev->setNext(current->getNext());
	        prev = current;
	        current = next;
	        count++;
	    }
 
	    if (next != NULL)
	        head->getNext() = reverse(next, k);
 
	    return prev;
	}
		// Print
	void printList(Node* node){
	    while (node != NULL) {
	        cout << node->getData() << " ";
	        node = node->getNext();
	    }
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
			linkList.printList(linkList.head);
			linkList.reverse(linkList.head);
			linkList.printList(linkList.head);
		}
		
		
		if(cmd == "exit"){
			exit(0);
		}
	}
	
	return 0;
	
}

