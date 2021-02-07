#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

class BST{
	public:
		node *root;
		void initBST(){
			root = NULL;
		}
		void insert(node *p, node *n){
			if(root == NULL)
			root =n;
			
			else{
				if(n->data < p->data){
					if(p->left == NULL)
					p->left = n;
					else
					insert(p->left, n);
				}
				else if(n->data > p->data){
					if(p->right == NULL)
					p->right = n;
					else
					insert(p->right, n);
				}
			}
		}
		
		void inOrder(node *r){
			if(root == NULL)
			cout<<"Empty!!!!!!\n";
			else{
				if(r!=NULL){
					inOrder(r->left);
					cout<<r->data<<" ";
					inOrder(r->right);
				}
			}
		}
		void preOrder(node *r){
			if(root == NULL)
			cout<<"Empty!!!!!!\n";
			else{
				if(r!=NULL){
					cout<<r->data<<" ";
					preOrder(r->left);
					preOrder(r->right);
				}
			}
		}
		void postOrder(node *r){
			if(root == NULL)
			cout<<"Empty!!!!!!\n";
			else{
				if(r!=NULL){
					postOrder(r->left);
					postOrder(r->right);
					cout<<r->data<<" ";
				}
				
			}
		}

		
};


int main(){
	BST bst;
	bst.initBST();
	int num;
	node *n;
	cout<<"Enter 10 numbers\n";
	for(int i=0;i<10;i++){
		cin>>num;
		n = new node;
		n->data = num;
		n->left = n->right = NULL;
		bst.insert(bst.root,n);
	}
	cout<<"Inorder Traversal: \n";
	bst.inOrder(bst.root);
	
	cout<<"Preorder Traversal: \n";
	bst.preOrder(bst.root);
	
	cout<<"postorder Traversal: \n";
	bst.postOrder(bst.root);
}
