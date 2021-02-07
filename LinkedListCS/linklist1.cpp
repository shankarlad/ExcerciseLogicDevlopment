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
	Linklist linkList1,linkList2;
	
	string cmd;
	int data,number,choice;
	
	do{
			cout<<"1.Insert at end\n2.print\n0.exit\n";
	
	cin>>choice;
	switch(choice){
		case 1:{
			cout<<"Enter data\n";
			while(data!=-1)
    		{
        		cin>>data;
        		if(data!=-1){
        			if(data%2==0)
        				linkList1.insertAtEnd(data);
        			else
        				linkList2.insertAtEnd(data);
				}
            		
    		}
    		
    		Node* even=linkList1.head;
    		Node* odd=linkList2.head;
    
    		Node* temp=even;
    		while(temp->getNext()!=NULL)
   			{
   				temp=temp->getNext();
			}
        		temp->setNext(odd);
        		
        	//	linkList1.print();
			break;
		}
			
		case 2:{
			linkList1.print();
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

