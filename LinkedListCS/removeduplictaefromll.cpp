#include<iostream>
#include <stack>
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
	
	void removeDuplicates(Node* head) { 
	    
	    Node* temp = head; 
	
	    Node* next_next; 
	     
	    if (temp == NULL) 
	   		return; 
	 
	    while (temp->getNext() != NULL) 
	    { 
	   
		    if (temp->getData() == temp->getNext()->getData()) 
		    { 
		             
		        next_next = temp->getNext()->getNext(); 
		        delete(temp->getNext()); 
		        next_next->setNext(temp->getNext()); 
		    } 
		    else 
		    { 
		        temp = temp->getNext(); 
		    } 
	    } 
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
	int choice;
	
	while(1){
		cin>>cmd;
		
	
		if(cmd == "ie"){
			cin>>data;
			linkList.insertAtEnd(data);	
		}
		
		
		if(cmd == "print"){
			//linkList.print();
			linkList.removeDuplicates(linkList.head);
			linkList.print();
		}
		

		if(cmd == "exit"){
			exit(0);
		}
	}
	
	return 0;
	
}

