#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class CLL{
	private:
		Node *root,*last;
	
	public:
		void create();
		void insertRight(int e);
		void deleteRight();
		void print();
		void cycle(int c);
};

void CLL::create(){
	root=last=NULL;
}

void CLL::insertRight(int e){
	Node *n;
	n= new Node;
	n->data=e;
	n->next = NULL;
	
	if(root == NULL){
		root = last = n->next = n;
		
	}
	else{
		last->next = n;
		n->next = root;
		last = n;
	}
}

void CLL::deleteRight(){
	Node *t,*t2;
	if(root == NULL){
		cout<<"List is empty!!!\n";
	}
	else if(root == last){
		cout<<"Deleted element: "<<root->data<<endl;
		delete root;
		root = last = NULL;
	}
	else{
		t = root;
		while(t !=last){
			t2 = t;
			t= t->next; 
		}
		t2->next = root;
		last = t2;
		cout<<"Deleted element: "<<t->data<<endl;
		delete t;
	}
}

void CLL::print(){
	Node *t;
	if(root == NULL){
		cout<<"List is empty!!!\n";
	}
	else{
		t =root;
		do{
			cout<<t->data<<" ";
			t = t->next;
		}while(t!= root);
	}
	cout<<endl;
}

void CLL::cycle(int c){
	Node *t;
	if(root == NULL){
		cout<<"List is empty!!!\n";
	}
	else{
		for(int i=1;i<=c;i++){
			t= root;	
			while(t->next!=last){
				t=t->next;
			}
			root = last;
			last = t;
		}	
	}
	
}

int main(){
	CLL cll;
	cll.create();
	int choice;
	int no;
	
	do{
		cout<<"Please enter choice"<<
				"\n1. Insert Right"<<
				"\n2. Delete Right"<<
				"\n3. Print"<<
				"\n4. cycle"<<
				"\n0. Exit!!"<<endl;
		cin>>choice;
		switch(choice){		
			case 1:
				{
					cout<<"Enter Number\n";
					cin>>no;
					cll.insertRight(no);
					break;
				}
			case 2:
				{
					cll.deleteRight();
					break;
				}
			case 3:
				{
					cll.print();
					break;
				}
			case 4:
				{
					int c;
					cout<<"Enter number of cylces\n";
					cin>>c;
					cll.cycle(c);
					cll.print();
					break;
				}
			case 0:
				{
					cout<<"Exiting !!!!!!...\n";
					break;
				}
			default:{
				cout<<"Invalid Choice\n";
				break;
			}
		}	
	}while(choice);
}
