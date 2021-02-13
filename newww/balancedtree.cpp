#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
class Node{
	public:
		int data;
		Node *left;
		Node *right;
};

Node* newNode(int data) 
{ 
    Node* node = new Node(); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 

int max(int a, int b) 
{ 
    return (a >= b) ? a : b; 
} 

int height(Node *node){
	if(node == NULL)
		return 0;
	
	return 1 + max(height(node->left),height(node->right));
}

bool isBalanced(Node *root){
	int lh,rh;

	if(root == NULL)
		return 1;
	
	lh=height(root->left);
	rh=height(root->right);
	
	 if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
        return 1; 
        
    return 0;
}

int main(){
	Node* root = newNode(4); 
    root->left = newNode(5); 
    root->left->right = newNode(3); 
    root->left->left = newNode(1); 
    root->right = newNode(5); 
    root->right->right = newNode(6); 
  
    if (isBalanced(root)) 
        cout << "Tree is balanced"; 
    else
        cout << "Tree is not balanced"; 
    return 0; 
}
