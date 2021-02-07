#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

class DLL{
	private:
		Node *root,*last;
	public:
		void create();
		void insertLeft(int e);
		void insertRight(int e);
		void deleteLeft();
		void deleteRight();
		void print();
		void reverserPrint();
};

void DLL::create(){
	root = last =NULL;
}

void DLL::insertLeft(int e){
	Node *n;
	n = new Node;
	n->data = e;
	n->left =n->right = NULL;
	
	if(root==NULL){
		root = last = n;
	}
	else{
		n->right = root;
		root->left = n;
		root= n;
	}
}

void DLL::insertRight(int e){
	Node *n;
	n = new Node;
	n->data = e;
	n->left =n->right = NULL;
	
	if(root==NULL){
		root = last = n;
	}
	else{
		last->right = n;
		n->left = last;
		last = n;
	}
}

void DLL::deleteLeft(){
	Node *t;
	if(root == NULL){
		cout<<"Empty list!!!!\n";
	}
	else{
		t = root;
		root = root->right;
		if(root !=NULL)
		root->left = NULL;
		cout<<"Deleted element: "<<t->data<<endl;
		delete t;
	}
}

void DLL::deleteRight(){
	Node *t;
	if(root == NULL){
		cout<<"Empty list!!!!\n";
	}
	else{
		t = last;
		last = last->left;
		if(last !=NULL)
			last->right = NULL;
		else 
			root = NULL;
		cout<<"Deleted element: "<<t->data<<endl;
		delete t;
	}	
}

void DLL::print(){
	Node *t;
	if(root == NULL){
		cout<<"List is empty!!!\n";
	}
	else{
		t =root;
		do{
			cout<<t->data<<" ";
			t = t->right;
		}while(t!= NULL);
	}
}

void DLL::reverserPrint(){
	Node *t;
	if(root == NULL){
		cout<<"List is empty!!!\n";
	}
	else{
		t =last;
		do{
			cout<<t->data<<" ";
			t = t->left;
		}while(t!= NULL);
	}
}

int main(){
	DLL dll;
	dll.create();
	int choice;
	int no;
	
	do{
		cout<<"Please enter choice\n"<<
		"1. Insert Left\n"<<
		"2. Insert Right\n"<<
		"3. Delete left\n"<<
		"4. Delete Right\n"<<
		"5. Print\n"<<
		"6. ReversePrint\n"<<
		"0. Exit\n";
		cin>>choice;
		switch(choice){
			case 1:
				{
					cout<<"Enter Number\n";
					cin>>no;
					dll.insertLeft(no);
					break;
				}
				
			case 2:
				{
					cout<<"Enter Number\n";
					cin>>no;
					dll.insertRight(no);
					break;
				}
			case 3:
				{
					dll.deleteLeft();
					break;
				}
			case 4:
				{
					dll.deleteRight();
					break;
				}
			case 5:
				{
					dll.print();
					break;
				}
			case 6:
				{
					dll.reverserPrint();
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


