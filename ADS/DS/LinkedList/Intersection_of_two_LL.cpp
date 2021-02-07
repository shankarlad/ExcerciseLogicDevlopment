#include<iostream>
#include<stack>
using namespace std;



struct Node{
	int data;
	struct Node *next;
};

class LinkedList{
	private:
		Node *root,*last;
		
	public: 
		friend void mergeLL(LinkedList&,LinkedList&,int);
		friend int getIntersection(LinkedList&,LinkedList&);
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

void mergeLL(LinkedList &l1,LinkedList &l2, int pos){
	Node *root1 = l1.root;
	Node *last2 = l2.last;
	for(int i = 1; i<pos;i++){
		root1 = root1->next;
	}
	last2->next = root1;
	l2.last = l1.last;
}

int getIntersection(LinkedList &l1, LinkedList &l2){
	stack<Node*> s1;
	stack<Node*> s2;
	Node *r1 = l1.root;
	Node *r2 = l2.root;
	int cnt=0;
	while(r1!=NULL){
		s1.push(r1);
		cnt++;
		r1=r1->next;
	}
	while(r2!=NULL){
		s2.push(r2);
		r2=r2->next;
	}
	while(!s1.empty() && !s2.empty()){
		if(s1.top() == s2.top()){
			s1.pop();
			s2.pop();
			cnt--;
		}
		else break;
	}
	return cnt;
}

int main(){
	LinkedList l1,l2;
	l1.initLinkedList();
	l1.insertRight(10);l1.insertRight(20);l1.insertRight(30);l1.insertRight(40);l1.insertRight(50);l1.insertRight(60);
	l2.initLinkedList();
	l2.insertRight(100);l2.insertRight(200);l2.insertRight(300);
	l1.print();
	l2.print();	
	mergeLL(l1,l2,1);
	l2.print();
	
	cout<<getIntersection(l1,l2);
	
	return 0;
}
