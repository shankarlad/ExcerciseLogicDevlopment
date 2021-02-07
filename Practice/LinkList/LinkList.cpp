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
		
		// Insert After
		int insertAfter(int after,int data){
			Node *node = new Node(data);
			Node *temp= head;
			while(temp->getData() != after){
				temp = temp->getNext();
				if(temp == NULL)
					return 0;
			}
			if(head->getData() == data){
				node->setNext(temp->getNext());
				head->setNext(node);
			}
			else{
				node->setNext(temp->getNext());
				temp->setNext(node);
			}
		}
		
		// Insert Before
		int insertBefore(int before,int data){
			Node *node = new Node(data);
			Node *temp = head;
			Node *prev = temp;
			while(temp->getData() != before){
				prev = temp;
				temp = temp->getNext();
				if(temp == NULL)
					return 0;
			}
			if(head->getData() == data){
				node->setNext(head);
				head = node;
			}
			else{
				node->setNext(prev->getNext());
				prev->setNext(node);
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
		
		// Delete Node
		int deleteNode(int data){
			Node *temp = head;
			Node *prev = temp;
			while(temp->getData()!=data){
				prev = temp;
				temp = temp->getNext();
				if(head == NULL)
					return 0;
			}
			if(head->getData() == data){
				head = head->getNext();
				delete temp;
			}else{
				prev->setNext(temp->getNext());
				delete temp;
			}
		}
		
		// Delete After
		int deleteAfter(int after){
			Node *temp = head;
			Node *prev = temp;
			while(temp->getData() != after){
				prev = temp;
				temp = temp->getNext();
				if(head == NULL)
					return 0;
			}
			prev = temp;
			temp = temp->getNext();
			if(temp!=NULL){
				prev->setNext(temp->getNext());
				delete temp;
			}
		}
		
		// Delete Before
		int deleteBefore(int before){
			Node *temp = head;
			Node *prev = temp;
			while(head->getData() == before){
				return 0;
			}
			if(head->getNext()->getData()==before){
				head = head->getNext();
			}else{
				while(temp->getNext()->getData()!=before){
					prev = temp;
					temp = temp->getNext();
				}
			prev->setNext(temp->getNext());
			delete temp;
			}
		}
		
		// Reverse LinkList
		 void reverses()
        {
            Node *temp = head;
            reverseNode(temp);
            cout<<endl;
        }

        void reverseNode(Node *temp)
        {
            if(temp->getNext()!=NULL)
            {
                reverseNode(temp->getNext());
            }
            cout<<temp->getData()<<" ";
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
