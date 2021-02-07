#include<iostream>

using namespace std;

class Node{
	private:
	int data;
        Node *left;
        Node *right;
    public:
    	Node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
        
        int getdata(){
            return data;
        }
        
        void setleft(Node *left){
            this->left=left;
        }
        
        void setright(Node *right){
            this->right=right;
        }
        
        Node *getleft(){
            return left;
        }
        
        Node *getright(){
            return right;
        }
};


class BST{
    private:
        Node *root;
    public:
        BST(){
            root=NULL;
        }
        Node *getroot(){
            return root;
        }
        void insert(int data){
            Node *node=new Node(data);
            if(root==NULL){
                root=node;
            }
            else{
                Node *temp=root;
                Node *prev=root;
                while(temp!=NULL){
                    prev=temp;
                    if(data<=temp->getdata()){
                        temp=temp->getleft();
                    }
                    else{
                        temp=temp->getright();
                    }
                }
                if(data<=prev->getdata()){
                    prev->setleft(node);
                }
                else{
                    prev->setright(node);
                }
            }
    	}	
    	
    	int inorder(Node *root){
            if(root==NULL){
                return 0;
            }
            else{
                inorder(root->getleft());
                cout<<root->getdata()<<" ";
                inorder(root->getright());
            }
        }
       
        
        int preorder(Node *root){
            if(root==NULL){
                return 0;
            }
            else{
                cout<<root->getdata()<<" ";
                preorder(root->getleft());
                preorder(root->getright());
            }
        }
        
         int postorder(Node *root){
            if(root==NULL){
                return 0;
            }
            else{
                preorder(root->getleft());
                preorder(root->getright());
                cout<<root->getdata()<<" ";
            }
        }
       
};

int main(){
	BST bst;
    int data;
    while(1)
    {
        cin>>data;
        if(data==-1)
        {
            break;
        }   
    bst.insert(data);
    }
   bst.inorder(bst.getroot());
   cout<<endl;
   bst.preorder(bst.getroot());
   cout<<endl;
   bst.postorder(bst.getroot());
	return 0;
}

