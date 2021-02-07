#include<iostream>
#include <stack>
using namespace std;

class Node{
	private:
			char data;
			Node *next;
			
	public:
		Node(int data){
			this->data = data;
			next = NULL;
		}
		
		char getData(){
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
		void insertAtEnd(char data){
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
		
		bool isPalindrome(Node * head){
    		stack<char> s;

		    Node* node = head;
		    while (node) {
		        s.push(node->getData());
		        node = node->getNext();
		    }
 
		    node = head;
		    while (node)
	    	{
		       
		        char top = s.top();
		        s.pop();
		
		        if (top != node->getData())
		            return false;
	
		        node = node->getNext();
   			 }
 
		    // we reach here only when the linked list is a palindrome
		    return true;
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
	char data,number;
	int choice;
	
	while(1){
		cin>>cmd;
		
	
		if(cmd == "ie"){
			cin>>data;
			linkList.insertAtEnd(data);	
		}
		
		
		if(cmd == "print"){
			linkList.print();
			if(linkList.isPalindrome(linkList.head))
				cout<<"Linklist is Palindrome";
			else
				cout<<"Linklist is not a palindrome";
		}
		

		if(cmd == "exit"){
			exit(0);
		}
	}
	
	return 0;
	
}

