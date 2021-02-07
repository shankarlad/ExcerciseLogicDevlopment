#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class LinkedList{
	private:
		Node *root,*last;
		int cnt;
		
	public: 
		void initLinkedList();
		void insertRight(int e);
		void deleteRight();
		void emptyList();
		void print();	
		void getDecimalForm();	
};

void LinkedList::initLinkedList(){
			root = NULL;
			last = NULL;
			cnt=0;
		}

void LinkedList::insertRight(int e){
	Node *n;
	n = new Node;
	n->data = e;
	n->next = NULL;
	
	if(root == NULL){
		root = n;
		last = n;  
	}	
	else{
		last->next = n;
		last = n; 
	}
	cnt++;
}

void LinkedList::deleteRight(){
	if(root == NULL){
		cout<<"Empty List!!!!!"<<endl;
	}
	else{
		Node *temp,*secondLast;
		temp =last;
		secondLast = root; 
		while(secondLast->next->next != NULL){
			secondLast = secondLast->next;
		}
		last = secondLast;
		last->next = NULL;
		cout<<"Deleted Element: "<<temp->data<<endl;
		delete temp;
		cnt--;
	}	
}


void LinkedList::emptyList(){
	Node *temp;
	if(root == NULL){
		cout<<"List Already Empty!!!!!"<<endl;
	}
	else{
		while(root!=NULL){
		temp = root;
		root = root->next; 
		delete temp;
	}
	cout<<"List is now Empty!!!\n";	
	cnt = 0;	
	}

}

void LinkedList::print(){
	Node *temp;
	if(root == NULL){
		cout<<"Empty List!!!!!"<<endl;
	}
	
	else{
		temp = root;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}

int power(int j){
	if(j==0) return 1;
	else
	return 2*power(j-1); 
}

void LinkedList::getDecimalForm(){
	Node *temp;
	int dec= 0;
	int i = cnt;
	if(root == NULL){
		cout<<"Empty List!!!!!"<<endl;
	}
	else{
		temp = root;
		while(temp!=NULL){
			dec += temp->data * power(--i);	
			temp = temp->next;
		}
		
	}
	
	cout<<"Decimal form of ";
	print();
	cout<<" is: "<<dec<<endl;
}


int main(){
	int choice,e;
	bool b;
	LinkedList l;
	l.initLinkedList();
	
	do{
		cout<<"Please enter your choice\n";
		cout<<"1. Insert Right\n";
		cout<<"2. Delete Right\n";
		cout<<"3. Print\n";
		cout<<"4. Empty the List\n";
		cout<<"5. print Decimal\n";
		cout<<"0. Exit\n";
		
		cin>>choice;
		
		switch(choice){			
			case 1:
				cout<<"Enter number to insert\n";
				cin>>e;
				l.insertRight(e);
				break;
			case 2:
				l.deleteRight();
				break;
			case 3:	
				l.print();				
				break;
			case 4:	
				l.emptyList();				
				break;
			case 5:	
				l.getDecimalForm();				
				break;
			case 0:
				cout<<"Exiting!!!!!\n";
				break;
			default:
				cout<<"Invalid Input!!!!!!!!!!!!!!\n";
				break;
			
		}
		
	}while(choice);
	return 0;
}

