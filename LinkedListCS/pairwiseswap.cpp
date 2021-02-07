#include<iostream>
#include <bits/stdc++.h> 
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
	
		void pairWiseSwap(Node* head) 
		{ 
		    Node* temp = head; 
		    while (temp != NULL && temp->getNext() != NULL) { 
		        swap(temp->getData(), 
		             temp->getNext()->getData()); 
		  
		        
		        temp = temp->getNext()->getNext(); 
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
			linkList.pairWiseSwap(linkList.head);
			linkList.print();
		}
		

		if(cmd == "exit"){
			exit(0);
		}
	}
	
	return 0;
	
}

