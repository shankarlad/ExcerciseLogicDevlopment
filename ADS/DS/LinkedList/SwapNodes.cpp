#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class LinkedList{
	private:
		Node *root,*last;
		
	public: 
		void initLinkedList();
		void insertRight(int e);
		void print();	
		void swapNodes(int n1,int n2);	
};

void LinkedList::initLinkedList(){
			root = NULL;
			last = NULL;
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


void LinkedList::swapNodes(int n1,int n2){
	Node *t1,*t2;
	t1=t2=root; 
	for(int i=1;i<n1;i++){
		t1 = t1->next;
	}
	for(int i=1;i<n2;i++){
		t2 = t2->next;
	}
	int temp;
	temp = t1->data;
	t1->data = t2->data;
	t2->data = temp;
}

int main(){
	int choice,e;
	bool b;
	LinkedList l;
	l.initLinkedList();
	
	do{
		cout<<"Please enter your choice\n";
		cout<<"1. Insert Right\n";
		cout<<"2. swapNodes\n";
		cout<<"3. Print\n";
		cout<<"0. Exit\n";
		
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter number to insert\n";
				cin>>e;
				l.insertRight(e);
				break;
				
			case 2:
				{	
					int a,b;
					cout<<"Enter node numbers\n";
					cin>>a;
					cin>>b;
					l.swapNodes(a,b);
				}

			case 3:	
				l.print();				
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

