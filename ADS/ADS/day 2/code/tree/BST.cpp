#include <iostream>
#include "queue.cpp"

using namespace std;

class Node{

    private:
        int data;
        Node* left;
        Node* right;
    public:
        
        Node(){
            left = right = NULL;
        }
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
        
        void print(){
            cout<<data<<" ";
        }

        int getData(){
            return data;
        }
        void setLeft(Node* left){
            this->left = left;
        }
        void setRight(Node* right){
            this->right = right;
        }
        Node* getLeft(){
            return left;
        }
        Node* getRight(){
            return right;
        }	
};

class BST{
    Node *root;
    public:
    BST(){
        root = NULL;
    }

    void insert(int data){
        Node *node = new Node(data);
        if( root == NULL)
            root = node;
        else{
            Node* temp = root;
            Node* prev = NULL;
            while( temp != NULL){
                prev = temp;
                if( data <= temp->getData())
                    temp= temp->getLeft();
                else
                    temp = temp->getRight();		
            }
            if( data <= prev->getData())
                prev->setLeft( node );	
            else
                prev->setRight( node );
        }

    }

    void BFT(){

        queue<Node*> store(100);

        store.enqueue( root );

        while( !store.isEmpty() ){

              Node *node = store.dequeue();

              node->print();

              if( node->getLeft() != NULL ){
                store.enqueue( node->getLeft() );
              }   
              if( node->getRight() != NULL ){
                store.enqueue( node->getRight() );
              }   
        }

    }
};

int main(){
    BST bst;
    while(1){
        string cmd;
        cin>>cmd;
        if( cmd == "ex"){
            break;
        }else if( cmd == "in"){
            int data;
            cin>>data;
            bst.insert(data);
        }else if( cmd == "BFT"){
            bst.BFT();
        }
    }	

    return 0;
}
