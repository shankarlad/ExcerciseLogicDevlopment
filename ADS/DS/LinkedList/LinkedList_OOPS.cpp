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
		void insertLeft(int e);
		void insertRight(int e);
		void deleteLeft();
		void deleteRight();
		void deleteElement(int e);
		void deleteAllOccurances(int e);
		void emptyList();
		bool search(int e);	
		void print();		
};

void LinkedList::initLinkedList(){
			root = NULL;
			last = NULL;
		}

void LinkedList::insertLeft(int e){
	Node *n;
	n = new Node;
	n->data = e;
	n->next = NULL;
	
	if(root == NULL){
		root = n;
		last = n;  
	}	
	else{
		n->next = root;
		root = n; 
	}
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


void LinkedList::deleteLeft(){
	if(root == NULL){
		cout<<"Empty List!!!!!"<<endl;
	}
	else{
		Node *temp;
		temp =root;
		root = root->next;
		cout<<"Deleted Element: "<<temp->data<<endl;	
		delete temp;
	}
	
}

void LinkedList::deleteRight(){
	if(root == NULL){
		cout<<"Empty List!!!!!"<<endl;
	}
	
	else if(root==last){
		cout<<"Deleted Element: "<<root->data<<endl;
		delete root;
		root = NULL;
	}
	
	else{
		Node *temp,*secondLast;
		temp =last;
		secondLast = root; 
		while(secondLast->next != last){
			secondLast = secondLast->next;
		}
		last = secondLast;
		last->next = NULL;
		cout<<"Deleted Element: "<<temp->data<<endl;
		delete temp;
	}	
}

void LinkedList::deleteElement(int e){
	Node *target,*prev;
	if(root == NULL){
		cout<<"Empty List!!!!!"<<endl;
	}
	
	if(root->data == e) deleteLeft();
	else if(last->data == e) deleteRight();
	
	else{
		target = prev = root;
		while(target!=NULL){
			if(target->data == e) break;
			prev = target;
			target = target->next;
		}
		
		if(target == NULL){
			cout<<"Element not found"<<endl;
		}
		
		else{
			prev->next = target->next;
			cout<<"Deleted Element: "<<target->data<<endl;
			delete target;
		}
		
	}
}

void LinkedList::deleteAllOccurances(int e){
	Node *target,*prev,*temp;
	int cnt = 0;
	if(root == NULL){
		cout<<"List is Empty!!!!!"<<endl;
	}
	
	else{
		target = prev = root;
		while(target!=NULL){
			if(target->data==e){
					if(target==root){
						root = root->next;
						prev = target;
						target = target->next;
						delete prev;
						cnt++;
					}
					else{
						prev->next = target->next;
						temp = target;
						target = target->next;
						delete temp;
						cnt++;
					}
			}
			else{
				prev = target;
				target = target->next;
			}
		}
		
		if(cnt == 0){
			cout<<"Element not found"<<endl;
		}
		else{
			cout<<cnt<<" Elements deleted"<<endl;
		}
		
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
	}

}

bool LinkedList::search(int e){
	Node *temp;
	if(root == NULL){
		cout<<"Empty List!!!!!"<<endl;
	}
	
	else{
		temp = root;
		while(temp!=NULL){
			if(temp->data == e)
			return true;
			temp = temp->next;
		}
		return false;
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


int main(){
	int choice,e;
	bool b;
	LinkedList l;
	l.initLinkedList();
	
	do{
		cout<<"Please enter your choice\n";
		cout<<"1. Insert Left\n";
		cout<<"2. Insert Right\n";
		cout<<"3. Delete Left\n";
		cout<<"4. Delete Right\n";
		cout<<"5. Delete element\n";
		cout<<"6. Search element\n";
		cout<<"7. Print\n";
		cout<<"8. Empty the List\n";
		cout<<"9. Delete all occurances of element\n";
		cout<<"0. Exit\n";
		
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter number to insert\n";
				cin>>e;
				l.insertLeft(e);
				break;
			case 2:
				cout<<"Enter number to insert\n";
				cin>>e;
				l.insertRight(e);
				break;
			case 3:
				l.deleteLeft();
				break;
			case 4:
				l.deleteRight();
				break;
			case 5:
				cout<<"Enter number to delete\n";
				cin>>e;
				l.deleteElement(e);
				break;
			case 6:
				cout<<"Enter number to search\n";
				cin>>e;
				b = l.search(e);
				if(b==true){
					cout<<"Number Found\n";
				}
				else cout<<"Number not found\n";
				break;
				
			case 7:	
				l.print();				
				break;
			case 8:	
				l.emptyList();				
				break;
			case 9:	
				cout<<"Enter number to delete all occurances\n";
				cin>>e;
				l.deleteAllOccurances(e);			
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

