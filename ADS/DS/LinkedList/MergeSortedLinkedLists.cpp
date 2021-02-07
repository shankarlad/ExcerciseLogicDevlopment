#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class LinkedList{
	public:
		Node *root,*last;
		
	public: 
		void initLinkedList();
		void insertRight(int e);
		void print();		
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


LinkedList mergeLinkedList(LinkedList &l1,LinkedList &l2){
	LinkedList sll;
	sll.initLinkedList();
	Node *r1 = l1.root;
	Node *r2 = l2.root;
	while(r1!=NULL && r2!=NULL){
		if(r1->data < r2->data){
			sll.insertRight(r1->data);
			r1=r1->next;
		}
		else{
			sll.insertRight(r2->data);
			r2=r2->next;
		}
		
	}
	while(r1!=NULL){
		sll.insertRight(r1->data);
		r1=r1->next;
	}
	while(r2!=NULL){
		sll.insertRight(r2->data);
		r2=r2->next;
	}
	
	return sll; 
}

int main(){
	LinkedList l1,l2;
	l1.initLinkedList();
	l2.initLinkedList();
	l1.insertRight(5);l1.insertRight(20);l1.insertRight(35),l1.insertRight(40);
	l2.insertRight(10);l2.insertRight(25);l2.insertRight(30);l2.insertRight(45);l2.insertRight(50);
	LinkedList sortedList = mergeLinkedList(l1,l2);
	sortedList.print();
	return 0;
}

