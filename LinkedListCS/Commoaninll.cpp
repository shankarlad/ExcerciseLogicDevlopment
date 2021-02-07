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
	Linklist linkList1,linkList2,linkList3;
	
	string cmd;
	int data,number,choice;
	
	do{
			cout<<"1.Insert at end\n2.print\n0.exit\n";
	
	cin>>choice;
	switch(choice){
		case 1:{
			
			linkList1.insertAtEnd(1);
			linkList1.insertAtEnd(2);
			linkList1.insertAtEnd(3);
			linkList1.insertAtEnd(4);
			linkList1.insertAtEnd(6);
			
			linkList2.insertAtEnd(2);
			linkList2.insertAtEnd(4);
			linkList2.insertAtEnd(6);
			linkList2.insertAtEnd(8);
			
			Node* head1=linkList1.head;
    		Node* head2=linkList2.head;
    		
//    		Node* temp1 = head1;
//    		Node* temp2 = head2;
    		while(head1->getNext()!=NULL){
    			if(head1->getData()==head2->getData()){
    				linkList3.insertAtEnd(head1->getData());
    				cout<<"ll3";
				}	
					head1=head1->getNext();
    				head2=head2->getNext();
			}
    		
			break;
		}
			
		case 2:{
			linkList1.print();
			linkList2.print();
			linkList3.print();
			break;
		}
		case 0:{
				cout<<"Exiting!!!!!!!!"<<endl;
				break;
			}
		default :{
			cout<<"Enter valid choice"<<endl;
			break;
		}
	}
	}while(choice);
	

	return 0;
	
}

