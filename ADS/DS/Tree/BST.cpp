#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

class BinaryTree{	
	public:
		Node *root;
		void initTree();
		void insert(Node *r,Node *n);
		void preOrder(Node *r);
		void postOrder(Node *r);
		void inOrder(Node *r);
		int count(Node *r);
		int height(Node *r);
		Node *deleteNode(Node *r,int key);
		struct Node *Delete(Node *,int);
};

void BinaryTree::initTree(){
	root = NULL;
}


void BinaryTree::insert(Node *r,Node *n){
	if(root == NULL){
		root = n;
	}
	else{
		if(n->data < r->data){
			if(r->left==NULL)
			r->left = n;
			else
			insert(r->left,n);
		}
		else{
			if(r->right==NULL)
			r->right = n;
			else
			insert(r->right,n);
		}
	}
}

void BinaryTree::inOrder(Node *r){
	if(r!=NULL){
 	inOrder(r->left);
 	cout<<r->data<<" ";
 	inOrder(r->right);
}
}

void BinaryTree::preOrder(Node *r){
	if(r!=NULL){
	cout<<r->data<<" ";
 	preOrder(r->left);
 	preOrder(r->right);
}
}

void BinaryTree::postOrder(Node *r){
	if(r!=NULL){
 	postOrder(r->left);
 	postOrder(r->right);
	cout<<r->data<<" ";
}
}

int BinaryTree::count(Node *r){
	int x,y;
	if(r!=NULL){
		x = count(r->left);
		y = count(r->right);
		return x+y+1;
	}
	else return 0;
}

int BinaryTree::height(Node *r){
	int x,y;
	if(r!=NULL){
		x=height(r->left);
		y= height(r->right);
		int ht = (x > y) ? (x+1) : (y+1);
		return ht;
	}
	else return -1;
}


Node * inPre(Node *pre){
	while(pre && pre->right != NULL){
		pre = pre->right;
	}
	return pre;
}


Node * inSuc(Node *suc){
	while(suc && suc->left != NULL){
		suc = suc->left;
	}
	return suc;
}

Node * BinaryTree::deleteNode(Node *p,int key){
	Node *q;
	if(p == NULL){
		cout<<"key: "<<key<<" Not found\n";
		return NULL;
	}
		
	else if(p->left == NULL && p->right == NULL && key == p->data)
		{
			if(p==root)
				root = NULL;
			delete p;
			return NULL;	
		}
	
	else if(key < p->data)
		p->left = deleteNode(p->left,key);
	else if(key > p->data)
		p->right = deleteNode(p->right,key);
	
	else if(key == p->data){
		if(height(p->left) > height(p->right)){
			q = inPre(p->left);
			p->data = q->data;
			p->left= deleteNode(p->left,q->data);	
		}
		else if(height(p->right) > height(p->left)){
			q = inSuc(p->right);
			p->data = q->data;
			p->right = deleteNode(p->right,q->data);
		}
		
	}
	return p;
}

struct Node * BinaryTree::Delete(struct Node *r, int key){
	if(r == NULL) {
		cout<<"Not fouund\n";
		return NULL;
	}
	
	else if(key < r->data)
		r->left = Delete(r->left,key);
	
	else if(key > r->data)
		r->right = Delete(r->right,key);
	
	else
	{
		//case 1: Leaf Node
		if(r->left == NULL && r->right == NULL){
			if(r== root)
				root = NULL;
			delete r;
			r = NULL;
			return r;
		} 	
		
		//case 2: (i) has only left child, right reference is NULL;
		else if(r->right == NULL){
			if(r==root) {root = r->left; delete r; return root;}
			struct Node *temp = r;
			r = r->left;
			delete temp;
			return r;
		}
		//case 2: (i) has only right child, left reference is NULL;
		else if(r->left == NULL){
			if(r==root) {root = r->right; delete r; return root;}
			struct Node *temp = r;
			r = r->right;
			delete temp;
			return r;
		}
		
		//case 3: has both the childs
		else
		{
			if(height(r->left) > height(r->right)){
				struct Node *temp = inPre(r->left);
				r->data = temp->data;
				r->left = Delete(r->left,temp->data);
			}
			else{
				struct Node *temp = inSuc(r->right);
				r->data = temp->data;
				r->right = Delete(r->right,temp->data);
			}	
		}
	}
	return r;
}


int main(){
	BinaryTree t;
	t.initTree();
	int choice;
	int no;
	Node *n;
	do{
		cout<<"Please enter choice\n"<<
		"1. Insert element\n"<<
		"2. PreOrder\n"<<
		"3. PostOrder\n"<<
		"4. InOrder\n"<<
		"5. Count\n"<<
		"6. Height\n"<<
		"7. Delete method1\n"<<
		"8. Delete method2\n"<<
		"0. Exit\n";
		cin>>choice;
		switch(choice){
			case 1:
				{
					cout<<"Enter Number\n";
					cin>>no;
					n = new Node;
					n->data = no;
					n->left = n->right = NULL;
					t.insert(t.root,n);
					break;
				}
				
			case 2:
				{
					t.preOrder(t.root);
					break;
				}
			case 3:
				{
					t.postOrder(t.root);
					break;
				}
			case 4:
				{
					t.inOrder(t.root);
					break;
				}
			case 5:
				{
					cout<<"The total count is: "<<t.count(t.root);
					break;
				}
			case 6:
				{
					cout<<"The total Height is: "<<t.height(t.root);
					break;
				}
			case 7:
				{
					int no;
					cout<<"Enter Number to delete: \n";
					cin>>no;
					t.deleteNode(t.root,no);
					break;
				}
			case 8:
				{
					int no;
					cout<<"Enter Number to delete: \n";
					cin>>no;
					t.Delete(t.root,no);
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
	
	
	return 0;
}
