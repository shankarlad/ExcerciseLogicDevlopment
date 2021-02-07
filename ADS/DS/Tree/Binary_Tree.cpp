#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *lChild,*rChild;
};

class Queue{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(){
        front = 0;
        rear = -1;
        size = 10;
        Q = new *Node[size];
    }
    
    Queue(int size){
    	front = 0;
        rear = -1;
        this->size = size;
        Q = new *Node[size];
	}
	
	void enqueue(Node e);
	void dequeue();
	bool isEmpty();
	bool isFull();
	
};


void Queue::enqueue(Node e){
	rear++;
	Q[rear] = e;
}

void Queue::dequeue(){
	Q[front] = NULL;
	front++;
}

bool Queue::isEmpty(){
	if(front>rear){
		return true;
	}
	else return false;
}

bool Queue::isFull(){
	if(rear == size-1)
	return true;
	
	else return false;
}


class BinaryTree{
	private:
		Node *root;
		
	public:
		void createTree();
		
};
void BinaryTree::createTree(){
	Node *n;
	n = new Node;
	
}

int main(){
	
}

