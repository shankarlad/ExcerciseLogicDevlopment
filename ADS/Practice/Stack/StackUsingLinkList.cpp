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
	private:
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
	
		// Delete End
		void deleteAtEnd(){
			Node *temp = head;
			Node *prev = temp;
			while(temp->getNext()!=NULL){
				prev = temp;
				temp=temp->getNext();
			} 
			prev->setNext(NULL);
			delete temp;
		}
		
		// LastElement in LinklIst(Stack Top)
		int lastElement(){
			Node* temp=head;
           	while(temp->getNext()!=NULL){
        	   temp=temp->getNext();
           }
           return temp->getData();
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


class Stack{
   private :
       LinkedList li;
   public:
        Stack(){

        }

        void push(int data){
            li.InsertE(data);
        }

        int pop(){
           return li.EndElementDelete();
        }

        int top(){
           return li.TopElement();
        }
       void  show(){
            li.DisplayNode();
         }
};

int main(){
	Linklist linkList;
	
	string cmd;
	int data,number;
	
	while(1){
		cin>>cmd;
		
		if(cmd == "ib"){
			cin>>data;
			linkList.insertAtBegining(data);
		}
		
		if(cmd == "ie"){
			cin>>data;
			linkList.insertAtEnd(data);
		}
		
		if(cmd == "iaf"){
			cin>>data;
			cin>>number;
			linkList.insertAfter(number,data);
		}
		
		if(cmd == "ibf"){
			cin>>data;
			cin>>number;
			linkList.insertBefore(number,data);
		}
		
		if(cmd=="de"){
			linkList.deleteAtEnd();
		}
		
		if(cmd=="dn"){
			cin>>data;
			linkList.deleteNode(data);
		}
		
		if(cmd=="da"){
			cin>>number;
			linkList.deleteAfter(number);
		}
		
		if(cmd=="db"){
			cin>>number;
			linkList.deleteBefore(number);
		}
		
		if(cmd == "print"){
			linkList.print();
		}
		
		if(cmd == "rvs"){
			linkList.reverses();
		}
		
		if(cmd == "exit"){
			exit(0);
		}
	}
	
	return 0;
	
}

